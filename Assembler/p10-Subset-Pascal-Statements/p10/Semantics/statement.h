#ifndef statement_h
#define statement_h 1
//-------------------------------------------------------------------------
//File statement.h contains prototypes for the following productions: 
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
//---------------------------------------------------------------------
//P-Code and Expression Trees
//---------------------------------------------------------------------
#include "../SymbolTable/PCode.h"
#include "../SymbolTable/Exp.h"
#include "factor.h"
//-------------------------------------------------------------------------
//Function statement implements the rule
//statement -> variable := expression
SList<Exp*>* statement(Exp*,Exp*);
//--------------------------------------------------------------------
//Function statement implements the rule
//statement -> procedure_statement
SList<Exp*>* statement(Exp*);
//-------------------------------------------------------------------------
//Function statement implements the rule
//statement -> compound_statement
SList<Exp*>* statement(SList<Exp*>*);
//-------------------------------------------------------------------------
//Function statement implements the rule
//statement -> IF expression THEN statement ELSE statement
SList<Exp*>* statement(Exp*,SList<Exp*>*,SList<Exp*>*);
//-------------------------------------------------------------------------
//Function statement implements the rule
//statement -> WHILE expression DO statement
SList<Exp*>* statement(Exp*, SList<Exp*>*);
//--------------------------------------------------------------------
#endif
