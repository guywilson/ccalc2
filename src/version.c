#include "version.h"

#define __BDATE__      "2024-11-05 15:09:25"
#define __BVERSION__   "0.1.005"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
