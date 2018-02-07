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
* File pastkn.h contains the list of positive integer codes that uniquely
* identify each token. #define macro directives are used to define each
* token. For example, #define PROGRAM 309. Alternatively, you may construct 
* this list using an enumerated type. However, you must ensure that every
* token has a positive integer code.
* -------------------------------------------------------------------------
*/

#ifndef PASTKN_H
#define PASTKN_H

#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

/*
* -------------------------------------------------------------------------
* Token definitions
* -------------------------------------------------------------------------
*/
#define PLUS            300
#define MINUS           301
#define STAR            302
#define SLASH           303
#define ASSIGN          304
#define PERIOD          305
#define COMMA           306
#define SEMICOLON       307
#define COLON           308
#define EQU             309
#define NEQ             310
#define LES             311
#define LEQ             312
#define GRT             313
#define GEQ             314
#define LPAREN          315
#define RPAREN          316
#define LBRACKET        317
#define RBRACKET        318
#define RANGE           319
#define AND             320
#define ARRAY           321
#define BEGIN_          322
#define DIV             323
#define DO              324
#define ELSE            325
#define END             326
#define FUNCTION        327
#define IF              328
#define MOD             329
#define NOT             330
#define OF              331
#define OR              332
#define PROCEDURE       333
#define PROGRAM         334
#define THEN            335
#define TO              336
#define TYPE            337
#define VAR             338
#define WHILE           339
#define ID              340
#define INTLIT          341
#define REALIT          342
#define CHRLIT          343

#endif