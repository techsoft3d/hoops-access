/*********************************************************************
 *                                                                   *
 *                          DevTools 3.1.0                           *
 *                                                                   *
 *  These coded instructions, statements and computer programs       *
 *  contain unpublished proprietary information of Tech Soft 3D,     *
 *  and are protected by Federal copyright law.  They may not be     *
 *  disclosed to third parties or copied or duplicated in any form,  *
 *  in whole or in part, without the prior written consent of        *
 *  Tech Soft 3D.                                                    *
 *                                                                   *
 *                 Copyright (C) 2026, Tech Soft 3D                  *
 *                                                                   *
 *********************************************************************/
/* vdm utility functions header file */
#ifndef VDMUTIL_DEF
#define VDMUTIL_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/attribute.h"
#include "sam/vdm/dataset.h"
#include "sam/vdm/library.h"

#define VDMUTIL_STRAINTYPE_NONE        0
#define VDMUTIL_STRAINTYPE_TENSOR      1
#define VDMUTIL_STRAINTYPE_ENGINEERING 2

#define VDMUTIL_TOKEN_DATASET     1
#define VDMUTIL_TOKEN_ATTRIBUTE   2
#define VDMUTIL_TOKEN_DATASETDATA 3
#define VDMUTIL_TOKEN_PUSHLIBRARY 4
#define VDMUTIL_TOKEN_POPLIBRARY  5

