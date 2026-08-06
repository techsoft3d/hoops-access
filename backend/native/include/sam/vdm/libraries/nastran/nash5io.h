/* vdm NASTRAN HDF5 utility functions header file */
#ifndef NASH5IO_DEF
#define NASH5IO_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"

#ifdef VKI_LIBAPI_HDF5
#include "hdf5.h"
#include "H5LTpublic.h"
#endif

#define NASH5IO_END        0
#define NASH5IO_GROUP      1
#define NASH5IO_DATASET    2
#define NASH5IO_MAXNUMPATH 20

#define NASH5IO_OPTISTRUCT_OFFSET 100000

typedef struct {
    Vint id;
    Vchar path[SYS_MAXPATHCHAR];
    Vchar** name;
    Vint* type;
    Vint numnames;
    Vint cur;
} vdm_NASh5io_Iter;

typedef struct vdm_NASh5io {
    Vint ierr;
    Vint memtypeflag;
    Vdouble* dbuf;
    Vfloat* fbuf;
    Vint* ibuf;
    Vint* idibuf;
    Vint dim[3];
    Vint iddim;
    Vint nindex;
    Vint explct;
    Vint cur;
    Vchar ipath[SYS_MAXPATHCHAR];
    Vchar path[NASH5IO_MAXNUMPATH][SYS_MAXPATHCHAR];
    Vint npush;
    vsy_IntDict* visited;
    Vint numiter;
    Vint recursive;
    vdm_NASh5io_Iter* iter;
    vsy_HashTable* iterht;
    Vchar* ds_labels;
    Vint* ds_num;
    Vint* ds_types;
    Vint* ds_flags;
    Vint* ds_isarray;
    size_t* ds_offset;
    size_t* ds_sizes;
    Vint maxnrows;
    size_t ds_size;
    Vint maxrows;
    Vint nrows;
    Vint ncols;
    Vint dsiter;
    Vint dsexists;
    Vchar* data;
    Vchar cached[SYS_MAXPATHCHAR];
    Vint source;
#ifdef VKI_LIBAPI_HDF5
    hid_t file;
    hid_t post;
    hid_t memspace;
    hid_t filespace;
    hid_t dataset;
    hid_t idmemspace;
    hid_t idfilespace;
    hid_t iddataset;
    hid_t pos[NASH5IO_MAXNUMPATH];
    hsize_t dims_ix[3];
    hsize_t iddims_ix;
    hsize_t dims;
    hsize_t iddims;
    hid_t* ds_native;
    hid_t space;
    hid_t memtype;
#endif
} vdm_NASh5io;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_NASh5io*
vdm_NASh5ioBegin(void);
VKI_EXTERN void
vdm_NASh5ioEnd(vdm_NASh5io* p);
VKI_EXTERN Vint
vdm_NASh5ioError(vdm_NASh5io* p);
VKI_EXTERN void
vdm_NASh5ioClose(vdm_NASh5io* p);
VKI_EXTERN void
vdm_NASh5ioOpen(vdm_NASh5io* p, Vchar* filename, Vlong* schema);
VKI_EXTERN void
vdm_NASh5ioPush(vdm_NASh5io* p, Vchar name[], Vint* status);
VKI_EXTERN void
vdm_NASh5ioPop(vdm_NASh5io* p);
VKI_EXTERN void
vdm_NASh5ioTop(vdm_NASh5io* p);
VKI_EXTERN void
vdm_NASh5ioInitIter(vdm_NASh5io* p, Vint* iterator);
VKI_EXTERN void
vdm_NASh5ioNextIter(vdm_NASh5io* p, Vint iterator, Vint* type, Vchar name[]);
VKI_EXTERN void
vdm_NASh5ioTermIter(vdm_NASh5io* p, Vint iterator);
VKI_EXTERN void
vdm_NASh5ioDatasetRowInfo(vdm_NASh5io* p, Vchar name[], Vint* nrows, Vchar labels[][80], Vint types[], Vint num[]);
VKI_EXTERN void
vdm_NASh5ioDatasetRowSize(vdm_NASh5io* p, Vchar name[], Vint irow, Vint* size);
VKI_EXTERN void
vdm_NASh5ioDatasetRowLabel(vdm_NASh5io* p, Vchar name[], Vint irow, Vchar label[80]);
VKI_EXTERN void
vdm_NASh5ioDatasetSize(vdm_NASh5io* p, Vchar name[], Vint* nrows, Vint* ncols);
VKI_EXTERN void
vdm_NASh5ioDatasetInitIter(vdm_NASh5io* p, Vchar name[], Vint flags[]);
VKI_EXTERN void
vdm_NASh5ioDatasetNextIter(vdm_NASh5io* p, Vint* icol);
VKI_EXTERN void
vdm_NASh5ioDatasetReadi(vdm_NASh5io* p, Vint irow, Vint data[]);
VKI_EXTERN void
vdm_NASh5ioDatasetRead2i(vdm_NASh5io* p, Vint irow, Vint data1[], Vint data2[]);
VKI_EXTERN void
vdm_NASh5ioDatasetReadd(vdm_NASh5io* p, Vint irow, Vdouble data[]);
VKI_EXTERN void
vdm_NASh5ioDatasetRead2d(vdm_NASh5io* p, Vint irow, Vdouble data1[], Vdouble data2[]);
VKI_EXTERN void
vdm_NASh5ioDatasetRead3d(vdm_NASh5io* p, Vint irow, Vdouble data1[], Vdouble data2[], Vdouble data3[]);
VKI_EXTERN void
vdm_NASh5ioDatasetReadl(vdm_NASh5io* p, Vint irow, Vlong data[]);
VKI_EXTERN void
vdm_NASh5ioDatasetReadc(vdm_NASh5io* p, Vint irow, Vchar data[]);
VKI_EXTERN Vint
vdm_NASh5ioDatasetReadRangeFloat(vdm_NASh5io* p, Vchar path[], Vint numnames, Vchar** names, Vint position, Vint length,
                                 void** buff, Vlong* wd, Vint* dataType);
VKI_EXTERN Vint
vdm_NASh5ioDatasetReadRangeInteger(vdm_NASh5io* p, Vchar path[], Vint numnames, Vchar** names, Vint position, Vint length,
                                   void** lbuf, Vlong* wd, Vint* dataType);
VKI_EXTERN void
vdm_NASh5ioDatasetReadColsd(vdm_NASh5io* p, Vchar path[], Vint numnames, Vchar** names, Vint ncols, Vint cols[], Vdouble** buff,
                            Vlong* wd);
VKI_EXTERN void
vdm_NASh5ioDatasetReadColsl(vdm_NASh5io* p, Vchar path[], Vint numnames, Vchar** names, Vint ncols, Vint cols[], Vlong** lbuf,
                            Vlong* wd);
VKI_EXTERN void
vdm_NASh5ioDatasetVersion(vdm_NASh5io* p, Vchar path[], Vint* iversion);

#ifdef __cplusplus
}
#endif

#endif
