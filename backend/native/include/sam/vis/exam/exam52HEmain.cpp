#include "exam52HE.h"
#include "sam/hoops_license.h"

int
main(int argc, char* argv[])
{
#ifdef VKI_LIBAPI_HOOPS
    example52HE::setHoopsLicense(HOOPS_LICENSE);
    return example52HE::run_example52HE(argc, argv);
#else
    return 0;
#endif
}