#ifdef __cplusplus
extern "C" {
#endif
/* inline methods */
extern Vchar* vdm_modecont[SYS_CATEGORY_MAX];
#define VDM_modecont(i) vdm_modecont[(i)]
extern Vchar* vdm_nodename[VIS_MAXASSOC];
#define VDM_nodename(i) vdm_nodename[(i)]
extern Vchar* vdm_nodedesc[VIS_MAXASSOC];
#define VDM_nodedesc(i) vdm_nodedesc[(i)]
extern Vchar* vdm_elemname[VIS_MAXASSOC];
#define VDM_elemname(i) vdm_elemname[(i)]
extern Vchar* vdm_elemdesc[VIS_MAXASSOC];
#define VDM_elemdesc(i) vdm_elemdesc[(i)]

extern void
vdm_numattributes(vdm_Library* library, Vint idst, Vint* numattributes);
extern void
vdm_getattval(vdm_Library* library, Vint idst, Vint iatt, void* value);
extern void
vdm_inqattribute(vdm_Library* library, Vint idst, Vint iatt, Vchar name[], Vint* length, Vint* type);
extern void
vdm_inqdataset(vdm_Library* library, Vint idst, Vchar name[], Vlong* lrec, Vint* nrow, Vint* ncol, Vint* type);
extern void
vdm_createQuaVal(Vint quavaltype, Vint ival, Vfloat fval, Vchar* quaval);
extern void
vdm_parseQuaVal(Vchar* cqua, Vint quaval[], Vint dtype[], Vint ival[], Vfloat fval[]);
extern void
vdm_createCaux(Vint nqua, Vint iqua[], const Vchar* cqua, Vint cplx, Vchar* caux);
extern void
vdm_createNodeDataset(Vint hist, Vint type, Vint nqua, Vint iqua[], const Vchar* cqua, Vint ipre, Vint cplx, Vint icat, Vint nsys,
                      Vint ncmp, Vint numnp, Vint id1, Vint id2, Vint id3, vdm_Dataset** dataset);
extern void
vdm_createNodeDatasetR(Vint type, Vint nqua, Vint iqua[], const Vchar* cqua, Vint ipre, Vint cplx, Vint icat, Vint nsys,
                       Vint ncmp, Vint numnp, Vint id1, Vint id2, Vint id3, vdm_Dataset** dataset);
extern void
vdm_createParticleDatasetR(Vint type, Vint nqua, Vint iqua[], const Vchar* cqua, Vint ipre, Vint ncmp, Vint nparticles, Vint id1,
                           Vint id2, Vint id3, vdm_Dataset** dataset);
extern void
vdm_createModeDataset(Vint type, Vint nqua, Vint iqua[], const Vchar* cqua, Vint dtyp, Vint ncmp, Vint nummode, Vint id1,
                      Vint id2, Vint id3, vdm_Dataset** dataset);
extern void
vdm_abbrNodeDataset(Vint type, Vint nabbr, const Vchar* caux, Vint id1, Vint id2, Vint id3, Vchar dabbr[]);
extern void
vdm_abbrParticleDataset(Vint type, Vint nabbr, const Vchar* caux, Vint id1, Vint id2, Vint id3, Vchar dabbr[]);
extern void
vdm_abbrElemDataset(Vint type, Vint nabbr, Vint sect, Vint enfl, const Vchar* caux, Vint id1, Vint id2, Vint id3, Vchar dabbr[]);
extern void
vdm_attrNodeDatasetQ(vdm_Dataset* dataset, Vint type, Vint nqua, Vint iqua[], const Vchar* cqua, Vint icat, Vint nsys, Vint ncmp);
extern void
vdm_attrElemDatasetQ(vdm_Dataset* dataset, Vint type, Vint nqua, Vint iqua[], const Vchar* cqua, Vint icat, Vint enfl, Vint esys,
                     Vint ncmp);
extern void
vdm_createEntDof(vdm_Library* library, vsy_Dictionary* hdict, Vint nument, Vint na, Vint* nh, vis_IdTran* idtranh, Vchar dname[]);
extern void
vdm_createSection(vdm_Library* library, vsy_Dictionary* hdict, Vint numel, Vint na, Vint* nh, vis_IdTran* idtranh, Vchar dname[],
                  vsy_Dictionary* hgdict, vis_Group* grouph);
extern void
vdm_lookupSection(vdm_Dataset* dataset, vsy_Dictionary* hdict, Vint* enfl, vis_IdTran** idtran, vsy_Dictionary* hgdict,
                  vis_Group** group);
extern void
vdm_formSectionPntr(vis_IdTran* idtrans, vis_IdTran* idtrani, Vint nind, Vint enfl, vis_Connect* connect, Vint ncmp,
                    vis_IdTran* idtranp);
extern void
vdm_addLayers(vsy_CVect* cvect, Vint index, Vint lpos, Vint nlay);
extern void
vdm_checkLayers(vsy_CVect* cvect, Vint numel, vis_IdTran* idtran, Vint* lflag);
extern void
vdm_createLayers(vdm_Library* library, vsy_Dictionary* hdict, Vint* nh, vsy_CVect* cvech, Vchar dname[], Vint* flag);
extern void
vdm_createMatSiz(vdm_Library* library, vsy_Dictionary* hdict, Vint* nh, vsy_CVect* cvech, Vchar dsname[], Vchar dname[]);
extern void
vdm_initIndex(vdm_DataFun* df, vdm_Library* library, vsy_Dictionary* hdict, Vint* nh);
extern void
vdm_createLinkIndexDataset(vdm_Library* library, vsy_Dictionary* hidict, Vint enttype, Vint* nhent, vis_IdTran* idtranh,
                           Vchar dname[], vdm_Dataset* associatedDataset);
extern void
vdm_lookupIndex(vdm_Dataset* dataset, vsy_Dictionary* hdict, Vint* nent, vis_IdTran** idtran);
extern void
vdm_initHistStep(vdm_DataFun* df, vdm_Library* library, vsy_Dictionary* hdict, Vint* nh);
extern void
vdm_createHistStep(vdm_Library* library, vsy_Dictionary* hdict, Vint* nh, vsy_IntVec* intvech, Vchar dname[]);
extern void
vdm_initHistTime(vdm_DataFun* df, vdm_Library* library, vsy_Dictionary* hdict, Vint iglv, Vint* nh);
extern void
vdm_createHistTime(vdm_Library* library, vsy_Dictionary* hdict, Vint iglv, Vint* nh, vsy_DblVec* dblvech, Vchar dname[]);
extern void
vdm_createComponent(vdm_Library* library, vsy_Dictionary* hdict, Vint enttype, Vint subtype, Vint lrec, Vint ncmp, Vint nind,
                    Vchar* dindx, Vint* nh, vsy_IntVec* intvech, Vchar dname[]);
extern void
vdm_findAbbrRoot(Vchar* droot, Vint* type);
extern void
vdm_findDataType(Vchar* dtype, Vint* dattype);
extern void
vdm_findComplexType(Vchar* ctype, Vint* complextype);
extern void
vdm_createElemCentDataset(Vint hist, Vint type, Vint nqua, Vint iqua[], const Vchar* cqua, Vint ipre, Vint cplx, Vint ieig,
                          Vint esys, Vint esec, Vint ncmp, Vint numel, Vint id1, Vint id2, Vint id3, vdm_Dataset** dataset);
extern void
vdm_createElemCentDatasetR(Vint type, Vint nqua, Vint iqua[], const Vchar* cqua, Vint ipre, Vint cplx, Vint ieig, Vint esys,
                           Vint esec, Vint ncmp, Vint numel, Vint id1, Vint id2, Vint id3, vdm_Dataset** dataset);
extern void
vdm_createElemNodeDataset(Vint hist, Vint type, Vint nqua, Vint iqua[], const Vchar* cqua, Vint ipre, Vint cplx, Vint ieig,
                          Vint esys, Vint sect, Vlong lng, Vint ncmp, Vint numel, Vint id1, Vint id2, Vint id3,
                          vdm_Dataset** dataset);
extern void
vdm_createElemNodeDatasetR(Vint type, Vint nqua, Vint iqua[], const Vchar* cqua, Vint ipre, Vint cplx, Vint ieig, Vint esys,
                           Vint sect, Vlong lng, Vint ncmp, Vint numel, Vint id1, Vint id2, Vint id3, vdm_Dataset** dataset);
extern void
vdm_createEIPDataset(Vint type, Vint nqua, Vint iqua[], const Vchar* cqua, Vint ipre, Vint cplx, Vint ieig, Vint esys, Vint sect,
                     Vlong lng, Vint ncmp, Vint numel, Vint id1, Vint id2, Vint id3, vdm_Dataset** dataset);
extern void
vdm_createEIPDatasetR(Vint hist, Vint type, Vint nqua, Vint iqua[], const Vchar* cqua, Vint ipre, Vint cplx, Vint ieig, Vint esys,
                      Vint sect, Vlong lng, Vint ncmp, Vint numel, Vint id1, Vint id2, Vint id3, vdm_Dataset** dataset);
extern void
vdm_createElemEntDataset(Vint type, Vint nqua, Vint iqua[], const Vchar* cqua, Vint enttype, Vint subtype, Vint ipre, Vint cplx,
                         Vint ieig, Vint esys, Vlong lng, Vint ncmp, Vint nument, Vint id1, Vint id2, Vint id3,
                         vdm_Dataset** dataset);
extern void
vdm_createElemEntDatasetR(Vint hist, Vint type, Vint nqua, Vint iqua[], const Vchar* cqua, Vint enttype, Vint subtype, Vint ipre,
                          Vint cplx, Vint ieig, Vint esys, Vlong lng, Vint ncmp, Vint nument, Vint id1, Vint id2, Vint id3,
                          vdm_Dataset** dataset);
extern void
vdm_createRedMatDataset(Vint type, Vint nqua, Vint iqua[], Vint ndof, Vint ipre, Vint isprs, Vlong lsprs, Vint dtype, Vint id1,
                        vdm_Dataset** dataset);
extern void
vdm_createDataset(vdm_Library* library, Vint type, Vchar* dnam, Vint lrec, Vint nrow, Vint ncol, Vint ntyp,
                  vdm_Dataset** dataset);
vdm_Dataset*
vdm_createDatasetResult(vis_ResultInformation* resultInformation);
extern void
vdm_createAttribute(vdm_Dataset* dataset, const Vchar* anam, const Vchar* cval);
extern void
vdm_saveAttribute(vdm_DataFun* df, Vint idst, const Vchar* name, Vint length, Vint type, void* val);
extern void
vdm_createAttributeReal(vdm_Dataset* dataset, const Vchar* anam, Vint nval, Vfloat rval[]);
extern void
vdm_createAttributeDouble(vdm_Dataset* dataset, const Vchar* anam, Vint nval, Vdouble rval[]);
extern void
vdm_createAttributeInt(vdm_Dataset* dataset, const Vchar* anam, Vint nval, Vint ival[]);
extern void
vdm_addContents(vdm_Dataset* dataset, const Vchar* caux, Vint type, Vint ieig);
extern void
vdm_saveContentsQ(vdm_DataFun* df, Vint idst, Vint type, Vint nqua, Vint iqua[], const Vchar* cqua, Vint icat);
extern void
vdm_addContentsQ(vdm_Dataset* dataset, Vint type, Vint nqua, Vint iqua[], const Vchar* cqua, Vint icat);
extern void
vdm_genDataType(Vint type, Vint ncmp, Vint* dtyp);
extern void
vdm_addDataType(vdm_Dataset* dataset, Vint type, Vint ncmp);
extern void
vdm_repDataType(vdm_Dataset* dataset, Vint datatype);
extern void
vdm_addScalarn(vdm_Dataset* dataset, Vint n, Vchar* stg);
extern void
vdm_copyTitle(const Vchar* tit, Vint len, Vchar* stg);
extern void
vdm_addTitles(vdm_Dataset* dataset, const Vchar* tit, const Vchar* stit, const Vchar* lab, const Vchar* slab);
extern void
vdm_addLabel(vdm_Dataset* dataset, Vint ist, const Vchar* stt);
extern void
vdm_addSubtitle(vdm_Dataset* dataset, Vint ist, const Vchar* stt);
extern void
vdm_nameComplex(vdm_Dataset* dataset, Vchar* dcplx);
extern void
vdm_addComplex(vdm_Dataset* dataset, Vint cplx, Vint link);
extern void
vdm_addStrainType(vdm_Dataset* dataset, Vint istrn);
extern void
vdm_addDataSource(vdm_Dataset* dataset, const Vchar* datasource);
extern void
vdm_createCSystem(vsy_HashTable* hashtable, vdm_Library* library, Vint dp);
extern void
vdm_createPartName(vis_Connect* connect, vdm_Library* library);
extern void
vdm_createDatasetForModelIntegerParameters(vdm_Library* library);
extern void
vdm_createDatasetsFromConnect(vis_Connect* connect, vdm_Library* library, Vint nx, Vint ex);
extern void
vdm_createUnits(vis_Units* units, vdm_Library* library);
extern void
vdm_writeParameter(vdm_DataFun* df, vis_GridFun* gf);
extern Vint
vdm_checkCols(vis_IdTran* idtran, Vint ncols, Vint cols[]);
extern void
vdm_initCols(Vlong lptr[], Vint ncols);
extern void
vdm_readElemSect(vsy_Dictionary* dict, Vchar* dsname, Vint numel, Vint ncols, Vint cols[], Vint* ibuff, Vlong* lptr);
extern void
vdm_readElemLays(vsy_Dictionary* dict, Vchar* dsname, Vint numel, Vint ncols, Vint cols[], Vint* ibuf, Vlong* lptr);
extern void
vdm_readElemDat(vsy_HashTable* ht, Vint key, Vint dp, Vfloat* fb, Vdouble* db);
extern void
vdm_createPart(vsy_HashTable* ht, vdm_Library* library, Vint dstype);
extern void
vdm_createPartEnt(vsy_HashTable* ht, vdm_Library* library);
extern void
vdm_createIDS(vsy_Dictionary* dt, vdm_Library* library);
extern void
vdm_readIDS(vsy_Dictionary* dt, vdm_Dataset* dataset, Vint* ib);
extern void
vdm_createMatl(vdm_Library* library, vsy_HashTable* hashtable);
extern void
vdm_readMatl(vsy_HashTable* hashtable, Vint dstype, Vint* ib, Vdouble* db);
extern void
vdm_checkMatl(vdm_Library* library, Vint* idsts, Vint* ndsts);
extern void
vdm_loadMatl(vdm_DataFun* df, vdm_Library* library, vsy_HashTable* hashtable, Vint idst);
extern void
vdm_saveMatl(vdm_DataFun* df, vsy_HashTable* hashtable);
extern void
vdm_createGProp(vis_GProp* gprop, vdm_Library* library);
extern void
vdm_readGProp(vis_GProp* gprop, Vint dstype, Vint* ibuff, Vdouble* dbuff);
extern void
vdm_checkGProp(vdm_Library* library, Vint* idsts, Vint* ndsts);
extern void
vdm_loadGProp(vdm_DataFun* df, vdm_Library* library, vis_GProp* gprop, Vint idst);
extern void
vdm_saveGProp(vdm_DataFun* df, vis_GProp* gprop);
extern void
vdm_createProp(vdm_Library* library, vsy_HashTable* hashtable);
extern void
vdm_readProp(vsy_HashTable* hashtable, Vint dstype, Vint* ibuff, Vdouble* dbuff);
extern void
vdm_checkProp(vdm_Library* library, Vint* idsts, Vint* ndsts);
extern void
vdm_loadProp(vdm_DataFun* df, vdm_Library* library, vsy_HashTable* ht, Vint idst);
extern void
vdm_saveProp(vdm_DataFun* df, vsy_HashTable* hashtable);
extern void
vdm_createASurf(vdm_Library* library, vsy_HashTable* hashtable);
extern void
vdm_readASurf(vsy_HashTable* hashtable, Vint id, Vint dstype, Vint* ib, Vdouble* db);
extern void
vdm_checkASurf(vdm_Library* library, Vint* idsts, Vint* ndsts);
extern void
vdm_loadASurf(vdm_DataFun* df, vdm_Library* library, vsy_HashTable* hashtable);
extern void
vdm_saveASurf(vdm_DataFun* df, vsy_HashTable* hashtable);
extern void
vdm_createSoln(vdm_Library* library, vsy_List* list);
extern void
vdm_readSoln(vsy_List* list, Vint dstype, Vint* ibuff, Vdouble* dbuff);
extern void
vdm_checkSoln(vdm_Library* library, Vint* idsts, Vint* ndsts);
extern void
vdm_loadSoln(vdm_DataFun* df, vdm_Library* library, vsy_List* list, Vint idst);
extern void
vdm_saveSoln(vdm_DataFun* df, vsy_List* list);
extern void
vdm_createFunc(vdm_Library* library, vsy_HashTable* hashtable);
extern void
vdm_readFunc(vsy_HashTable* hashtable, Vint dstype, Vint* ib, Vdouble* db);
extern void
vdm_checkFunc(vdm_Library* library, Vint* idsts, Vint* ndsts);
extern void
vdm_loadFunc(vdm_DataFun* df, vdm_Library* library, vsy_HashTable* hashtable, Vint idst);
extern void
vdm_saveFunc(vdm_DataFun* df, vsy_HashTable* hashtable);
extern void
vdm_readCSystem(vsy_HashTable* hashtable, Vint dstype, Vint dp, Vint* ib, Vfloat* fb, Vdouble* db);
extern void
vdm_readIdTran(vis_IdTran* idtran, Vint* ibuff);
extern void
vdm_readConnect(vis_Connect* connect, Vint dstype, Vint id1, Vint dp, Vint* ibuff, Vfloat* fbuff, Vdouble* dbuff);
extern void
vdm_refRCase(vsy_HashTable* rch, Vint sid, vis_RCase** rcase);
extern void
vdm_createRCase(vdm_Library* library, vsy_HashTable* ht, Vint rid, Vint numnp);
extern void
vdm_readRCase(vsy_HashTable* ht, Vint rid, Vint dstype, Vint* ib, Vdouble* db);
extern void
vdm_checkRCase(vdm_Library* library, Vint mdsts, Vint idsts[], Vint* ndsts);
extern void
vdm_loadRCase(vdm_DataFun* df, vdm_Library* library, vsy_HashTable* ht, Vint idst);
extern void
vdm_saveRCase(vdm_DataFun* df, vsy_HashTable* ht, Vint smcase, Vint numnp);
extern void
vdm_createICase(vdm_Library* library, vsy_HashTable* ht, Vint icid, Vint numnp);
extern void
vdm_readICase(vsy_HashTable* ht, Vint iid, Vint dstype, Vint* ib, Vdouble* db);
extern void
vdm_checkICase(vdm_Library* library, Vint mdsts, Vint idsts[], Vint* ndsts);
extern void
vdm_loadICase(vdm_DataFun* df, vdm_Library* library, vsy_HashTable* ht, Vint idst);
extern void
vdm_saveICase(vdm_DataFun* df, vsy_HashTable* ht, Vint smcase, Vint numnp);
extern void
vdm_createMCase(vdm_Library* library, vsy_HashTable* ht, Vint rid);
extern void
vdm_readMCase(vsy_HashTable* ht, Vint rid, Vint dstype, Vint* ib, Vdouble* db);
extern void
vdm_checkMCase(vdm_Library* library, Vint mdsts, Vint idsts[], Vint* ndsts);
extern void
vdm_loadMCase(vdm_DataFun* df, vdm_Library* library, vsy_HashTable* ht, Vint idst);
extern void
vdm_saveMCase(vdm_DataFun* df, vsy_HashTable* ht, Vint smcase);
extern void
vdm_refLCase(vsy_HashTable* lch, vis_GridFun* gf, Vint sid, vis_LCase** lcase);
extern void
vdm_createLCase(vdm_Library* library, vsy_HashTable* ht, Vint lid, Vint numnp, Vint numel);
extern void
vdm_readLCase(vsy_HashTable* ht, Vint lid, Vint nfree, Vint dstype, Vint* ib, Vdouble* fb);
extern void
vdm_checkLCase(vdm_Library* library, Vint enttype, Vint type, Vint mdsts, Vint idsts[], Vint* ndsts);
extern void
vdm_loadLCase(vdm_DataFun* df, vdm_Library* library, vsy_HashTable* ht, Vint idst, vis_GridFun* gf, Vint enttype, Vint type);
extern void
vdm_saveLCase(vdm_DataFun* df, vsy_HashTable* ht, Vint smcase, Vint numnp, Vint numel);
extern void
vdm_createCPair(vdm_Library* library, vsy_HashTable* ht, Vint cpid, Vint numnp);
extern void
vdm_readCPair(vsy_HashTable* ht, Vint cpid, Vint dstype, Vint* ib, Vdouble* db);
extern void
vdm_checkCPair(vdm_Library* library, Vint mdsts, Vint idsts[], Vint* ndsts);
extern void
vdm_loadCPair(vdm_DataFun* df, vdm_Library* library, vsy_HashTable* ht, Vint idst, vis_GridFun* gf);
extern void
vdm_saveCPair(vdm_DataFun* df, vsy_HashTable* ht, Vint numnp);
extern void
vdm_createRBody(vdm_Library* library, vsy_HashTable* ht, Vint rbid);
extern void
vdm_readRBody(vsy_HashTable* ht, Vint rbid, Vint dstype, Vint* ib, Vdouble* db);
extern void
vdm_checkRBody(vdm_Library* library, Vint mdsts, Vint idsts[], Vint* ndsts);
extern void
vdm_loadRBody(vdm_DataFun* df, vdm_Library* library, vsy_HashTable* ht, Vint idst, vis_GridFun* gf);
extern void
vdm_saveRBody(vdm_DataFun* df, vsy_HashTable* ht);
extern void
vdm_loadPart(vdm_DataFun* df, vdm_Library* library, vsy_HashTable* ht, Vint idst);
extern void
vdm_savePart(vdm_DataFun* df, vsy_HashTable* ht, Vint nument, Vint dstype);
extern void
vdm_readPart(vsy_HashTable* ht, Vint idx, Vint* ibuff);
extern void
vdm_deletePart(vsy_HashTable* ht);
extern void
vdm_loadPartEnt(vdm_DataFun* df, vdm_Library* library, vsy_HashTable* ht, Vint idst);
extern void
vdm_savePartEnt(vdm_DataFun* df, vsy_HashTable* ht);
extern void
vdm_readPartEnt(vsy_HashTable* ht, Vint idx, Vint* ibuff);
extern void
vdm_deletePartEnt(vsy_HashTable* ht);
extern void
vdm_processIdTran(vis_IdTran* idtran, vis_IdTran* idtrantype);
extern void
vdm_processConnect(vis_Connect* connect, vis_IdTran* idtrannode, Vint* ierr, Vint* jerr);
extern Vint
vdm_handleConnect(vis_IdTran* idtranelem, Vint ein, Vint nid, Vchar* func);
extern void
vdm_processCSystem(vsy_HashTable* csh, vis_IdTran* idtrannode, vis_GridFun* gridfun, Vint* ierr);
extern void
vdm_readModel(vis_Connect* connect, vsy_HashTable* csh, vsy_HashTable* elemsets, vsy_HashTable* nodesets,
              vsy_HashTable* elementsets, vsy_HashTable* mph, vsy_HashTable* eph, vsy_HashTable* tch, vsy_HashTable* rch,
              vsy_HashTable* ich, vsy_HashTable* lch, vsy_HashTable* mch, vsy_HashTable* ash, vsy_HashTable* cph,
              vsy_HashTable* rbh, vsy_List* spl, vis_GProp* gprop, vis_Units* units, Vint type, Vint id1, Vint dp, Vint* ibuf,
              Vint* flag);
extern void
vdm_readUnits(vis_Units* units, Vint type, Vint* ibuf, Vint* flag);
extern void
vdm_nameElemType(Vint iel, Vint shape, Vchar name[9]);
extern void
vdm_renameDuplicate(vdm_Library* library, vdm_Dataset* dataset, Vint* idi);
extern void
vdm_transformCoord(vis_Connect* connect, vsy_HashTable* hashcsys);
extern void
vdm_crackComp6(Vint ps, Vint comp[6]);
extern void
vdm_decode(Vchar dsname[], Vchar name[], Vint* id1, Vint* id2, Vint* id3);
extern void
vdm_sortIds(Vint num, Vint ids[], Vint iss[]);
extern void
vdm_searchIds(Vint isort, Vint num, Vint ids[], Vint iss[], Vint id, Vint* is);
extern void
vdm_setIds1(Vint idtyp, Vint idoff[3], Vint idbas[3], Vint* id1);
extern void
vdm_setIds2(Vint idtyp, Vint idoff[3], Vint idbas[3], Vint* id1, Vint* id2);
extern void
vdm_setIds3(Vint idtyp, Vint idoff[3], Vint idbas[3], Vint* id1, Vint* id2, Vint* id3);
extern void
vdm_fillCorner(Vint shape, Vint maxi, Vint maxj, Vint nrws, Vfloat xc[]);
extern void
vdm_fillCornerDouble(Vint shape, Vint maxi, Vint maxj, Vint nrws, Vdouble xc[]);
extern void
vdm_checkASCII(FILE* fd, Vint nbytes, Vint* status);
extern void
vdm_checkCharacterEncoding(FILE* fd, Vint nbytes, Vint* status, Vchar func[]);
extern void
vdm_InitData(void* buff, Vlong lrec, Vint dtyp, Vint inod);
extern void
vdm_ZeroNoDataR(Vfloat* buff, Vint num);
extern void
vdm_ZeroNoDataD(Vdouble* buff, Vint num);
extern void
vdm_loadConnect(vdm_DataFun* df, vdm_Library* library, Vint lmpre, vis_Connect** cn, Vchar func[], Vint* ierr, Vint focusconn);
extern void
vdm_saveModel(vis_Model* model, Vint smsingle, Vint smcase, vdm_DataFun* df, Vchar func[], Vint* ierr);
extern void
vdm_polyAddFace(Vint ia_conn[][20], Vchar ca_counter[][8], Vint n, Vint nix, Vint ix[]);
extern void
vdm_polyProcFaces(Vint ia_conn[][20], Vchar ca_counter[][8], Vint numel);
extern void
vdm_polyGetShape(Vchar ca_counter[][8], Vint n, Vint* shape, Vint* maxi);
extern Vint
vdm_revFace(Vint nix, Vint pix[], Vint qix[]);
extern void
vdm_defdataset(vdm_Library* library, const Vchar* name, Vlong lrec, Vint nrow, Vint ncol, Vint dstype, Vint* idst, Vchar source[],
               Vint type, Vchar func[], Vint* ierr);
extern void
vdm_defattribute(vdm_Library* library, Vint idst, const Vchar* name, Vint length, Vint atttype, Vint* iatt, Vint type,
                 Vchar func[], Vint* ierr);
extern void
vdm_setattval(vdm_Library* library, Vint idst, Vint iatt, void* value, Vint type, Vchar func[], Vint* ierr);
extern void
vdm_saveConnect2Native(vis_Connect* connect, Vchar filnam[]);
extern Vint
vdm_CheckFilePathSuffix(Vchar inputfile[], Vchar suffix[]);
extern void
vdm_createNodeAssoc(vdm_Library* library, Vint numnp, Vint assoctype, Vint dataSetType);
extern void
vdm_printEntitiesMultipleId(vis_IdTran* entityIdtran, vis_Connect* connect, const Vchar* entityName);
extern void
vdm_ProcessDOFtoRemove(Vint numberOfElements, vis_Connect* connect, vsy_HashTable* elementPropertyHashTable);
extern void
vdm_ANSLibMidsideRotationAngleInterpolation(Vint shape, Vint maxi, Vint maxj, Vdouble dtmp[][3]);
extern void
vdm_isAnsysLicenseEnvironmentVariableDetected(Vint* flag);
extern Vint
vdm_isResultDataset(vdm_Dataset* dataset);

#ifdef __cplusplus
}
#endif

#endif
