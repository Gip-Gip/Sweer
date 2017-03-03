/* ssln_n2i - converts SSLNs to integers

ARGUMENTS:

VARIABLES:

*/

#include <ssln_n2i.h>

natural ssln_n2i(ssln src)
{
    natural retInt = ZERO, numn = src.integerSize;

    while(numn--)
    {
        retInt <<= BYTESHFT;
        retInt = src.integer[numn];
    }

    FREEALL();
    return retInt;
}
