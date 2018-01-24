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

extern ofstream tfs;
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
	{tfs << endl << "#01 program -> program_head program_declarations program_body";
	}
program_head:
	PROGRAM ID program_parameters SEMICOLON
	{tfs << endl << "#02 program_head -> program id program_parameters SEMICOLON";
	}
program_declarations:
	declarations subprogram_declarations
	{tfs << endl << "#03 program_declarations -> declarations subprogram_declarations";
	}
program_body:
	compound_statement PERIOD
	{tfs << endl << "#04 program_body -> compound_statement PERIOD";
	}
program_parameters:
	{tfs << endl << "#05 program_parameters -> EMPTY";
	}
program_parameters: 
	LPAREN program_parameter_list RPAREN
	{tfs << endl << "#06 program_parameters -> ( program_parameters )";
	}
program_parameter_list:
	identifier_list
	{tfs << endl << "#07 program_parameter_list -> identifier_list";
	}
identifier_list:
	ID	
	{tfs << endl << "#08 identifier_list -> ID";
	}
identifier_list:
	identifier_list COMMA ID
	{tfs << endl << "#09 identifier_list -> identifier_list , ID";
	}
declarations:
	{tfs << endl << "#10 declarations -> EMPTY";
	}
declarations:
	declarations VAR identifier_list COLON type SEMICOLON 
	{tfs << endl << "#11 declarations -> declarations VAR identifier_list : type SEMICOLON";
	}
type:
	standard_type
	{tfs << endl << "#12 type -> standard_type";
	}
type:
	ARRAY LBRACKET INTLIT RANGE INTLIT RPAREN OF standard_type
	{tfs << endl << "#13 type -> array [ intlit .. intlit ] of standard_type";
	}
standard_type:
	ID
	{tfs << endl << "#14 standard_type -> ID";
	}
subprogram_declarations:
	{tfs << endl << "#15 subprogram_declarations -> EMPTY";
	}
subprogram_declarations:
	subprogram_declarations subprogram_declarations SEMICOLON
	{tfs << endl << "#16 subprogram_declarations -> subprogram_declarations subprogram_declaration ;";
	}
subprogram_declarations:
	subprogram_head declarations compound_statement
	{tfs << endl << "#17 subprogram_declarations -> subprogram_head declarations compound_statement";
	}
subprogram_head:
	FUNCTION ID subprogram_parameters COLON standard_type SEMICOLON
	{tfs << endl << "#18 subprogram_head -> function id subprogram_parameters : standard_type ;";
	}
subprogram_head:
	PROCEDURE ID subprogram_parameters SEMICOLON
	{tfs << endl << "#19 subprogram_head -> procedure ID subprogram_parameters ;";
	}
subprogram_parameters:
	{tfs << endl << "#20 subprogram_parameters -> EMPTY";
	}
subprogram_parameters:
	LPAREN parameter_list RPAREN
	{tfs << endl << "#21 subprogram_parameters -> ( parameter_list )";
	}
parameter_list:
	identifier_list COLON type
	{tfs << endl << "#22 parameter_list -> identifier_list : type";
	}
parameter_list:
	parameter_list SEMICOLON identifier_list COLON type
	{tfs << endl << "#23 parameter_list -> parameter_list ; identifier_list : type";
	}
compound_statement:
	BEGIN_ optional_statements END
	{tfs << endl << "#24 compound_statement -> BEGIN optional_statements END";
	}
optional_statements:
	{tfs << endl << "#25 optional_statements -> EMPTY";
	}
optional_statements:
	statement_list
	{tfs << endl << "#26 optional_statements -> statement_list";
	}
statement_list:
	statement
	{tfs << endl << "#27 statement_list -> statement";
	}
statement_list:
	statement_list SEMICOLON statement
	{tfs << endl << "#28 statement_list -> statement_list SEMICOLON statement";
	}
statement:
	variable ASSIGN expression
	{tfs << endl << "#29 statement -> variable := expression";
	}
statement:
	procedure_statement
	{tfs << endl << "#30 statement -> procedure_statement";
	}
