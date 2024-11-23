#include "version.h"

#define __BDATE__      "2024-11-23 11:40:20"
#define __BVERSION__   "1.0.010"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
