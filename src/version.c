#include "version.h"

#define __BDATE__      "2024-11-05 17:14:17"
#define __BVERSION__   "0.1.008"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
