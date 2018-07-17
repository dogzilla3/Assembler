#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

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
#include "factor.h"
#include "statement_list.h"

extern ofstream fout;
extern ofstream pcout;
extern int line;
extern int col;
extern SymbolTable ST;
extern Label L;

SList<Exp*>* Statement_list(SList<Exp*>* s)
{   SList<Exp*>* sl=new SList<Exp*>;
    sl->Append(s);
    sl->Print(fout);
    return sl;
}

SList<Exp*>* Statement_list(SList<Exp*>* sl, SList<Exp*>* s)
{   sl->Append(s);
    sl->Print(fout);
    return sl;
}
