#ifndef Height_h
#define Height_h 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;
//-------------------------------------------------------------------------
//Application include files
//-------------------------------------------------------------------------
#include "SymbolTable/PCode.h"
#include "SymbolTable/Exp.h"
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
class Height {
   int C;                     //Current height of the computation stack
   int M;                     //Maximum height of the computation stack
   void InitStackDelta(void);
   void Compute(PCode* P);    //Add the difference contributed by PCode P
                              //to the running total.
public:
   Height();
   int Maximum(void);         //Return the maximum height of the computation stack
   void FindHeight(Exp* E);   //Find the height of the expression E
};
#endif

