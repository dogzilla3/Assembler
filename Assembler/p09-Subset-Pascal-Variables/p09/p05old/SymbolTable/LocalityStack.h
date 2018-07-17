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
* A LocalityStack is a stack of localities.  Each locality stores the symbols
* created in that locality.  Member tos corresponds to the lexical level.
* Standard or native symbols like, integer, char, real, etc., are stored
* at lexical level zero (0).
* -------------------------------------------------------------------------
*/


#ifndef LocalityStack_h 
#define LocalityStack_h 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Typ.h"
#include "Sym.h"
#include "Namespace.h"
#include "Locality.h"

using namespace std;
//-----------------------------------------------------------------------------
//A LocalityStack is a stack of localities.  Each locality stores the symbols
//created in that locality.  Member top corresponds to the lexical level. 
//Standard or native symbols like, integer, char, real, etc., are stored
//at lexical level zero (0).
//-----------------------------------------------------------------------------
class LocalityStack {
    int size;                 //Maximum number of localities in the symbol table
  public: int top;                  //Index of the locality on top of the stack
    Locality** LocalityPtrs;  //Points to an array of pointers to Localities
public:
    LocalityStack(int sz=100);//Allocate storage for the stack
    ~LocalityStack();         //Reclaim storage for the stack
    bool IsEmpty(void);       //Is the stack empty?
    bool IsFull(void);        //Is the stack full?
    void Push(Locality* L);   //Push a new locality on the stack
    Locality* Pop(void);      //Pop a locality from the stack
    Locality* Top(void);      //Obtain the locality on top of the stack
    Sym* Find(string& id);    //Find a symbol in the stack
    Sym* Find(char* id);      //Find a symbol in the stack
    void Insert(Sym* S);      //Insert a symbol in the locality on top of the
                              //stack
    int LexicalLevel(void);   //Return the lexical level of the locality on
                              //top of the stack
    void Print(ostream& o);   //Print all the localities currently on the
                              //stack
    void Print                //Print the locality on top of the stack
       (ostream& o            
       ,int ll
       );
};
#endif
