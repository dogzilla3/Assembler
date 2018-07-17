
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

#include "subprogram_prolog.h"

extern ofstream pcout;
extern ofstream fout;
extern int line;
extern int col;
extern SymbolTable ST;
extern Label L;

SList<Exp*>* subprogram_prolog(SubprogramSymbol* S)
{   SList<Exp*>* L=new SList<Exp*>;
    PCode* P=new PCode(S->ELabel(),"ent","sp",S->SPLabel());
    Exp* E=new Exp(ST.TVoid(),P);
    L->Insert(E);
    P=new PCode("","ent","ep",S->EPLabel());
    E=new Exp(ST.TVoid(),P);
    L->Insert(E);
    return L;
}

