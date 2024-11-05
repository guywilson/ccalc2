#include "version.h"

#define __BDATE__      "2024-11-05 23:00:58"
#define __BVERSION__   "0.1.011"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
