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
/* vfs utility functions header file */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
/*                                                                          */
/*  (C) Esmond G. Ng                                                        */
/*  Last modified:  October 22, 2000                                        */
/*                                                                          */
/*  Acknowledgements:                                                       */
/*      Many of the procedures are based on previous Fortran                */
/*      implementations.  People who have contributed to the                */
/*      research, development, and Fortran implementations                  */
/*      include Joseph W-H. Liu, Esmond G. Ng, Barry W. Peyton,             */
/*      and Padma Raghavan.                                                 */
/*                                                                          */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
/*                                                                          */
/*  Notes on the sparse Cholesky factorization codes.                       */
/*                                                                          */
/*  The codes in the suite compute a LDL' factorization of a sparse         */
/*  symmetric matrix.  It can handle negative diagonal pivots, but not      */
/*  zero diagonal pivots.  It uses the factorization to solve a linear      */
/*  system.                                                                 */
/*                                                                          */
/*==========================================================================*/
/*                                                                          */
/*  The sparse Cholesky factorization codes are contained in 5 files:       */
/*                                                                          */
/*          Sparse_Cholesky.h                                               */
/*          Symbolic.c                                                      */
/*          Numeric.c                                                       */
/*          Util.c                                                          */
/*                                                                          */
/*==========================================================================*/
/*                                                                          */
/*  Sparse_Cholesky.h                                                       */
/*                                                                          */
/*      This file defines a C structure Sp_Chol that will be used in the    */
/*      sparse factorization codes.                                         */
/*                                                                          */
/*==========================================================================*/
/*                                                                          */
/*  Util.c                                                                  */
/*                                                                          */
/*      This file contains a number of utility procedures.                  */
/*                                                                          */
/*      ------------------------------------------------------------------  */
/*                                                                          */
/*      Sparse_Cholesky_Init                                                */
/*      (                                                                   */
/*          L, malloc_fun, free_fun, fflush_fun, ftell_fun, fseek_fun,      */
/*          fread_fun, fwrite_fun                                           */
/*      )                                                                   */
/*                                                                          */
/*              L           :  type Sp_Chol                                 */
/*              fflush_fun  :  pointer to I/O flush function                */
/*              ftell_fun   :  pointer to function to return file position  */
/*              fseek_fun   :  pointer to function to move file pointer     */
/*              fread_fun   :  pointer to function for reading file         */
/*              fwrite_fun  :  pointer to function for writing file         */
/*                                                                          */
/*          This procedure initializes the C structure that will contain    */
/*          relevant data structures for sparse Cholesky factorization.     */
/*          This procedure must be called before any procedure from the     */
/*          is invoked.                                                     */
/*                                                                          */
/*      ------------------------------------------------------------------  */
/*                                                                          */
/*      Sparse_Cholesky_Exit                                                */
/*      (                                                                   */
/*          L                                                               */
/*      )                                                                   */
/*                                                                          */
/*              L           :  type Sp_Chol                                 */
/*                                                                          */
/*          This procedure releases all the arrays allocated during the     */
/*          solution process.  It must be called after the end of the       */
/*          solution process.                                               */
/*                                                                          */
/*      ------------------------------------------------------------------  */
/*                                                                          */
/*      Print_Statistics                                                    */
/*      (                                                                   */
/*          stream, L                                                       */
/*      )                                                                   */
/*                                                                          */
/*              stream      :  pointer to output file                       */
/*              L           :  type Sp_Chol                                 */
/*                                                                          */
/*          This procedure prints various information and statistics about  */
/*          sparse Cholesky factorization.                                  */
/*                                                                          */
/*==========================================================================*/
/*                                                                          */
/*  Symbolic.c                                                              */
/*                                                                          */
/*      This file contains procedures that implement the ordering and       */
/*      symbolic factorization steps.                                       */
/*                                                                          */
/*          Four ordering options are available.                            */
/*                                                                          */
/*              1       :  minimum degree algorithm with multiple           */
/*                         eliminations                                     */
/*              2       :  a variant of mmd1                                */
/*              3       :  an approximate minimum deficient algorithm       */
/*              4       :  the natural ordering (i.e., no reordering)       */
/*                                                                          */
/*      ------------------------------------------------------------------  */
/*                                                                          */
/*      Ordering                                                            */
/*      (                                                                   */
/*          n, nproc, xadj, adjncy, order, L, iflag, options,               */
/*          userorder                                                       */
/*      )                                                                   */
/*                                                                          */
/*              n           :  order of the matrix                          */
/*              nproc       :  number of processors for parmetis            */
/*              xadj        :  pointer to the full adjacency structure      */
/*              adjncy      :  the adjacency structure of the matrix        */
/*              order       :  the ordering method                          */
/*              L           :  of type Sp_Chol                              */
/*              iflag       :  error code                                   */
/*              options     :  METIS options                                */
/*              mmdswitch   :  METIS MMDSWITCH parameter                    */
/*              userorder   :  user ordering if that's the order chosen     */
/*              numThreads  :  number of threads for parallel metis         */
/*                                                                          */
/*          This procedure computes an ordering for sparse factorization.   */
/*                                                                          */
/*      ------------------------------------------------------------------  */
/*                                                                          */
/*      Cholesky_Structure                                                  */
/*      (                                                                   */
/*          n, xadj, adjncy, L, nofnzl, maxsupsze, fctops, slvops, iflag    */
/*      )                                                                   */
/*                                                                          */
/*              n           :  order of the matrix                          */
/*              xadj        :  pointer to the full adjacency structure      */
/*              adjncy      :  the adjacency structure of the matrix        */
/*              L           :  type Sp_Chol                                 */
/*              blas        :  flag indicating if BLAS library is to be     */
/*                             used in numerical factorization              */
/*              bndsupcol   :  bound on the maximum number of columns in    */
/*                             a supernode when BLAS library is used        */
/*              nofnzl      :  number of nonzero entries in factor          */
/*              maxsupsze   :  largest supernode by nonzero count           */
/*              fctops      :  factorization operation count                */
/*              slvops      :  triangular solution operation count          */
/*              iflag       :  error code                                   */
/*                                                                          */
/*          This procedure returns various counts about the factorization.  */
/*                                                                          */
/*      ------------------------------------------------------------------  */
/*                                                                          */
/*      Symbolic_Factorization                                              */
/*      (                                                                   */
/*          n, xadj, adjncy, fmethod, cachesze, memsze, iflag               */
/*      )                                                                   */
/*                                                                          */
/*              n           :  order of the matrix                          */
/*              xadj        :  pointer to the full adjacency structure      */
/*              adjncy      :  the adjacency structure of the matrix        */
/*              fmethod     :  factorization method                         */
/*                              method = 1:  sparse left-looking blocked    */
/*                                           factorization                  */
/*                              method = 2:  in-core blocked multifrontal   */
/*                                           factorization                  */
/*                              method = 3:  out-of-core blocked            */
/*                                           multifrontal factorization     */
/*              cachesze    :  size of the cache memory in kilobytes; set   */
/*                             it to zero if no cache is present            */
/*              memsze      :  size of in-core memory to be used for        */
/*                             out-of-core multifrontal factorization       */
/*              L           :  of type Sp_Chol                              */
/*              iflag       :  error code                                   */
/*                                                                          */
/*          This procedure performs symbolic factorization.                 */
/*                                                                          */
/*==========================================================================*/
/*                                                                          */
/*  Numeric.c                                                               */
/*                                                                          */
/*      This file contains procedures that implement the numerical          */
/*      factorization and triangular solution steps.                        */
/*                                                                          */
/*          Three factorization options are available.                      */
/*                                                                          */
/*              1       :  in-core left-looking blocked factorization       */
/*              2       :  in-core multifrontal blocked factorization       */
/*              3       :  out-of-core multifrontal blocked factorizaiton   */
/*                                                                          */
/*      ------------------------------------------------------------------  */
/*                                                                          */
/*      Input_Numerical_Values                                              */
/*      (                                                                   */
/*          colptr, rowidx, anz, L, iflag                                   */
/*      )                                                                   */
/*                                                                          */
/*              colptr      :  pointers to columns of matrix                */
/*              rowidx      :  row indices, arranged by columns             */
/*              anz         :  numerical values, arranged by columns        */
/*              L           :  type Sp_Chol                                 */
/*              iflag       :  error code                                   */
/*                                                                          */
/*          This procedure puts numerical values into the data structures.  */
/*                                                                          */
/*      ------------------------------------------------------------------  */
/*                                                                          */
/*      Numerical_Factorization                                             */
/*      (                                                                   */
/*          L, level, tol, ndiag, iflag                                     */
/*      )                                                                   */
/*                                                                          */
/*              L           :  of type Sp_Chol                              */
/*              level       :  level of loop unrolling in matrix kernels    */
/*                             (possible values are 1, 2, 4, and 8)         */
/*              tol         :  relative tolerance for detecting large       */
/*                             pivot reduction                              */
/*              ndiag       :  number of negative entries on the diagonal   */
/*                             in the factorization                         */
/*              zpivot      :  equation where factorization fails           */
/*              iflag       :  error code                                   */
/*                                                                          */
/*          This procedure performs numerical factorization.                */
/*                                                                          */
/*      ------------------------------------------------------------------  */
/*                                                                          */
/*      Numerical_Solution                                                  */
/*      (                                                                   */
/*          L, nrhs, rhs, soln, iflag                                       */
/*      )                                                                   */
/*                                                                          */
/*              L           :  of type Sp_Chol                              */
/*              nrhs        :  number of right-hand side vectors            */
/*              rhs         :  the right-hand side vectors                  */
/*              soln        :  the solution vectors                         */
/*              iflag       :  error code                                   */
/*                                                                          */
/*          This procedure performs triangular solution.                    */
/*                                                                          */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
/*                                                                          */
/*  Error codes.                                                            */
/*                                                                          */
/*       0  :   No errors.                                                  */
/*                                                                          */
/*      ------------------------------------------------------------------  */
/*                                                                          */
/*      21  :   Invalid execution sequence; initialization must be          */
/*              performed successfully before invoking ordering.            */
/*      22  :   Invalid ordering choice (<1 or >4).                         */
/*      23  :   Fail to allocate work storage in ordering.                  */
/*      24  :   Fail to allocate data structure for sparse Cholesky         */
/*              factorization in ordering.                                  */
/*                                                                          */
/*      ------------------------------------------------------------------  */
/*                                                                          */
/*      31  :   Invalid execution sequence; ordering must be performed      */
/*              successfully before invoking symbolic factorization.        */
/*      32  :   Fail to allocate work storage for determining structure     */
/*              information.                                                */
/*      33  :   Fail to allocate data structures for sparse Cholesky        */
/*              factorization during structure information determination.   */
/*                                                                          */
/*      ------------------------------------------------------------------  */
/*                                                                          */
/*      41  :   Invalid execution sequence; structure information must be   */
/*              performed successfully before invoking symbolic             */
/*              factorization.                                              */
/*      42  :   Invalid factorization method (<1 or >3).                    */
/*      43  :   Invalid cache size (<0).                                    */
/*      44  :   Invalid memory size (<0).                                   */
/*      45  :   Fail to allocate work storage for symbolic factorization.   */
/*      46  :   Fail to allocate data structures for sparse Cholesky        */
/*              factorization in symbolic factorization.                    */
/*      47  :   Insufficient storage to perform symbolic Cholesky           */
/*              factorization.                                              */
/*      48  :   Fail to allocate work storage for numerical factorization   */
/*              in symbolic factorizatioj.                                  */
/*      49  :   Insufficient storage to perform out-of-core multifrontal    */
/*              multifrontal factorization.                                 */
/*                                                                          */
/*      ------------------------------------------------------------------  */
/*                                                                          */
/*      51  :   Invalid execution sequence; symbolic factorization must     */
/*              be performed succcessfully before invoking numerical        */
/*              input.                                                      */
/*      52  :   Fail to allocate data structure for sparse Cholesky         */
/*              factorization in the numerical input phase.                 */
/*      53  :   Invalid factorization method.                               */
/*                                                                          */
/*      ------------------------------------------------------------------  */
/*                                                                          */
/*      61  :   Invalid execution sequence; numerical input must be         */
/*              performed succcessfully before invoking numerical           */
/*              factorization.                                              */
/*      62  :   Invalid factorization method (<1 or >3).                    */
/*      63  :   Invalid level of loop unrolling (!= 1, 2, 4, 8).            */
/*      64  :   Invalid relative tolerance (<0).                            */
/*      65  :   Small pivot detected in numerical factorization (input      */
/*              matrix may or may not be singular).                         */
/*      66  :   Large relative pivot reduction during numerical             */
/*              factorization.                                              */
/*      67  :   Insufficient storage to perform numerical Cholesky          */
/*              factorization.                                              */
/*                                                                          */
/*      ------------------------------------------------------------------  */
/*                                                                          */
/*      71  :   Invalid execution sequence; numerical factorization must    */
/*              be performed successfully before computing determinant.     */
/*      72  :   Invalid factorization method.                               */
/*                                                                          */
/*      ------------------------------------------------------------------  */
/*                                                                          */
/*      81  :   Invalid execution sequence; numerical factorization must    */
/*              be performed successfully before invoking numerical         */
/*              solution.                                                   */
/*      82  :   Invalid factorization method.                               */
/*      83  :   Fail to allocate work storage for numerical solution.       */
/*                                                                          */
/*      ------------------------------------------------------------------  */
/*                                                                          */
/*      91  :   Error in writing data in out-of-core solver.                */
/*      92  :   Error in reading data in out-of-core solver.                */
/*      93  :   Error in getting file position in out-of-core solver.       */
/*      94  :   Error in seeking file position in out-of-core               */
/*      95  :   Error in flushing file in out-of-core solver.               */
/*                                                                          */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

