#include <stdio.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
test_hashtable(void);
static void
test_vhashtable(void);
static void
test_intvhash(void);
static void
test_list(void);
static void
test_stack(void);
static void
test_dictionary(void);
static void
print_integer(Vint* n);

/*----------------------------------------------------------------------
                      Test and demonstrate collection objects
----------------------------------------------------------------------*/
int
main()
{
    vsy_LicenseValidate(HOOPS_LICENSE);

    test_hashtable();
    test_vhashtable();
    test_intvhash();
    test_list();
    test_stack();
    test_dictionary();
    return 0;
}

/*----------------------------------------------------------------------
                      HashTable
----------------------------------------------------------------------*/
static void
test_hashtable(void)
{
    Vint i;
    vsy_HashTable* htab;
    Vint num, count, key, keys[10];
    Vchar* str;

    printf("\nHashTable test\n");

    /* instance HashTable object */
    htab = vsy_HashTableBegin();
    /* set initial allocation to two objects */
    vsy_HashTableDef(htab, 2);
    /* inquire and count */
    vsy_HashTableInq(htab, &num);
    vsy_HashTableCount(htab, &count);
    printf("num = %d, count = %d\n", num, count);

    /* insert some simple "string" objects */
    vsy_HashTableInsert(htab, 3, (Vobject*)"three");
    vsy_HashTableInsert(htab, 0, (Vobject*)"zero");
    vsy_HashTableInsert(htab, 2, (Vobject*)"two");
    vsy_HashTableInsert(htab, 1, (Vobject*)"one");

    /* count and find maximum key */
    vsy_HashTableCount(htab, &count);
    vsy_HashTableMaxKey(htab, &key);
    printf("count= %d, max key= %d\n", count, key);

    /* get all keys */
    vsy_HashTableAllKeys(htab, keys);
    for (i = 0; i < count; i++) {
        printf("key = %d\n", keys[i]);
    }
    /* remove a couple */
    vsy_HashTableRemove(htab, 2);
    vsy_HashTableRemove(htab, 0);
    /* add some */
    vsy_HashTableInsert(htab, 4, (Vobject*)"four");
    vsy_HashTableInsert(htab, 15, (Vobject*)"fifteen");

    /* now inquire and count */
    vsy_HashTableInq(htab, &num);
    vsy_HashTableCount(htab, &count);
    printf("num = %d, count = %d\n", num, count);

    /* InitIter,NextIter traversal */
    vsy_HashTableInitIter(htab);
    while (vsy_HashTableNextIter(htab, &key, (Vobject**)&str), str != NULL) {
        printf("key = %d, string = %s\n", key, str);
    }
    /* delete object */
    vsy_HashTableEnd(htab);
}

/*----------------------------------------------------------------------
                      VHashTable
----------------------------------------------------------------------*/
static void
test_vhashtable(void)
{
    vsy_VHashTable* htab;
    Vint size, num, count, key[3];
    Vchar* str;

    printf("\nVHashTable test\n");

    /* instance HashTable object */
    htab = vsy_VHashTableBegin();
    /* set initial allocation to three keys and two objects */
    vsy_VHashTableDef(htab, 3, 2);
    /* inquire and count */
    vsy_VHashTableInq(htab, &size, &num);
    vsy_VHashTableCount(htab, &count);
    printf("size = %d, num = %d, count = %d\n", size, num, count);

    /* insert some simple "string" objects */
    key[0] = 1;
    key[1] = 2;

    key[2] = 3;
    vsy_VHashTableInsert(htab, key, (Vobject*)"three");
    key[2] = 0;
    vsy_VHashTableInsert(htab, key, (Vobject*)"zero");
    key[2] = 2;
    vsy_VHashTableInsert(htab, key, (Vobject*)"two");
    key[2] = 1;
    vsy_VHashTableInsert(htab, key, (Vobject*)"one");

    /* count */
    vsy_VHashTableCount(htab, &count);
    printf("count= %d\n", count);

    /* remove a couple */
    key[2] = 2;
    vsy_VHashTableRemove(htab, key);
    key[2] = 0;
    vsy_VHashTableRemove(htab, key);
    /* add some */
    key[2] = 4;
    vsy_VHashTableInsert(htab, key, (Vobject*)"four");
    key[2] = 15;
    vsy_VHashTableInsert(htab, key, (Vobject*)"fifteen");

    /* now inquire and count */
    vsy_VHashTableInq(htab, &size, &num);
    vsy_VHashTableCount(htab, &count);
    printf("size = %d, num = %d, count = %d\n", size, num, count);

    /* InitIter,NextIter traversal */
    vsy_VHashTableInitIter(htab);
    while (vsy_VHashTableNextIter(htab, key, (Vobject**)&str), str != NULL) {
        printf("key = %d %d %d, string = %s\n", key[0], key[1], key[2], str);
    }
    /* delete object */
    vsy_VHashTableEnd(htab);
}

