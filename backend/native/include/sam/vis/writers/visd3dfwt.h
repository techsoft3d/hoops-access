/* Dyna3D header file */
#ifndef VDMD3D_DEF
#define VDMD3D_DEF

#define D3D_NUMELEMTYPES 13

typedef struct {
    /* Initialization size must be larger than the longest name and desc words in d3dtypes */
    const Vchar name[SYS_MAXNAMECHAR];
    const Vchar desc[SYS_MAXNAMECHAR];
    Vint featyp, feaspc;
    Vint esys;
} fetypesD3D;
/* supported element types */
static const fetypesD3D d3dtypes[D3D_NUMELEMTYPES] = {
{"SOLID", "Solid", VIS_ELEM_SOLID, 0, SYS_ELEMSYS_GLOBAL},
{"TSHELL", "Thick Shell", VIS_ELEM_SOLID, SYS_SOLID_SHELL, SYS_ELEMSYS_GLOBAL},
{"SHELL", "Shell", VIS_ELEM_SHELL, 0, SYS_ELEMSYS_FIRSTEDGE},
{"BEAM", "Beam", VIS_ELEM_BEAM, 0, SYS_ELEMSYS_UNKNOWN},
{"DISCRETE", "Discrete Spring or Damper", VIS_ELEM_SPRINGDASHPOT, 0, SYS_ELEMSYS_FIRSTEDGE},
{"MASS", "Lumped Mass", VIS_ELEM_MASS, SYS_MASS_LUMP, 0},
{"INERTIA", "Lumped Inertia", VIS_ELEM_MASS, SYS_MASS_LUMP, 0},
{"SEATBELT", "Seat Belt", VIS_ELEM_SPRINGDASHPOT, SYS_SPRINGDASHPOT_SEATBELT, SYS_ELEMSYS_FIRSTEDGE},
{"PLOTEL", "Plot", SYS_ELEM_PLOT, 0, SYS_ELEMSYS_GLOBAL},
{"SPH", "Lumped Mass", SYS_ELEM_MASS, SYS_MASS_LUMP, SYS_ELEMSYS_GLOBAL},
{"PARTICLE", "Particle", SYS_ELEM_MASS, SYS_MASS_LUMP, SYS_ELEMSYS_GLOBAL},
{"DES", "Discrete Sphere", SYS_ELEM_MASS, SYS_MASS_LUMP, SYS_ELEMSYS_GLOBAL},
{"MESHSURF", "Mesh Surface", SYS_ELEM_MEMBRANE, SYS_MEMBRANE_FACE, SYS_ELEMSYS_GLOBAL},
};

enum ifetyp { SOLID, TSHELL, SHELL, BEAM, DISCRETE, MASS, INERTIA, SEATBELT, PLOTEL, SPH, PARTICLE, DES, MESHSURF };

#define D3D_NUMELEMSETTYPES 6
typedef struct {
    const Vchar name[SYS_MAXNAMECHAR];
    const Vchar desc[SYS_MAXNAMECHAR];
    Vint elementType;
} elemSetTypes;
/* supported element sets selection types */
static const elemSetTypes d3desettypes[D3D_NUMELEMSETTYPES] = {{"SOLID", "Solids set", SOLID},
                                                               {"TSHELL", "Thick Shells set", TSHELL},
                                                               {"SHELL", "Shells set", SHELL},
                                                               {"BEAM", "Beams set", BEAM},
                                                               {"DISCRETE", "Discrete Springs or Dampers set", DISCRETE},
                                                               {"PART", "parts set", D3D_NUMELEMTYPES + 1}};

enum ielemSetTyp { SETSOLID, SETTSHELL, SETSHELL, SETBEAM, SETDISCRETE, SETPART };

#endif
