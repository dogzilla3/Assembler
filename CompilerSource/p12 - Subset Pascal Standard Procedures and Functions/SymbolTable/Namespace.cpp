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
* A Namespace is a collection of Symbol Descriptors that were declared in
* a particular locality or in a record.  The Symbol Descriptors describe
* type names, variables, and subprograms if the locality is a locality defined
* by a program or a subprogram.  The Symbol Descriptors describe fields in
* the locality is defined by a record
* -------------------------------------------------------------------------
*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Namespace.h"
using namespace std;


Namespace::Node::Node(Sym* Symbol):LNode(0), SymbolDesc(Symbol),RNode(0){}
Namespace::Node* Namespace::Insert(Node* N,Sym* S)
{   if (!N) return new Node(S);  
    if (S->Id()==N->SymbolDesc->Id()) return N;
    if (S->Id()<N->SymbolDesc->Id()) {
        N->LNode=Insert(N->LNode, S);
    } else {
        N->RNode=Insert(N->RNode, S);
    }
    return N;
}

void Namespace::Node::Print(ostream& o,int level)
{ 
  SymbolDesc->Print(o,level);
}

Namespace::Namespace():Root(0){}

void Namespace::Kill(Node* N)
{   if (!N) return;
    Kill(N->LNode);
    Kill(N->RNode);
    delete N;
}

Namespace::~Namespace() {Kill(Root);}

void Namespace::Insert(Sym* S)
{

  Root=Insert(Root,S);
}

Sym* Namespace::Find(Node* N,string& key)
{   if (!N) return 0;
    if (key==N->SymbolDesc->Id()) return N->SymbolDesc;
    if (key<N->SymbolDesc->Id()) {
        return Find(N->LNode,key);
    } else {
        return Find(N->RNode,key);
    }
}

Sym* Namespace::Find(string& key){return Find(Root,key);}

void Namespace::Print(Node* N, ostream& o,int level)
{
    if (!N) return;
    Print(N->LNode,o,level);
    N->Print(o,level);
    Print(N->RNode,o,level);
}

void Namespace::Print(ostream& o,int level)
{   o << endl;
    Print(Root,o,level);
    o << endl;
}

void Namespace::Print(ostream& o){Print(o,0);}
