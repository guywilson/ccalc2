#include "version.h"

#define __BDATE__      "2025-10-25 21:17:41"
#define __BVERSION__   "1.0.013"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
