#ifndef USERSUBPROGRAM_H
#define USERSUBPROGRAM_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
//---------------------------------------------------------------------
//Supporting utilities
//---------------------------------------------------------------------
#include "../slist.h"
#include "../SymbolTable/Label.h"
#include "../SymbolTable/Typ.h"
#include "../SymbolTable/Sym.h"
#include "../SymbolTable/Namespace.h"
#include "../SymbolTable/Locality.h"
#include "../SymbolTable/LocalityStack.h"
#include "../SymbolTable/SymbolTable.h"
#include "../SymbolTable/PCode.h"
#include "../SymbolTable/Exp.h"

//-------------------------------------------------------------------------
//Function UserSubprogram implements the rule
//procedure_statement -> ID ( expression_list )
//procedure_statement -> ID
//factor -> ID ( expression_list )
//factor -> ID *where ID is a function*
//when ID is the name of a user procedure.
//-------------------------------------------------------------------------
Exp* UserSubprogram(SubprogramSymbol*,SList<Exp*>*);
#endif

