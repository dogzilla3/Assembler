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
* -------------------------------------------------------------------------
*
*
* -------------------------------------------------------------------------
* The file identifier_List. defines a container for identifiers as well as overloaded
* brackets to access the data
* -------------------------------------------------------------------------
*/

#ifndef IDENTIFIER_LIST_H
#define IDENTIFIER_LIST_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

#include "slist.h"

SList<string>* idList (string*);
SList<string>* idList (SList<string>*, string*);

#endif
