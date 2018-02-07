/*
 * -------------------------------------------------------------------------
 * Author: Gregory Levy
 * Student ID: *20444120
 * E-Mail: glevy@uco.edu
 * Course: CMSC 4173 – Translator Design
 * CRN: 21175, Spring, 2017
 * Project: p02 - Subset Pascal Parser
 * Due: January 24, 2018
 * Account: tt072
 * Edit for a pull
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
int col = 1;
int line = 1;
map<string, int, comparer> reserveWords;
%}

%%
[{][^{]*[}]									{	for (int a=0;a<strlen(yytext);a++) {
													col++;
													if (yytext[a]=='\n') {
														col=1;
														line++;
													}
												}
											}
[ \t]+										{col+=strlen(yytext);}
[\n]										{line++; col=1;}	
[_a-zA-Z][_a-zA-Z0-9]*						{return(tokenManager(ID));}
[']([^']|(\'\'))([^']|(\'\'))+[']			{return(tokenManager(CHRLIT));} 
[0-9]+										{return(tokenManager(INTLIT));}
[0-9]+([eE][0-9]+)?							{return(tokenManager(REALIT));}
[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?			{return(tokenManager(REALIT));}
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
  reserveWords.insert (pair <string, int> ("and",	279));
  reserveWords.insert (pair <string, int> ("array", 280));
  reserveWords.insert (pair <string, int> ("begin", 281));
  reserveWords.insert (pair <string, int> ("div", 282));
  reserveWords.insert (pair <string, int> ("do", 283));
  reserveWords.insert (pair <string, int> ("else", 284));
  reserveWords.insert (pair <string, int> ("end", 285));
  reserveWords.insert (pair <string, int> ("function", 286));
  reserveWords.insert (pair <string, int> ("if", 287));
  reserveWords.insert (pair <string, int> ("mod", 288));
  reserveWords.insert (pair <string, int> ("not", 289));
  reserveWords.insert (pair <string, int> ("of", 290));
  reserveWords.insert (pair <string, int> ("or", 291));
  reserveWords.insert (pair <string, int> ("procedure", 292));
  reserveWords.insert (pair <string, int> ("program", 293));
  reserveWords.insert (pair <string, int> ("then", 294));
  reserveWords.insert (pair <string, int> ("to", 295));
  reserveWords.insert (pair <string, int> ("type", 296));
  reserveWords.insert (pair <string, int> ("var", 297));
  reserveWords.insert (pair <string, int> ("while", 298));
  reserveWords.insert (pair <string, int> ("id", 300));
  reserveWords.insert (pair <string, int> ("intlit", 301));
  reserveWords.insert (pair <string, int> ("realit", 302));
  reserveWords.insert (pair <string, int> ("chrlit", 303));
  reserveWords.insert (pair <string, int> ("comment", 304));
}
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
