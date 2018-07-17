#ifndef subprogram_prolog_h
#define subprogram_prolog_h 1

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
#include "../SymbolTable/Label.h"

#include "../SymbolTable/PCode.h"
#include "../SymbolTable/Exp.h"
#include "factor.h"

SList<Exp*>* subprogram_prolog(SubprogramSymbol* S);
#endif

