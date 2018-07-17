/*
* -------------------------------------------------------------------------
* Author: Gregory Levy
* Student ID: *20444120
* E-Mail: glevy@uco.edu
* Course: CMSC 4173 <96> Translator Design
* CRN: 21175, Spring, 2017
* Project: p02 - Subset Pascal Parser
* Due: January 24, 2018
* Account: tt072
* -------------------------------------------------------------------------
*
*
* -------------------------------------------------------------------------
* 
* 
* -------------------------------------------------------------------------
*/


#ifndef EXP_H
#define EXP_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

#include "PCode.h"
#include "Typ.h"
#include "Sym.h"

class Exp 
{
	Exp* leftExp;
	Exp* rightExp;
	Typ* typ;
	PCode* pCode;

public:
	Exp(Typ*, PCode*);
	Exp(Exp*, Exp*, Typ*, PCode*);
	void PPrint(ostream&);
	void TPrint(ostream&, int);
	void Print(ostream&);
	Typ* Type();
	void LeftAppend(Exp*);
	bool IsBoolean();
	bool IsCharacter();
	bool IsInteger();
	bool IsReal();
	PCode* FetchPCode();
	friend class Height;
};

#endif
