

#ifndef subprogram_parameters_h
#define subprogram_parameters_h 1

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "../slist.h"
#include "../SymbolTable/Typ.h"
#include "../SymbolTable/Sym.h"
#include "../SymbolTable/Label.h"
#include "../SymbolTable/Namespace.h"
#include "../SymbolTable/Locality.h"
#include "../SymbolTable/LocalityStack.h"
#include "../SymbolTable/SymbolTable.h"

using namespace std;

//---------------------------------------------------------------------
//Semantic include files
//---------------------------------------------------------------------
//subprogram_parameters->empty
//---------------------------------------------------------------------
SList<VariableSymbol*>* subprogram_parameters(void);
//---------------------------------------------------------------------
//subprogram_parameters->LPAREN parameter_list RPAREN
//---------------------------------------------------------------------
SList <VariableSymbol*>* subprogram_parameters(SList<VariableSymbol*>* V);
#endif
