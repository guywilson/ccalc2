#include "version.h"

#define __BDATE__      "2025-10-25 21:28:20"
#define __BVERSION__   "1.0.014"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
