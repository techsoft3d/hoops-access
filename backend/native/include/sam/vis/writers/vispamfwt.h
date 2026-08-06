/* ESI header file */
#ifndef VDMPAM_DEF
#define VDMPAM_DEF

#define PAM_NUMELEMTYPES 13

typedef struct {
    /* Initialization size must be larger than the longest name and desc words in pamtypes */
    const Vchar name[SYS_MAXNAMECHAR];
    const Vchar desc[SYS_MAXNAMECHAR];
    Vint featyp, feaspc;
    Vint esys;
} fetypesPam;

static const fetypesPam pamtypes[PAM_NUMELEMTYPES] = {
{"SOLID", "Solid", VIS_ELEM_SOLID, 0, SYS_ELEMSYS_GLOBAL},
{"BSHEL", "Brick Shell", VIS_ELEM_SOLID, 0, SYS_ELEMSYS_GLOBAL},
{"TSHEL", "Thick Shell", VIS_ELEM_SHELL, 0, SYS_ELEMSYS_GLOBAL},
{"SHELL", "Shell", VIS_ELEM_SHELL, 0, SYS_ELEMSYS_FIRSTEDGE},
{"SHEL6", "Shell", VIS_ELEM_SHELL, 0, SYS_ELEMSYS_FIRSTEDGE},
{"SHEL8", "Shell", VIS_ELEM_SHELL, 0, SYS_ELEMSYS_MIDEDGE},
{"MEMBR", "Membrane", VIS_ELEM_MEMBRANE, 0, SYS_ELEMSYS_STANDARD},
{"BEAM", "Beam", VIS_ELEM_BEAM, 0, SYS_ELEMSYS_UNKNOWN},
{"BAR", "Bar", VIS_ELEM_TRUSS, 0, SYS_ELEMSYS_UNKNOWN},
{"SPRGBM", "Spring-Beam", VIS_ELEM_SPRINGDASHPOT, 0, SYS_ELEMSYS_FIRSTEDGE},
{"SPRING", "6-DOF Spring/Dashpot", VIS_ELEM_SPRINGDASHPOT, 0, SYS_ELEMSYS_FIRSTEDGE},
{"GAP", "Gap", VIS_ELEM_GAP, 0, SYS_ELEMSYS_FIRSTEDGE},
{"PARTICLE", "Particle", SYS_ELEM_MASS, SYS_MASS_LUMP, SYS_ELEMSYS_GLOBAL},
};

enum ifetyp { SOLID, BSHEL, TSHEL, SHELL, SHEL6, SHEL8, MEMBR, BEAM, BAR, SPRGBM, SPRING, GAP, PARTICLE };

#endif
