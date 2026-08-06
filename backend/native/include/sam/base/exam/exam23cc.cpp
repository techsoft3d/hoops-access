#include <stdio.h>
#include <math.h>
#include "sam/base/base.h"

class Vcquad {
  public:
    Vcquad(): a(vut_VQuadLoad(0.)) {}
    Vcquad
    operator=(Vdouble b);
    Vcquad
    operator+(Vcquad b);
    Vcquad
    operator-(Vcquad b);
    Vcquad
    operator-();
    Vcquad
    operator*(Vcquad b);
    Vcquad
    operator+=(Vcquad b);
    Vcquad
    operator-=(Vcquad b);
    Vcquad
    operator*=(Vcquad b);
    Vcquad
    operator/=(Vcquad b);
    Vcquad
    operator/(Vcquad b);
    Vint
    operator<(Vcquad b);
    Vint
    operator<=(Vcquad b);
    Vint
    operator>(Vcquad b);
    Vint
    operator>=(Vcquad b);
    Vint
    operator==(Vcquad b);
    Vcquad
    sqrt();
    void
    Printf();

  private:
    Vquad a;
};

Vcquad
Vcquad::operator=(Vdouble b)
{
    Vcquad x;

    a = vut_VQuadLoad(b);
    return *this;
}

Vcquad
Vcquad::operator+(Vcquad b)
{
    Vcquad x;
    Vint ierr;

    x.a = vut_VQuadAdd(a, b.a, &ierr);
    return x;
}

Vcquad
Vcquad::operator-(Vcquad b)
{
    Vcquad x;
    Vint ierr;

    x.a = vut_VQuadSub(a, b.a, &ierr);
    return x;
}

Vcquad
Vcquad::operator-()
{
    Vcquad x;

    x.a = vut_VQuadNeg(a);
    return x;
}

Vcquad
Vcquad::operator*(Vcquad b)
{
    Vcquad x;
    Vint ierr;

    x.a = vut_VQuadMult(a, b.a, &ierr);
    return x;
}

Vcquad
Vcquad::operator+=(Vcquad b)
{
    Vint ierr;

    a = vut_VQuadAdd(a, b.a, &ierr);
    return *this;
}

Vcquad
Vcquad::operator-=(Vcquad b)
{
    Vint ierr;

    a = vut_VQuadSub(a, b.a, &ierr);
    return *this;
}

Vcquad
Vcquad::operator*=(Vcquad b)
{
    Vint ierr;

    a = vut_VQuadMult(a, b.a, &ierr);
    return *this;
}

Vcquad
Vcquad::operator/=(Vcquad b)
{
    Vint ierr;

    a = vut_VQuadDiv(a, b.a, &ierr);
    return *this;
}

Vcquad
Vcquad::operator/(Vcquad b)
{
    Vcquad x;
    Vint ierr;

    x.a = vut_VQuadDiv(a, b.a, &ierr);
    return x;
}

Vint
Vcquad::operator<(Vcquad b)
{
    return vut_VQuadLT(a, b.a);
}

Vint
Vcquad::operator>(Vcquad b)
{
    return vut_VQuadGT(a, b.a);
}

Vint
Vcquad::operator>=(Vcquad b)
{
    return vut_VQuadGE(a, b.a);
}

Vint
Vcquad::operator==(Vcquad b)
{
    return vut_VQuadEQ(a, b.a);
}

Vcquad
Vcquad::sqrt()
{
    Vcquad x;
    Vint ierr;

    x.a = vut_VQuadSqrt(a, &ierr);
    return x;
}

void
Vcquad::Printf()
{
    Vint ierr;

    vut_VQuadPrintf(a, 41, 1, &ierr);
}

/*----------------------------------------------------------------------
                      C++ Operator Overloading for Quadruple Precision
----------------------------------------------------------------------*/
int
main()
{
    Vcquad ca, cb, cc, v[3];

    /* load and store operations */
    ca = 1.23;
    cb = 2.;
    printf("ca = ");
    ca.Printf();
    printf("\n");
    printf("cb = ");
    cb.Printf();
    printf("\n\n");

    /* arithmetic operation */
    cc = ca + cb;
    printf("ca + cb = ");
    cc.Printf();
    printf("\n\n");
    cc = ca - cb;
    printf("ca - cb = ");
    cc.Printf();
    printf("\n\n");
    cc = ca * cb;
    printf("ca * cb = ");
    cc.Printf();
    printf("\n\n");
    cc = ca / cb;
    printf("ca / cb = ");
    cc.Printf();
    printf("\n\n");

    cc = ca.sqrt();
    printf("sqrt(ca)= ");
    cc.Printf();
    printf("\n\n");

    cc = -ca;
    printf("-ca= ");
    cc.Printf();
    printf("\n\n");

    cc = ca;
    cc += cb;
    printf("ca + cb = ");
    cc.Printf();
    printf("\n\n");

    cc = ca;
    cc -= cb;
    printf("ca - cb = ");
    cc.Printf();
    printf("\n\n");

    cc = ca;
    cc *= cb;
    printf("ca * cb = ");
    cc.Printf();
    printf("\n\n");

    cc = ca;
    cc /= cb;
    printf("ca / cb = ");
    cc.Printf();
    printf("\n\n");

    /* comparisons */
    if (ca < cb) {
        printf("ca < cb\n");
    }
    else {
        printf("ca >= cb\n");
    }
    if (cb < ca) {
        printf("cb < ca\n");
    }
    else {
        printf("cb >= ca\n");
    }
    if (ca == ca) {
        printf("ca = ca\n");
    }
    /* vector operation */
    v[0] = 3.;
    v[1] = 4.;
    v[2] = 5.;
    cc = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
    printf("v . v = ");
    cc.Printf();
    printf("\n\n");
    return 0;
}
