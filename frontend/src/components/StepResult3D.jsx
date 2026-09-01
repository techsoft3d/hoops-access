import { useState } from 'react';
import EnvisionViewer from "../envision/EnvisionViewer";
import TreeNode from './TreeNode';
import { buildTreeAndTable } from '../data/buildTreeAndTable';

export default function StepResult3D({ geometryData }) {
  const [selected, setSelected] = useState(null);
  const [collapsedLabels, setCollapsedLabels] = useState(() => new Set());

  if (!geometryData) {
    return (
      <div className="flex-1 min-h-0 bg-gray-100 rounded-lg relative overflow-hidden">
        <p className="flex items-center justify-center h-full text-[13px] text-gray-400">
          Waiting for Access to structure the file...
        </p>
      </div>
    );
  }

  const { tree } = buildTreeAndTable(geometryData);

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
    <div className="grid grid-cols-1 md:grid-cols-[0.5fr_1.5fr] gap-5 flex-1 min-h-0 overflow-y-auto">
      <div className="order-2 md:order-1 bg-gray-50 border border-gray-200 rounded-lg p-4 h-40 md:h-full overflow-y-auto">
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

      <div className="order-1 md:order-2 bg-gray-100 rounded-lg h-64 md:h-full relative overflow-hidden">
        <EnvisionViewer geometryData={geometryData} selectedPartIndex={selectedPartIndex} />
      </div>
    </div>
  );
}