#define VML_ERROR_FAILED_FACTORIZATION  81
#define VML_ERROR_INVALID_FACTORIZATION 82
#define VML_ERROR_MEMORY_ALLOCATION     83

#ifndef VFSNG_H
#define VFSNG_H
#include <stdlib.h>
#include <string.h>
#ifndef VKI_ARCH_MAC
#include <malloc.h>
#endif
#include <limits.h>
#include <float.h>
#include <stddef.h>
#include <stdio.h>
#include "sam/base/basedefs.h"
#include "sam/base/vsy_threadpool.h"
#include "sam/base/progress.h"

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

/*--------------------------------------------------------------------------*/
/*  INFTY (needed in Order.c)                                               */
/*      It is the largest machine-representable integer.                    */
/*                                                                          */
/*  MACHINE_EPSILON (needed in Numeric.c)                                   */
/*      It is the largest floating-point number such that                   */
/*          1 + MACHINE_EPSILON = 1.                                        */
/*                                                                          */
/*  DET_POWER (needed in Numeric.c)                                         */
/*      It determines the representation of the determinant of the input    */
/*      matrix that is to be computed by Compute_Determinant():             */
/*          det(matrix) = detfrac * 10**detexp                              */
/*      where  1 <= | detfrac | < 10**DET_POWER.                            */
/*                                                                          */
/*  CACHSZ_UNIT (needed in Numeric.c)                                       */
/*      Unit in which cache size will be specified (Kbyte).                 */
/*                                                                          */
/*  MEMSZE_UNIT (needed in Numeric.c)                                       */
/*      Unit in which memory for factor nonzero entries will be specified   */
/*      (Mbyte).                                                            */
/*  BLAS                                                                    */
/*      Flag indicating if BLAS library is to be used.                      */
/*          0 if BLAS library is not available.                             */
/*          1 if BLAS library is available.                                 */
/*--------------------------------------------------------------------------*/

