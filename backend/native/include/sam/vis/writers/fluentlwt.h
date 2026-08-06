/* FLUENTLwt object */
#ifndef FLUENTLWT_DEF
#define FLUENTLWT_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"

typedef struct vis_FLUENTLwt {
    Vint ierr;
    FILE* fd;
    vis_GridFun* gf;
    Vint numnp;
    Vint numel;
    Vint soltyp; /* solution type */
    Vint nantyp; /* analysis type */
    vis_Connect* connect;
    vis_Connect* connectf;    /* corner node cells */
    Vint ztype;               /* elem assoc to determine zones */
    Vint ynzero, znzero;      /* number of non-zero y and z coordinates */
    Vint ndim;                /* number of spatial dimensions */
    Vint numcell;             /* number of solid elements */
    Vint numface;             /* number of 3D faces or 2D edges */
    Vint numnode;             /* number of corner nodes */
    Vint subtype;             /* 3D face or 2D edge */
    vsy_List* listzone;       /* complete zone identification string */
    vsy_IntVec* veczone;      /* zone identifier (partid) */
    vsy_IntDict* namestgpid;  /* use this to search for unique zone namestg */
    vsy_List* namezone;       /* keep track of actual generated zone name */
    vis_Group* fgroup;        /* unique face group */
    vis_IdTran* idtranpid;    /* pids of solid elements */
    vis_IdTran* idtranuni;    /* unique pids (cell zones) of solid elements */
    vis_IdTran* idtranfir;    /* first element in cell zone */
    vis_IdTran* idtrannum;    /* number of elements in cell zone */
    vis_IdTran* idtranetp;    /* element type in cell zone */
    vis_IdTran* idtrantyp;    /* type in cell zone */
    Vint numpart;             /* number of parts */
    vsy_HashTable* cellzones; /* PropSets for cell zone info by pid */
    vsy_IntDict* intdict;     /* face zone number of faces */
    vsy_IntDict* intdictfetp; /* face face_types */
    vsy_IntDict* intdictftyp; /* face boundary types */
    vsy_IntDict* intdictfifz; /* face zone number */
    vsy_List* listznam;       /* znam by face zone number */
    Vint numfacezone;         /* number of face zones */
    vis_IdTran* idtranffir;   /* first face in face zone */
    vis_IdTran* idtranfnum;   /* number of faces in face zone */
    vis_IdTran* idtranfetp;   /* face type in face zone */
    vis_IdTran* idtranftyp;   /* type in face zone */
    Vint* ia_feid;            /* element id of face */
    Vint* ia_feno;            /* element no of face */
    Vint* ia_feix;            /* element adjacent of face */
    Vint* ia_fifz;            /* element zone of face */
    vsy_HashTable* facezones; /* PropSets for face zone info */
} vis_FLUENTLwt;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vis_FLUENTLwt*
vis_FLUENTLwtBegin(void);
VKI_EXTERN void
vis_FLUENTLwt_Construct(vis_FLUENTLwt* p);
VKI_EXTERN void
vis_FLUENTLwtEnd(vis_FLUENTLwt* p);
VKI_EXTERN void
vis_FLUENTLwt_Destruct(vis_FLUENTLwt* p);
VKI_EXTERN Vint
vis_FLUENTLwtError(vis_FLUENTLwt* p);
VKI_EXTERN void
vis_FLUENTLwtInit(vis_FLUENTLwt* p, vis_Model* model);
VKI_EXTERN void
vis_FLUENTLwtTerm(vis_FLUENTLwt* p);
VKI_EXTERN void
vis_FLUENTLwtDimension(vis_FLUENTLwt* p, Vint* nd);
VKI_EXTERN void
vis_FLUENTLwtNumEntities(vis_FLUENTLwt* p, Vint* numcell, Vint* numface, Vint* numnode);
VKI_EXTERN void
vis_FLUENTLwtNumCellZone(vis_FLUENTLwt* p, Vint* numcellzone);
VKI_EXTERN void
vis_FLUENTLwtCellZoneParam(vis_FLUENTLwt* p, Vint ithcellzone, Vint* ifirst, Vint* ilast, Vint* type, Vint* etype);
VKI_EXTERN void
vis_FLUENTLwtCellZoneType(vis_FLUENTLwt* p, Vint ithcellzone, Vint type[]);
VKI_EXTERN void
vis_FLUENTLwtCellZoneElem(vis_FLUENTLwt* p, Vint ithcellzone, Vint elem[]);
VKI_EXTERN void
vis_FLUENTLwtCellZoneName(vis_FLUENTLwt* p, Vint ithcellzone, Vchar name[]);
VKI_EXTERN void
vis_FLUENTLwtCellZoneId(vis_FLUENTLwt* p, Vint ithcellzone, Vint* id);
VKI_EXTERN void
vis_FLUENTLwtNumFaceZone(vis_FLUENTLwt* p, Vint* numfacezone);
VKI_EXTERN void
vis_FLUENTLwtFaceZoneParam(vis_FLUENTLwt* p, Vint ithfacezone, Vint* ifirst, Vint* ilast, Vint* type, Vint* etype);
VKI_EXTERN void
vis_FLUENTLwtFaceZoneType(vis_FLUENTLwt* p, Vint ithfacezone, Vint type[]);
VKI_EXTERN void
vis_FLUENTLwtFaceZone(vis_FLUENTLwt* p, Vint ithfacezone, Vint ixf[], Vint cr[], Vint cl[]);
VKI_EXTERN void
vis_FLUENTLwtFaceZoneName(vis_FLUENTLwt* p, Vint ithfacezone, Vchar name[]);
VKI_EXTERN void
vis_FLUENTLwtFaceZoneId(vis_FLUENTLwt* p, Vint ithfacezone, Vint* id);
VKI_EXTERN void
vis_FLUENTLwtNode(vis_FLUENTLwt* p, Vdouble x[]);
VKI_EXTERN void
vis_FLUENTLwtWriteModelAux(vis_FLUENTLwt* p, vis_Model* model, const Vchar* path);
VKI_EXTERN void
vis_FLUENTLwtWriteModel(vis_FLUENTLwt* p, vis_Model* model, const Vchar* path);

#ifdef __cplusplus
}
#endif

#endif
