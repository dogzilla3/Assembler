//-------------------------------------------------------------------------
//File compound_statement.cpp contains implementations for the following 
//productions: 
//compound_statement -> BEGIN optional_statements END
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
//Function prototypes are given in file compound_statement.h
//-------------------------------------------------------------------------
#include "compound_statement.h"

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
