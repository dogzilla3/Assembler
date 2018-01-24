/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PLUS = 258,
    MINUS = 259,
    STAR = 260,
    SLASH = 261,
    ASSIGN = 262,
    PERIOD = 263,
    COMMA = 264,
    SEMICOLON = 265,
    COLON = 266,
    EQU = 267,
    NEQ = 268,
    LES = 269,
    LEQ = 270,
    GRT = 271,
    GEQ = 272,
    LPAREN = 273,
    RPAREN = 274,
    LBRACKET = 275,
    RBRACKET = 276,
    RANGE = 277,
    RESERVE_WORDS = 278,
    AND = 279,
    ARRAY = 280,
    BEGIN_ = 281,
    DIV = 282,
    DO = 283,
    ELSE = 284,
    END = 285,
    FUNCTION = 286,
    IF = 287,
    MOD = 288,
    NOT = 289,
    OF = 290,
    OR = 291,
    PROCEDURE = 292,
    PROGRAM = 293,
    THEN = 294,
    TO = 295,
    TYPE = 296,
    VAR = 297,
    WHILE = 298,
    REGULAR_EXPRESSIONS = 299,
    ID = 300,
    INTLIT = 301,
    REALIT = 302,
    CHRLIT = 303,
    COMMENT = 304
  };
#endif
/* Tokens.  */
#define PLUS 258
#define MINUS 259
#define STAR 260
#define SLASH 261
#define ASSIGN 262
#define PERIOD 263
#define COMMA 264
#define SEMICOLON 265
#define COLON 266
#define EQU 267
#define NEQ 268
#define LES 269
#define LEQ 270
#define GRT 271
#define GEQ 272
#define LPAREN 273
#define RPAREN 274
#define LBRACKET 275
#define RBRACKET 276
#define RANGE 277
#define RESERVE_WORDS 278
#define AND 279
#define ARRAY 280
#define BEGIN_ 281
#define DIV 282
#define DO 283
#define ELSE 284
#define END 285
#define FUNCTION 286
#define IF 287
#define MOD 288
#define NOT 289
#define OF 290
#define OR 291
#define PROCEDURE 292
#define PROGRAM 293
#define THEN 294
#define TO 295
#define TYPE 296
#define VAR 297
#define WHILE 298
#define REGULAR_EXPRESSIONS 299
#define ID 300
#define INTLIT 301
#define REALIT 302
#define CHRLIT 303
#define COMMENT 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 41 "paspar.y" /* yacc.c:1909  */
 string* token; 

#line 155 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
