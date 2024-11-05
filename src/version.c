#include "version.h"

#define __BDATE__      "2024-11-05 16:42:41"
#define __BVERSION__   "0.1.007"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
