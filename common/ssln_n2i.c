/* ssln_n2i - "converts" SSLNs to integers

ARGUMENTS:

VARIABLES:

*/

#include <ssln_n2i.h>

natural ssln_n2i(ssln src)
{
    natural retInt = src.integer[ZERO];
    FREEALL();
    return retInt;
}
