#ifndef subprogram_head_h
#define subprogram_head_h 1
//---------------------------------------------------------
//File subprogram_head.h defines semantics for the production
//subprogram_head->PROGRAM ID program_parameters ;
//---------------------------------------------------------
//Author: Thomas R. Turner
//E-Mail: trturner@uco.edu
//Date:   February, 2012
//---------------------------------------------------------
//Copyright February, 2012 by Thomas R. Turner
//Do not reproduce without permission from Thomas R. Turner
//---------------------------------------------------------
//---------------------------------------------------------------------
//C++ inlcude files
//---------------------------------------------------------------------
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
SubprogramSymbol* subprogram_head(string id,SList<VariableSymbol*>* VL,Typ* T);
SubprogramSymbol* subprogram_head(string id,SList<VariableSymbol*>* VL);

#endif
