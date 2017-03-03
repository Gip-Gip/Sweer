/* ssln_typ.h - defines the types used by ssln

ENUMS:

TYPEDEFS:

DEFINITIONS:

MACROS:

*/

#ifndef SSLN_TYP_H

#include <ssln_def.h>

typedef long int natural;
typedef unsigned char numeral;
typedef char character;
typedef character * string;

typedef enum {
    none,
    err_errno,
} ssln_error;

typedef enum {
    false,
    true,
    neither,
} bool;

typedef struct {
    bool negative;
    bool literal;
    ssln_error error;
    natural integerSize;
    natural fractionalSize;
    numeral *integer;
    numeral *fractional;
} ssln;

#define SSLN_TYP_H NULL
#endif
