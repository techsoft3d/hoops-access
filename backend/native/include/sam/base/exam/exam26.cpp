#include <stdio.h>
#include <wchar.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Test and demonstrate StrUtil
----------------------------------------------------------------------*/
int
main()
{
    wchar_t euro[] = {L'U', L'n', L'i', L'c', L'o', L'd', L'e', L' ', L'E', L'u', L'r', L'o', L'=', L' ', 0x20ac, L'\0'};
    Vchar str[256];
    wchar_t wstr[256];
    Vint numchar;

    vsy_LicenseValidate(HOOPS_LICENSE);

    printf("\nStrUtil test\n");

    /* convert wide char to utf8 */
    vut_StrUtilToUTF8(euro, 256, str);

    numchar = vut_StrUtilLenUTF8(str);
    printf("number of characters= %d\n", numchar);
    printf("%s\n", str);
    /* convert back to wide char */
    vut_StrUtilFromUTF8(str, 256, wstr);
    /* test */
    if (wcscmp(wstr, euro)) {
        printf("string comparison fails\n");
    }
    else {
        printf("string comparison succeeds\n");
    }

    return 0;
}
