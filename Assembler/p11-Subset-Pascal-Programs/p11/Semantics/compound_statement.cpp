

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
#include "factor.h"
#include "compound_statement.h"

using namespace std;

extern ofstream fout;
extern ofstream pcout;
extern int line;
extern int col;
extern SymbolTable ST;
extern Label L;

//-------------------------------------------------------------------------
//Function compound_statement implements the rule
//compound_statement -> BEGIN optional_statements END
//-------------------------------------------------------------------------
SList<Exp*>* Compound_statement(SList<Exp*>* os)
{
	os->Print(fout);
	return os;
}
