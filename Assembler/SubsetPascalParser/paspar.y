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

extern ofstream fout;
extern int line;
extern int col;

using namespace std;

void yyerror(const char* m);
%}
%union { std::string* token; }
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
program:
	program_head program_declarations program_body
	{fout << endl << "#01 program -> program_head program_declarations program_body";
	}
program_head:
	PROGRAM ID program_parameters SEMICOLON 
	{fout << endl << "#02 program_head -> program id program_parameters SEMICOLON";
	}
program_declarations:
	declarations subprogram_declarations
	{fout << endl << "#03 program_declarations -> declarations subprogram_declarations";
	}
program_body:
	compound_statement PERIOD
	{fout << endl << "#04 program_body -> compound_statement PERIOD";
	}
program_parameters:
	{fout << endl << "#05 program_parameters -> EMPTY";
	}
program_parameters: 
	LPAREN program_parameter_list RPAREN
	{fout << endl << "#06 program_parameters -> ( program_parameters )";
	}
program_parameter_list:
	identifier_list
	{fout << endl << "#07 program_parameter_list -> identifier_list";
	}
identifier_list:
	ID	
	{fout << endl << "#08 identifier_list -> ID";
	}
identifier_list:
	identifier_list COMMA ID
	{fout << endl << "#09 identifier_list -> identifier_list , ID";
	}
declarations:
	{fout << endl << "#10 declarations -> EMPTY";
	}
declarations:
	declarations VAR identifier_list COLON type SEMICOLON 
	{fout << endl << "#11 declarations -> declarations VAR identifier_list : type SEMICOLON";
	}
type:
	standard_type
	{fout << endl << "#12 type -> standard_type";
	}
type:
	ARRAY LBRACKET INTLIT RANGE INTLIT RPAREN OF standard_type
	{fout << endl << "#13 type -> array [ intlit .. intlit ] of standard_type";
	}
standard_type:
	ID
	{fout << endl << "#14 standard_type -> ID";
	}
subprogram_declarations:
	{fout << endl << "#15 subprogram_declarations -> EMPTY";
	}
subprogram_declarations:
	subprogram_declarations subprogram_declaration SEMICOLON
	{fout << endl << "#16 subprogram_declarations -> subprogram_declarations subprogram_declaration ;";
	}
subprogram_declaration:
	subprogram_head declarations compound_statement
	{fout << endl << "#17 subprogram_declarations -> subprogram_head declarations compound_statement";
	}
subprogram_head:
	FUNCTION ID subprogram_parameters COLON standard_type SEMICOLON
	{fout << endl << "#18 subprogram_head -> function id subprogram_parameters : standard_type ;";
	}
subprogram_head:
	PROCEDURE ID subprogram_parameters SEMICOLON
	{fout << endl << "#19 subprogram_head -> procedure ID subprogram_parameters ;";
	}
subprogram_parameters:
	{fout << endl << "#20 subprogram_parameters -> EMPTY";
	}
subprogram_parameters:
	LPAREN parameter_list RPAREN
	{fout << endl << "#21 subprogram_parameters -> ( parameter_list )";
	}
parameter_list:
	identifier_list COLON type
	{fout << endl << "#22 parameter_list -> identifier_list : type";
	}
parameter_list:
	parameter_list SEMICOLON identifier_list COLON type
	{fout << endl << "#23 parameter_list -> parameter_list ; identifier_list : type";
	}
compound_statement:
	BEGIN_ optional_statements END
	{fout << endl << "#24 compound_statement -> BEGIN optional_statements END";
	}
optional_statements:
	{fout << endl << "#25 optional_statements -> EMPTY";
	}
optional_statements:
	statement_list
	{fout << endl << "#26 optional_statements -> statement_list";
	}
statement_list:
	statement
	{fout << endl << "#27 statement_list -> statement";
	}
statement_list:
	statement_list SEMICOLON statement
	{fout << endl << "#28 statement_list -> statement_list SEMICOLON statement";
	}
statement:
	variable ASSIGN expression
	{fout << endl << "#29 statement -> variable := expression";
	}
statement:
	procedure_statement
	{fout << endl << "#30 statement -> procedure_statement";
	}
