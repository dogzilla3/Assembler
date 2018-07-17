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
* File SymbolTable.cpp implements member functions of class SymbolTable
* -----------------------------------------------------------------------------
*
*
*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include "../slist.h"
#include "Typ.h"
#include "StandardTypes.h"
#include "Sym.h"
#include "Label.h"
#include "Namespace.h"
#include "Locality.h"
#include "LocalityStack.h"
#include "SymbolTable.h"

using namespace std;


SymbolTable::SymbolTable()
{   NewLocality();   
    Standard();
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
SymbolTable::~SymbolTable()
{   PopLocality();
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void SymbolTable::Standard(void)
{   StandardTypes();
    StandardConstants();
    StandardProcedures();
    StandardFunctions();
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void SymbolTable::StandardTypes(void)
{       
    typvoid=new Void();
    SetTVoid(typvoid);
    
    typaddress=new Address();
    SetTAddress(typaddress);
    
    typboolean=new Boolean();
    SetTBoolean(typboolean);
    Sym* sboolean=new TypeSymbol("boolean",typboolean);
    Insert(sboolean);

    typchar=new Character();
    SetTChar(typchar);
    Sym* schar=new TypeSymbol("char",typchar);
    Insert(schar);

    typinteger=new Integer();
    SetTInteger(typinteger);
    Sym* sinteger=new TypeSymbol("integer",typinteger);
    Insert(sinteger);

    typreal=new Real();
    SetTReal(typreal);
    Sym* sreal=new TypeSymbol("real",typreal);
    Insert(sreal);
}
//-----------------------------------------------------------------------------
//Function StandardConstants initalizes standard constants.
//-----------------------------------------------------------------------------
void SymbolTable::StandardConstants(void)
{  Sym* sfalse=new ConstantSymbol("false",typboolean,"0");
   Insert(sfalse);
   Sym* strue= new ConstantSymbol("true" ,typboolean,"1");
   Insert(strue);
}
void SymbolTable::StandardProcedures(void)
{  Sym* wrb=new StandardProcedureSymbol("writeboolean"    ,"wrb");
   Insert(wrb);
   Sym* wrc=new StandardProcedureSymbol("writechar"       ,"wrc");
   Insert(wrc);
   Sym* wri=new StandardProcedureSymbol("writeinteger"    ,"wri");
   Insert(wri);
   Sym* wre=new StandardProcedureSymbol("writeexponential","wre");
   Insert(wre); 
   Sym* wrf=new StandardProcedureSymbol("writefixed"      ,"wrf");
   Insert(wrf);
   Sym* wln=new StandardProcedureSymbol("writeln"         ,"wln");
   Insert(wln);
   Sym* wrs=new StandardProcedureSymbol("writestring"     ,"wrs");
   Insert(wrs);
   Sym* rdc=new StandardProcedureSymbol("readchar"        ,"rdc");
   Insert(rdc);
   Sym* rdi=new StandardProcedureSymbol("readinteger"     ,"rdi");
   Insert(rdi);
   Sym* rdr=new StandardProcedureSymbol("readreal"        ,"rdr");
   Insert(rdr);
   Sym* rds=new StandardProcedureSymbol("readstring"      ,"rds");
   Insert(rds);
   Sym* rln=new StandardProcedureSymbol("readln"          ,"rln");
   Insert(rln);
}
void SymbolTable::StandardFunctions(void)
{  Sym* abs=new StandardFunctionSymbol("abs"  ,"abs");
   Insert(abs);
   Sym* sqt=new StandardFunctionSymbol("sqrt" ,"sqt");
   Insert(sqt);
   Sym* exp=new StandardFunctionSymbol("exp" ,"exp");
   Insert(exp);
   Sym* ln=new StandardFunctionSymbol("ln" ,"ln");
   Insert(ln);
   Sym* trc=new StandardFunctionSymbol("trunc","trc");
   Insert(trc);
   Sym* rnd=new StandardFunctionSymbol("round","rnd");
   Insert(rnd);
   Sym* ord=new StandardFunctionSymbol("ord"  ,"ord");
   Insert(ord);
   Sym* chr=new StandardFunctionSymbol("chr"  ,"chr");
   Insert(chr);
   Sym* inc=new StandardFunctionSymbol("succ" ,"inc");
   Insert(inc);
   Sym* dec=new StandardFunctionSymbol("pred" ,"dec");
   Insert(dec);
}
//-----------------------------------------------------------------------------
//Print the symbols in the Symbol Table stored at the current lexical level
//-----------------------------------------------------------------------------
void SymbolTable::Print(ostream& o)
{   if (curLocality) curLocality->Print(o);   
}

//-----------------------------------------------------------------------------
//Print the symbols in the Symbol Table stored at the current lexical level
//-----------------------------------------------------------------------------
void SymbolTable::PrintAll (ostream& o)
{
  if (curLocality) LocalityStack::PrintAll (o);
}
//-----------------------------------------------------------------------------
//Function NewLocality creates a new locality and pushes it on the stack.
//-----------------------------------------------------------------------------
void SymbolTable::NewLocality(void)
{   curLocality=new Locality(LexicalLevel()+1);   //Create a new locality
    Push(curLocality);                            //Push the locality on the 
                                                  //LocalityStack
}
//-----------------------------------------------------------------------------
//Function PopLocality pops the locality from the top of the LocalityStack
//-----------------------------------------------------------------------------
void SymbolTable::PopLocality(void)
{ 
  
  curLocality =Pop();                             //Pop the current Locality from
                                                  //the LocalityStack
  curLocality =Top();                             //Make L the top of the locality stack
}

Typ* SymbolTable::TVoid(void){return typvoid;}
Typ* SymbolTable::TAddress(void){return typaddress;}
Typ* SymbolTable::TChar(void){return typchar;}
Typ* SymbolTable::TInteger(void){return typinteger;}
Typ* SymbolTable::TReal(void){return typreal;}
Typ* SymbolTable::TBoolean(void){return typboolean;}
