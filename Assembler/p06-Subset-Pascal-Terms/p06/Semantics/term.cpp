


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
#include "term.h"

using namespace std;

extern ofstream fout;
extern int line;
extern int col;
extern SymbolTable ST;
//--------------------------------------------------------------------
//Function CoerceLeftExpressionToReal coerces the left expression to
//real if the left expression has type integer and the right expression
//has type real.
//--------------------------------------------------------------------
Exp* CoerceLeftExpressionToReal(Exp* leftExpression, Exp* rightExpression)
{
  if (!leftExpression->IsReal () && !leftExpression->IsInteger ())
    yyerror ("Semantic error 1: left expression is not Integer and not Real");

  if (leftExpression->IsInteger () && rightExpression->IsReal ())
  {
    PCode* P = new PCode ("", "flt", "", "");
    return new Exp (leftExpression, 0, ST.TReal (), P);
  }
  else
  {
    return leftExpression;
  }
}
//--------------------------------------------------------------------
//Function CoerceRightExpressionToReal coerces the right expression to
//real if the right expression has type integer and the left expression
//has type real.
//--------------------------------------------------------------------
Exp* CoerceRightExpressionToReal(Exp* leftExpression, Exp* rightExpression)
{
  if (!rightExpression->IsReal () && !rightExpression->IsInteger ())
    yyerror ("Semantic error 2: right expression is not Integer and not Real");

  if (rightExpression->IsInteger () && leftExpression->IsReal ())
  {
    PCode* P = new PCode ("", "flt", "", "");
    return new Exp (0, rightExpression, ST.TReal (), P);
  }
  else
  {
    return rightExpression;
  }
}
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
  return E;
}
//--------------------------------------------------------------------
//Function term -> term / factor
//--------------------------------------------------------------------
Exp* termSlashFactor (Exp* term, Exp* factor)
{
  cout << "Left side is term and: ";
  term->Type ()->Print (cout, 10);
  if (!term->IsReal ())
    yyerror ("Semantic error 3: the left expressions must be real");
  cout << "Right side is factor and: ";
  factor->Type ()->Print (cout, 10);
  if (!factor->IsReal ())
    yyerror ("Semantic error 3: the right expressions must be real");
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
    yyerror ("Semantic error 4: the left expression must be integer");
  if (!factor->IsInteger ())
    yyerror ("Semantic error 4: the right expression must be integer");

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
    yyerror ("Semantic error 5: the left expression must be integer");
  if (!factor->IsInteger ())
    yyerror ("Semantic error 5: the right expression must be integer");

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
    yyerror ("Semantic error 6: the left expression must be Boolean");
  if (!factor->IsBoolean ())
    yyerror ("Semantic error 6: the right expression must be Boolean");

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

