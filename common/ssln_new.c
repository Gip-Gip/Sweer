/* ssln_new - returns a new large number

ARGUMENTS:

VARIABLES:

ssln ret - the new large number being returned

*/

#include <ssln_cmn.h>

ssln ssln_new()
{
    ssln ret;

    ret.negative = false;
    ret.literal = false;
    ret.error = none;
    ret.integerSize = NUMALLOC;
    ret.fractionalSize = NUMALLOC;
    if(!(ret.integer = calloc(NUMALLOC, sizeof(numeral))) ||
        !(ret.fractional = calloc(NUMALLOC, sizeof(numeral))))

        ret.error = err_errno + errno;

    return ret;
}
