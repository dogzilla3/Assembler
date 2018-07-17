


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "../slist.h"
#include "../paslex.h"
#include "../paspar.h"
#include "../yyerror.h"
#include "../SymbolTable/Typ.h"
#include "../SymbolTable/Sym.h"
#include "../SymbolTable/Namespace.h"
#include "../SymbolTable/Locality.h"
#include "../SymbolTable/LocalityStack.h"
#include "../SymbolTable/SymbolTable.h"
#include "../SymbolTable/PCode.h"
#include "../SymbolTable/Exp.h"
#include "coercetoreal.h"
#include "term.h"

using namespace std;

extern ofstream fout;
extern int line;
extern int col;
extern SymbolTable ST;

//--------------------------------------------------------------------
//Function term -> term * factor
//--------------------------------------------------------------------
Exp* termMultFactor (Exp* term, Exp* factor)
{
  term = CoerceLeftExpressionToReal (term, factor);
  factor = CoerceRightExpressionToReal (term, factor);
  //---------------------------------------------------------------------
  //multiply
  //---------------------------------------------------------------------
  PCode* P;
  Exp* E;
  if (term->IsReal () || factor->IsReal ())
  {
    P = new PCode ("", "mpr", "", "");
    E = new Exp (term, factor, ST.TReal (), P);
  }
  else
  {
    P = new PCode ("", "mpi", "", "");
    E = new Exp (term, factor, ST.TReal (), P);
  }
  E->Print(fout);
  return E;
}
//--------------------------------------------------------------------
//Function term -> term / factor
//--------------------------------------------------------------------
Exp* termSlashFactor (Exp* term, Exp* factor)
{
  //if (!term->IsReal ())
  //  yyerror ("Semantic error: the left expressions must be real");
  //if (!factor->IsReal ())
  //  yyerror ("Semantic error: the right expressions must be real");
  term = CoerceLeftExpressionToReal (term, factor);
  factor = CoerceRightExpressionToReal (term, factor);
  //---------------------------------------------------------------------
  //Divide real
  //---------------------------------------------------------------------
  PCode* P = new PCode ("", "dvr", "", "");
  Exp* E = new Exp (term, factor, ST.TReal (), P);
  E->Print (fout);
  return E;
}
//--------------------------------------------------------------------
//Function term -> term DIV factor
//--------------------------------------------------------------------
Exp* termDivFactor (Exp* term, Exp* factor)
{
  if (!term->IsInteger ())
    yyerror ("Semantic error:: the left expression must be integer");
  if (!factor->IsInteger ())
    yyerror ("Semantic error:: the right expression must be integer");

  PCode* P = new PCode ("", "dvi", "", "");
  Exp* E = new Exp (term, factor, ST.TInteger (), P);
  E->Print (fout);
  return E;
}
//--------------------------------------------------------------------
//Function term -> term MOD factor
//--------------------------------------------------------------------
Exp* termModFactor (Exp* term, Exp* factor)
{
  if (!term->IsInteger ())
    yyerror ("Semantic error:: the left expression must be integer");
  if (!factor->IsInteger ())
    yyerror ("Semantic error:: the right expression must be integer");

  PCode* P = new PCode ("", "mod", "", "");
  Exp* E = new Exp (term, factor, ST.TInteger (), P);
  E->Print (fout);
  return E;
}
//--------------------------------------------------------------------
//Function term -> term AND factor
//--------------------------------------------------------------------
Exp* termAndFactor (Exp* term, Exp* factor)
{
  if (!term->IsBoolean ())
    yyerror ("Semantic error:: the left expression must be Boolean");
  if (!factor->IsBoolean ())
    yyerror ("Semantic error:: the right expression must be Boolean");

  PCode* P = new PCode ("", "and", "", "");
  Exp* E = new Exp (term, factor, ST.TBoolean (), P);
  E->Print (fout);
  return E;
}
//-------------------------------------------------------------------------
//Function term implements the rule
//term -> factor
//-------------------------------------------------------------------------
Exp* term (Exp* factor) { return factor; }
//-------------------------------------------------------------------------
//Function term implements the rule
//term -> term mulop factor
//-------------------------------------------------------------------------
Exp* term (Exp* term, string* op, Exp* factor)
{
  if (*op == "*")  return termMultFactor (term, factor);
  if (*op == "/") return termSlashFactor (term, factor);
  if (*op == "div") return termDivFactor (term, factor);
  if (*op == "mod") return termModFactor (term, factor);
  if (*op == "and") return termAndFactor (term, factor);
  yyerror ("Semantic error: invalid mulop");
}

