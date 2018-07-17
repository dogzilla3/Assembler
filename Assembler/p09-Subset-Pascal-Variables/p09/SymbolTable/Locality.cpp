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
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Namespace.h"
#include "Locality.h"

using namespace std;

struct AlignmentException {
    AlignmentException(int al)
    {   cout << endl;
        cout << "Alignment Exception - an alignment can never be zero.";
        cout << endl;
    }
};

Locality::Locality(int ll):lexicallevel(ll),offset(5){}

int Locality::Offset(void){return offset;}
int Locality::Offset(int size,int alignment)
{    //-------------------------------------------------------------------
     //Variables and fields must be aligned on the boundaries given by
     //their types.  For example, floating point values having type
     //real must be aligned on 64-bit boundaries.
     //-------------------------------------------------------------------
     //Determine if the current offset can be used to allocate the
     //input variable or field.
     //-------------------------------------------------------------------
     if (alignment==0) throw AlignmentException(alignment);
     int remainder=offset%alignment;
     //-------------------------------------------------------------------
     //Add unused space to make the current offset suitable to allocate
     //storage for the next item
     //-------------------------------------------------------------------
     if (remainder) offset=offset+(alignment-remainder);
     int o=offset;        //Record and return the current offset
     offset=offset+size;  //Allocate storage for the given item
     return o;
}

void Locality::Print(ostream& o)
{   o << endl;
    o << "Locality: lexical level " << lexicallevel;
    Namespace::Print(o, lexicallevel);
}

int Locality::LexicalLevel(void){return lexicallevel;}

void Locality::Insert(Sym* S)
{
  if (S->IsVariableSymbol()) {        
        VariableSymbol* vs=(VariableSymbol*)S;
        vs->setLexicalLevel(LexicalLevel());
        Typ* T=S->Type(); 
        int sz =T->Size();
        int al=T->Alignment();
        int address=Offset(sz,al);
        vs->setAddress(address);
    }
    Namespace::Insert(S);
}
