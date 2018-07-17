

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

#include "../slist.h"
#include "../paslex.h"
#include "../paspar.h"
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

#include "procedure_statement.h"
#include "usersubprogram.h"

extern ofstream pcout;
extern ofstream fout;
extern int line;
extern int col;
extern SymbolTable ST;

Exp* StandardProcedure(StandardProcedureSymbol* S)
{   PCode* P=new PCode("","csp","",S->CSPID());
    Exp* E=new Exp(ST.TVoid(),P);
    return E;
}

Exp* procedure_statement(string* id)
{  Sym* S=ST.Find(*id);
   SList<Exp*>* e=new SList<Exp*>;
   if (!S) yyerror("Semantic error - ID cannot be found");
   if (S->IsProcedureSymbol())
       return UserSubprogram((SubprogramSymbol*)S,e);
   else if (S->IsStandardProcedureSymbol() )
       return StandardProcedure((StandardProcedureSymbol*)S);
   else yyerror("Semantic error - ID must be a procedure");
}

void rvaluetolvalue(SList<Exp*>* e)
{
    for (e->First();!e->IsEol();e->Next()) {
        Exp* E=e->Member();
        PCode* p=E->FetchPCode();
        if (   (p->Op()=="lvb")
            || (p->Op()=="lvc")
            || (p->Op()=="lvi")
            || (p->Op()=="lvr")
           ) {
            p->StoreOp("lda");
        }
    }
}


Exp* StandardProcedure(StandardProcedureSymbol* S, SList<Exp*>* e)
{
    PCode* P;
    Exp* E=0;
    if (   (S->Id()=="readchar")
        || (S->Id()=="readinteger")
        || (S->Id()=="readreal")
        || (S->Id()=="readstring")
       ) {
        rvaluetolvalue(e);
    }
    //--------------------------------------------------------------------
    //Traverse the list of argument-expressions and create an arg-pcode
    //for each expression
    //--------------------------------------------------------------------
    for (e->First();!e->IsEol();e->Next()) {
       Exp* A=e->Member();
       P=new PCode("","arg","","");
       E=new Exp(E,A,ST.TVoid(),P);
    }
    P=new PCode
        (""                             //Label
        ,"csp"                          //P-Code Op - Call Standard Procedure
        ,""
        ,S->CSPID()
        );
    E=new Exp(E,0,ST.TVoid(),P);
    E->PPrint(fout);
    return E;
}

Exp* procedure_statement(string* id, SList<Exp*>* EL)
{  Sym* S=ST.Find(*id);
   if (!S) yyerror("Semantic error - ID cannot be found");
   if (S->IsProcedureSymbol())
       return UserSubprogram((SubprogramSymbol*)S,EL);
   else if (S->IsStandardProcedureSymbol() )
       return StandardProcedure((StandardProcedureSymbol*)S,EL);
   else yyerror("Semantic error - ID must be a procedure");
}