#define INFTY           INT_MAX     /*  from limits.h           */
#define MACHINE_EPSILON DBL_EPSILON /*  from float.h            */

#define CACHSZ_UNIT 1024.0
#define MEMSZE_UNIT 1024.0 * 1024.0

#define BLAS_DEFAULT 1 /*  default:     BLAS       */

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
typedef struct MultiFrontalPlanner MultiFrontalPlanner;
typedef struct BlasFile BlasFile;

/** \brief User supplied functions pointers for operating system calls  */
typedef struct {
    void* (*fopen)(const char*, const char*);
    int (*fclose)(void*);
    int(*fflush) /*!< \brief flushing I/O                                    */
    (void*);
    Vlong(*ftell) /*!< \brief return position in file                         */
    (void*);
    int(*fseek) /*!< \brief move to location in file                        */
    (void*, Vlong, Vint);
    size_t(*fread) /*!< \brief reading file                                    */
    (void*, size_t, size_t, void*);
    size_t(*fwrite) /*!< \brief writing file                                    */
    (const void*, size_t, size_t, void*);
} UserFunctions;

typedef struct MFStorage {
    const char* ooc_fileName;
    BlasFile* blasFile;
} MFStorage;

typedef struct MatrixData {
    double* anz;
    double* uanz;
} MatrixData;

