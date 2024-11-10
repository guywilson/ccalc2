#include "version.h"

#define __BDATE__      "2024-11-10 09:15:16"
#define __BVERSION__   "1.0.005"

const char * getVersion(void)
{
    return __BVERSION__;
}

const char * getBuildDate(void)
{
    return __BDATE__;
}