statement:
	compound_statement
	{tfs << endl << "#31 statement -> compound_statement";
	}
statement:
	IF expression THEN statement ELSE statement
	{tfs << endl << "#32 statement -> if expression then statement else statement";
	}
statement:
	WHILE expression DO statement
	{tfs << endl << "#33 statement -> while expression do statement";
	}
variable:
	ID
	{tfs << endl << "#34 variable -> ID";
	}
variable:
	ID LPAREN expression RPAREN
	{tfs << endl << "#35 variable -> id LPAREN expression RPAREN";
	}
procedure_statement:
	ID
	{tfs << endl << "#36 procedure_statement -> ID";
	}
procedure_statement:
	ID LPAREN expression_list RPAREN
	{tfs << endl << "#37 ID ( expression_list )";
	}
expression_list:
	expression
	{tfs << endl << "#38 expression_list -> expression";
	}
expression_list:
	expression_list COMMA expression
	{tfs << endl << "#39 expression_list -> expression_list , expression";
	}
expression:
	simple_expression
	{tfs << endl << "#40 expression -> simple_expression";
	}
expression:
	simple_expression relop simple_expression
	{tfs << endl << "#41 expression -> simple_expression relop simple_expression";
	}
relop:
	EQU
	{tfs << endl << "#42 relop -> =";
	}
relop:
	NEQ
	{tfs << endl << "#43 relop -> <>";
	}
relop:
	LES
	{tfs << endl << "#44 relop -> <";
	}
relop:
	LEQ
	{tfs << endl << "#45 relop -> <=";
	}
relop:
	GRT
	{tfs << endl << "#46 relop -> >";
	}
relop:
	GEQ
	{tfs << endl << "#47 relop -> >=";
	}
simple_expression:
	term
	{tfs << endl << "#48 simple_expression -> term";
	}
simple_expression:
	sign term
	{tfs << endl << "#49 simple_expression -> sign term";
	}
simple_expression:
	simple_expression addop term
	{tfs << endl << "#50 simple_expression -> simple_expression addop term";
	}
sign:
	PLUS
	{tfs << endl << "#51 sign -> +";
	}
sign:
	MINUS
	{tfs << endl << "#52 sign -> -";
	}
addop:
	PLUS
	{tfs << endl << "#53 addop -> +";
	}
addop:
	MINUS
	{tfs << endl << "#54 addop -> -";
	}
addop:
	OR
	{tfs << endl << "#55 procedure_statement -> or";
	}
term:
	factor
	{tfs << endl << "#56 term -> factor";
	}
term:
	term mulop factor
	{tfs << endl << "#57 term -> term mulop factor";
	}
mulop:
	STAR
	{tfs << endl << "#58 mulop -> *";
	}
mulop:
	SLASH
	{tfs << endl << "#59 mulop -> /";
	}
mulop:
	DIV
	{tfs << endl << "#60 mulop -> DIV";
	}
mulop:
	MOD
	{tfs << endl << "#61 mulop -> MOD";
	}
mulop:
	AND
	{tfs << endl << "#62 mulop -> AND";
	}
factor:
	ID
	{tfs << endl << "#63 factor -> ID";
	}
factor:
	ID LBRACKET expression RBRACKET
	{tfs << endl << "#64 factor -> ID RBRACKET expression RBRACKET";
	}
factor:
	ID LPAREN expression_list RPAREN
	{tfs << endl << "#65 factor -> id LPAREN expression_list RPAREN";
	}
factor:
	LPAREN expression RPAREN
	{tfs << endl << "#66 mulop -> LPAREN expression RPAREN";
	}
factor:
	NOT factor
	{tfs << endl << "#67 mulop -> NOT factor";
	}
factor:
	INTLIT
	{tfs << endl << "#68 factor -> INTLIT";
	}
factor:
	REALIT
	{tfs << endl << "#69 factor -> REALIT";
	}
factor:
	CHRLIT
	{tfs << endl << "#70 factor -> CHRLIT";
	}
%%
void yyerror(const char* m)
{
	cout << endl << "line(" << line << ") col(" << col << ") " << m;
	cout << endl; 
}
