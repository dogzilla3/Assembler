

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
#include "../SymbolTable/Label.h"
#include "../SymbolTable/Typ.h"
#include "../SymbolTable/Sym.h"
#include "../SymbolTable/Namespace.h"
#include "../SymbolTable/Locality.h"
#include "../SymbolTable/LocalityStack.h"
#include "../SymbolTable/SymbolTable.h"
#include "../SymbolTable/PCode.h"
#include "../SymbolTable/Exp.h"
#include "variable.h"

extern ofstream fout;
extern int line;
extern int col;
extern SymbolTable ST;

Exp* variable_symbol(VariableSymbol* V)
{   int ll=ST.LexicalLevel()-V->LexicalLevel();
    PCode* P=new PCode("","lda",ll,V->Address());
    Exp* E=new Exp(V->Type(),P);
    E->Print(fout);
    return E;
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
Exp* function_symbol(FunctionSymbol* F)
{   PCode* P=new PCode("","lda",0,0);
    Exp* E=new Exp(F->ReturnType(),P);
    E->Print(fout);
    return E;
}


Exp* variable(string* id)
{
	Sym* S=ST.Find(*id);
	if (!S) yyerror("Semantic error - ID cannot be found");
	if (S) S->Print(fout,0);
	symkind sk=S->Symkind();
	Exp* E=0;
	SList<Exp*>* e=new SList<Exp*>;
	
	switch (sk) {
		case symkind_variable:
            		return variable_symbol((VariableSymbol*)S);
        		break;
        	case symkind_function:
            		return function_symbol((FunctionSymbol*)S);
        		break;
        	default:
            		yyerror("Semantic error - ID must be a variable or a function");
    	}
    	return E;

}

Exp* variable(string* id, Exp* e)
{
    	Sym* S=ST.Find(*id);       //Find the array identifier
    	if (!S) yyerror("Semantic error - ID cannot be found");
    	if (!S->IsVariableSymbol()) yyerror("Semantic error: identifier is not a variable");
    	VariableSymbol* V=(VariableSymbol*)S;
    
	Typ* T=V->Type();         //Obtain the array type
    	if (!T->IsArray()) yyerror("Semantic error: identifier is not an array");
    	Array* AT=(Array*)T;
    	Typ* ET=e->Type();         //Obtain the index expression type
    	if (!ET->IsInteger()) yyerror("Semantic error: index expression is not an integer");
    	PCode* P;                  //A pointer to a p-code for general use
    	Exp* L;                    //Left expression pointer
    	Exp* R;                    //Right expression pointer
    	int ll=ST.LexicalLevel()-V->LexicalLevel();
    	int a=V->Address();
    	P=new PCode("","lda",ll,a);
    	R=new Exp(ST.TAddress(),P);

	e->LeftAppend(R);
    
	Range* IT=AT->IndexType();
    	string lo=IT->LoBound();
    	P=new PCode("","ldc","i",lo);
    	R=new Exp(ST.TInteger(),P);
    	P=new PCode("","sbi","","");
    	L=new Exp(e,R,ST.TInteger(),P);
    
	int stride=AT->Stride();
    	P=new PCode("","ixa","",stride);
    	Typ* ELT=AT->ElementType();
    	L=new Exp(L,0,ELT,P);
    	L->Print(fout);
    	return L;
}

