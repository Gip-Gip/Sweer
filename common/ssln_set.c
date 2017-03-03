/* ssln_set - sets a ssln

ARGUMENTS:

ssln *dest - the number being set
ssln src - the number being set to

VARIABLES:

*/

#include <ssln_set.h>

ssln ssln_set(ssln *dest, ssln src)
{
    dest->negative = src.negative;
    dest->integerSize = src.integerSize;
    dest->fractionalSize = src.fractionalSize;

    if(!(dest->integer = realloc(dest->integer, src.integerSize)) ||
        !(dest->fractional = realloc(dest->fractional, src.fractionalSize)))
    {
        dest->error = err_errno + errno;
        return *dest;
    }

    memcpy(dest->integer, src.integer, src.integerSize);
    memcpy(dest->fractional, src.fractional, src.fractionalSize);

    if(src.literal) ssln_rid(src);

    return *dest;
}
