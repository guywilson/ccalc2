#include "version.h"

#define __BDATE__      "2024-12-17 21:29:28"
#define __BVERSION__   "1.0.012"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
