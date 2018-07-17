//-------------------------------------------------------------------------
//File statement.cpp contains functions for the following productions: 
//statement -> variable := expression
//statement -> procedure_statement
//statement -> compound_statement
//statement -> IF expression THEN statement ELSE statement
//statement -> WHILE expression DO statement
//-------------------------------------------------------------------------
//---------------------------------------------------------------------
//Author:   Thomas R. Turner
//E-Mail:   trturner@uco.edu
//Date:     March, 2012
//---------------------------------------------------------------------
//Copyright March, 2012 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//---------------------------------------------------------------------
//C++ inlcude files
//---------------------------------------------------------------------
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
//-------------------------------------------------------------------------
//statement.h
//-------------------------------------------------------------------------
#include "statement.h"
//---------------------------------------------------------------------
//Externals
//---------------------------------------------------------------------
extern ofstream pcout;
extern ofstream fout;
extern int line;
extern int col;
extern SymbolTable ST;
extern Label L;
//-------------------------------------------------------------------------
//Function statement implements the rule
//statement -> variable := expression
//-------------------------------------------------------------------------
SList<Exp*>* statement(Exp* variable,Exp* expression)
{   if (variable->Type()!=expression->Type()) yyerror("Semantic error:Assignment type mismatch");
    string tc=expression->Type()->TypeChar();
    PCode* P=new PCode("","sti",tc,"");
    Exp* E=new Exp(variable,expression,ST.TVoid(),P);
    E->Print(fout);
    SList<Exp*>* S=new SList<Exp*>;
    S->Insert(E);
    return S;
}
//--------------------------------------------------------------------
//Function statement implements the rule
//statement -> procedure_statement
SList<Exp*>* statement(Exp* procedure_statement)
{   SList<Exp*>* L=new SList<Exp*>;
    L->Insert(procedure_statement);
    return L;
}
//-------------------------------------------------------------------------
//Function statement implements the rule
//statement -> compound_statement
SList<Exp*>* statement(SList<Exp*>* compound_statement)
{   return compound_statement;
}
//-------------------------------------------------------------------------
//Function statement implements the rule
//statement -> IF expression THEN statement ELSE statement
//  expression
//  fjp "elsebegin"
//  true_statement
//  ujp "elseend"
//  elsebegin:
//  else_statement
//  elseend
//-------------------------------------------------------------------------
SList<Exp*>* statement(Exp* expression,SList<Exp*>* then_statement,SList<Exp*>* else_statement)
{   string elsebegin=L.New();           //Create label that begins the else-statement
    PCode* P;
    P=new PCode("","fjp","",elsebegin); //Jump to else-statement if expression is false
    Exp* E;
    E=new Exp(expression,0,ST.TVoid(),P);
    SList<Exp*>* IS=new SList<Exp*>;      //Create an If-Statement
    IS->Insert(E);                      //Insert the fjp expression to the If-Statement
    IS->Append(then_statement);         //Append the then-statement to the If-Statement
    string elseend=L.New();             //Create the label that is placed after the else-statement
    P=new PCode("","ujp","",elseend);   //Jump to the end of the else-statement after completing
                                        //the then-statement
    E=new Exp(ST.TVoid(),P);
    IS->Insert(E);                      //Insert the expression on the list
    P=new PCode(elsebegin,"","","");    //Create a label expression that begins the else-statement
    E=new Exp(ST.TVoid(),P);
    IS->Insert(E);
    IS->Append(else_statement);         //Append the else-statement
    P=new PCode(elseend,"","","");      
    E=new Exp(ST.TVoid(),P);
    IS->Insert(E);                      //Insert the label at the end of the else-statement
    IS->Print(fout);
    return IS;
}
//-------------------------------------------------------------------------
//Function statement implements the rule
//statement -> WHILE expression DO statement
//    whilebegin:
//    expression
//    fjp "whileend"
//    body_statement
//    ujp "whilebegin"
//    whileend:
//-------------------------------------------------------------------------
SList<Exp*>* statement(Exp* expression,SList<Exp*>* body_statement)
{   PCode* P;
    Exp*  E;
    string whilebegin=L.New();          //Create whilebegin label
    string whileend=L.New();            //Create whileend label
    P=new PCode(whilebegin,"","","");
    E=new Exp(ST.TVoid(),P);
    SList<Exp*>* WS=new SList<Exp*>;      
    WS->Insert(E);                      //Insert whilebegin label
    P=new PCode("","fjp","",whileend);
    E=new Exp(expression,0,ST.TVoid(),P);    
    WS->Insert(E);                      //Insert while-test expression and false-jump
    WS->Append(body_statement);         //Append the while-body-statement
    P=new PCode("","ujp","",whilebegin);
    E=new Exp(ST.TVoid(),P);
    WS->Insert(E);                      //Insert unconditional jump to while-test
    P=new PCode(whileend,"","","");
    E=new Exp(ST.TVoid(),P);
    WS->Insert(E);                      //Insert whileend label
    WS->Print(fout);
    return WS;
}
//--------------------------------------------------------------------
