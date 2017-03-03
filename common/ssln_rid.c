/* ssln_rid - removes the given ssln from memory

ARGUMENTS:

ssln num - the ssln being removed

VARIABLES:

*/

#include <ssln_rid.h>

void ssln_rid(ssln num)
{
    free(num.integer);
    free(num.fractional);
}
