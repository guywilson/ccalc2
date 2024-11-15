#include "version.h"

#define __BDATE__      "2024-11-15 18:47:47"
#define __BVERSION__   "1.0.006"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
