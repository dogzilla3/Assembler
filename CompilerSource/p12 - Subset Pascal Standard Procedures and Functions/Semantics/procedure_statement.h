#ifndef PROCEDURE_STATEMENT_H
#define PROCEDURE_STATEMENT_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

#include "../slist.h"
#include "../paslex.h"
#include "../SymbolTable/Label.h"
#include "../SymbolTable/Typ.h"
#include "../SymbolTable/Sym.h"
#include "../SymbolTable/Namespace.h"
#include "../SymbolTable/Locality.h"
#include "../SymbolTable/LocalityStack.h"
#include "../SymbolTable/SymbolTable.h"
#include "../SymbolTable/PCode.h"
#include "../SymbolTable/Exp.h"

Exp* procedure_statement(string*);

Exp* procedure_statement(string*, SList<Exp*>*);

#endif

