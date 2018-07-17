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
#include "Typ.h"
#include "Sym.h"
#include "Namespace.h"
#include "Locality.h"
#include "LocalityStack.h"

using namespace std;

struct LocalityStackException {
    LocalityStackException(const char* m)
    {   cout << endl;
        cout << "I am the LocalityStack and I am " << m << ".";
        cout << endl;
    }
};


LocalityStack::LocalityStack(int sz):size(sz),top(-1){LocalityPtrs=new Locality*[size];}

LocalityStack::~LocalityStack(){if (LocalityPtrs) delete[] LocalityPtrs;}

bool LocalityStack::IsEmpty(void){return top==-1;}

bool LocalityStack::IsFull(void){return top>=size-1;}

void LocalityStack::Push(Locality* V)
{   if (IsFull()) throw LocalityStackException("full");
    LocalityPtrs[++top]=V;
}

Locality* LocalityStack::Pop(void)
{   if (IsEmpty()) throw LocalityStackException("empty");
    return LocalityPtrs[top--];
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Locality* LocalityStack::Top(void)
{   if (IsEmpty()) return 0; else return LocalityPtrs[top]; 
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Sym* LocalityStack::Find(char* id){string s(id); return Find(s);}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Sym* LocalityStack::Find(string& id)
{   for (int l=top;l>=0;l--) {
        Sym* s= LocalityPtrs[l]->Find(id);
        if (s) return s;
    }
    return 0;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void LocalityStack::Insert(Sym* S)
{
  LocalityPtrs[top]->Insert(S);
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int LocalityStack::LexicalLevel(void){return top;}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void LocalityStack::Print(ostream& o)
{
  for (int a=0;a<=top;a++) {
        o << endl << "Lexical level: " << a;
        LocalityPtrs[a]->Print(o);     
    }
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void LocalityStack::Print(ostream& o,int ll)
{   o << endl << "Lexical level: " << ll;
    LocalityPtrs[top]->Print(o);
}
