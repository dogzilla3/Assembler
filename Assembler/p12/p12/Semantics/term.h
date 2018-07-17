#ifndef TERM_H
#define TERM_H

/*
* -------------------------------------------------------------------------
* Author: Gregory Levy
* Student ID: *20444120
* E-Mail: glevy@uco.edu
* Course: CMSC 4173 ? Translator Design
* CRN: 25838, Spring, 2018
* Project: p02 - Subset Pascal Parser
* Due: January 24, 2018
* Account: tt072
*
* Author: William Bohanan
* Student ID: *20276952
* E-Mail: wbohanan@uco.edu
* Course: CMSC 4173 ? Translator Design
* CRN: 25838, Spring, 2018
* Project: p02 - Subset Pascal Parser
* Due: January 24, 2018
* Account: tt067
* -------------------------------------------------------------------------
*
*
* -------------------------------------------------------------------------
* Typ.h Defines Subset Pascal Types*********************************************************************change this
* -------------------------------------------------------------------------
* 
* 
* -------------------------------------------------------------------------
* Grammar for terms
* -------------------------------------------------------------------------
* term -> factor
* term -> term * factor
* term -> term / factor
* term -> term div factor
* term -> term mod factor
* term -> term and factor
*
*
*/


#include "../slist.h"
#include "../SymbolTable/Typ.h"
#include "../SymbolTable/Sym.h"
#include "../SymbolTable/Namespace.h"
#include "../SymbolTable/Locality.h"
#include "../SymbolTable/LocalityStack.h"
#include "../SymbolTable/SymbolTable.h"
#include "../SymbolTable/PCode.h"
#include "../SymbolTable/Exp.h"

using namespace std;

Exp* termMultFactor (Exp*, Exp*);
Exp* termSlashFactor (Exp*, Exp*);
Exp* termDivFactor (Exp*, Exp*);
Exp* termModFactor (Exp*, Exp*);
Exp* termAndFactor (Exp*, Exp*);
Exp* term(Exp*);
Exp* term(Exp*, string*, Exp*);

#endif
