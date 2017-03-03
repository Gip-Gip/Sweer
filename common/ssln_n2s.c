/* ssln_n2s - converts a number to a string of the desired base

ARGUMENTS:

ssln num - the number being converted
natural base - the base to use

VARIABLES:

string ret - the string being returned

*/

#include <ssln_n2s.h>

string ssln_n2s(ssln num, natural base)
{
    string ret = calloc(STRALLOC, sizeof(character));
    ssln workNum = ssln_new();
    bool negative = num.negative;

    ssln_set(&workNum, num);

    workNum.negative = false;

    while(ssln_gt(workNum, SSLN_ZERO))
    {
        ret = ssln_sap(
            ret,
            ssln_numTable[ssln_n2i(ssln_mod(workNum, ssln_i2s(base)))],
            true,
            false);

        ssln_set(&workNum, ssln_div(workNum, ssln_i2s(base)));
    }

    if(negative) ret = ssln_sap(ret, SSLN_NEG, true, false);

    ssln_rid(workNum);

    return ret;
}