statement:
	compound_statement
	{fout << endl << "#31 statement -> compound_statement";
	}
statement:
	IF expression THEN statement ELSE statement
	{fout << endl << "#32 statement -> if expression then statement else statement";
	}
statement:
	WHILE expression DO statement
	{fout << endl << "#33 statement -> while expression do statement";
	}
variable:
	ID
	{fout << endl << "#34 variable -> ID";
	}
variable:
	ID LPAREN expression RPAREN
	{fout << endl << "#35 variable -> id LPAREN expression RPAREN";
	}
variable:
	variable PERIOD ID
	{fout << endl << "#** variable ->*******";
	}
procedure_statement:
	ID
	{fout << endl << "#36 procedure_statement -> ID";
	}
procedure_statement:
	ID LPAREN expression_list RPAREN
	{fout << endl << "#37 ID ( expression_list )";
	}
expression_list:
	expression
	{fout << endl << "#38 expression_list -> expression";
	}
expression_list:
	expression_list COMMA expression
	{fout << endl << "#39 expression_list -> expression_list , expression";
	}
expression:
	simple_expression
	{fout << endl << "#40 expression -> simple_expression";
	}
expression:
	simple_expression relop simple_expression
	{fout << endl << "#41 expression -> simple_expression relop simple_expression";
	}
relop:
	EQU
	{fout << endl << "#42 relop -> =";
	}
relop:
	NEQ
	{fout << endl << "#43 relop -> <>";
	}
relop:
	LES
	{fout << endl << "#44 relop -> <";
	}
relop:
	LEQ
	{fout << endl << "#45 relop -> <=";
	}
relop:
	GRT
	{fout << endl << "#46 relop -> >";
	}
relop:
	GEQ
	{fout << endl << "#47 relop -> >=";
	}
simple_expression:
	term
	{fout << endl << "#48 simple_expression -> term";
	}
simple_expression:
	sign term
	{fout << endl << "#49 simple_expression -> sign term";
	}
simple_expression:
	simple_expression addop term
	{fout << endl << "#50 simple_expression -> simple_expression addop term";
	}
sign:
	PLUS
	{fout << endl << "#51 sign -> +";
	}
sign:
	MINUS
	{fout << endl << "#52 sign -> -";
	}
addop:
	PLUS
	{fout << endl << "#53 addop -> +";
	}
addop:
	MINUS
	{fout << endl << "#54 addop -> -";
	}
addop:
	OR
	{fout << endl << "#55 procedure_statement -> or";
	}
term:
	factor
	{fout << endl << "#56 term -> factor";
	}
term:
	term mulop factor
	{fout << endl << "#57 term -> term mulop factor";
	}
mulop:
	STAR
	{fout << endl << "#58 mulop -> *";
	}
mulop:
	SLASH
	{fout << endl << "#59 mulop -> /";
	}
mulop:
	DIV
	{fout << endl << "#60 mulop -> DIV";
	}
mulop:
	MOD
	{fout << endl << "#61 mulop -> MOD";
	}
mulop:
	AND
	{fout << endl << "#62 mulop -> AND";
	}
factor:
	ID
	{fout << endl << "#63 factor -> ID";
	}
factor:
	ID LBRACKET expression RBRACKET
	{fout << endl << "#64 factor -> ID RBRACKET expression RBRACKET";
	}
factor:
	ID LPAREN expression_list RPAREN
	{fout << endl << "#65 factor -> id LPAREN expression_list RPAREN";
	}
factor:
	LPAREN expression RPAREN
	{fout << endl << "#66 mulop -> LPAREN expression RPAREN";
	}
factor:
	NOT factor
	{fout << endl << "#67 mulop -> NOT factor";
	}
factor:
	INTLIT
	{fout << endl << "#68 factor -> INTLIT";
	}
factor:
	REALIT
	{fout << endl << "#69 factor -> REALIT";
	}
factor:
	CHRLIT
	{fout << endl << "#70 factor -> CHRLIT";
	}
%%
void yyerror(const char* m)
{	
	cout << endl << "line(" << line << ") col(" << col << ") " << m;
	cout << endl; 
}
