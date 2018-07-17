#ifndef PASLEX_H
#define PASLEX_H 1

#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

#include "pastkn.h"


/*
* -------------------------------------------------------------------------
* Scanner
* -------------------------------------------------------------------------
*/
#ifdef __cplusplus
extern "C"
#endif

int yylex (void);

class Scan
{
  int tcode;                      //Code for the most recent token found


  public:
  Scan (FILE* i);                 //Redirect the input source from the
                                  //keyboard to input file i.
  int Lex (void);                 //Call the scanner yylex and return the code
                                  //found by yylex
  int fetchTokenCode (void);      //Return the code of the most recent token
  void storeTokenCode (int T);    //Store the token code.
  char* fetchSpelling (void);     //Return the spelling of the most recent token
  int fetchLine (void);
  int fetchCol (void);
  void printToken(std::ostream& o, int, int, int);

};
#endif
