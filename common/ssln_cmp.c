/* ssln_cmp - compares two numbers and returns "true" if they are equal

ARGUMENTS:

VARIABLES:

*/

#include <ssln_cmp.h>

bool ssln_cmp(ssln num1, ssln num2)
{
    if(num1.negative == num2.negative &&
        num1.integerSize == num2.integerSize &&
        num1.fractionalSize == num2.fractionalSize &&
        !memcmp(num1.integer, num2.integer, num1.integerSize) &&
        !memcmp(num1.fractional, num2.fractional, num1.fractionalSize))
    {
        FREEALL();
        return true;
    }

    FREEALL();

    return false;
}
