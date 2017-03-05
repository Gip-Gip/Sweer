/* ssln_eEr - creates a ssln which will only used for the error embedded in it
ARGUMENTS:

natural error - the error to embed

VARIABLES:

ssln ret

*/

#include <ssln_eEr.h>

ssln ssln_eEr(natural error)
{
    ssln ret = ssln_new();

    ret.literal = true;
    ret.error = error;
    return ret;
}
