#ifndef SIMPLE_EXP_H
#define SIMPLE_EXP_H

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

Exp* simple_expression(Exp*);

Exp* simple_expression(string*, Exp*);

Exp* simple_expression(Exp*, string*, Exp*);

#endif
