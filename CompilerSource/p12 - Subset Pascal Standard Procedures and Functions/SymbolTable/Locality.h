/*
* -------------------------------------------------------------------------
* Author: Gregory Levy
* Student ID: *20444120
* E-Mail: glevy@uco.edu
* Course: CMSC 4173 - Translator Design
* CRN: 25838, Spring, 2018
* Project: p02 - Subset Pascal Parser
* Due: January 24, 2018
* Account: tt072
*
* Author: William Bohanan
* Student ID: *20276952
* E-Mail: wbohanan@uco.edu
* Course: CMSC 4173 - Translator Design
* CRN: 25838, Spring, 2018
* Project: p02 - Subset Pascal Parser
* Due: January 24, 2018
* Account: tt067
* -------------------------------------------------------------------------
*
*
* -------------------------------------------------------------------------
* A locality is a Namespace and functions that manage addresses relative to
* the start of the locality.
* -------------------------------------------------------------------------
*
*/

#ifndef Locality_h 
#define Locality_h 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Typ.h"
#include "Sym.h"
#include "Namespace.h"

using namespace std;

class Locality : public Namespace {
    int lexicallevel;         //Lexical Level of the Locality
    int offset;               //Next available bit-address
public:
    Locality(int ll);         //Record the lexical level of the locality and 
                              //initialize the relative address counter
    int Offset(void);         //Return the current offset
    int Offset                //Return the starting bit-address for the 
                              //next available variable or field based
                              //on parameters size and alignment
        (int size             //Number of bits required by a variable or
                              //field of type requesting storage
        ,int alignment        //Alignment specification given in bits
                              //for the variable or field of the type
                              //requesting storage
        );
    void Print(ostream& o);   //Print all the symbols in this locality
    int LexicalLevel(void);   //Return the lexical level of the locality
    void Insert(Sym* S);      //Insert Symbol Descriptor S into the Namespace
};


#endif
