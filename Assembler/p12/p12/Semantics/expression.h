#ifndef EXPRESSION_H
#define EXPRESSION_H

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

Exp* expression(Exp* simple_expression);

Exp* expression(Exp* left_simple_expression,string* relop,Exp* right_simple_expression);

#endif

