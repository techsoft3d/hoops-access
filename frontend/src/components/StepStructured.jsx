import { useEffect, useState } from 'react';
import PrimaryButton from './PrimaryButton';
import { buildTreeAndTable } from '../data/buildTreeAndTable';

function TreeNode({ node, selectedLabel, onSelect, collapsedLabels, onToggleCollapse, depth = 0 }) {
  const isSelected = selectedLabel === node.label;
  const hasChildren = Boolean(node.children && node.children.length);
  const isCollapsed = collapsedLabels.has(node.label);

  return (
    <div>
      <button
        type="button"
        onClick={() => {
          onSelect(node);
          if (hasChildren) 
            onToggleCollapse(node.label);
        }}
        style={{ paddingLeft: depth * 16 }}
        className={
          'block w-full text-left text-[13px] leading-loose rounded px-1 -mx-1 transition-colors cursor-pointer ' +
          (isSelected ? 'bg-brand/10 text-brand font-semibold' : 'text-gray-800 hover:bg-gray-100')
        }
      >
        {hasChildren ? (isCollapsed ? '▸' : '▾') : '▸'} {node.label}
      </button>
      {hasChildren && !isCollapsed &&
        node.children.map((child) => (
          <TreeNode
            key={child.label}
            node={child}
            selectedLabel={selectedLabel}
            onSelect={onSelect}
            collapsedLabels={collapsedLabels}
            onToggleCollapse={onToggleCollapse}
            depth={depth + 1}
          />
        ))}
    </div>
  );
}

export default function StepStructured({ format, geometryData, onNext }) {
  const [selected, setSelected] = useState(null);
  const [collapsedLabels, setCollapsedLabels] = useState(() => new Set());

  useEffect(() => {
    setSelected(null);
    setCollapsedLabels(new Set());
  }, [format]);

  if (!geometryData) {
    return <p className="text-[13px] text-gray-400">Waiting for Access to structure the file...</p>;
  }

  const { tree, table } = buildTreeAndTable(geometryData);

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

  const highlightedIds = selected ? new Set((selected.nodeIds ?? []).map(String)) : null;

  return (
    <div>
      <div className="grid grid-cols-[0.9fr_1.1fr] gap-5">
        <div className="bg-gray-50 border border-gray-200 rounded-lg p-4">
          <p className="text-[11px] font-bold text-gray-400 uppercase tracking-wide mb-2.5">
            Model tree
          </p>
          {tree.map((node) => (
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

        <div className="bg-gray-50 rounded-lg p-4 border-2 border-brand">
          <p className="text-[11px] font-bold text-brand uppercase tracking-wide mb-2.5">
            Node coordinates
          </p>
          <table className="w-full text-[13px] border-collapse">
            <thead>
              <tr className="text-gray-400">
                {table.columns.map((col) => (
                  <th key={col} className="text-left font-normal py-1 px-1.5">
                    {col}
                  </th>
                ))}
              </tr>
            </thead>
            <tbody>
              {(highlightedIds
                ? table.rows.filter((row) => highlightedIds.has(String(row.node)))
                : table.rows
              ).map((row) => {
                const isHighlighted = Boolean(highlightedIds);
                return (
                  <tr
                    key={row.node}
                    className={
                      'border-t border-gray-200 ' +
                      (isHighlighted ? 'bg-[#eaf3ff]' : '')
                    }
                  >
                    <td className={'py-1 px-1.5 ' + (isHighlighted ? 'text-brand' : '')}>
                      {row.node}
                    </td>
                    <td className="py-1 px-1.5">{row.x}</td>
                    <td className="py-1 px-1.5">{row.y}</td>
                    <td className="py-1 px-1.5">{row.z}</td>
                  </tr>
                );
              })}
            </tbody>
          </table>
        </div>
      </div>

      <div className="flex justify-center mt-6">
        <PrimaryButton onClick={onNext}>View in 3D</PrimaryButton>
      </div>
    </div>
  );
}