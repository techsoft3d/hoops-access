#include <stdio.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
test_bitvec(void);
static void
test_dblvec(void);
static void
test_intvec(void);
static void
test_inthash(void);
static void
test_intdict(void);
static void
test_intstack(void);
static void
test_intque(void);
static void
print_bitvector(vsy_BitVec* bitvec, Vchar* stg);

/*----------------------------------------------------------------------
                      Demonstration of Numeric Type Collections
----------------------------------------------------------------------*/
int
main()
{
    vsy_LicenseValidate(HOOPS_LICENSE);

    test_bitvec();
    test_dblvec();
    test_intvec();
    test_intdict();
    test_intstack();
    test_inthash();
    test_intque();
    return 0;
}

/*----------------------------------------------------------------------
                      BitVec
----------------------------------------------------------------------*/
static void
test_bitvec(void)
{
    vsy_BitVec *bitvecx, *bitvecy, *bitvecz;
    Vint index, maxindex, flag, count;

    printf("\nBitVec test\n");

    /* instance object */
    bitvecx = vsy_BitVecBegin();

    /* set some indices */
    vsy_BitVecSet(bitvecx, 1, 1);
    vsy_BitVecSet(bitvecx, 3, 1);
    vsy_BitVecSet(bitvecx, 5, 1);

    /* get max index referenced */
    vsy_BitVecInq(bitvecx, &maxindex);
    printf("maximum index = %d\n", maxindex);

    /* test get */
    for (index = 0; index <= maxindex; index++) {
        vsy_BitVecGet(bitvecx, index, &flag);
        printf("index %d = %d\n", index, flag);
    }
    /* count flags */
    vsy_BitVecCount(bitvecx, &count);
    printf("number of flags = %d\n", count);

    /* test iteration with print */
    print_bitvector(bitvecx, (Vchar*)"X");

    /* boolean operations */
    bitvecy = vsy_BitVecBegin();
    bitvecz = vsy_BitVecBegin();

    /* copy the bit vector to bit vector x */
    vsy_BitVecBoolean(bitvecy, BITVEC_SET, bitvecx);
    vsy_BitVecSet(bitvecy, 5, 0);
    print_bitvector(bitvecy, (Vchar*)"Y is a copy of X with index 5 set to zero");

    vsy_BitVecBoolean(bitvecz, BITVEC_SET, bitvecy);
    vsy_BitVecBoolean(bitvecz, BITVEC_AND, bitvecx);
    print_bitvector(bitvecz, (Vchar*)"Z is X AND Y");

    vsy_BitVecBoolean(bitvecz, BITVEC_SET, bitvecy);
    vsy_BitVecBoolean(bitvecz, BITVEC_OR, bitvecx);
    print_bitvector(bitvecz, (Vchar*)"Z is X OR Y");

    vsy_BitVecBoolean(bitvecz, BITVEC_SET, bitvecy);
    vsy_BitVecBoolean(bitvecz, BITVEC_XOR, bitvecx);
    print_bitvector(bitvecz, (Vchar*)"Z is X XOR Y");

    vsy_BitVecComplement(bitvecy);
    print_bitvector(bitvecy, (Vchar*)"Y is NOT Y");

    vsy_BitVecSetParami(bitvecy, VSY_INCLUDEZERO, SYS_OFF);
    print_bitvector(bitvecy, (Vchar*)"exclude index zero from Y");

    /* delete object */
    vsy_BitVecEnd(bitvecx);
    vsy_BitVecEnd(bitvecy);
    vsy_BitVecEnd(bitvecz);
}

/*----------------------------------------------------------------------
                      print utility
----------------------------------------------------------------------*/
static void
print_bitvector(vsy_BitVec* bitvec, Vchar* stg)
{
    Vint index;

    /* print a title */
    printf("\n%s\n", stg);
    /* print indices of all one bits */
    vsy_BitVecInitIter(bitvec);
    while (vsy_BitVecNextIter(bitvec, &index), index >= 0) {
        printf("index = %d\n", index);
    }
}

