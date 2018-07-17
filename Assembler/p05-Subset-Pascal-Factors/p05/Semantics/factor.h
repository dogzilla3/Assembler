#ifndef FACTOR_H
#define FACTOR_H


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

#include "../slist.h"
#include "../SymbolTable/Typ.h"
#include "../SymbolTable/Sym.h"
#include "../SymbolTable/Namespace.h"
#include "../SymbolTable/Locality.h"
#include "../SymbolTable/LocalityStack.h"
#include "../SymbolTable/SymbolTable.h"
#include "../SymbolTable/PCode.h"
#include "../SymbolTable/Exp.h"

Exp* factor_1 (string*);

Exp* factor_1_constant(ConstantSymbol*);

Exp* factor_1_variable(VariableSymbol*);

Exp* factor_1_function(FunctionSymbol*);

Exp* factor_2(string*, Exp*);

Exp* factor_3(string*, SList<Exp*>*);

Exp* factor_4(Exp*);

Exp* factor_5(Exp*);

Exp* factor_6(string*);

Exp* factor_7(string*);

Exp* factor_8(string*);

#endif
