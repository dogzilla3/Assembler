../SymbolTable/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

#include "../slist.h"
#include "../yyerror.h"

#include "../SymbolTable/Typ.h"
#include "../SymbolTable/Sym.h"
#include "../SymbolTable/Namespace.h"
#include "../SymbolTable/Locality.h"
#include "../SymbolTable/LocalityStack.h"
#include "../SymbolTable/SymbolTable.h"
#include "../SymbolTable/Label.h"

#include "../SymbolTable/PCode.h"
#include "../SymbolTable/Exp.h"
#include "factor.h"
#include "../SymbolTable/Height.h"

#include "subprogram_epilog.h"

extern ofstream pcout;
extern ofstream fout;
extern int line;
extern int col;
extern SymbolTable ST;
extern Label L;

SList<Exp*>* subprogram_epilog(SubprogramSymbol* S,SList<Exp*>* compound_statement)
{  SList<Exp*>* L=new SList<Exp*>;
   string tc=S->ReturnType()->TypeChar();
   PCode* P=new PCode("","rtn",tc,"");
   Exp* E=new Exp(ST.TVoid(),P);
   E->Print(fout);
   fout << endl;
   L->Insert(E);
   int spvalue =ST.Offset();
   P=new PCode("#define",S->SPLabel(),spvalue,"");
   E=new Exp(ST.TVoid(),P);
   E->Print(fout);
   fout << endl;
   L->Insert(E);
   Height H;
   //-----------------------------------------------------------------------
   //Find the maximum height of the computation stack, epvalue
   //-----------------------------------------------------------------------
   for (compound_statement->First();!compound_statement->IsEol();compound_statement->Next()) {
       Exp* E=compound_statement->Member();
       H.FindHeight(E);
   }
   fout << endl;
   int epvalue=spvalue+H.Maximum();
   P=new PCode("#define",S->EPLabel(),epvalue,"");
   E=new Exp(ST.TVoid(),P);
   E->Print(fout);
   fout << endl;
   L->Insert(E);
   return L;
}