/*----------------------------------------------------------------------
                      DblVec
----------------------------------------------------------------------*/
static void
test_dblvec(void)
{
    vsy_DblVec* dblvec;
    Vint num, count;
    Vint index;
    Vdouble val, *ptr;

    printf("\nDblVec test\n");

    /* instance DblVec object */
    dblvec = vsy_DblVecBegin();
    /* set initial allocation to two integers */
    vsy_DblVecDef(dblvec, 2);
    /* inquire and count */
    vsy_DblVecInq(dblvec, &num);
    vsy_DblVecCount(dblvec, &count);
    printf("num = %d, count = %d\n", num, count);

    /* insert some integers */
    vsy_DblVecSet(dblvec, 5, 105.);
    vsy_DblVecSet(dblvec, 3, 103.);
    vsy_DblVecSet(dblvec, 7, 107.);
    vsy_DblVecSet(dblvec, 2, 102.);
    vsy_DblVecSet(dblvec, 1, 101.);

    /* get a set value */
    vsy_DblVecGet(dblvec, 5, &val);
    printf("value = %f\n", val);
    /* get an unset value */
    vsy_DblVecGet(dblvec, 6, &val);
    printf("value = %f\n", val);

    /* get pointer, index starts from 1 */
    vsy_DblVecGetPtr(dblvec, &ptr);
    vsy_DblVecInq(dblvec, &num);
    for (index = 1; index <= num; index++) {
        printf("index= %d, value= %f\n", index, ptr[index - 1]);
    }
    /* InitIter,NextIter traversal */
    vsy_DblVecInitIter(dblvec);
    while (vsy_DblVecNextIter(dblvec, &index, &val), index != -1) {
        printf("index = %d, value = %f\n", index, val);
    }
    /* clear */
    vsy_DblVecClear(dblvec);
    /* inquire and count */
    vsy_DblVecInq(dblvec, &num);
    vsy_DblVecCount(dblvec, &count);
    printf("num = %d, count = %d\n", num, count);

    /* delete object */
    vsy_DblVecEnd(dblvec);
}

/*----------------------------------------------------------------------
                      IntVec
----------------------------------------------------------------------*/
static void
test_intvec(void)
{
    vsy_IntVec* intvec;
    Vint num, count;
    Vint index;
    Vint val, *ptr;

    printf("\nIntVec test\n");

    /* instance IntVec object */
    intvec = vsy_IntVecBegin();
    /* set initial allocation to two integers */
    vsy_IntVecDef(intvec, 2);
    /* inquire and count */
    vsy_IntVecInq(intvec, &num);
    vsy_IntVecCount(intvec, &count);
    printf("num = %d, count = %d\n", num, count);

    /* insert some integers */
    vsy_IntVecSet(intvec, 5, 105);
    vsy_IntVecSet(intvec, 3, 103);
    vsy_IntVecSet(intvec, 7, 107);
    vsy_IntVecSet(intvec, 2, 102);
    vsy_IntVecSet(intvec, 1, 101);

    /* get a set value */
    vsy_IntVecGet(intvec, 5, &val);
    printf("value = %d\n", val);
    /* get an unset value */
    vsy_IntVecGet(intvec, 6, &val);
    printf("value = %d\n", val);

    /* get pointer, index starts from 1 */
    vsy_IntVecGetPtr(intvec, &ptr);
    vsy_IntVecInq(intvec, &num);
    for (index = 1; index <= num; index++) {
        printf("index= %d, value= %d\n", index, ptr[index - 1]);
    }
    /* InitIter,NextIter traversal */
    vsy_IntVecInitIter(intvec);
    while (vsy_IntVecNextIter(intvec, &index, &val), index != -1) {
        printf("index = %d, value = %d\n", index, val);
    }
    /* clear */
    vsy_IntVecClear(intvec);
    /* inquire and count */
    vsy_IntVecInq(intvec, &num);
    vsy_IntVecCount(intvec, &count);
    printf("num = %d, count = %d\n", num, count);

    /* delete object */
    vsy_IntVecEnd(intvec);
}

/*----------------------------------------------------------------------
                      IntDict
----------------------------------------------------------------------*/
static void
test_intdict(void)
{
    vsy_IntDict* intdict;
    Vint num, count;
    Vchar* name;
    Vint val;

    printf("\nIntDict test\n");

    /* instance IntDict object */
    intdict = vsy_IntDictBegin();
    /* set initial allocation to two integers */
    vsy_IntDictDef(intdict, 2);
    /* inquire and count */
    vsy_IntDictInq(intdict, &num);
    vsy_IntDictCount(intdict, &count);
    printf("num = %d, count = %d\n", num, count);

    /* insert some integers */
    vsy_IntDictInsert(intdict, "105", 105);
    vsy_IntDictInsert(intdict, "103", 103);
    vsy_IntDictInsert(intdict, "100", 100);
    vsy_IntDictInsert(intdict, "102", 102);
    vsy_IntDictInsert(intdict, "101", 101);

    /* lookup a legal value */
    vsy_IntDictLookup(intdict, "101", &val);
    printf("value = %d\n", val);
    /* lookup a illegal value */
    vsy_IntDictLookup(intdict, "104", &val);
    printf("value = %d\n", val);

    /* now inquire and count */
    vsy_IntDictInq(intdict, &num);
    vsy_IntDictCount(intdict, &count);
    printf("num = %d, count = %d\n", num, count);

    /* InitIter,NextIter traversal */
    vsy_IntDictInitIter(intdict);
    while (vsy_IntDictNextIter(intdict, &name, &val), name != NULL) {
        printf("name = %s, value = %d\n", name, val);
    }
    /* clear */
    vsy_IntDictClear(intdict);
    /* inquire and count */
    vsy_IntDictInq(intdict, &num);
    vsy_IntDictCount(intdict, &count);
    printf("num = %d, count = %d\n", num, count);

    /* delete object */
    vsy_IntDictEnd(intdict);
}