/*----------------------------------------------------------------------
                      IntVHash
----------------------------------------------------------------------*/
static void
test_intvhash(void)
{
    vsy_IntVHash* ivhash;
    Vint size, num, count, key[3], ival;

    printf("\nIntVHash test\n");

    /* instance IntVHash object */
    ivhash = vsy_IntVHashBegin();
    /* set initial allocation to three keys and two objects */
    vsy_IntVHashDef(ivhash, 3, 2);
    /* inquire and count */
    vsy_IntVHashInq(ivhash, &size, &num);
    vsy_IntVHashCount(ivhash, &count);
    printf("size = %d, num = %d, count = %d\n", size, num, count);

    /* insert some simple "string" objects */
    key[0] = 1;
    key[1] = 2;

    key[2] = 3;
    vsy_IntVHashInsert(ivhash, key, 3);
    key[2] = 2;
    vsy_IntVHashInsert(ivhash, key, 2);
    key[2] = 1;
    vsy_IntVHashInsert(ivhash, key, 1);

    /* count */
    vsy_IntVHashCount(ivhash, &count);
    printf("count= %d\n", count);

    /* remove a couple */
    key[2] = 2;
    vsy_IntVHashRemove(ivhash, key);
    key[2] = 0;
    vsy_IntVHashRemove(ivhash, key);
    /* add some */
    key[2] = 4;
    vsy_IntVHashInsert(ivhash, key, 4);
    key[2] = 15;
    vsy_IntVHashInsert(ivhash, key, 15);

    /* now inquire and count */
    vsy_IntVHashInq(ivhash, &size, &num);
    vsy_IntVHashCount(ivhash, &count);
    printf("size = %d, num = %d, count = %d\n", size, num, count);

    /* InitIter,NextIter traversal */
    vsy_IntVHashInitIter(ivhash);
    while (vsy_IntVHashNextIter(ivhash, key, &ival), ival != 0) {
        printf("key = %d %d %d, ival = %d\n", key[0], key[1], key[2], ival);
    }
    /* delete object */
    vsy_IntVHashEnd(ivhash);
}

/*----------------------------------------------------------------------
                      List
----------------------------------------------------------------------*/
static void
test_list(void)
{
    vsy_List* list;
    Vint values[3] = {1, 10, 20};

    printf("\nList test\n");
    /* instance object */
    list = vsy_ListBegin();
    /* insert some numbers */
    vsy_ListInsert(list, values[0], (Vobject*)&values[0]);
    vsy_ListInsert(list, values[1], (Vobject*)&values[1]);
    vsy_ListInsert(list, values[2], (Vobject*)&values[2]);
    /* ForEach facility to list contents */
    vsy_ListForEach(list, (Vfunc1*)print_integer);
    printf("\n");
    /* remove an object and list contents again */
    vsy_ListRemove(list, values[1]);
    vsy_ListForEach(list, (Vfunc1*)print_integer);
    printf("\n");
    /* delete object */
    vsy_ListEnd(list);
}

/*----------------------------------------------------------------------
                      Stack
----------------------------------------------------------------------*/
static void
test_stack(void)
{
    vsy_Stack* stack;
    Vint values[3] = {1, 10, 20};

    printf("\nStack test\n");
    /* instance object */
    stack = vsy_StackBegin();

    /* push some numbers */
    vsy_StackPush(stack, (Vobject*)&values[0]);
    vsy_StackPush(stack, (Vobject*)&values[1]);
    vsy_StackPush(stack, (Vobject*)&values[2]);
    /* ForEach facility to list contents */
    vsy_StackForEach(stack, (Vfunc1*)print_integer);
    printf("\n");
    /* pop an object off and list contents again*/
    vsy_StackPop(stack);
    vsy_StackForEach(stack, (Vfunc1*)print_integer);
    printf("\n");
    /* delete object */
    vsy_StackEnd(stack);
}

/*----------------------------------------------------------------------
                      Dictionary
----------------------------------------------------------------------*/
static void
test_dictionary(void)
{
    vsy_Dictionary* dict;
    Vint num, count;
    Vchar* name;
    Vchar* str;

    printf("\nDictionary test\n");

    /* instance Dictionary object */
    dict = vsy_DictionaryBegin();
    /* set initial allocation to two objects */
    vsy_DictionaryDef(dict, 2);
    /* inquire and count */
    vsy_DictionaryInq(dict, &num);
    vsy_DictionaryCount(dict, &count);
    printf("num = %d, count = %d\n", num, count);

    /* insert some simple "string" objects */
    vsy_DictionaryInsert(dict, "Three", (Vobject*)"three");
    vsy_DictionaryInsert(dict, "Zero", (Vobject*)"zero");
    vsy_DictionaryInsert(dict, "Two", (Vobject*)"two");
    vsy_DictionaryInsert(dict, "One", (Vobject*)"one");
    /* remove a couple */
    vsy_DictionaryRemove(dict, "Two");
    vsy_DictionaryRemove(dict, "Zero");
    /* add some */
    vsy_DictionaryInsert(dict, "Four", (Vobject*)"four");
    vsy_DictionaryInsert(dict, "Fifteen", (Vobject*)"fifteen");

    /* now inquire and count */
    vsy_DictionaryInq(dict, &num);
    vsy_DictionaryCount(dict, &count);
    printf("num = %d, count = %d\n", num, count);

    /* InitIter,NextIter traversal */
    vsy_DictionaryInitIter(dict);
    while (vsy_DictionaryNextIter(dict, &name, (Vobject**)&str), str != NULL) {
        printf("name = %s, string = %s\n", name, str);
    }
    /* reinsert name and lookup */
    vsy_DictionaryInsert(dict, "Three", (Vobject*)"3");
    vsy_DictionaryLookup(dict, "Three", (Vobject**)&str);
    printf("name = %s, string = %s\n", "Three", str);

    /* delete object */
    vsy_DictionaryEnd(dict);
}

/*----------------------------------------------------------------------
                      print utility
----------------------------------------------------------------------*/
static void
print_integer(Vint* n)
{
    printf("%d ", *n);
}
