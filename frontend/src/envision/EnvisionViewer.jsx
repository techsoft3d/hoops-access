import { useEffect, useRef } from "react";
import { buildEnvisionGeometry } from "./buildEnvisionGeometry";

/**
 * Renders the 3D geometry from real Access-derived geometryData
 * ({ nodes, parts }) using HOOPS Envision for Web.
 *
 * Contour/scalar coloring is not yet wired up (scalar results aren't
 * produced by access_cli yet) — parts render in a plain neutral color
 * for now.
 */
export default function EnvisionViewer({ geometryData }) {
  const containerRef = useRef(null);
  const canvasRef = useRef(null);

  const appRef = useRef({
    session: null,
    view: null,
    model: null,
    rafId: null,
    resizeObserver: null,
  });

  // 1. One-time setup: session, viewer, view, render loop ---
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

  // 2. Rebuild the model whenever geometryData changes ---
  useEffect(() => {
    const cee = window.cee;
    const { view } = appRef.current;
    if (!cee || !view || !geometryData)
      return;

    view.removeAllModels();

    const model = new cee.usg.UnstructGridModel();
    const state = model.addState();
    const { geometry } = buildEnvisionGeometry(cee, geometryData);
    state.geometry = geometry;

    // No scalar results yet — plain neutral color on every part.
    for (const part of state.geometry.getPartArray()) {
      part.settings.color = new cee.Color3(0.6, 0.65, 0.7);
      part.settings.fringesVisible = false;
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
  }, [geometryData]);

  return (
    <div ref={containerRef} style={{ width: "100%", height: "100%" }}>
      <canvas ref={canvasRef} style={{ width: "100%", height: "100%", display: "block" }} />
    </div>
  );
}