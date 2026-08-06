/* PERMAS results tables */

#ifndef VDMPERMAS_DEF
#define VDMPERMAS_DEF

typedef struct {
    const Vchar* name;
    Vint shape;
    Vint maxi;
    Vint maxj;
    Vint maxk;
    Vint featype;
    Vint feaspec;
    Vint permute;
    Vint esys;
    Vint axi;
} vdm_PERMASLib_elem;

typedef struct {
    Vint restype;
    const Vchar* description;
    const Vchar* eltype;
    Vint enttype;
    Vint subtype;
    Vint special;
    Vint ndim;
    Vint nqua;
    Vint iqua[SYS_NQUA_MAX];
    const Vchar* cqua;
    Vint patterni[9];
    Vint patterno[9];
} vdm_PERMASLib_restype;

typedef struct {
    const Vchar* name;
    Vint soltyp;
    Vint nantyp;
    Vint nonlin;
} vdm_PERMASLib_soltyp;

typedef struct {
    const Vchar* name;
    Vint ntypes;
    Vint columndependent;
    vdm_PERMASLib_restype* types;
} vdm_PERMASLib_res;

#endif
