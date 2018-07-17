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
* identifier_list.h defines the behaviors of the identifier list, mainly
* insertion and printing of an indentifier list and individual identifiers
* -------------------------------------------------------------------------
*/

#include "identifierList.h"

extern ofstream fout;


SList<string>* idList(string* identifier)
{
	SList<string>* identifierList = new SList<string>;
  identifierList->Insert(*identifier);
  identifierList->Print (fout, " identifier_list=");
	return identifierList;
}

SList<string>* idList(SList<string>* identifierList, string* identifier)
{
  identifierList->Insert(*identifier);
  identifierList->Print (fout, " identifier_list=");
  return identifierList;
}


