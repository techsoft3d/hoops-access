import PrimaryButton from './PrimaryButton';

function TreeNode({ node }) {
  return (
    <div>
      <div className="text-[13px] text-gray-800 leading-loose">
        {node.children ? '▾' : '▸'} {node.label}
      </div>
      {node.children?.map((child) => (
        <div key={child.label} className="pl-5 text-[13px] text-gray-800 leading-loose">
          <span
            className={
              'inline-block w-2 h-2 rounded-sm mr-1.5 ' +
              (child.color === 'blue' ? 'bg-brand' : 'bg-gray-400')
            }
          />
          {child.label}
        </div>
      ))}
    </div>
  );
}

export default function StepStructured({ format, onNext }) {
  return (
    <div>
      <p className="text-[13px] font-light text-gray-600 mb-3.5 text-center">
        Same data, extracted through one consistent API, regardless of the
        format above
      </p>

      <div className="grid grid-cols-[0.9fr_1.1fr] gap-5">
        <div className="bg-gray-50 border border-gray-200 rounded-lg p-4">
          <p className="text-[11px] font-bold text-gray-400 uppercase tracking-wide mb-2.5">
            Model tree
          </p>
          {format.tree.map((node) => (
            <TreeNode key={node.label} node={node} />
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
              {format.table.rows.map((row) => (
                <tr
                  key={row.node}
                  className={
                    'border-t border-gray-200 ' +
                    (row.highlight ? 'bg-[#eaf3ff]' : '')
                  }
                >
                  <td className={'py-1 px-1.5 ' + (row.highlight ? 'text-brand' : '')}>
                    {row.node}
                  </td>
                  <td className="py-1 px-1.5">{row.x}</td>
                  <td className="py-1 px-1.5">{row.y}</td>
                  <td className="py-1 px-1.5">{row.z}</td>
                </tr>
              ))}
            </tbody>
          </table>
          <div className="bg-[#1a1a1a] rounded-md p-2 mt-2.5 font-mono text-[11px] text-gray-300">
            {format.apiCall}
          </div>
        </div>
      </div>

      <div className="flex justify-center mt-6">
        <PrimaryButton onClick={onNext}>View in 3D</PrimaryButton>
      </div>
    </div>
  );
}