typedef struct VKIComplex {
    double real;
    double imag;
} VKIComplex;
inline double
real(VKIComplex c)
{
    return c.real;
}
inline double
imag(VKIComplex c)
{
    return c.imag;
}
#ifdef __cplusplus
#include <complex>
inline VKIComplex
operator+(const VKIComplex& a, const VKIComplex& b)
{
    return {a.real + b.real, a.imag + b.imag};
}

inline VKIComplex
operator*(const VKIComplex& a, const VKIComplex& b)
{
    return {a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real};
}

inline VKIComplex&
operator*=(VKIComplex& c, double alpha)
{
    c.real *= alpha;
    c.imag *= alpha;
    return c;
}

inline VKIComplex&
operator*=(VKIComplex& c, const VKIComplex& alpha)
{
    c = c * alpha;
    return c;
}
#endif
/****************************************************************************/
/*******   Sparse_Cholesky.h   **********************************************/
/****************************************************************************/
typedef struct PivotDetails {
    Vint cureqn;      /*!< \briefcurrent user equation number */
    int maxdpivot;    /*!< \brief maximum drop pivot                      */
    double maxdvalue; /*!< \brief maximum drop value                      */
    int singular;     /*!< \brief singularity flag                        */
    double old_diag;  /*!< \brief diagonal value before change            */
    double new_diag;  /*!< \brief diagonal value after change             */
    double upd_diag;  /*!< \brief diagonal value after updated change     */
    int adj_diag;     /*!< \brief flag for adjusted diagonal              */
    int ndiag;        /*!< \brief number of negative diag entries in L    */

    VKIComplex detfrac; /*!< \brief fractional part of determinant          */
    int detexp;         /*!< \brief exponent part of determinant            */
    int abortflag;      /*!< Flag to the factorization should abort.        */
    Vint numsing;       /*!< Number of singular pivots detected so far.     */
    Vint* singpivots;   /*!< Pointer to the array of singular pivot indices.*/
    double progress;    /*!< Progress factor (0 = start; 1.0 = end.         */
    // RECOVERY
    int maxdupd;   /*  maximum drop update flag                        */
    int maxdnbupd; /*  maximum drop no blas update flag                */
} PivotDetails;

