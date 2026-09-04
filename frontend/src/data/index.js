export const formats = {
  Nastran: {
    label: 'Nastran',
    filename: 'sdvk-531-toq_wing_box_simcenter-2_10incr_s-toq_wing_box_simcenter-2_10inc_4lcs.op2',
    samplePath: `${import.meta.env.BASE_URL}samples/sdvk-531-toq_wing_box_simcenter-2_10incr_s-toq_wing_box_simcenter-2_10inc_4lcs.op2`,
  },
  'Abaqus': {
    label: 'Abaqus',
    filename: 'viewer_tutorial_2026.odb',
    samplePath: `${import.meta.env.BASE_URL}samples/viewer_tutorial_2026.odb`,
  },
  'Ansys': {
    label: 'Ansys',
    filename: 'caefat-qa01-lnr113-ans2-v2026R1.rst',
    samplePath: `${import.meta.env.BASE_URL}samples/caefat-qa01-lnr113-ans2-v2026R1.rst`,
  },
};

export const formatList = Object.values(formats);