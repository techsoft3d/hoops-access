import { useEffect, useRef } from "react";
import { geometryByFormat } from "../data/geometryData";
import { buildEnvisionGeometry } from "./buildEnvisionGeometry";
import { CONTOUR_COLORS, hexToUnitRgb } from "../data/contourColors";

/**
 * Renders the 3D geometry for the given format id (e.g. "nastran", "ansys",
 * "abaqus", "fluent") using HOOPS Envision for Web, contoured by resultName
 * if a matching fake dataset exists in geometryData.js.
 */
export default function EnvisionViewer({ formatId, resultName }) {
  const containerRef = useRef(null);
  const canvasRef = useRef(null);

  const appRef = useRef({
    session: null,
    view: null,
    model: null,
    rafId: null,
    resizeObserver: null,
  });

  //1. One-time setup: session, viewer, view, render loop ---
  useEffect(() => {
    const cee = window.cee;
    const canvas = canvasRef.current;
    const container = containerRef.current;
    if (!cee || !canvas || !container) 
      return;

    const session = new cee.CloudSession();
    const viewer = session.addViewer(canvas);
    if (!viewer) {
      console.error("EnvisionViewer: no WebGL support");
      return;
    }
    const view = viewer.addView();
    view.background.setSingleColor({ r: 0.95, g: 0.95, b: 0.95, a: 1 });
    view.operators.push(new cee.NavigationOperator());

    appRef.current.session = session;
    appRef.current.view = view;

    const resizeObserver = new ResizeObserver(() => {
      const { clientWidth, clientHeight } = container;
      if (clientWidth > 0 && clientHeight > 0) {
        session.getViewerAt(0).resizeViewer(clientWidth, clientHeight);
      }
    });
    resizeObserver.observe(container);
    appRef.current.resizeObserver = resizeObserver;

    const frameCallback = (t) => {
      appRef.current.session?.handleAnimationFrameCallback(t);
      appRef.current.rafId = requestAnimationFrame(frameCallback);
    };
    appRef.current.rafId = requestAnimationFrame(frameCallback);

    return () => {
      cancelAnimationFrame(appRef.current.rafId);
      appRef.current.resizeObserver?.disconnect();
      session.destroySession();
    };
  }, []);

  // 2. Rebuild the model + contour whenever format or result changes ---
  useEffect(() => {
    const cee = window.cee;
    const { view } = appRef.current;
    if (!cee || !view) 
      return;

    const geometryData = geometryByFormat[formatId];
    if (!geometryData) {
      console.warn(`EnvisionViewer: no geometry data for format "${formatId}"`);
      return;
    }

    view.removeAllModels();

    const model = new cee.usg.UnstructGridModel();
    const state = model.addState();
    const { geometry, nodeIdsByPartIndex } = buildEnvisionGeometry(cee, geometryData);
    state.geometry = geometry;

    // Apply the fake scalar dataset for this resultName, if one exists.
    const scalarsByNodeId = geometryData.scalarsByResult?.[resultName];
    if (scalarsByNodeId) {
      const allValues = Object.values(scalarsByNodeId);
      const min = Math.min(...allValues);
      const max = Math.max(...allValues);

      const low = hexToUnitRgb(CONTOUR_COLORS.low);
      const mid = hexToUnitRgb(CONTOUR_COLORS.mid);
      const high = hexToUnitRgb(CONTOUR_COLORS.high);

      const mapper = new cee.ScalarMapperFilledContoursUniform();
      mapper.colorArray = [
        new cee.Color4(low.r, low.g, low.b, 1),
        new cee.Color4(mid.r, mid.g, mid.b, 1),
        new cee.Color4(high.r, high.g, high.b, 1),
      ];
      mapper.setRange(min, max);
      model.fringesSettings.scalarMapper = mapper;

      state.geometry.getPartArray().forEach((part, partIdx) => {
        const nodeIds = nodeIdsByPartIndex[partIdx];
        const scalarArr = new Float32Array(
          nodeIds.map((nodeId) => scalarsByNodeId[nodeId] ?? 0)
        );
        const partScalar = new cee.usg.PartScalars(
          cee.usg.ResultMapping.PER_NODE,
          scalarArr
        );
        state.setPartFringesAt(partIdx, partScalar);
        part.settings.fringesVisible = true;
      });
    } else {
      // No dataset for this result yet — fall back to a plain neutral color.
      for (const part of state.geometry.getPartArray()) {
        part.settings.color = new cee.Color3(0.6, 0.65, 0.7);
        part.settings.fringesVisible = false;
      }
    }

    view.addModel(model);
    appRef.current.model = model;

    const bbox = model.getBoundingBox();
    const viewer = appRef.current.session.getViewerAt(0);
    const navOp = view.operators.get(cee.StandardOperator.NAVIGATION);
    if (navOp) navOp.rotationPoint = bbox.getCenter();

    view.camera.setFromLookAt(
      cee.Vec3.add(bbox.getCenter(), new cee.Vec3(2, -3, 2)),
      bbox.getCenter(),
      new cee.Vec3(0, 0, 1)
    );
    view.camera.fitView(bbox, view.camera.getDirection(), view.camera.getUp(), 1.4);
    viewer.requestRedraw();
  }, [formatId, resultName]);

  return (
    <div ref={containerRef} style={{ width: "100%", height: "100%" }}>
      <canvas ref={canvasRef} style={{ width: "100%", height: "100%", display: "block" }} />
    </div>
  );
}