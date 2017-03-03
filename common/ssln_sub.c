/* ssln_sub - subtracts the from the first number

ARGUMENTS:

ssln subtrahend
ssln minuend

VARIABLES:

*/

#include <ssln_sub.h>

ssln ssln_sub(ssln subtrahend, ssln minuend)
{
    ssln difference,
        workingSubtrahend = ssln_new(),
        workingMinuend = ssln_new();
    natural numn = INDEXINIT, worknum;
    bool carry = false;

    ssln_set(&workingSubtrahend, subtrahend);
    ssln_set(&workingMinuend, minuend);

    if(ssln_cmp(workingSubtrahend, workingMinuend))
    {
        FREEALL();
        return ssln_i2s(ZERO);
    }

    if(workingSubtrahend.negative & (!workingMinuend.negative))
    {
        workingMinuend.negative = false;
        difference = ssln_add(workingMinuend, workingSubtrahend);
        difference.negative = true;
        return difference;
    }

    if((!workingSubtrahend.negative) & workingMinuend.negative)
    {
        workingMinuend.negative = false;
        return ssln_add(workingSubtrahend, workingMinuend);
    }

    difference = ssln_new();

    if(ssln_gt(workingMinuend, workingSubtrahend))
    {
        ssln_set(&difference, ssln_sub(workingMinuend, workingSubtrahend));
        difference.literal = true;
        difference.negative = !difference.negative;
        FREEALL();
        return difference;
    }

    ssln_set(&difference, workingSubtrahend);

    while(++numn < workingMinuend.integerSize || carry)
    {
        worknum =
            CARRYNUM +
            difference.integer[numn]  -
            carry -
            (numn < workingMinuend.integerSize ?
                workingMinuend.integer[numn] : ZERO);

        carry = !(worknum / CARRYNUM);
        difference.integer[numn] = worknum % CARRYNUM;
    }

    numn = difference.integerSize;

    while(--numn && !difference.integer[numn]) difference.integerSize --;

    difference.literal = true;

    FREEALL();
    return difference;
}
