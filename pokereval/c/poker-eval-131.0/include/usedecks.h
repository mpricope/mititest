#ifndef __USEDECKS_H__
#define __USEDECKS_H__

#include "poker_defs.h"

int 
testOmaha8(const char *holestr, const char *boardstr);

int evalOmaha(char * holestr,char * boardstr,uint32 * o_hival,uint32 * o_lowval);

int evalOmahaI(uint32  holeCards[],uint32 boardCards[],uint32 * o_hival,uint32 * o_lowval);

#endif