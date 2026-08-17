import { useEffect, useRef } from "react";
import { buildEnvisionGeometry } from "./buildEnvisionGeometry";

// A small palette of visually distinct colors, one per part by default.
// If there are more parts than colors, it cycles back to the start.
const PART_COLORS = [
  [0.25, 0.55, 0.85], // blue
  [0.85, 0.45, 0.25], // orange
  [0.35, 0.7, 0.4],   // green
  [0.6, 0.4, 0.75],   // purple
  [0.8, 0.7, 0.2],    // yellow
];
const NEUTRAL_COLOR = [0.8, 0.8, 0.8];

function getPartColor(index) {
  return PART_COLORS[index % PART_COLORS.length];
}

/**
 * Renders the 3D geometry from real Access-derived geometryData
 * ({ nodes, parts }) using HOOPS Envision for Web.
 *
 * Each part gets its own distinct color by default. If selectedPartIndex
 * is provided, that part keeps its own color and every other part is
 * dimmed to a neutral gray, isolating the selection.
 *
 * Contour/scalar coloring is not yet wired up (scalar results aren't
 * produced by access_cli yet).
 */
export default function EnvisionViewer({ geometryData, selectedPartIndex }) {
  const containerRef = useRef(null);
  const canvasRef = useRef(null);

  const appRef = useRef({
    session: null,
    view: null,
    model: null,
    state: null,
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
  //    Each part gets its own distinct default color right away.
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

    state.geometry.getPartArray().forEach((part, idx) => {
      part.settings.color = new cee.Color3(...getPartColor(idx));
      part.settings.fringesVisible = false;
    });

    view.addModel(model);
    appRef.current.model = model;
    appRef.current.state = state;

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

  // 3. Re-color parts whenever the selected part changes — no model rebuild ---
  //    Selected part keeps its own color; every other part dims to neutral gray.
  //    No selection at all → every part shows its own distinct color again.
  useEffect(() => {
    const cee = window.cee;
    const { view, state, session } = appRef.current;
    if (!cee || !view || !state)
      return;

    state.geometry.getPartArray().forEach((part, idx) => {
      const isIsolating = selectedPartIndex !== null && selectedPartIndex !== undefined;
      const color = !isIsolating || idx === selectedPartIndex
        ? getPartColor(idx)
        : NEUTRAL_COLOR;
      part.settings.color = new cee.Color3(...color);
    });

    session?.getViewerAt(0)?.requestRedraw();
  }, [selectedPartIndex]);

  return (
    <div ref={containerRef} style={{ width: "100%", height: "100%" }}>
      <canvas ref={canvasRef} style={{ width: "100%", height: "100%", display: "block" }} />
    </div>
  );
}