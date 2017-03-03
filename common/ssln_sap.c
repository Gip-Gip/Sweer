/* ssln_sap - combines the base and source string

ARGUMENTS:

string base - the base string
string source - the string being appended to the base
bool freeBase - free the base
bool freeSource - free the source

VARIABLES:

string out - the string being returned

*/

#include <ssln_sap.h>

string ssln_sap(string base, string source, bool freeBase, bool freeSource)
{
    string out = calloc(strlen(base) + strlen(source) + STRALLOC,
                        sizeof(character));

    strcpy(out, source);
    strcat(out, base);

    if(freeBase) free(base);
    if(freeSource) free(source);

    return out;
}
