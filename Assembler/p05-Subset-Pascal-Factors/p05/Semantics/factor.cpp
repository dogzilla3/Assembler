

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

#include "../slist.h"

#include "../paslex.h"
#include "../paspar.h"

#include "../SymbolTable/yyerror.h"
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
{
   Sym* S=ST.Find(*id);
   if (!S) yyerror("Semantic error - ID cannot be found");
   if (S) S->Print(fout,0);
   symkind sk = S->Symkind();
   Exp* E=0;
   switch (sk) {
       case symkind_constant:  //Create an ldc PCode Exp
           E=factor_1_constant((ConstantSymbol*)S);
       break;
       case symkind_variable:  //Create a ldx PCode Exp
           E=factor_1_variable((VariableSymbol*)S);
       break;
       case symkind_type:      //Not valid - call yyerror
           yyerror("Semantic error - ID cannot be a type name ");
       break;
       case symkind_function:  //Call the function
           if (S->IsFunctionSymbol())
           {         
              E=factor_1_function((FunctionSymbol*)S);      
           }

           else
              yyerror("Semantic error - ID must be a function ");
       break;
   }

   return E;
}

Exp* factor_1_constant(ConstantSymbol* S)
{
    Typ* T=S->Type();
    string cv=S->ConstantValue();
    PCode* P=new PCode
        (""
        ,"ldc"
        ,T->TypeChar()
        ,cv
        );
    Exp* E=new Exp(T,P);
    E->PPrint(fout);
    return E;
}

Exp* factor_1_variable(VariableSymbol* S)
{
    Typ* T=S->Type();
    string op="lv" + T->TypeChar();
    int ll=ST.LexicalLevel()-S->LexicalLevel();
    int a=S->Address();
    PCode* P=new PCode("",op,ll,a);
    Exp* E=new Exp(T,P);
    E->PPrint(fout);
    return E;
}

Exp* factor_1_function(FunctionSymbol* S)
{
    Typ* T=S->Type();
    Subprogram* F;
    if (T->IsSubprogram()) F=(Subprogram*)T;
    Typ* RT=F->ReturnType();
    PCode* P;
    Exp* E;
    int ll=ST.LexicalLevel()-S->LexicalLevel();
    P=new PCode("","mst",ll,"");
    E=new Exp(ST.TVoid(),P);
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


Exp* factor_2(string* id,Exp* e)
{
   //------------------------------------------------------------------
   //------------------------------------------------------------------
   Sym* S=ST.Find(*id);       //Find the array identifier
   if (!S) yyerror("Semantic error - ID cannot be found");
   if (!S->IsVariableSymbol()) yyerror("Semantic error: identifier is not a variable");
   VariableSymbol* V=(VariableSymbol*)S;
   //------------------------------------------------------------------
   //Validate that the id is an array
   //------------------------------------------------------------------
   Typ* T=V->Type();         //Obtain the array type
   if (!T->IsArray()) yyerror("Semantic error: identifier is not an array");
   Array* AT=(Array*)T;
   //------------------------------------------------------------------
   //Validate that the index expression type is an integer
   //------------------------------------------------------------------
   Typ* ET=e->Type();         //Obtain the index expression type
   if (!ET->IsInteger()) yyerror("Semantic error: index expression is not an integer");
   //------------------------------------------------------------------
   //------------------------------------------------------------------
   PCode* P;                  //A pointer to a p-code for general use
   Exp* L;                    //Left expression pointer
   Exp* R;                    //Right expression pointer
   //------------------------------------------------------------------
   //Load the base address of the array.
   //------------------------------------------------------------------
   int ll=ST.LexicalLevel()-V->LexicalLevel();
   int a=V->Address();
   P=new PCode("","lda",ll,a);
   R=new Exp(ST.TAddress(),P);
   //------------------------------------------------------------------
   //Append R on the left-most side of the index expression e
   //------------------------------------------------------------------
   e->LeftAppend(R);
   
   Range* IT=AT->IndexType();
   string lo=IT->LoBound();
   P=new PCode("","ldc","i",lo);
   R=new Exp(ST.TInteger(),P);
   P=new PCode("","sbi","","");
   L=new Exp(e,R,ST.TInteger(),P);
   //------------------------------------------------------------------
   //Next, obtain the stride, the distance between elements of the array
   //------------------------------------------------------------------
   int stride=AT->Stride();
   P=new PCode("","ixa","",stride);
   L=new Exp(L,0,ST.TAddress(),P);
   //------------------------------------------------------------------
   //Employ the load-indirect, ind, p-code to fetch the element
   //------------------------------------------------------------------
   Typ* ELT=AT->ElementType();
   string tc=ELT->TypeChar();
   P=new PCode("","ind",tc,"");
   L=new Exp(L,0,ELT,P);
   L->Print(fout);
   return L;
}

Exp* UserFunction(FunctionSymbol* S,SList<Exp*>* e)
{  //--------------------------------------------------------------------
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

Exp* StandardFunction(StandardFunctionSymbol* S,SList<Exp*>* e)
{
   /*PCode* P;
   //--------------------------------------------------------------------
   //All Standard Functions have one and only one argument
   //--------------------------------------------------------------------
   e->First();
   Exp* E=e->Member();
   Typ* A=E->Type();
   string op=S->CSPID();
   Typ* F;
   if (op=="dec"||op=="inc") F=A;
   if (op=="rnd"||op=="trc") F=ST.TInteger();
   if (op=="chr") F=ST.TChar();
   if (op=="ord") F=ST.TInteger();
   if ((op=="abs") && (A==ST.TInteger())) op="abi";
   if ((op=="abs") && (A==ST.TReal())) op="abr";
   P=new PCode
       (""                             //Label
       ,op                             //P-Code instruction for the function
       ,""
       ,""
       );
   E=new Exp(E,0,F,P);
   return E;
   return 0;*/
}


Exp* factor_3(string* id,SList<Exp*>* e)
{
   Sym* S=ST.Find(*id);       //Find the function identifier
   //--------------------------------------------------------------------
   //Validate that (1) the identifier is in the symbol table and
   //(2) that the identifier is a function symbol
   //--------------------------------------------------------------------
   if (!S) yyerror("Semantic error - ID cannot be found");
   if (S->IsFunctionSymbol())
       return UserFunction((FunctionSymbol*)S,e);
   else if (S->IsStandardFunctionSymbol())
       return StandardFunction((StandardFunctionSymbol*)S,e);
   else yyerror("Semantic error - ID must be function");
   return 0;
}
//--------------------------------------------------------------------
//Function factor_4 implements the rule
//factor -> ( expression )
//--------------------------------------------------------------------
Exp* factor_4(Exp* E)
{
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


