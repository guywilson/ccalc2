#include "version.h"

#define __BDATE__      "2024-11-03 22:14:36"
#define __BVERSION__   "0.1.002"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
