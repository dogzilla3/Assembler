#ifndef COERCETOREAL_H
#define COERCETOREAL_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

#include "../slist.h"
#include "../yyerror.h"
#include "../SymbolTable/Typ.h"
#include "../SymbolTable/Sym.h"
#include "../SymbolTable/Namespace.h"
#include "../SymbolTable/Locality.h"
#include "../SymbolTable/LocalityStack.h"
#include "../SymbolTable/SymbolTable.h"
#include "../SymbolTable/PCode.h"
#include "../SymbolTable/Exp.h"

//--------------------------------------------------------------------
//Function CoerceLeftExpressionToReal coerces the left expression to
//real if the left expression has type integer and the right expression
//has type real.
//--------------------------------------------------------------------
Exp* CoerceLeftExpressionToReal(Exp*, Exp*);

//--------------------------------------------------------------------
//Function CoerceRightExpressionToReal coerces the right expression to
//real if the right expression has type integer and the left expression
//has type real.
//--------------------------------------------------------------------
Exp* CoerceRightExpressionToReal(Exp*, Exp*);

#endif
