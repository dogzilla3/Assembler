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
#include "../SymbolTable/PCode.h"
#include "../SymbolTable/Exp.h"
#include "../Height.h"

extern ofstream fout;
extern ofstream pcout;
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


///program, subprogram epilog and prolog
SList<Exp*>* program_epilog(SubprogramSymbol* S)
{   //-----------------------------------------------------------------
    //Create a List of expression for the program epilog
    //-----------------------------------------------------------------
    SList<Exp*>* L=new SList<Exp*>;

    //-----------------------------------------------------------------
    //Create and insert the mark stack pcode that creates the
    //stack mark for the program
    //-----------------------------------------------------------------
    PCode* P=new PCode("","mst","0","");
    Exp* E=new Exp(ST.TVoid(),P);
    L->Insert(E);

    //-----------------------------------------------------------------
    //Create and insert the call to the program body
    //-----------------------------------------------------------------
    P=new PCode("","cup","0",S->ELabel());
    E=new Exp(ST.TVoid(),P);
    L->Insert(E);

    //-----------------------------------------------------------------
    //Create and insert the stop instruction to halt the p-code
    //interpreter
    //-----------------------------------------------------------------
    P=new PCode("","stp","","");
    E=new Exp(ST.TVoid(),P);
    L->Insert(E);

    return L;
}

SList<Exp*>* subprogram_epilog(SubprogramSymbol* S,SList<Exp*>* compound_statement)
{  SList<Exp*>* L=new SList<Exp*>;
   string tc=S->ReturnType()->TypeChar();
   PCode* P=new PCode("","rtn",tc,"");
   Exp* E=new Exp(ST.TVoid(),P);
   E->Print(fout);
   fout << endl;
   L->Insert(E);
   int spvalue =ST.Offset();
   P=new PCode("#define",S->SPLabel(),spvalue,"");
   E=new Exp(ST.TVoid(),P);
   E->Print(fout);
   fout << endl;
   L->Insert(E);
   Height H;
   //-----------------------------------------------------------------------
   //Find the maximum height of the computation stack, epvalue
   //-----------------------------------------------------------------------
   for (compound_statement->First();!compound_statement->IsEol();compound_statement->Next()) {
       Exp* E=compound_statement->Member();
       H.FindHeight(E);
   }
   fout << endl;
   int epvalue=spvalue+H.Maximum();
   P=new PCode("#define",S->EPLabel(),epvalue,"");
   E=new Exp(ST.TVoid(),P);
   E->Print(fout);
   fout << endl;
   L->Insert(E);
   return L;
}

SList<Exp*>* subprogram_prolog(SubprogramSymbol* S)
{   fout << endl << "SP_P Entered Function" << endl;
    SList<Exp*>* L=new SList<Exp*>;
	S->Print(fout, 5);
fout << endl << "SP_P Created List" << endl;
fout << endl << "EPLabel " << endl;
fout << S->ELabel() << " SPLabel " << S->SPLabel() << endl;
    PCode* P=new PCode(S->ELabel(),"ent","sp",S->SPLabel());
fout << endl << "SP_P Made PCode" << endl;
    Exp* E=new Exp(ST.TVoid(),P);
fout << endl << "SP_P Made Exp" << endl;
    L->Insert(E);
fout << endl << "SP_P Exp into List" << endl;
    P=new PCode("","ent","ep",S->EPLabel());
fout << endl << "SP_P Second PCode" << endl;
    E=new Exp(ST.TVoid(),P);
fout << endl << "SP_P 2nd Exp" << endl;
    L->Insert(E);
fout << endl << "SP_P 2nd Insert" << endl;
    return L;
}


