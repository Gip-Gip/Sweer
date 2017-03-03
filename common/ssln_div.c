/* ssln_div - divides the dividend by the divisor

ARGUMENTS:

ssln dividend
ssln divisor

VARIABLES:

*/

#include <ssln_div.h>

ssln ssln_div(ssln dividend, ssln divisor)
{
    ssln quotent = ssln_new(),
        workingDividend = ssln_new(),
        workingDivisor = ssln_new();

    natural raise = dividend.integerSize;

    ssln_set(&quotent, ssln_i2s(ZERO));
    ssln_set(&workingDividend, dividend);
    ssln_set(&workingDivisor, divisor);

    while(ssln_gt(workingDividend, workingDivisor) ||
        ssln_cmp(workingDividend, workingDivisor))
    {
        while(ssln_gt(workingDividend, ssln_ras(workingDivisor, raise)) ||
            ssln_cmp(workingDividend, ssln_ras(workingDivisor, raise)))
        {
            ssln_set(
                &workingDividend,
                ssln_sub(workingDividend, ssln_ras(workingDivisor, raise)));

            ssln_set(
                &quotent,
                ssln_add(quotent, ssln_ras(ssln_i2s(ONE), raise)));
        }

        raise --;
    }

    FREEALL();

    quotent.literal = true;

    return quotent;
}
