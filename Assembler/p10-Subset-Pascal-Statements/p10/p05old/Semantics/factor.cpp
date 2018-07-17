

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

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

#include "factor.h"

extern ofstream fout;
extern int line;
extern int col;
extern SymbolTable ST;

Exp* factor_1 ( string* id)
{  Sym* S=ST.Find(*id);
   if (!S) yyerror("Semantic error - ID cannot be found");
   if (S) S->Print(fout,0);
   symkind sk=S->Symkind();
   Exp* E=0;
/*   switch (sk) {
       case sk_constant:  //Create an ldc PCode Exp
           E=factor_1_constant((ConstantSymbol*)S);
       break;
       case sk_variable:  //Create a ldx PCode Exp
           E=factor_1_variable((VariableSymbol*)S);
       break;
       case sk_type:      //Not valid - call yyerror
           yyerror("Semantic error - ID cannot be a type name ");
       break;
       case sk_function:  //Call the function
           if (S->IsFunctionSymbol())
              E=factor_1_function((FunctionSymbol*)S);
           else
              yyerror("Semantic error - ID must be a function ");

       break;
   }
*/
   return E;
}

Exp* factor_5(Exp* factor)
{
   Typ* T=factor->Type();
   if (T!=ST.TBoolean()){
       yyerror("Semantic error NOT operand is not Boolean");
   }
   PCode* P=new PCode("","not","","");
   Exp* E=new Exp(factor,0,T,P);
   E->PPrint(fout);
   return E;
}

Exp* factor_6(string* intlit)
{  PCode* P=new PCode("","ldc","i",*intlit);
   Exp* E=new Exp(ST.TInteger(),P);
   E->PPrint(fout);
   return E;
}

Exp* factor_7(string* realit)
{  PCode* P=new PCode("","ldc","r",*realit);
   Exp* E=new Exp(ST.TReal(),P);
   E->PPrint(fout);
   return E;
}

Exp* factor_8(string* chrlit)
{  PCode* P=new PCode("","ldc","c",*chrlit);
   Exp* E=new Exp(ST.TChar(),P);
   E->PPrint(fout);
   return E;
}


