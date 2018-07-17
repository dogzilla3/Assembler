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
* -----------------------------------------------------------------------------
* File StandardTypes.cpp makes Standard Types available to the Symbol Table. 
* -----------------------------------------------------------------------------
*
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include "StandardTypes.h"

using namespace std;


Typ* TypeVoid;
Typ* TypeAddress;
Typ* TypeBoolean;
Typ* TypeChar;
Typ* TypeInteger;
Typ* TypeReal;


void SetTVoid(Typ* tv){TypeVoid=tv;}
void SetTAddress(Typ* ta){TypeAddress=ta;}
void SetTBoolean(Typ* tb){TypeBoolean=tb;}
void SetTChar(Typ* tc){TypeChar=tc;}
void SetTInteger(Typ* ti){TypeInteger=ti;}
void SetTReal(Typ* tr){TypeReal=tr;}
Typ* GetTVoid(void){return TypeVoid;}
Typ* GetTAddress(void){return TypeAddress;}
Typ* GetTBoolean(void){return TypeBoolean;}
Typ* GetTChar(void){return TypeChar;}
Typ* GetTInteger(void){return TypeInteger;}
Typ* GetTReal(void){return TypeReal;}

