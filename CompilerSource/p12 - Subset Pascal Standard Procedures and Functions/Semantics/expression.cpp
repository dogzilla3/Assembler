

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "../slist.h"
#include "../paslex.h"
#include "../paspar.h"
#include "../yyerror.h"
#include "../SymbolTable/Typ.h"
#include "../SymbolTable/Sym.h"
#include "../SymbolTable/Namespace.h"
#include "../SymbolTable/Locality.h"
#include "../SymbolTable/LocalityStack.h"
#include "../SymbolTable/SymbolTable.h"
#include "../SymbolTable/PCode.h"
#include "../SymbolTable/Exp.h"
#include "expression.h"

using namespace std;

extern ofstream pcout;
extern ofstream fout;
extern int line;
extern int col;
extern SymbolTable ST;

Exp* expression(Exp* simple_expression)
{
   return simple_expression;
}

Exp* expression(Exp* LE,Exp* RE,string relop)
{  Typ* LT=LE->Type();
   Typ* RT=RE->Type();
   Typ* B=ST.TBoolean();
   if (LT!=RT) yyerror("Semantic Error:unequal left and right types.");
   string typechar=LT->TypeChar();
   PCode* P=new PCode("",relop,typechar,"");
   Exp* E=new Exp(LE,RE,B,P);
   E->Print(fout);
   return E;
}

Exp* expression(Exp* left_simple_expression,string* relop,Exp* right_simple_expression)
{   if (*relop=="=" ) return expression(left_simple_expression,right_simple_expression,"equ");
    if (*relop=="<>") return expression(left_simple_expression,right_simple_expression,"neq");
    if (*relop=="<" ) return expression(left_simple_expression,right_simple_expression,"les");
    if (*relop=="<=") return expression(left_simple_expression,right_simple_expression,"leq");
    if (*relop==">" ) return expression(left_simple_expression,right_simple_expression,"grt");
    if (*relop==">=") return expression(left_simple_expression,right_simple_expression,"geq");
    yyerror("Semantic error: invalid relop");
}
