/* ssln_gt - compares two SSLNs and sees if the first number is greater than the
             second number

ARGUMENTS:

ssln num1
ssln num2

VARIABLES:

*/

#include <ssln_gt.h>

bool ssln_gt(ssln num1, ssln num2)
{
    ssln cmpnum1 = ssln_new(), cmpnum2 = ssln_new();
    natural numn = num1.integerSize;

    ssln_set(&cmpnum1, num1);
    ssln_set(&cmpnum2, num2);

    if(ssln_cmp(cmpnum1, cmpnum2) || cmpnum2.integerSize > cmpnum1.integerSize)
    {
        FREEALL();
        return false;
    }

    if(cmpnum1.integerSize > cmpnum2.integerSize)
    {
        FREEALL();
        return true;
    }

    while(numn--)
    {
        if(cmpnum1.integer[numn] > cmpnum2.integer[numn])
        {
            FREEALL();
            return true;
        }

        if(cmpnum2.integer[numn] > cmpnum1.integer[numn])
        {
            FREEALL();
            return false;
        }
    }

    FREEALL();
    return false;
}
