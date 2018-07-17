#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

#include "../slist.h"
#include "../yyerror.h"
#include "../SymbolTable/Typ.h"
#include "../SymbolTable/Sym.h"
#include "../SymbolTable/Namespace.h"
#include "../SymbolTable/Locality.h"
#include "../SymbolTable/LocalityStack.h"
#include "../SymbolTable/SymbolTable.h"
#include "../SymbolTable/PCode.h"
#include "../SymbolTable/Exp.h"

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
    yyerror ("Semantic error: left expression is not Integer and not Real");

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
    yyerror ("Semantic error: right expression is not Integer and not Real");

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

