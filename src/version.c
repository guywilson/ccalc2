#include "version.h"

#define __BDATE__      "2024-11-06 09:38:36"
#define __BVERSION__   "0.1.012"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
