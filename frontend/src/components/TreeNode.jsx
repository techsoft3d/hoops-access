export default function TreeNode({ node, selectedLabel, onSelect, collapsedLabels, onToggleCollapse, depth = 0 }) {
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
        {hasChildren ? (isCollapsed ? '▸' : '▾') : '•'} {node.label}
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
