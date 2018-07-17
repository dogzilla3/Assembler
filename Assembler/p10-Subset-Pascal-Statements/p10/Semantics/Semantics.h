/*
* -------------------------------------------------------------------------
* Author: Gregory Levy
* Student ID: *20444120
* E-Mail: glevy@uco.edu
* Course: CMSC 4173 ? Translator Design
* CRN: 25838, Spring, 2018
* Project: p02 - Subset Pascal Parser
* Due: January 24, 2018
* Account: tt072
*
* Author: William Bohanan
* Student ID: *20276952
* E-Mail: wbohanan@uco.edu
* Course: CMSC 4173 ? Translator Design
* CRN: 25838, Spring, 2018
* Project: p02 - Subset Pascal Parser
* Due: January 24, 2018
* Account: tt067
* -------------------------------------------------------------------------
*
*
* -------------------------------------------------------------------------
* Typ.h Defines Subset Pascal Types
* -------------------------------------------------------------------------
*/

#ifndef program_h
#define program_h 1

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
#include "../Semantics/Semantics.h"
#include "../SymbolTable/PCode.h"
#include "../SymbolTable/Exp.h"
#include "factor.h"

using namespace std;


void program (SubprogramSymbol* S,SList<Exp*>* compound_statement);
void program (void);
SubprogramSymbol* program_head (string);
SList<Exp*>* Program_body(SList<Exp*>* compound_statement);
void subprogram_declaration (SubprogramSymbol* S,SList<Exp*>* compound_statement);
void subprogram_declaration (void);
Typ* standard_type (string);
SList <VariableSymbol*>* subprogram_parameters ();
SList <VariableSymbol*>* subprogram_parameters (SList<VariableSymbol*>*);
void variable_declarations (SList<string>*, Typ* );
Typ* type (Typ*);
Typ* type (string, string, Typ*);
SList<VariableSymbol*>* parameter_list (SList<string>*, Typ*);
SList<VariableSymbol*>* parameter_list (SList<VariableSymbol*>*, SList<string>*, Typ*);
SList<string>* id_list (string*);
SList<string>* id_list (SList<string>*, string*);
static Subprogram* ParameterList (SList<VariableSymbol*>*, Typ*);
static void InsertVariables (SList<VariableSymbol*>*);
void subprogram_head (string, SList<VariableSymbol*>*);
void subprogram_head (string, SList<VariableSymbol*>*, Typ*);

void subprogram_head (string, SList<VariableSymbol*>*, Typ*,int);
void subprogram_head (string, SList<VariableSymbol*>*,int);
SList<Exp*>* program_epilog(SubprogramSymbol* S);
SList<Exp*>* subprogram_prolog(SubprogramSymbol* S);
SList<Exp*>* subprogram_epilog(SubprogramSymbol* S,SList<Exp*>* compound_statement);


#endif
