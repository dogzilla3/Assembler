/*
* -------------------------------------------------------------------------
* Author: Gregory Levy
* Student ID: *20444120
* E-Mail: glevy@uco.edu
* Course: CMSC 4173 ? Translator Design
* CRN: 25838, Spring, 2018
* Project: p02 - Subset Pascal Parser
* Due: January 24, 2018
* Account: tt072
*
* Author: William Bohanan
* Student ID: *20276952
* E-Mail: wbohanan@uco.edu
* Course: CMSC 4173 ? Translator Design
* CRN: 25838, Spring, 2018
* Project: p02 - Subset Pascal Parser
* Due: January 24, 2018
* Account: tt067
* -------------------------------------------------------------------------
*
*
* -------------------------------------------------------------------------
* File StandardTypes.h makes Standard Types available to the Symbol Table.
* -------------------------------------------------------------------------
*
*/

#ifndef StandardTypes_h 
#define StandardTypes_h 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Typ.h"

using namespace std;


void SetTVoid(Typ* tv);
void SetTAddress(Typ* ta);
void SetTBoolean(Typ* tb);
void SetTChar(Typ* tc);
void SetTInteger(Typ* ti);
void SetTReal(Typ* tr);
Typ* GetTVoid(void);
Typ* GetTAddress(void);
Typ* GetTBoolean(void);
Typ* GetTChar(void);
Typ* GetTInteger(void);
Typ* GetTReal(void);
#endif