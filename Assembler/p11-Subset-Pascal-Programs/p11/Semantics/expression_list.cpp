

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "../slist.h"
#include "../yyerror.h"
#include "../SymbolTable/Label.h"
#include "../SymbolTable/Typ.h"
#include "../SymbolTable/Sym.h"
#include "../SymbolTable/Namespace.h"
#include "../SymbolTable/Locality.h"
#include "../SymbolTable/LocalityStack.h"
#include "../SymbolTable/SymbolTable.h"
#include "../SymbolTable/PCode.h"
#include "../SymbolTable/Exp.h"
#include "expression_list.h"

using namespace std;

SList<Exp*>* expression_list(Exp* expression)
{  SList<Exp*>* L=new SList<Exp*>;
   L->Insert(expression);
   return L;
}
//--------------------------------------------------------------------
//Expression_2: expression_list -> expression_list , expression
//--------------------------------------------------------------------
SList<Exp*>* expression_list(SList<Exp*>* expression_list,Exp* expression)
{  expression_list->Insert(expression);
   return expression_list;
}


