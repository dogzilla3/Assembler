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

#ifndef Namespace_h 
#define Namespace_h 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Typ.h"
#include "Sym.h"

using namespace std;


class Namespace {
    //-------------------------------------------------------------------------
    //A Node in a binary has left and right subordinate trees and a pointer
    //to a Symbol Descriptor
    //-------------------------------------------------------------------------
    struct Node {
        Node* LNode;          //Points to the left subordinate tree
        Sym* SymbolDesc;      //Points to a Symbol Descriptor
        Node* RNode;          //Points to the right subordinate tree
        Node(Sym* S);         //Constructs a leaf Node
        void  Print           //Prints a Symbol Descriptor to
             (ostream& o      //Output stream o
             ,int level       //Indented two spaces for each level
             );
    };
    Node* Root;              //Root of the Namespace
    Node* Insert             //Insert Symbol Descriptor S at Node N and
        (Node* N             //return a pointer to the node where S was
        ,Sym* S              //inserted
        );
    void Kill(Node* N);      //Recursively reclaim storage for all the
                             //Nodes in the tree using a postorder
                             //traversal
    Sym*  Find               //Find the Symbol Descriptor that describes
        (Node* N             //the identifier k.  Begin the search at Node
        ,string& k           //N.
        );
    void  Print              //Recursively print all the nodes in the
        (Node* N             //Namespace using an inorder traversal beginning
        ,ostream& o          //with Node N.
        ,int level           //Indent two spaces times the value of level
        );
public:
   Namespace();              //Create an empty Namespace
   ~Namespace();             //Reclaim storage for all the Nodes in the
                             //Namespace
   void Insert(Sym* S);      //Insert Symbol Descriptor S in the Namespace
   Sym* Find(string& k);     //Find the Symbol Descriptor for identifier k
                             //or return 0 if not found
   void Print                //Initiate the recursive printing of all the
                             //Symbol Descriptors in the Namespace
        (ostream& o          //Print to output stream o
        ,int level           //Begin printing at level zero
        );
   void Print(ostream& o);   //Print the Namespace
};
#endif