void program (SubprogramSymbol* S,SList<Exp*>* compound_statement)
{
fout << endl << "Entered Function" << endl;
  SList<Exp*>* prolog=subprogram_prolog(S);
  fout << endl << "prolog";
  prolog->Print(fout);
fout << endl << "Through prolog" << endl;
  fout << endl << "compound_statement";
  compound_statement->Print(fout);

  SList<Exp*>* epilog=subprogram_epilog(S,compound_statement);
  fout << endl << "epilog";
  epilog->Print(fout);

  SList<Exp*>* programepilog=program_epilog(S);
  fout << endl << "program epilog";
  programepilog->Print(fout);

  SList <Exp*>* L=new SList<Exp*>;
  L->Append(prolog);
  L->Append(compound_statement);
  L->Append(epilog);
  L->Append(programepilog);

  L->Print(pcout);

  ST.Print (fout);             //Print Locality 1
  ST.PopLocality ();
  ST.Print (fout);             //Print Locality 0
}

SubprogramSymbol* program_head (string id)
{
   SList<VariableSymbol*>* VL=new SList<VariableSymbol*>;
   Subprogram* PL=ParameterList(VL,ST.TVoid());
   ProcedureSymbol* P=new ProcedureSymbol(id,PL,0);

   ST.Insert(P);
   ST.NewLocality();
   return P;
}

SList<Exp*>* Program_body(SList<Exp*>* compound_statement)
{
  return compound_statement;  
}

void subprogram_declaration (void)
{
	ST.Print (fout);
	ST.PopLocality ();
}


void subprogram_declaration (SubprogramSymbol* S,SList<Exp*>* compound_statement)
{
	if (S != NULL)
	{
		cout << "The pointer is not null" << endl;
		string test = S->ELabel ();
		cout << test << endl;

	}
	else
	{
		cout << "The pointer is null" << endl;
	}
	S -> Print (cout, 10);
  SList<Exp*>* prolog=subprogram_prolog(S);
  fout << endl << "prolog";
  prolog->Print(fout);
  fout << endl << "compound_statement";
  compound_statement->Print(fout);
  SList<Exp*>* epilog=subprogram_epilog(S,compound_statement);
  fout << endl << "epilog";
  epilog->Print(fout);
  //-----------------------------------------------------------------------
  //Now, concatenate the prolog, compound_statement, and the epilog into
  //a single list.
  //-----------------------------------------------------------------------
  SList <Exp*>* L=new SList<Exp*>;
  L->Append(prolog);
  L->Append(compound_statement);
  L->Append(epilog);
  //-----------------------------------------------------------------------
  //Now, print the subprogram to the PCode File
  //-----------------------------------------------------------------------
  L->Print(pcout);

  ST.Print(fout);            //Print the symbol table at this lexical level
  ST.PopLocality();         //Pop the current locality

}

void subprogram_head (string id, SList<VariableSymbol*>* VL, Typ* RT)
{
  Subprogram* PL = ParameterList (VL, RT);
  FunctionSymbol* F = new FunctionSymbol (id, PL,ST.LexicalLevel());
  ST.Insert (F);
  ST.NewLocality ();
  InsertVariables (VL);
}

void subprogram_head(string id,SList<VariableSymbol*>* VL)
{
   Subprogram* PL=ParameterList(VL,ST.TVoid());
   ProcedureSymbol* P = new ProcedureSymbol (id, PL, ST.LexicalLevel ());
   ST.Insert (P);
   ST.NewLocality ();
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
  return new Array (I, T);
}


SList<VariableSymbol*>* parameter_list (SList<string>* il, Typ* t)
{
  SList<VariableSymbol*>* vl = new SList<VariableSymbol*>;
  for (il->First (); !il->IsEol (); il->Next ())
  {
    string id = il->Member ();
    VariableSymbol* s = new VariableSymbol (id, t);
    vl->Insert (s);

  }
  return vl;
}

SList<VariableSymbol*>* parameter_list (SList<VariableSymbol*>* vl, SList<string>* il, Typ* t)
{
  for (il->First (); !il->IsEol (); il->Next ())
  {
    string id = il->Member ();
    VariableSymbol* s = new VariableSymbol (id, t);
    vl->Insert (s);
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
  //SList<Typ*>* pl = new SList<Typ*>;
  for (vl->First (); !vl->IsEol (); vl->Next ())
  {
    VariableSymbol* s = vl->Member ();
    ST.Insert (s);
  }
}
