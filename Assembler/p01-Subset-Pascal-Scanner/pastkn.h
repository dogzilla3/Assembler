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
#define ID              320
#define INTLIT          321
#define REALIT          322
#define CHRLIT          324
#define COMMENT         325
#define AND             326
#define ARRAY           327
#define DIV             328
#define DO              329
#define ELSE            330
#define END             331
#define FUNCTION        332
#define IF              333
#define MOD             334
#define NOT             335
#define OF              336
#define OR              337
#define PROCEDURE       338
#define PROGRAM         339
#define THEN            340
#define TO              341
#define TYPE            342
#define VAR             343
#define WHILE           344

#endif