/* ssln_i2s - converts integers to the ssln type

ARGUMENTS:

natural num - the integer being converted

VARIABLES:

*/

#include <ssln_i2s.h>

ssln ssln_i2s(natural num)
{
    ssln ret = ssln_new();
    natural numn = 0;

    ret.literal = true;

    while(num)
    {
        ret.integer[numn++] = num & FULLBYTE;
        num >>= BYTESHFT;

        if(num && ssln_adi(&ret).error)
        {
            return ret;
        }
    }

    return ret;
}
