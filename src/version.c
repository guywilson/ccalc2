#include "version.h"

#define __BDATE__      "2026-09-12 14:55:31"
#define __BVERSION__   "1.0.000"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
