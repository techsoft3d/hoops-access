import { useEffect, useState } from 'react';
import PrimaryButton from './PrimaryButton';

function TreeNode({ node, selectedLabel, onSelect, isCollapsed, onToggleCollapse }) {
  const isSelected = selectedLabel === node.label;
  const hasChildren = Boolean(node.children);
  return (
    <div>
      <button
        type="button"
        onClick={() => {
          onSelect(node);
          if (hasChildren) onToggleCollapse(node.label);
        }}
        className={
          'w-full text-left text-[13px] leading-loose rounded px-1 -mx-1 transition-colors cursor-pointer ' +
          (isSelected ? 'bg-brand/10 text-brand font-semibold' : 'text-gray-800 hover:bg-gray-100')
        }
      >
        {hasChildren ? (isCollapsed ? '▸' : '▾') : '▸'} {node.label}
      </button>
      {hasChildren && !isCollapsed &&
        node.children.map((child) => {
          const isChildSelected = selectedLabel === child.label;
          return (
            <button
              type="button"
              key={child.label}
              onClick={() => onSelect(child)}
              className={
                'block w-full text-left pl-5 text-[13px] leading-loose rounded px-1 -mx-1 transition-colors cursor-pointer ' +
                (isChildSelected ? 'bg-brand/10 text-brand font-semibold' : 'text-gray-800 hover:bg-gray-100')
              }
            >
              <span
                className={
                  'inline-block w-2 h-2 rounded-sm mr-1.5 bg-brand'
                }
              />
              {child.label}
            </button>
          );
        })}
    </div>
  );
}

export default function StepStructured({ format, onNext }) {
  const [selected, setSelected] = useState(null);
  const [collapsedLabels, setCollapsedLabels] = useState(() => new Set());

  // reset the selection and collapse state whenever the user switches to a different format
  useEffect(() => {
    setSelected(null);
    setCollapsedLabels(new Set());
  }, [format]);

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

  const highlightedIds = selected ? new Set(selected.nodeIds ?? []) : null;

  return (
    <div>
      <div className="grid grid-cols-[0.9fr_1.1fr] gap-5">
        <div className="bg-gray-50 border border-gray-200 rounded-lg p-4">
          <p className="text-[11px] font-bold text-gray-400 uppercase tracking-wide mb-2.5">
            Model tree
          </p>
          {format.tree.map((node) => (
            <TreeNode
              key={node.label}
              node={node}
              selectedLabel={selected?.label}
              onSelect={handleSelect}
              isCollapsed={collapsedLabels.has(node.label)}
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
                {format.table.columns.map((col) => (
                  <th key={col} className="text-left font-normal py-1 px-1.5">
                    {col}
                  </th>
                ))}
              </tr>
            </thead>
            <tbody>
              {(highlightedIds
                ? format.table.rows.filter((row) => highlightedIds.has(row.node))
                : format.table.rows
              ).map((row) => {
                const isHighlighted = highlightedIds ? true : row.highlight;
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
          {selected && highlightedIds.size === 0 && (
            <p className="text-[11px] text-gray-400 mt-2">
              No coordinate data published for "{selected.label}" yet.
            </p>
          )}
        </div>
      </div>

      <div className="flex justify-center mt-6">
        <PrimaryButton onClick={onNext}>View in 3D</PrimaryButton>
      </div>
    </div>
  );
}