#include "version.h"

#define __BDATE__      "2024-11-05 12:45:57"
#define __BVERSION__   "0.1.004"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
