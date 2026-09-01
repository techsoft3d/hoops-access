import { useState } from 'react';
import EnvisionViewer from "../envision/EnvisionViewer";
import TreeNode from './TreeNode';
import { buildTreeAndTable } from '../data/buildTreeAndTable';

export default function StepResult3D({ geometryData }) {
  const [selected, setSelected] = useState(null);
  const [collapsedLabels, setCollapsedLabels] = useState(() => new Set());

  if (!geometryData) {
    return (
      <div className="bg-gray-100 rounded-lg h-136 relative overflow-hidden">
        <p className="flex items-center justify-center h-full text-[13px] text-gray-400">
          Waiting for Access to structure the file...
        </p>
      </div>
    );
  }

  const { tree } = buildTreeAndTable(geometryData);

  // The 3D step keeps the tree limited to what's actually highlightable in
  // the viewer — Mesh/Parts. Materials, Element Properties, Interaction
  // Pairs, or anything else non-spatial doesn't map to anything isolatable
  // here, so only Mesh survives; full detail lives in the Structured step.
  const VISIBLE_BRANCHES = new Set(['Mesh']);

  const treeWithoutElements = tree.map((modelNode) => ({
    ...modelNode,
    children: modelNode.children
      .filter((child) => VISIBLE_BRANCHES.has(child.label))
      .map((child) => ({
        ...child,
        children: child.children?.map((grandchild) => ({ ...grandchild, children: undefined })),
      })),
  }));

  function handleSelect(node) {
    setSelected((prev) => (prev?.label === node.label ? null : node));
  }

  function handleToggleCollapse(label) {
    setCollapsedLabels((prev) => {
      const next = new Set(prev);
      if (next.has(label)) next.delete(label);
      else next.add(label);
      return next;
    });
  }

  const selectedPartIndex = typeof selected?.partIndex === 'number' ? selected.partIndex : null;

  return (
    <div className="grid grid-cols-[0.5fr_1.5fr] gap-5">
      <div className="bg-gray-50 border border-gray-200 rounded-lg p-4">
        <p className="text-[11px] font-bold text-gray-400 uppercase tracking-wide mb-2.5">
          Model tree
        </p>
        {treeWithoutElements.map((node) => (
          <TreeNode
            key={node.label}
            node={node}
            selectedLabel={selected?.label}
            onSelect={handleSelect}
            collapsedLabels={collapsedLabels}
            onToggleCollapse={handleToggleCollapse}
          />
        ))}
      </div>

      <div className="bg-gray-100 rounded-lg h-136 relative overflow-hidden">
        <EnvisionViewer geometryData={geometryData} selectedPartIndex={selectedPartIndex} />
      </div>
    </div>
  );
}