/*----------------------------------------------------------------------
                      IntStack
----------------------------------------------------------------------*/
static void
test_intstack(void)
{
    vsy_IntStack* intstack;
    Vint id, num;

    printf("\nIntStack test\n");

    /* instance IntStack object */
    intstack = vsy_IntStackBegin();
    /* set initial allocation to 20 integers */
    vsy_IntStackDef(intstack, 20);

    /* push some integers */
    vsy_IntStackPush(intstack, 105);
    vsy_IntStackPush(intstack, 103);
    vsy_IntStackPush(intstack, 100);
    vsy_IntStackPush(intstack, 102);
    vsy_IntStackPush(intstack, 101);

    vsy_IntStackPrint(intstack);

    vsy_IntStackPush(intstack, 101);
    vsy_IntStackPrint(intstack);

    /* pop */
    vsy_IntStackPop(intstack, &id);
    printf("id = %d\n", id);
    vsy_IntStackPrint(intstack);

    /* clear */
    vsy_IntStackClear(intstack);
    vsy_IntStackPrint(intstack);

    vsy_IntStackCount(intstack, &num);
    printf("num = %d\n", num);

    /* delete object */
    vsy_IntStackEnd(intstack);
}

/*----------------------------------------------------------------------
                      IntHash
----------------------------------------------------------------------*/
static void
test_inthash(void)
{
    vsy_IntHash* inthash;
    Vint num, count, key;
    Vint val;

    printf("\nIntHash test\n");

    /* instance IntHash object */
    inthash = vsy_IntHashBegin();
    /* set initial allocation to two integers */
    vsy_IntHashDef(inthash, 2);
    /* inquire and count */
    vsy_IntHashInq(inthash, &num);
    vsy_IntHashCount(inthash, &count);
    printf("num = %d, count = %d\n", num, count);

    /* insert some integers */
    vsy_IntHashInsert(inthash, 5, 105);
    vsy_IntHashInsert(inthash, 3, 103);
    vsy_IntHashInsert(inthash, 0, 100);
    vsy_IntHashInsert(inthash, 2, 102);
    vsy_IntHashInsert(inthash, 1, 101);

    /* lookup a legal value */
    vsy_IntHashLookup(inthash, 1, &val);
    printf("value = %d\n", val);
    /* lookup a illegal value */
    vsy_IntHashLookup(inthash, 4, &val);
    printf("value = %d\n", val);

    /* now inquire and count */
    vsy_IntHashInq(inthash, &num);
    vsy_IntHashCount(inthash, &count);
    printf("num = %d, count = %d\n", num, count);

    /* InitIter,NextIter traversal */
    vsy_IntHashInitIter(inthash);
    while (vsy_IntHashNextIter(inthash, &key, &val), val != 0) {
        printf("key = %d, value = %d\n", key, val);
    }
    /* delete object */
    vsy_IntHashEnd(inthash);
}

/*----------------------------------------------------------------------
                      IntQue
----------------------------------------------------------------------*/
static void
test_intque(void)
{
    vsy_IntQue* intque;
    Vint num, count;
    Vint val;

    printf("\nIntQue test\n");

    /* instance IntQue object */
    intque = vsy_IntQueBegin();
    /* set initial allocation to two integers */
    vsy_IntQueDef(intque, 2);
    /* inquire and count */
    vsy_IntQueInq(intque, &num);
    vsy_IntQueCount(intque, &count);
    printf("num = %d, count = %d\n", num, count);

    /* put some integers */
    vsy_IntQuePut(intque, 105);
    vsy_IntQuePut(intque, 103);
    vsy_IntQuePut(intque, 100);
    vsy_IntQuePut(intque, 102);
    vsy_IntQuePut(intque, 101);

    /* reference */
    vsy_IntQueRef(intque, &val);
    printf("value = %d\n", val);

    /* get */
    vsy_IntQueGet(intque, &val);
    printf("value = %d\n", val);

    /* now inquire and count */
    vsy_IntQueInq(intque, &num);
    vsy_IntQueCount(intque, &count);
    printf("num = %d, count = %d\n", num, count);

    /* delete object */
    vsy_IntQueEnd(intque);
}
