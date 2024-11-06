#include "version.h"

#define __BDATE__      "2024-11-06 13:30:01"
#define __BVERSION__   "0.1.013"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
