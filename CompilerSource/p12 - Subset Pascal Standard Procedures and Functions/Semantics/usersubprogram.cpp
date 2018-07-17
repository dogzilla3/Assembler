

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
//---------------------------------------------------------------------
//Supporting utilities
//---------------------------------------------------------------------
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
#include "usersubprogram.h"

extern ofstream pcout;
extern ofstream fout;
extern int line;
extern int col;
extern SymbolTable ST;

//--------------------------------------------------------------------
//if ID is a user function
//1.  Create a node with a MST p-code - this p-code must be printed first
//2.  The nodes of the expression list must occur in the same order as
//    the argument-expressions they represent
//3.  Create a node with a CUP p-code
//                    cup
//                   /
//                 arg
//                / \
//             ...   en
//             /
//          arg
//          / \
//       arg   e2
//       / \
//     mst  e1
//-------------------------------------------------------------------------
//Function UserSubprogram implements the rule
//procedure_statement -> ID ( expression_list )
//procedure_statement -> ID
//factor -> ID ( expression_list )
//factor -> ID *where ID is a function*
//when ID is the name of a user procedure.
//-------------------------------------------------------------------------

Exp* UserSubprogram(SubprogramSymbol* S, SList<Exp*>* e)
{   //--------------------------------------------------------------------
    //Obtain the function type FT, and the return type, RT, of the function
    //--------------------------------------------------------------------
    Typ* RT=S->ReturnType();
    PCode* P;
    Exp* E;
    //--------------------------------------------------------------------
    //Put a mark stack, mst, at the bottom of the list.
    //--------------------------------------------------------------------
    int ll=ST.LexicalLevel()-S->LexicalLevel();
    P=new PCode("","mst",ll,"");
    E=new Exp(ST.TVoid(),P);
    //--------------------------------------------------------------------
    //Traverse the list of argument-expressions and create an arg-pcode
    //for each expression
    //--------------------------------------------------------------------
    for (e->First();!e->IsEol();e->Next()) {
       Exp* A=e->Member();
       P=new PCode("","arg","","");
       E=new Exp(E,A,ST.TVoid(),P);
    }
    //--------------------------------------------------------------------
    //Create the cup-pcode and node
    //--------------------------------------------------------------------
    int pc=S->ParameterCount();
    P=new PCode
        (""                             //Label
        ,"cup"                          //P-Code Op - Call User Procedure
        ,pc                             //Operand 1 - Parameter Count
        ,S->ELabel()                    //Operand 2 - Entry Label
        );
    E=new Exp(E,0,RT,P);
    E->Print(fout);
    return E;
}

