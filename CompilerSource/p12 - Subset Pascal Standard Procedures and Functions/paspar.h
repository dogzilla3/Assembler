/*
* -------------------------------------------------------------------------
* Author: Gregory Levy
* Student ID: *20444120
* E-Mail: glevy@uco.edu
* Course: CMSC 4173 – Translator Design
* CRN: 21175, Spring, 2017
* Project: p01 - Subset Pascal Scanner
* Due: January 24, 2018
* Account: tt072
*
* Author: William Bohanan
* Student ID: *20276952
* E-Mail: wbohanan@uco.edu
* Course: CMSC 4173 – Translator Design
* CRN: 25838, Spring, 2018
* Project: p02 - Subset Pascal Parser
* Due: January 24, 2018
* Account: tt072
* -------------------------------------------------------------------------
*
*
*/
#ifndef PASPAR_H
#define PASPAR_H

#include "paslex.h"

#ifndef __cplusplus
extern "C"
#endif
int yyparse (void);
#endif
class Parser : public Scan {
public:
	Parser(FILE* i):Scan(i){}
	int Parse(void) { return yyparse(); }
};
