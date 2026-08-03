import { useEffect, useRef } from "react";
import { geometryByFormat } from '../data/geometryData.js';
import buildEnvisionGeometry from '../envision/buildEnvisionGeometry.js';

/**
 * Renders the 3D geometry for the given format id (e.g. "nastran", "ansys",
 * "abaqus", "fluent") using HOOPS Envision for Web.
 *
 * Fills its parent container completely — size it with a wrapper div
 * (e.g. className="h-75 rounded-lg overflow-hidden").
 */
export default function EnvisionViewer({ formatId }) {
  const containerRef = useRef(null);
  const canvasRef = useRef(null);

  // Long-lived Envision objects — created once, reused across format changes.
  const appRef = useRef({
    session: null,
    view: null,
    model: null,
    rafId: null,
    resizeObserver: null,
  });

  // --- One-time setup: session, viewer, view, render loop ---
  useEffect(() => {
    const cee = window.cee;
    const canvas = canvasRef.current;
    const container = containerRef.current;
    if (!cee || !canvas || !container) return;

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

    // Keep the canvas sized to whatever space its container gives it.
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
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, []);

  // --- Rebuild the model whenever the selected format changes ---
  useEffect(() => {
    const cee = window.cee;
    const { view } = appRef.current;
    if (!cee || !view) return;

    const geometryData = geometryByFormat[formatId];
    if (!geometryData) {
      console.warn(`EnvisionViewer: no geometry data for format "${formatId}"`);
      return;
    }

    // Remove whatever was shown before
    view.removeAllModels();

    const model = new cee.usg.UnstructGridModel();
    const state = model.addState();
    const { geometry } = buildEnvisionGeometry(cee, geometryData);
    state.geometry = geometry;

    view.addModel(model);
    appRef.current.model = model;

    // Frame the camera on the new model
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
  }, [formatId]);

  return (
    <div ref={containerRef} style={{ width: "100%", height: "100%" }}>
      <canvas ref={canvasRef} style={{ width: "100%", height: "100%", display: "block" }} />
    </div>
  );
}
