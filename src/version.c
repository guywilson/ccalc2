#include "version.h"

#define __BDATE__      "2024-12-08 19:53:56"
#define __BVERSION__   "1.0.011"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
