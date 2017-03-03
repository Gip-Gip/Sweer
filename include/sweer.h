/* sweer.h - a header for everything Sweer

ENUMS:

TYPEDEFS:

DEFINITIONS:

MACROS:

*/

#ifndef SWEER_H

#ifndef NULL
#define NULL
#endif

/* TYPEDEFS */

typedef long unsigned int natural;
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

/* VARIABLES */

extern string ssln_numTable;

/* FUNCTIONS */

extern ssln ssln_new(void);
extern ssln ssln_set(ssln *, ssln);
extern ssln ssln_adi(ssln *);
extern ssln ssln_i2n(natural);
extern void ssln_rid(ssln);
extern bool ssln_cmp(ssln, ssln);
extern bool ssln_gt(ssln, ssln);
extern ssln ssln_add(ssln, ssln);
extern ssln ssln_sub(ssln, ssln);
extern ssln ssln_div(ssln, ssln);
extern ssln ssln_mod(ssln, ssln);
extern string ssln_n2s(ssln, natural);

#define SWEER_H NULL
#endif
