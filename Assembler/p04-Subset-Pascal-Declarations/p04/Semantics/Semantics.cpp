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

extern ofstream fout;
extern int line;
extern int col;
extern Label L;
extern SymbolTable ST;

struct TypeException
{
  TypeException (Sym* s)
  {
    cout << endl << "Error on line " << line;
    cout << " colomn " << col << endl;
    cout << "The symbol shown below is not a type symbol.";
  }
};

void program (void)
{
  ST.Print (fout);             //Print Locality 1
  ST.PopLocality ();
  ST.Print (fout);             //Print Locality 0
}

void program_head (string id)
{
  Sym* p = new ProgramSymbol (id);
  ST.Insert (p);
  ST.NewLocality ();
}

void subprogram_declaration ()
{
  ST.Print (fout);
  ST.PopLocality ();
}

void subprogram_head (string id, SList<VariableSymbol*>* VL, Typ* RT)
{
  Subprogram* PL = ParameterList (VL, RT);
  FunctionSymbol* F = new FunctionSymbol (id, PL,ST.LexicalLevel());
  ST.NewLocality ();
  ST.Insert (F);
  InsertVariables (VL);
}

void subprogram_head(string id,SList<VariableSymbol*>* VL)
{  Subprogram* PL=ParameterList(VL,ST.TVoid());
   ProcedureSymbol* P=new ProcedureSymbol(id,PL, ST.LexicalLevel ());
   ST.NewLocality ();
   ST.Insert(P);
   InsertVariables(VL);
}


Typ* standard_type (string id)
{
  Sym* s = ST.Find (id);
  if (!s->IsTypeSymbol ()) throw TypeException (s);
  s->Print (fout, 0);
  return s->Type ();
}


SList <VariableSymbol*>* subprogram_parameters ()
{
  return new SList<VariableSymbol*>;
}

SList <VariableSymbol*>* subprogram_parameters (SList<VariableSymbol*>* V)
{
  return V;
}

void variable_declarations (SList<string>* il, Typ* t)
{
  for (il->First (); !il->IsEol (); il->Next ())
  {
    string id = il->Member ();
    VariableSymbol* s = new VariableSymbol (id, t, ST.LexicalLevel());
    ST.Insert (s);
  }
}


Typ* type (Typ* T) { return T; }

Typ* type (string lo, string hi, Typ* T)
{
  Typ* I = new Range (ST.TInteger (), lo, hi);
  return new Array ((Range*) I, T);
}


SList<VariableSymbol*>* parameter_list (SList<string>* il, Typ* t)
{
  SList<VariableSymbol*>* vl = new SList<VariableSymbol*>;
  for (il->First (); !il->IsEol (); il->Next ())
  {
    string id = il->Member ();
    VariableSymbol* s = new VariableSymbol (id, t);
    ST.Insert (s);

  }
  return vl;
}

SList<VariableSymbol*>* parameter_list (SList<VariableSymbol*>* vl, SList<string>* il, Typ* t)
{
  for (vl->First (); !vl->IsEol (); vl->Next ())
  {
    string id = il->Member ();
    VariableSymbol* s = new VariableSymbol (id, t);
    ST.Insert (s);

  }
  return vl;
}


SList<string>* id_list (string* s)
{
  SList<string>* l = new SList<string>;
  l->Insert (*s);
  l->Print (fout, " identifier_list =");
  return l;
}

SList<string>* id_list (SList<string>* l, string* s)
{
  l->Insert (*s);
  l->Print (fout, " identifier_list =");
  return l;
}

static Subprogram* ParameterList (SList<VariableSymbol*>* vl, Typ* rt)
{
  SList<Typ*>* pl = new SList<Typ*>;
  for (vl->First (); !vl->IsEol (); vl->Next ())
  {
    VariableSymbol* s = vl->Member ();
    Typ* t = s->Type ();
    pl->Insert (t);
  }
  return new Subprogram (pl, rt);
}

static void InsertVariables (SList<VariableSymbol*>* vl)
{
  SList<Typ*>* pl = new SList<Typ*>;
  for (vl->First (); !vl->IsEol (); vl->Next ())
  {
    VariableSymbol* s = vl->Member ();
    ST.Insert (s);
  }
}
