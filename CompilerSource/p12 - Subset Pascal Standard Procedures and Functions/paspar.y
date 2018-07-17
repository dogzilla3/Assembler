%{

/*
 * -------------------------------------------------------------------------
 * Author: Gregory Levy
 * Student ID: *20444120
 * E-Mail: glevy@uco.edu
 * Course: CMSC 4173  Translator Design
 * CRN: 25838, Spring, 2018
 * Project: p02 - Subset Pascal Parser
 * Due: January 24, 2018
 * Account: tt072
 *
 * Author: William Bohanan
 * Student ID: *20276952
 * E-Mail: wbohanan@uco.edu
 * Course: CMSC 4173  Translator Design
 * CRN: 25838, Spring, 2018
 * Project: p02 - Subset Pascal Parser
 * Due: January 24, 2018
 * Account: tt067
 * -------------------------------------------------------------------------
 *
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "paslex.h"
#include "paspar.h"
#include "slist.h"
#include "identifierList.h"
#include "Semantics/Semantics.h"
#include "Semantics/factor.h"
#include "Semantics/term.h"
#include "Semantics/simple_expression.h"
#include "Semantics/expression.h"
#include "Semantics/procedure_statement.h"
#include "Semantics/expression_list.h"
#include "Semantics/variable.h"
#include "Semantics/compound_statement.h"
#include "Semantics/optional_statements.h"
#include "Semantics/statement.h"
#include "Semantics/statement_list.h"
#include "Semantics/subprogram_head.h"
#include "SymbolTable/PCode.h"
#include "SymbolTable/Exp.h"
#include "SymbolTable/Typ.h"
#include "SymbolTable/Sym.h"
#include "SymbolTable/Label.h"
#include "SymbolTable/Namespace.h"
#include "SymbolTable/Locality.h"
#include "SymbolTable/LocalityStack.h"
#include "SymbolTable/SymbolTable.h"

void yyerror(const char* m);

extern ofstream fout;
extern ofstream pcout;
extern int line;
extern int col;
extern Label L;

SymbolTable ST;

using namespace std;

void yyerror(const char* m);
%}
%union {
  SubprogramSymbol* subprog;
  string* token;
  SList<string>* strlist;
  Typ* type;
  SList<VariableSymbol*>* varlist;
  Exp* exp;
  SList<Exp*>* explist;
}
%type  <subprog> program_head
%type  <subprog> subprogram_head
%type  <varlist> parameter_list
%type  <varlist> subprogram_parameters
%type  <type>    type
%type  <type>    standard_type
%type  <strlist> identifier_list
%type  <exp>     factor
%type  <exp>     term
%type  <exp>     simple_expression
%type  <exp>     expression
%type  <exp>     procedure_statement
%type  <exp>     variable
%type  <explist> expression_list
%type  <explist> statement
%type  <explist> compound_statement
%type  <explist> statement_list
%type  <explist> optional_statements
%type  <explist> program_body   
%type  <token>   mulop
%type  <token>   addop
%type  <token>   relop
%type  <token>   sign
%token <token> PLUS
%token <token> MINUS
%token <token> STAR
%token <token> SLASH
%token <token> ASSIGN
%token <token> PERIOD
%token <token> COMMA
%token <token> SEMICOLON
%token <token> COLON
%token <token> EQU
%token <token> NEQ
%token <token> LES
%token <token> LEQ
%token <token> GRT
%token <token> GEQ
%token <token> LPAREN
%token <token> RPAREN
%token <token> LBRACKET
%token <token> RBRACKET
%token <token> RANGE
%token <token> RESERVE_WORDS
%token <token> AND
%token <token> ARRAY
%token <token> BEGIN_
%token <token> DIV
%token <token> DO
%token <token> ELSE
%token <token> END
%token <token> FUNCTION
%token <token> IF
%token <token> MOD
%token <token> NOT
%token <token> OF
%token <token> OR
%token <token> PROCEDURE
%token <token> PROGRAM
%token <token> THEN
%token <token> TO
%token <token> TYPE
%token <token> VAR
%token <token> WHILE
%token <token> REGULAR_EXPRESSIONS
%token <token> ID
%token <token> INTLIT
%token <token> REALIT
%token <token> CHRLIT
%token <token> COMMENT
%%

/* #1 */
program:
	program_head program_declarations program_body
	{fout << endl << "#01 program -> program_head program_declarations program_body";
		program($1,$3);
	}

/* #2 */
program_head:
	PROGRAM ID program_parameters SEMICOLON 
	{fout << endl << "#02 program_head -> program ID(" << (*$2) << ") program_parameters SEMICOLON";
		$$=program_head(*$2);
	}

/* #3 */
program_declarations:
	variable_declarations subprogram_declarations
	{fout << endl << "#03 program_declarations -> declarations subprogram_declarations";
	}

/* #4 */
program_body:
	compound_statement PERIOD
	{fout << endl << "#04 program_body -> compound_statement PERIOD";
		$$=Program_body($1);
	}

/* #5 */
program_parameters:
	{fout << endl << "#05 program_parameters -> EMPTY";
	}

/* #6 */
program_parameters: 
	LPAREN program_parameter_list RPAREN
	{fout << endl << "#06 program_parameters -> ( program_parameters )";
	}

/* #7 */
program_parameter_list:
	identifier_list
	{fout << endl << "#07 program_parameter_list -> identifier_list";
	}

/* #8 */
identifier_list:
	ID	
	{fout << endl << "#08 identifier_list -> ID(" << (*$1) << ")";	
		$$=idList($1);
	}

/* #9 */
identifier_list:
	identifier_list COMMA ID
	{fout << endl << "#09 identifier_list -> identifier_list , ID(" << (*$3) << ")";
		$$=idList($1,$3);
	}

/* #10 */
variable_declarations:
	{fout << endl << "#10 variable_declarations -> EMPTY";
	}

/* #11 */
variable_declarations:
	variable_declarations VAR identifier_list COLON type SEMICOLON 
	{fout << endl << "#11 variable_declarations -> variable_declarations VAR identifier_list " << (*$3).PrintList() << " : type SEMICOLON";
		variable_declarations($3, $5);
	}

/* #12 */
type:
	standard_type
	{fout << endl << "#12 type -> standard_type";
		$$=type($1);
	}

/* #13 */
type:
	ARRAY LBRACKET INTLIT RANGE INTLIT RBRACKET OF standard_type
	{fout << endl << "#13 type -> array [ intlit .. intlit ] of standard_type";
		$$=type(*$3,*$5,$8);
	}

/* #14 */
standard_type:
	ID
	{fout << endl << "#14 standard_type -> ID(" << (*$1) << ")";
		$$=standard_type(*$1);
	}

/* #15 */
subprogram_declarations:
	{fout << endl << "#15 subprogram_declarations -> EMPTY";
	}

/* #16 */
subprogram_declarations:
	subprogram_declarations subprogram_declaration SEMICOLON
	{fout << endl << "#16 subprogram_declarations -> subprogram_declarations subprogram_declaration ;";
		
	}

/* #17 */
subprogram_declaration:
	subprogram_head variable_declarations compound_statement
	{fout << endl << "#17 subprogram_declarations -> subprogram_head declarations compound_statement";
		subprogram_declaration($1,$3);
	}

/* #18 */
subprogram_head:
	FUNCTION ID subprogram_parameters COLON standard_type SEMICOLON
	{fout << endl << "#18 subprogram_head -> function ID(" << (*$2) << ") subprogram_parameters : standard_type ;";
		$$=subprogram_head(*$2,$3,$5);
	}

/* #19 */
subprogram_head:
	PROCEDURE ID subprogram_parameters SEMICOLON
	{fout << endl << "#19 subprogram_head -> procedure ID(" << (*$2) << ") subprogram_parameters ;";
		$$=subprogram_head(*$2,$3);
	}

/* #20 */
subprogram_parameters:
	{fout << endl << "#20 subprogram_parameters -> EMPTY";
		$$=subprogram_parameters();
	}

/* #21 */
subprogram_parameters:
	LPAREN parameter_list RPAREN
	{fout << endl << "#21 subprogram_parameters -> ( parameter_list )";
		$$=subprogram_parameters($2);
	}

/* #22 */
parameter_list:
	identifier_list COLON type
	{fout << endl << "#22 parameter_list -> identifier_list : type";
		$$=parameter_list($1, $3);
	}

/* #23 */
parameter_list:
	parameter_list SEMICOLON identifier_list COLON type
	{fout << endl << "#23 parameter_list -> parameter_list ; identifier_list : type";
		$$=parameter_list($1, $3, $5);
	}

/* #24 */
compound_statement:
	BEGIN_ optional_statements END
	{fout << endl << "#24 compound_statement -> BEGIN optional_statements END";
		$$=Compound_statement($2);	
	}	

/* #25 */
optional_statements:
	{fout << endl << "#25 optional_statements -> EMPTY";
		$$=Optional_statements();
	}

/* #26 */
optional_statements:
	statement_list
	{fout << endl << "#26 optional_statements -> statement_list";
		$$=Optional_statements($1);
	}

/* #27 */
statement_list:
	statement
	{fout << endl << "#27 statement_list -> statement";
		$$=Statement_list($1);
	}

/* #28 */
statement_list:
	statement_list SEMICOLON statement
	{fout << endl << "#28 statement_list -> statement_list SEMICOLON statement";
		$$=Statement_list($1,$3);
	}

/* #29 */
statement:
	variable ASSIGN expression
	{fout << endl << "#29 statement -> variable := expression";
		$$=statement($1,$3);
	}

/* #30 */
statement:
	procedure_statement
	{fout << endl << "#30 statement -> procedure_statement";
		$$=statement($1);
	}

/* #31 */
statement:
	compound_statement
	{fout << endl << "#31 statement -> compound_statement";
		$$=statement($1);
	}

/* #32 */
statement:
	IF expression THEN statement ELSE statement
	{fout << endl << "#32 statement -> if expression then statement else statement";
		$$=statement($2,$4,$6);
	}

/* #33 */
statement:
	WHILE expression DO statement
	{fout << endl << "#33 statement -> while expression do statement";
		$$=statement($2,$4);
	}

/* #34 */
variable:
	ID
	{fout << endl << "#34 variable -> ID(" << (*$1) << ")";
		$$=variable($1);
	}

/* #35 */
variable:
	ID LBRACKET expression RBRACKET
	{fout << endl << "#35 variable -> ID(" << (*$1) << ") LPAREN expression RPAREN";
		$$=variable($1, $3);
	}

/* #36 */
procedure_statement:
	ID
	{fout << endl << "#36 procedure_statement -> ID(" << (*$1) << ")";
		$$=procedure_statement($1);
	}

/* #37 */
procedure_statement:
	ID LPAREN expression_list RPAREN
	{fout << endl << "#37 ID(" << (*$1) << ") ( expression_list )";
		$$=procedure_statement($1, $3);
	}

/* #38 */
expression_list:
	expression
	{fout << endl << "#38 expression_list -> expression";
		$$=expression_list($1);
	}

/* #39 */
expression_list:
	expression_list COMMA expression
	{fout << endl << "#39 expression_list -> expression_list , expression";
		$$=expression_list($1,$3);
	}

/* #40 */
expression:
	simple_expression
	{fout << endl << "#40 expression -> simple_expression";
		$$=expression($1);
	}

/* #41 */
expression:
	simple_expression relop simple_expression
	{fout << endl << "#41 expression -> simple_expression relop simple_expression";
		$$=expression($1,$2,$3);
	}

/* #42 */
relop:
	EQU
	{fout << endl << "#42 relop -> =";
	}

/* #43 */
relop:
	NEQ
	{fout << endl << "#43 relop -> <>";
	}

/* #44 */
relop:
	LES
	{fout << endl << "#44 relop -> <";
	}

/* #45 */
relop:
	LEQ
	{fout << endl << "#45 relop -> <=";
	}

/* #46 */
relop:
	GRT
	{fout << endl << "#46 relop -> >";
	}

/* #47 */
relop:
	GEQ
	{fout << endl << "#47 relop -> >=";
	}

/* #48 */
simple_expression:
	term
	{fout << endl << "#48 simple_expression -> term";
		$$=simple_expression($1);
	}

/* #49 */
simple_expression:
	sign term
	{fout << endl << "#49 simple_expression -> sign term";
		$$=simple_expression($1, $2);
	}

/* #50 */
simple_expression:
	simple_expression addop term
	{fout << endl << "#50 simple_expression -> simple_expression addop term";
		$$=simple_expression($1, $2, $3);
	}

/* #51 */
sign:
	PLUS
	{fout << endl << "#51 sign -> +";
	}

/* #52 */
sign:
	MINUS
	{fout << endl << "#52 sign -> -";
	}

/* #53 */
addop:
	PLUS
	{fout << endl << "#53 addop -> +";
	}

/* #54 */
addop:
	MINUS
	{fout << endl << "#54 addop -> -";
	}

/* #55 */
addop:
	OR
	{fout << endl << "#55 procedure_statement -> or";
	}

/* #56 */
term:
	factor
	{fout << endl << "#56 term -> factor";
		$$=term($1);
	}

/* #57 */
term:
	term mulop factor
	{fout << endl << "#57 term -> term mulop factor";
		$$=term($1, $2, $3);
	}

/* #58 */
mulop:
	STAR
	{fout << endl << "#58 mulop -> *";
	}

/* #59 */
mulop:
	SLASH
	{fout << endl << "#59 mulop -> /";
	}

/* #60 */
mulop:
	DIV
	{fout << endl << "#60 mulop -> DIV";
	}

/* #61 */
mulop:
	MOD
	{fout << endl << "#61 mulop -> MOD";
	}

/* #62 */
mulop:
	AND
	{fout << endl << "#62 mulop -> AND";
	}

/* #63 */
factor:
	ID
	{fout << endl << "#63 factor -> ID(" << (*$1) << ")";
		$$ = factor_1($1);
	}

/* #64 */
factor:
	ID LBRACKET expression RBRACKET
	{fout << endl << "#64 factor -> ID(" << (*$1) << ") RBRACKET expression RBRACKET";
		$$=factor_2($1, $3);
	}

/* #65 */
factor:
	ID LPAREN expression_list RPAREN
	{fout << endl << "#65 factor -> ID(" << (*$1) << ") LPAREN expression_list RPAREN";
		$$ = factor_3($1, $3);
	}

/* #66 */
factor:
	LPAREN expression RPAREN
	{fout << endl << "#66 mulop -> LPAREN expression RPAREN";
		$$ = factor_4($2);
	}

/* #67 */
factor:
	NOT factor
	{fout << endl << "#67 mulop -> NOT factor";
		$$ = factor_5($2);
	}

/* #68 */
factor:
	INTLIT
	{fout << endl << "#68 factor -> INTLIT(" << (*$1) << ")";
		$$ = factor_6($1);
	}

/* #69 */
factor:
	REALIT
	{fout << endl << "#69 factor -> REALIT(" << (*$1) << ")";
		$$ = factor_7($1);
	}

/* #70 */
factor:
	CHRLIT
	{fout << endl << "#70 factor -> CHRLIT(" << (*$1) << ")";
		$$ = factor_8($1);
	}
%%


void yyerror(const char* m)
{	
	cout << endl << "line(" << line << ") col(" << col << ") " << m;
	cout << endl; 
}
