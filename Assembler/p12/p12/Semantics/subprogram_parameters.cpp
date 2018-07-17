

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
#include "subprogram_parameters.h"

using namespace std;

extern ofstream tfs;
extern int line;
extern int col;
extern Label L;
//---------------------------------------------------------------------
//Global variables defined in paspar.y
//---------------------------------------------------------------------
extern SymbolTable ST;        //The SymbolTable
//---------------------------------------------------------------------
//subprogram_parameters->empty
//---------------------------------------------------------------------
List <VariableSymbol*>* subprogram_parameters(void)
{   return new List<VariableSymbol*>;
}
//---------------------------------------------------------------------
//subprogram_parameters->LPAREN parameter_list RPAREN
//---------------------------------------------------------------------
List <VariableSymbol*>* subprogram_parameters(List<VariableSymbol*>* V)
{   return V;
}
