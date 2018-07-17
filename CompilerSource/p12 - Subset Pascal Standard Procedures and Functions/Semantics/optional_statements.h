#ifndef optional_statements
#define optional_statements 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
//---------------------------------------------------------------------
//Supporting utilities
//---------------------------------------------------------------------
#include "../slist.h"
#include "../yyerror.h"
//---------------------------------------------------------------------
//Symbol Table
//---------------------------------------------------------------------
#include "../SymbolTable/Label.h"
#include "../SymbolTable/Typ.h"
#include "../SymbolTable/Sym.h"
#include "../SymbolTable/Namespace.h"
#include "../SymbolTable/Locality.h"
#include "../SymbolTable/LocalityStack.h"
#include "../SymbolTable/SymbolTable.h"
//---------------------------------------------------------------------
//P-Code and Expression Trees
//---------------------------------------------------------------------
#include "../SymbolTable/PCode.h"
#include "../SymbolTable/Exp.h"
#include "factor.h"
//-------------------------------------------------------------------------
//Function optional_statements implements the rule
//optional_statements -> empty
//-------------------------------------------------------------------------
SList<Exp*>* Optional_statements(void);
//--------------------------------------------------------------------
//optional_statements -> statement_list
//--------------------------------------------------------------------
SList<Exp*>* Optional_statements(SList<Exp*>*);
#endif
