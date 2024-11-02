#include "version.h"

#define __BDATE__      "2024-10-31 08:04:38"
#define __BVERSION__   "0.1.001"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
