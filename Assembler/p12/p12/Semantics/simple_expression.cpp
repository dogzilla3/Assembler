#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

#include "../slist.h"
#include "../paslex.h"
#include "../paspar.h"
#include "../SymbolTable/Typ.h"
#include "../SymbolTable/Sym.h"
#include "../SymbolTable/Namespace.h"
#include "../SymbolTable/Locality.h"
#include "../SymbolTable/LocalityStack.h"
#include "../SymbolTable/SymbolTable.h"
#include "../SymbolTable/PCode.h"
#include "../SymbolTable/Exp.h"
#include "simple_expression.h"
#include "coercetoreal.h"


extern ofstream fout;
extern int line;
extern int col;
extern SymbolTable ST;

Exp* simple_expression(Exp* term){return term;}

Exp* simple_expression(string* sign,Exp* term)
{
    //------------------------------------------------------------------
    //Emit a semantic error if the term has neither type integer or real
    //------------------------------------------------------------------
    if (!term->IsInteger()&&!term->IsReal())
        yyerror("Semantic error: term must be integer or real");
    //------------------------------------------------------------------
    //Do nothing if the sign is positive "+"
    //------------------------------------------------------------------
    if (*sign=="+") return term;
    //------------------------------------------------------------------
    //------------------------------------------------------------------
    PCode* P;
    Exp*  E;
    //------------------------------------------------------------------
    //  Term must have type integer or real
    //  Generate a negate integer, ngi, if the term has type integer
    //  Generate a negate real, ngr, if the term has type real
    //------------------------------------------------------------------
    if (term->IsInteger()) {
        P=new PCode("","ngi","","");
        E=new Exp(term,0,ST.TInteger(),P);
    } else {
        P=new PCode("","ngr","","");
        E=new Exp(term,0,ST.TReal(),P);
    }
    E->Print(fout);
    return E;
}


Exp* add(Exp* l,Exp* r)
{   //--------------------------------------------------------------------
    //Coerce left and right expressions to real if either is integer and
    //the other is real
    //--------------------------------------------------------------------
    l=CoerceLeftExpressionToReal(l,r);
    r=CoerceRightExpressionToReal(l,r);
    //---------------------------------------------------------------------
    //add
    //---------------------------------------------------------------------
    PCode* P;
    Exp* E;
    if (l->IsReal()||r->IsReal()) {
        P=new PCode("","adr","","");
        E=new Exp(l,r,ST.TReal(),P);
    } else {
        P=new PCode("","adi","","");
        E=new Exp(l,r,ST.TInteger(),P);
    }
    E->Print(fout);
    return E;
}
//--------------------------------------------------------------------
//Function subtract creates an expression to subtract the left
//expression from the  right expression
//--------------------------------------------------------------------
Exp* subtract(Exp* l,Exp* r)
{   //--------------------------------------------------------------------
    //Coerce left and right expressions to real if either is integer and
    //the other is real
    //--------------------------------------------------------------------
    l=CoerceLeftExpressionToReal(l,r);
    r=CoerceRightExpressionToReal(l,r);
    //---------------------------------------------------------------------
    //subtract
    //---------------------------------------------------------------------
    PCode* P;
    Exp* E;
    if (l->IsReal()||r->IsReal()) {
        P=new PCode("","sbr","","");
        E=new Exp(l,r,ST.TReal(),P);
    } else {
        P=new PCode("","sbi","","");
        E=new Exp(l,r,ST.TInteger(),P);
    }
    E->Print(fout);
    return E;
}

Exp* disjunction(Exp* l,Exp* r)
{   //--------------------------------------------------------------------
    //Both expressions must be Boolean
    //-------------------------------------------------------------------
    if (!l->IsBoolean()) yyerror("Semantic error: the left expression must be Boolean");
    if (!r->IsBoolean()) yyerror("Semantic error: the right expression must be Boolean");
    //---------------------------------------------------------------------
    //disjunction
    //---------------------------------------------------------------------
    PCode* P=new PCode("","ior","","");
    Exp* E=new Exp(l,r,ST.TBoolean(),P);
    E->Print(fout);
    return E;
}
//--------------------------------------------------------------------
//Function simple_expression -> simple_expression addop term
//--------------------------------------------------------------------
Exp* simple_expression(Exp* simpleexpression, string* addop, Exp* term)
{   if (*addop=="+" ) return add(simpleexpression,term);
    if (*addop=="-" ) return subtract(simpleexpression,term);
    if (*addop=="or") return disjunction(simpleexpression,term);
    yyerror("Semantic error: invalid addop");
}

