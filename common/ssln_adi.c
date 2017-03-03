/* ssln_adi - adds a single numeral to the end of an ssln's integer-part

ARGUMENTS:

ssln num - the number being added to

VARIABLES:

*/

#include <ssln_adi.h>

ssln ssln_adi(ssln *num)
{
    if(!(num->integer = realloc(num->integer, num->integerSize += NUMALLOC)))
        num->error = err_errno + errno;

    num->integer[num->integerSize - ONE] = ZERO;

    return *(num);
}
