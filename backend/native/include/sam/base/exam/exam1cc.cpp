#include <stdio.h>
#include "sam/base/base.h"

static void
test_hashtable(void);
static void
test_list(void);
static void
test_stack(void);
static void
test_dictionary(void);
static void
print_integer(Vint n);

/*----------------------------------------------------------------------
                      Test and demonstrate collection objects
----------------------------------------------------------------------*/
int
main()
{
    test_hashtable();
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
    vsy_HashTable* htab;
    Vint num, count, key;
    Vchar* str;

    printf("\nHashTable test\n");

    /* instance HashTable object */
    htab = new vsy_HashTable;
    /* set initial allocation to two objects */
    htab->Def(2);
    /* inquire and count */
    htab->Inq(&num);
    htab->Count(&count);
    printf("num = %d, count = %d\n", num, count);

    /* insert some simple "string" objects */
    htab->Insert(3, (Vobject*)"three");
    htab->Insert(0, (Vobject*)"zero");
    htab->Insert(2, (Vobject*)"two");
    htab->Insert(1, (Vobject*)"one");
    /* remove a couple */
    htab->Remove(2);
    htab->Remove(0);

    /* now inquire and count */
    htab->Inq(&num);
    htab->Count(&count);
    printf("num = %d, count = %d\n", num, count);

    /* InitIter,NextIter traversal */
    htab->InitIter();
    for (;;) {
        htab->NextIter(&key, (Vobject**)&str);
        if (str == NULL)
            break;
        printf("key = %d, string = %s\n", key, str);
    }
    /* delete object */
    delete htab;
}

/*----------------------------------------------------------------------
                      List
----------------------------------------------------------------------*/
static void
test_list(void)
{
    vsy_List* list;

    printf("\nList test\n");
    /* instance object */
    list = new vsy_List;
    /* insert some numbers */
    list->Insert(1, (void*)1);
    list->Insert(10, (void*)10);
    list->Insert(20, (void*)20);
    /* ForEach facility to list contents */
    list->ForEach((void (*)(void*))print_integer);
    printf("\n");
    /* remove an object and list contents again */
    list->Remove(10);
    list->ForEach((void (*)(void*))print_integer);
    printf("\n");
    /* delete object */
    delete list;
}

/*----------------------------------------------------------------------
                      Stack
----------------------------------------------------------------------*/
static void
test_stack(void)
{
    vsy_Stack* stack;

    printf("\nStack test\n");
    /* instance object */
    stack = new vsy_Stack;
    /* push some numbers */
    stack->Push((void*)1);
    stack->Push((void*)10);
    stack->Push((void*)20);
    /* ForEach facility to list contents */
    stack->ForEach((void (*)(void*))print_integer);
    printf("\n");
    /* pop an object off and list contents again*/
    stack->Pop();
    stack->ForEach((void (*)(void*))print_integer);
    printf("\n");
    /* delete object */
    delete stack;
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
    dict = new vsy_Dictionary;
    /* set initial allocation to two objects */
    dict->Def(2);
    /* inquire and count */
    dict->Inq(&num);
    dict->Count(&count);
    printf("num = %d, count = %d\n", num, count);

    /* insert some simple "string" objects */
    dict->Insert("Three", (Vobject*)"three");
    dict->Insert("Zero", (Vobject*)"zero");
    dict->Insert("Two", (Vobject*)"two");
    dict->Insert("One", (Vobject*)"one");
    /* remove a couple */
    dict->Remove("Two");
    dict->Remove("Zero");

    /* now inquire and count */
    dict->Inq(&num);
    dict->Count(&count);
    printf("num = %d, count = %d\n", num, count);

    /* InitIter,NextIter traversal */
    dict->InitIter();
    while (dict->NextIter(&name, (Vobject**)&str), str != NULL) {
        printf("name = %s, string = %s\n", name, str);
    }
    /* reinsert name and lookup */
    dict->Insert("Three", (Vobject*)"3");
    dict->Lookup("Three", (Vobject**)&str);
    printf("name = %s, string = %s\n", "Three", str);

    /* delete object */
    delete dict;
}

/*----------------------------------------------------------------------
                      print utility
----------------------------------------------------------------------*/
static void
print_integer(Vint n)
{
    printf("%d ", n);
}