/*--------------------------------------------------------------------------*/
/*  Following is a structure that describes the sparse factorization.       */
/*--------------------------------------------------------------------------*/
struct Sp_Chol {
    /*----------------------------------------------------------------------*/
    /*  Input matrix information ...                                        */
    /*----------------------------------------------------------------------*/
    /**\brief Monitoring function.  */
    void (*funmon)(PivotDetails* piv, Vobject*);
    Vobject* funmonobj; /*!< \brief user data for monitoring function       */
    vsy_Progress* progress;
    Vint curcol; /*!< \brief current factorization column            */

    PivotDetails pivotDetails;
    int neqns;           /*!< \brief number of equations                     */
    const Vlong* colptr; /*!< \brief pointers to columns of input matrix     */
    Vint* rowidx;        /*!< \brief row indices of input matrix             */

    double A_norm; /*!< \brief norm of input matrix                    */

    int* map;     /*!< \brief SetTemp map */
    int* invmap;  /*!< \brief SetTemp inverse map */
    double* diag; /*!< \brief matrix diagonal */
    int monfreq;  /*!< \brief monitor function call frequency */

    /*----------------------------------------------------------------------*/
    /*  Parameters governing the solution process ...                       */
    /*----------------------------------------------------------------------*/
    int order;           /*!< \brief ordering algorithm                        */
    int method;          /*!< \brief method used to perform the factorization  */
    int blas;            /*!< \brief flag to indicate use of BLAS              */
    int cmplx;           /*!< \brief flag to indicate if the matrix is complex.*/
    int bndsupcol;       /*!< \brief bound on no. of columns in supernode      */
    int level;           /*!< \brief level of loop unrolling                   */
    double memsze;       /*!< \brief memory size (in MB) for out-of-core lnz   */
    double tol_zero;     /*!< \brief tolerance for detecting singularity       */
    double singTol;      /*!< \brief tolerance for detecting large reduction (=>singularities)    */
    double autospcValue; /*!< \brief Reduce pivot singularity value (AutoSpc_Factor*MaxDiag) */

