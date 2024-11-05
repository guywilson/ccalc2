#include "version.h"

#define __BDATE__      "2024-11-05 15:25:30"
#define __BVERSION__   "0.1.006"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
