#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* list of system error types */
static Vint errortable[SYS_ERROR_MAX] = {SYS_ERROR_VALUE,      SYS_ERROR_ENUM,      SYS_ERROR_OBJECTTYPE, SYS_ERROR_MEMORY,
                                         SYS_ERROR_NULLOBJECT, SYS_ERROR_FILE,      SYS_ERROR_COMPUTE,    SYS_ERROR_OPERATION,
                                         SYS_ERROR_OVERFLOW,   SYS_ERROR_UNDERFLOW, SYS_ERROR_UNKNOWN,    SYS_ERROR_FORMAT,
                                         SYS_ERROR_SEVERE,     SYS_ERROR_LOAD};

static const Vchar* errorname[SYS_ERROR_MAX] = {
"SYS_ERROR_VALUE",   "SYS_ERROR_ENUM",    "SYS_ERROR_OBJECTTYPE", "SYS_ERROR_MEMORY",   "SYS_ERROR_NULLOBJECT",
"SYS_ERROR_FILE",    "SYS_ERROR_COMPUTE", "SYS_ERROR_OPERATION",  "SYS_ERROR_OVERFLOW", "SYS_ERROR_UNDERFLOW",
"SYS_ERROR_UNKNOWN", "SYS_ERROR_FORMAT",  "SYS_ERROR_SEVERE",     "SYS_ERROR_LOAD"};

static void
user_ErrorHandler(const Vchar* funcname, Vint errorflag, const Vchar* message)
{
    printf("\n");
    if (funcname) {
        printf("function : %s\n", funcname);
    }
    if (errorflag > 0 && errorflag <= SYS_ERROR_MAX) {
        printf("error    : %s\n", vut_ErrorString(errorflag));
    }
    if (strlen(message)) {
        printf("message  : %s\n", message);
    }
}

static void*
user_malloc(size_t siz)
{
    printf("\n");
    printf("malloc %lu bytes\n", (unsigned long)siz);
    return (malloc(siz));
}

static void*
user_realloc(void* ptr, size_t siz)
{
    printf("\n");
    printf("realloc %p ptr, %lu bytes\n", ptr, (unsigned long)siz);
    return (realloc(ptr, siz));
}

static void
user_free(void* ptr)
{
    printf("\n");
    printf("free %p ptr\n", ptr);
    free(ptr);
}

/*----------------------------------------------------------------------
                      Install user error handler and memory management
----------------------------------------------------------------------*/
int
main()
{
    Vint i;
    vsy_List* list;
    Vint num;
    Vint ierr;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* print DevTools version string */
    printf("version= %s\n", vut_Name(NAME_VERSION, 0));

    /* install user error handler */
    vut_ErrorSetHandler(user_ErrorHandler);

    /* install user memory management */
    vut_MemorySetFunctions(user_malloc, user_realloc, user_free);

    /* instance object */
    list = vsy_ListBegin();
    /* insert some numbers */
    /* index= -1 produces an error */
    vsy_ListInsert(list, -1, (void*)1);
    vsy_ListInsert(list, 10, (void*)10);
    vsy_ListInsert(list, 20, (void*)20);

    /* count objects */
    vsy_ListCount(list, &num);
    printf("\n");
    printf("num= %d\n", num);
    printf("\n");

    /* reinstall default error handler */
    vut_ErrorSetHandler(NULL);

    /* insert an object */
    /* index= -2 produces an error */
    vsy_ListInsert(list, -2, (void*)2);
    /* query object for error and search */
    ierr = vsy_ListError(list);
    /* in general, errors are non-zero */
    if (ierr) {
        for (i = 0; i < SYS_ERROR_MAX; i++) {
            if (ierr == errortable[i]) {
                printf("\nError, ierr= %d, name= %s\n", ierr, errorname[i]);
                break;
            }
        }
    }
    /* delete object */
    vsy_ListEnd(list);
    return 0;
}
