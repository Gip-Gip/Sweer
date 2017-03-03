/* ssln_add - adds two sslns together

ARGUMENTS:

ssln aguend
ssln addend

VARIABLES:

*/

#include <ssln_add.h>

ssln ssln_add(ssln aguend, ssln addend)
{
    ssln ret;
    natural numn = INDEXINIT, worknum;
    bool carry = false;

    if(aguend.negative & (!addend.negative))
    {
        aguend.negative = false;
        ret = ssln_sub(aguend, addend);
        ret.negative = !ret.negative;
        return ret;
    }

    if((!aguend.negative) & addend.negative)
    {
        addend.negative = false;
        return ssln_sub(aguend, addend);
    }

    ret = ssln_new();

    ret.literal = true;

    ssln_set(&ret, aguend);


    while(++numn < addend.integerSize || carry)
    {
        if(numn == ret.integerSize) ssln_adi(&ret);

        worknum =
            ret.integer[numn] +
            carry +
            (numn < addend.integerSize ? addend.integer[numn] : ZERO);

        ret.integer[numn] = worknum % CARRYNUM;
        carry = worknum / CARRYNUM;
    }

    FREEALL();

    return ret;
}
