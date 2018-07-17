#ifndef statement_list
#define statement_list 1
//-------------------------------------------------------------------------
//File statement_list.cpp contains function prototypes for the following 
//productions: 
//statement_list: statement_list -> statement
//statement_list: statement_list -> statement_list ; statement
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
#include "../SymbolTable/Label.h"
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
//Function statement_list implements the rule
//statement_list -> statement 
//-------------------------------------------------------------------------
SList<Exp*>* Statement_list(SList<Exp*>* s);
//--------------------------------------------------------------------
//statement_list -> statement_list ; statement 
//--------------------------------------------------------------------
SList<Exp*>* Statement_list(SList<Exp*>* sl,SList<Exp*>* s);
#endif
