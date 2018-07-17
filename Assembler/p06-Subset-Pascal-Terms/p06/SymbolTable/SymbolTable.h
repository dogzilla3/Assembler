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
* File SymbolTable.h defines the attributes of SymbolTables for the symbol table
* -----------------------------------------------------------------------------
*
*
*/


#ifndef SymbolTable_h 
#define SymbolTable_h 1


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Typ.h"
#include "Sym.h"
#include "Label.h"
#include "Namespace.h"
#include "Locality.h"
#include "LocalityStack.h"

using namespace std;


class SymbolTable : public LocalityStack {
    Locality* curLocality;              //Points to the current locality

    Typ* typaddress;            //Points to standard type address
    Typ* typvoid;               //Points to standard type void
    Typ* typchar;               //Points to standard type char
    Typ* typinteger;            //Points to standard type integer
    Typ* typreal;               //Points to standard type real
    Typ* typboolean;            //Points to standard type boolean
    Typ* typstring;             //Points to standard type string
public:
    SymbolTable();            //Creates locality 0 and pushes it on the locality
                              //Stack
    ~SymbolTable();           //SymbolTable post processing
    //-------------------------------------------------------------------------
    //Function StandardTypes puts Subset Pascal Standard Types in the symbol
    //table at locality zero.  Standard types include integer,char,real,
    //and boolean.
    //-------------------------------------------------------------------------
    void Standard(void);
    void StandardTypes(void);
    void StandardConstants(void);
    void StandardProcedures(void);
    void StandardFunctions(void);
    void Print(ostream& o);   //Print the symbols in the current lexical level
    void NewLocality(void);   //Create a new locality and push it on the
                              //Locality Stack
    void PopLocality(void);   //Pop the current locality from the LocalityStack
                              //and replace it with the locality next to the
                              //Top of the stack.

    Typ* TAddress(void);      //Returns internal type address
    Typ* TVoid(void);         //Returns internal type void
    Typ* TChar(void);         //Returns standard type char
    Typ* TInteger(void);      //Returns standard type integer
    Typ* TReal(void);         //Returns standard type real
    Typ* TBoolean(void);      //Returns standard type Boolean

};        
#endif
