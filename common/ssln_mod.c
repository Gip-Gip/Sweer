/* ssln_div - divides the dividend by the divisor

ARGUMENTS:

ssln dividend
ssln divisor

VARIABLES:

*/

#include <ssln_mod.h>

ssln ssln_mod(ssln dividend, ssln divisor)
{
    ssln workingDividend = ssln_new(),
        workingDivisor = ssln_new();
    natural raise = dividend.integerSize;

    ssln_set(&workingDividend, dividend);
    ssln_set(&workingDivisor, divisor);

    if(ssln_cmp(workingDivisor, SSLN_ZERO))
    {
        FREEALL();

        workingDividend.literal = true;
        return workingDividend;
    }

    while(ssln_gt(workingDividend, workingDivisor) ||
        ssln_cmp(workingDividend, workingDivisor))
    {
        while(ssln_gt(workingDividend, ssln_ras(workingDivisor, raise)) ||
            ssln_cmp(workingDividend, ssln_ras(workingDivisor, raise)))
        {
            ssln_set(
                &workingDividend,
                ssln_sub(workingDividend, ssln_ras(workingDivisor, raise)));
        }

        raise --;
    }

    FREEALL();

    workingDividend.literal = true;

    return workingDividend;
}