    /*----------------------------------------------------------------------*/
    /*  Ordering information ...                                            */
    /*----------------------------------------------------------------------*/
    int* perm; /*!< \brief permutation                             */
    int* invp; /*!< \brief inverse of permutation                  */

    /*----------------------------------------------------------------------*/
    /*  Supernode information ...                                           */
    /*----------------------------------------------------------------------*/
    Vlong nsuper;  /*!< \brief number of supernodes                        */
    Vlong* xsuper; /*!< \brief supernode partitioning                      */
    Vlong* snode;  /*!< \brief column-to-supernode mapping (membership)    */
    Vlong* split;  /*!< \brief fine splitting of supernodes for cache      */

    Vlong* etpar;  /*!< \brief parent of elimination tree                  */
    Vlong* parent; /*!< \brief parent of supernodal elimination tree       */
    Vlong* fchild; /*!< \brief first-child of supernodal elimination tree  */
    Vlong* nxtsib; /*!< \brief sibing of supernodal elimination tree       */
    Vlong* colcnt; /*!< \brief nonzero counts in columns of Cholesky factor*/

    /*------------------------------------------------------------------------*/
    /*  Cholesky factor structure information ...                             */
    /*------------------------------------------------------------------------*/
    Vlong* xlindx; /*!< \brief pointers to compressed row indices.       */
    int* lindx;    /*!< \brief compressed row indices of Cholesky factor.*/

    Vlong nofsub;    /*!< \brief number of compressed row indices.         */
    Vlong nofnzl;    /*!< \brief number of nonzero entries in L.           */
    Vlong maxcolsze; /*!< \brief length of largest column                  */
    Vlong maxsupcol; /*!< \brief Maximum number of columns in a supernode  */
    Vlong maxsupsze; /*!< \brief size of largest supernode rectangle block.*/
    Vlong minoocsze; /*!< \brief Minimum out of core memory requirement.   */
    Vlong treeht;    /*!< \brief height of supernodal elimination tree     */

    /*----------------------------------------------------------------------*/
    /*  Cholesky factor information ...                                     */
    /*----------------------------------------------------------------------*/
    Vlong* xlnz;  /*!< \brief pointers to numerical values               */
    double* lnz;  /*!< \brief numerical values of Cholesky factor        */
    double* ulnz; /*!< \brief numerical values of upper Cholesky factor  */
    Vlong lnzsze; /*!< \brief size of lnz allocated                      */

    double fctops; /*!< \brief number of operations in factorization      */
    double slvops; /*!< \brief number of operations in triangular solution*/

    Vlong rwsze;  /*!< \brief size of temporary array for factorization  */
    Vlong tmpsze; /*!< \brief size of temporary array for factorization  */
    Vlong supsze; /*!< \brief size of supernode stack for MF code        */

    /*----------------------------------------------------------------------*/
    /*  Pointers to workspace ...                                           */
    /*----------------------------------------------------------------------*/
    Vint* relind;   /*!< \brief relative indices                        */
    Vint* indmap;   /*!< \brief map indices                             */
    Vlong* iwork;   /*!< \brief integer workspace                       */
    double* rwork;  /*!< \brief floating-point workspace                */
    double* rworku; /*!< \brief upper floating-point workspace          */
    double* tmpvec; /*!< \brief floating-point workspace                */

    /*----------------------------------------------------------------------*/
    /*  Threading details                                                   */
    /************************************************************************/
    int nThreads; /*!< \brief Number of concurrent threads to use.    */

    // OLD DATA RECOVERY
    Vint abortflag; /*  abort flag                                      */
    double cachsz;  /*  cache size (in Kbytes)                          */
    double* anz;    /*  numerical values of input matrix                */
    /*----------------------------------------------------------------------*/
    /*  Out-of-core factorization information ...                           */
    /*----------------------------------------------------------------------*/
    void* ioptr;   /*  I/O pointer                                     */
    void* ioptru;  /*  I/O pointer for upper factor                    */
    Vlong nblks;   /*  number of blocks to be written                  */
    Vlong* numsup; /*  numbers of supernodes in blocks                 */
    Vlong* blksze; /*  sizes of blocks                                 */
    Vlong* blkptr; /*  positions of blocks                             */
    /*----------------------------------------------------------------------*/
    /*  Pointers to workspace ...                                           */
    /*----------------------------------------------------------------------*/
    Vlong* xupd;

