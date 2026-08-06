#include <stdio.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Test and demonstrate Calc
----------------------------------------------------------------------*/
int
main()
{
    vsy_Calc* calc;
    Vint type;
    Vint vali;
    Vdouble vald;
    Vchar valc[81];

    vsy_LicenseValidate(HOOPS_LICENSE);

    printf("\nCalc test\n");

    /* instance Calc object */
    calc = vsy_CalcBegin();

    /* postfix notation */
    vsy_CalcDef(calc, CALC_INFIX);

    vsy_CalcInit(calc);
    /* set tokens */
    vsy_CalcSetToken(calc, CALC_INTEGER, -15, 0., NULL);
    vsy_CalcSetToken(calc, CALC_ADD, 0, 0., NULL);
    vsy_CalcSetToken(calc, CALC_INTEGER, 5, 0., NULL);
    vsy_CalcSetToken(calc, CALC_MUL, 0, 0., NULL);
    vsy_CalcSetToken(calc, CALC_LPAREN, 0, 0., NULL);
    vsy_CalcSetToken(calc, CALC_INTEGER, -6, 0., NULL);
    vsy_CalcSetToken(calc, CALC_SUB, 0, 0., NULL);
    vsy_CalcSetToken(calc, CALC_INTEGER, 3, 3., NULL);
    vsy_CalcSetToken(calc, CALC_RPAREN, 0, 0., NULL);
    vsy_CalcTerm(calc);
    /* evaluate */
    type = CALC_INTEGER;
    vsy_CalcEval(calc, type, &vali, &vald, valc);
    printf("type= %d\n", type);
    if (type == CALC_INTEGER) {
        printf("integer= %d\n", vali);
    }
    else if (type == CALC_FLOAT) {
        printf("float= %e\n", vald);
    }
    else if (type == CALC_STRING) {
        printf("string= %s\n", valc);
    }

    /* delete object */
    vsy_CalcEnd(calc);
    return 0;
}
