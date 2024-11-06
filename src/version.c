#include "version.h"

#define __BDATE__      "2024-11-06 18:06:01"
#define __BVERSION__   "1.0.002"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
