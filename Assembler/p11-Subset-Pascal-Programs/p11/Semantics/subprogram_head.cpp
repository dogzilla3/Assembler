
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "../slist.h"
#include "../SymbolTable/Typ.h"
#include "../SymbolTable/Sym.h"
#include "../SymbolTable/Label.h"
#include "../SymbolTable/Namespace.h"
#include "../SymbolTable/Locality.h"
#include "../SymbolTable/LocalityStack.h"
#include "../SymbolTable/SymbolTable.h"

using namespace std;


//---------------------------------------------------------------------
//Semantic include files
//---------------------------------------------------------------------
#include "subprogram_head.h"
//---------------------------------------------------------------------
//Functions
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//Externals
//---------------------------------------------------------------------
extern ofstream tfs;
extern int line;
extern int col;
extern Label L;
//---------------------------------------------------------------------
//Global variables defined in paspar.y
//---------------------------------------------------------------------
extern SymbolTable ST;        //The SymbolTable
//---------------------------------------------------------------------
//Function ParameterList creates a parameter list from a list of Variables
//---------------------------------------------------------------------
static Subprogram* ParameterList(SList<VariableSymbol*>* VL,Typ* RT)
{   SList<Typ*>* PL=new SList<Typ*>;
    for (VL->First();!VL->IsEol();VL->Next())
    {   VariableSymbol* S=VL->Member();
        Typ* T=S->Type();
        PL->Insert(T);
    }
    return new Subprogram(PL,RT);
}
//---------------------------------------------------------------------
//Function InsertVariables inserts variables into the symbol table
//---------------------------------------------------------------------
static void InsertVariables(SList<VariableSymbol*>* VL)
{   for (VL->First();!VL->IsEol();VL->Next()) {
        VariableSymbol* S=VL->Member();
        ST.Insert(S);
    }
}
//---------------------------------------------------------------------
//subprogram_head->FUNCTION ID subprogram_parameters COLON standard_type SEMICOLON
//1.  Traverse the list of variable symbols to create list of parameters
//2.  Create a function symbol using the list of parameters created in step 1.
//3.  Insert the function symbol into the symbol table.
//4.  Create a new locality.
//5.  Insert the variable symbols into the symbol table.
//---------------------------------------------------------------------
SubprogramSymbol* subprogram_head(string id,SList<VariableSymbol*>* VL,Typ* RT)
{  Subprogram* PL=ParameterList(VL,RT);
   FunctionSymbol* F=new FunctionSymbol(id,PL,ST.LexicalLevel());
   ST.Insert(F);
   ST.NewLocality();
   InsertVariables(VL);
   return F;
}
//---------------------------------------------------------------------
//subprogram_head->PROCEDURE ID subprogram_parameters SEMICOLON
//1.  Traverse the list of variable symbols to create list of parameters
//2.  Create a procedure symbol using the list of parameters created in step 1.
//3.  Insert the procedure symbol into the symbol table.
//4.  Create a new locality.
//5.  Insert the variable symbols into the symbol table.
//---------------------------------------------------------------------
SubprogramSymbol* subprogram_head(string id,SList<VariableSymbol*>* VL)
{  Subprogram* PL=ParameterList(VL,ST.TVoid());
   ProcedureSymbol* P=new ProcedureSymbol(id,PL,ST.LexicalLevel());
   ST.Insert(P);
   ST.NewLocality();
   InsertVariables(VL);
   return P;
}
