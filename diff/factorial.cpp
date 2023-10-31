
#include "factorial.h"
unsigned int fact(unsigned int n)
{
    unsigned int ret = 1;
    if (n > 0) {
        for (unsigned int i = 1; i <= n; ++i)
            ret *= i;
    }
    return ret;
}