    /*----------------------------------------------------------------------*/
    /*  Function pointers ...                                               */
    /*----------------------------------------------------------------------*/
    void*(*malloc) /*  storage allocation                              */
    (size_t);
    void(*free) /*  storage deallocation                            */
    (void*);
    int(*fflush) /*  flushing I/O                                    */
    (void*);
    Vlong(*ftell) /*  return position in file                         */
    (void*);
    int(*fseek) /*  move to location in file                        */
    (void*, Vlong, Vint);
    size_t(*fread) /*  reading file                                    */
    (void*, size_t, size_t, void*);
    size_t(*fwrite) /*  writing file                                    */
    (const void*, size_t, size_t, void*);

    // END OF OLD DATA RECOVERY
    /*----------------------------------------------------------------------*/
    /*  Error information ...                                               */
    /*----------------------------------------------------------------------*/
    int stage; /*!< \brief stage of the solution process           */

    MatrixData A; /*!< \brief numerical values of input matrix        */
    /*----------------------------------------------------------------------*/
    /*  Out-of-core factorization information ...                           */
    /*----------------------------------------------------------------------*/
    MFStorage lFile; /*!< \brief Structure for in/out of core L.         */

    MultiFrontalPlanner* multiFrontalPlanner;

    UserFunctions functions;
};

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

/*--------------------------------------------------------------------------*/
/*  User callable procedures ...                                            */
/*--------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

extern void
vml_Sparse_Cholesky_Init(struct Sp_Chol* L, int (*fflush_fun)(void*), Vlong (*ftell_fun)(void*),
                         int (*fseek_fun)(void*, Vlong, int), size_t (*fread_fun)(void*, size_t, size_t, void*),
                         size_t (*fwrite_fun)(const void*, size_t, size_t, void*));

extern void
vml_Ordering(int neqns, int nproc, Vlong* xadj, int* adjncy, int order, struct Sp_Chol* L, int* iflag, int options[],
             int userorder[]);

extern void
vml_Cholesky_Structure_Info(int neqns, Vlong* xadj, int* adjncy, int blas, int cmplx, Vlong bndsupcol, struct Sp_Chol* L,
                            Vlong* nofnzl, Vlong* maxsupsze, double* fctops, double* slvops, int* iflag);

extern void
vml_Symbolic_Factorization(const int neqns, const Vlong* xadj, const int* adjncy, const int fmethod, double memsze,
                           struct Sp_Chol* L, int* iflag);

extern void
vml_Cholesky_Numerical_Alloc(int neqns, double cachesze, struct Sp_Chol* L, int* iflag, Vlong* lnzsze, Vlong* rworksize);

extern void
vml_Cholesky_Set_lnz(struct Sp_Chol* L, double* lnz, double* ulnz, double* rwork, double* rworku);

extern void
vml_Input_Numerical_Values(Vlong* pointers, Vlong* qointersb, int* indices, double* values, double* uvalues, struct Sp_Chol* L,
                           int* iflag, int* map, int* invmap);

extern void
vml_Numerical_Factorization(struct Sp_Chol* L, int level, double tol, double atol, double tolz, int* ndiag, int* zpivot,
                            int* iflag, Vlong* pointers, Vlong* qointersb, int* indices, double* values, double* uvalues,
                            double* detfrac, int* detexp, int* map, int* invmap, double* diag, int monfreq);

extern void
vml_Numerical_Solution(struct Sp_Chol* L, int nrhs, double** rhs, double** soln, int* iflag);

extern void
vml_Sparse_Cholesky_Exit(struct Sp_Chol* L);

extern void
vml_Print_Statistics(FILE* stream, struct Sp_Chol* L);

extern void
vml_SetMonitorFunction(struct Sp_Chol* L, Vfunc* func, Vobject* object);

#ifdef __cplusplus
}
#endif

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#endif
