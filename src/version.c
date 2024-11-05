#include "version.h"

#define __BDATE__      "2024-11-05 17:21:18"
#define __BVERSION__   "0.1.009"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
