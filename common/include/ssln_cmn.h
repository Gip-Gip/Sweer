/* ssln_cmn.h - includes files needed all around the Sweer project

ENUMS:

TYPEDEFS:

DEFINITIONS:

MACROS:

*/

#ifndef SSLN_CMN_H

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ssln_typ.h>
#include <ssln_mac.h>

extern string ssln_numTable[];
extern ssln ssln_eEr();
extern ssln ssln_new(void);
extern ssln ssln_set(ssln *, ssln);
extern ssln ssln_adi(ssln *);
extern ssln ssln_i2n(natural);
extern string ssln_sap(string, string, bool, bool);
extern void ssln_rid(ssln);
extern bool ssln_cmp(ssln, ssln);
extern bool ssln_gt(ssln, ssln);
extern ssln ssln_add(ssln, ssln);
extern ssln ssln_sub(ssln, ssln);
extern ssln ssln_div(ssln, ssln);
extern ssln ssln_mod(ssln, ssln);
extern natural ssln_n2i(ssln);
extern ssln ssln_ras(ssln, natural);

#define SSLN_CMN_H NULL
#endif
