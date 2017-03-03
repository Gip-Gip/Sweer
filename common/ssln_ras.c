/* ssln_ras - adds a given number of digits to an SSLN

ARGUMENTS:

ssln num
natural raise

VARIABLES:

*/

#include <ssln_cmn.h>

ssln ssln_ras(ssln num, natural raise)
{
    ssln workNum = ssln_new(), ret = ssln_new();

    ssln_set(&ret, num);
    ssln_set(&workNum, ret);

    free(ret.integer);
    ret.integer = calloc(ret.integerSize += raise, sizeof(numeral));
    memcpy(ret.integer + raise, workNum.integer, workNum.integerSize);

    ssln_rid(workNum);

    ret.literal = true;
    return ret;
}
