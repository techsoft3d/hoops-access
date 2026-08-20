export const formats = {
  Nastran: {
    label: 'Nastran',
    filename: 'sdvk-531-toq_wing_box_simcenter-2_10incr_s-toq_wing_box_simcenter-2_10inc_4lcs.op2',
    samplePath: '/samples/sdvk-531-toq_wing_box_simcenter-2_10incr_s-toq_wing_box_simcenter-2_10inc_4lcs.op2',
    isBinary: true,
  },
  'LS-DYNA': {
    label: 'LS-DYNA',
    filename: 'sample_plate.key',
    samplePath: '/samples/sample_plate.key',
  },
  'IDEAS UNV': {
    label: 'IDEAS UNV',
    filename: 'sample_plate.unv',
    samplePath: '/samples/sample_plate.unv',
  },
};

export const formatList = Object.values(formats);