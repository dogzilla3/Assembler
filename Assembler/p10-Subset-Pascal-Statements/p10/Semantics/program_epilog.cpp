
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
//---------------------------------------------------------------------
//Supporting utilities
//---------------------------------------------------------------------
#include "../slist.h"
#include "../yyerror.h"
//---------------------------------------------------------------------
//Symbol Table
//---------------------------------------------------------------------
#include "../SymbolTable/Typ.h"
#include "../SymbolTable/Sym.h"
#include "../SymbolTable/Namespace.h"
#include "../SymbolTable/Locality.h"
#include "../SymbolTable/LocalityStack.h"
#include "../SymbolTable/SymbolTable.h"
#include "../SymbolTable/Label.h"
//---------------------------------------------------------------------
//P-Code and Expression Trees
//---------------------------------------------------------------------
#include "../SymbolTable/PCode.h"
#include "../SymbolTable/Exp.h"
#include "factor.h"
#include "../Height.h"

extern ofstream fout;
extern ofstream pcout;
extern int line;
extern int col;
extern SymbolTable ST;
extern Label L;

SList<Exp*>* program_epilog(SubprogramSymbol* S)
{   //-----------------------------------------------------------------
    //Create a List of expression for the program epilog
    //-----------------------------------------------------------------
    SList<Exp*>* L=new SList<Exp*>;

    //-----------------------------------------------------------------
    //Create and insert the mark stack pcode that creates the
    //stack mark for the program
    //-----------------------------------------------------------------
    PCode* P=new PCode("","mst","0","");
    Exp* E=new Exp(ST.TVoid(),P);
    L->Insert(E);

    //-----------------------------------------------------------------
    //Create and insert the call to the program body
    //-----------------------------------------------------------------
    P=new PCode("","cup","0",S->ELabel());
    E=new Exp(ST.TVoid(),P);
    L->Insert(E);

    //-----------------------------------------------------------------
    //Create and insert the stop instruction to halt the p-code
    //interpreter
    //-----------------------------------------------------------------
    P=new PCode("","stp","","");
    E=new Exp(ST.TVoid(),P);
    L->Insert(E);

    return L;
}

