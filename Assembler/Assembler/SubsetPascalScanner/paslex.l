/*
 * -------------------------------------------------------------------------
 * Author: Gregory Levy
 * Student ID: *20444120
 * E-Mail: glevy@uco.edu
 * Course: CMSC 4173 – Translator Design
 * CRN: 21175, Spring, 2017
 * Project: p01 - Subset Pascal Scanner
 * Due: January 17, 2018
 * Account: tt072
 * -------------------------------------------------------------------------
 *
 *
 * -------------------------------------------------------------------------
 * File paslex.l defines our lex
 * -------------------------------------------------------------------------
 */

/*
 * -------------------------------------------------------------------------
 * Definition Section
 * -------------------------------------------------------------------------
 */

%{
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <string>
#include "paslex.h"

using namespace std;

struct comparer
{
    public:
    bool operator()(const std::string x, const std::string y)
    {
         return x.compare(y)<0;
    }
};

int tokenManager(int token);
void badTokenException();
static int col = 1;
static int line = 1;
map<string, int, comparer> reserveWords;
%}

%%
"{"[^}]*"}"									{col+=strlen(yytext);}
[ \t]+										{col+=strlen(yytext);}
[\n]										{line++; col=1;}	
"+"											{return(tokenManager(PLUS));}
"-"											{return(tokenManager(MINUS));}
"*"											{return(tokenManager(STAR));}
"/"											{return(tokenManager(SLASH));}
":="										{return(tokenManager(ASSIGN));}
"."											{return(tokenManager(PERIOD));}		
","											{return(tokenManager(COMMA));}
";"											{return(tokenManager(SEMICOLON));}
":"											{return(tokenManager(COLON));}
"="											{return(tokenManager(EQU));}
"<>"										{return(tokenManager(NEQ));}
"<"											{return(tokenManager(LES));}
"<="										{return(tokenManager(LEQ));}
">"											{return(tokenManager(GRT));}
">="										{return(tokenManager(GEQ));}
"("											{return(tokenManager(LPAREN));}
")"											{return(tokenManager(RPAREN));}
"["											{return(tokenManager(LBRACKET));}
"]"											{return(tokenManager(RBRACKET));}
".."										{return(tokenManager(RANGE));}
([a-zA-Z]|_)[a-zA-Z0-9]*					{return(tokenManager(ID));}
[0-9]+										{return(tokenManager(INTLIT));}
[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?			{return(tokenManager(REALIT));}
[0-9]+([eE][0-9]+)?							{return(tokenManager(REALIT));}
['][a-zA-Z0-9|'][']							{return(tokenManager(CHRLIT));}
.											{badTokenException();}
%%

void badTokenException()
{
	cout << "ERROR! Unrecognized token at: Line " << line << " Column " << col << endl;
	cout << "Program terminated" << endl;
	exit (EXIT_FAILURE);
}

int tokenManager(int T)
{  
	col+=strlen(yytext);
	if(T == ID)
	{
		string lower(yytext);

		for (int i=0; lower[i]; i++) 
		{
			lower[i] = tolower(lower[i]);
		}
		map<string, int>::iterator it = reserveWords.find(lower);
		if(it != reserveWords.end())
		{
			return reserveWords.find(lower)->second;
		}
		else
		{
			return T;
		}
	}
	else
	{
		return T;
	}	
}

Scan::Scan(FILE* i)
{ 
  yyin=i;
  reserveWords.insert (pair <string, int> ("and", 326));
  reserveWords.insert (pair <string, int> ("array", 327));
  reserveWords.insert (pair <string, int> ("div", 328));
  reserveWords.insert (pair <string, int> ("do", 329));
  reserveWords.insert (pair <string, int> ("else", 330));
  reserveWords.insert (pair <string, int> ("end", 331));
  reserveWords.insert (pair <string, int> ("function", 332));
  reserveWords.insert (pair <string, int> ("if", 333));
  reserveWords.insert (pair <string, int> ("mod", 334));
  reserveWords.insert (pair <string, int> ("not", 335));
  reserveWords.insert (pair <string, int> ("of", 336));
  reserveWords.insert (pair <string, int> ("or", 337));
  reserveWords.insert (pair <string, int> ("procedure", 338));
  reserveWords.insert (pair <string, int> ("program", 339));
  reserveWords.insert (pair <string, int> ("then", 340));
  reserveWords.insert (pair <string, int> ("to", 341));
  reserveWords.insert (pair <string, int> ("type", 342));
  reserveWords.insert (pair <string, int> ("var", 343));
  reserveWords.insert (pair <string, int> ("while", 344));
};


int Scan::Lex(void)
{ 
	return tcode=yylex();
}

char* Scan::fetchSpelling(void)
{ 
	return ((char*)yytext);
}

int Scan::fetchTokenCode(void)
{ 
	return tcode;
}

void Scan::storeTokenCode(int T)
{ 
	tcode=T;
}

int Scan::fetchLine()
{
	return line;
}

int Scan::fetchCol()
{
	return col;
}