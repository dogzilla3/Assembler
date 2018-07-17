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
* Typ.h Defines Subset Pascal Types
* -------------------------------------------------------------------------
*/

#ifndef Sym_h
#define Sym_h 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Typ.h"

using namespace std;

//Symbol classifications
enum symkind
    {symkind_constant              //Constant symbol
    ,symkind_variable              //Variable symbol
    ,symkind_type                  //Type symbol
    ,symkind_procedure             //Type procedure
    ,symkind_function              //Type function
    ,symkind_program               //Type program
    ,symkind_standardprocedure     //Type standard procedure
    ,symkind_standardfunction      //type standard function
    };
//---------------------------------------------------------------------------
//All Symbols have, at minimum, a symbol classification - symkind -, an 
//identifier, and a type
//---------------------------------------------------------------------------
class Sym {
    symkind symbolkind;                           //Symbol classification
    string id;                                    //Symbol identifier
    Typ* type;                                       //Symbol type
public:
    Sym(symkind k,const char* i,Typ* u); 
    Sym(symkind k,string i,Typ* u);
    string SymkindSymbol(symkind sk);
    symkind Symkind (void);                        //Return the enumeration constant 
                                                   //for this symbol
    virtual void Print(ostream& o,int indent);
    string Id(void);                              //Returns the Symbol's id.
    Typ* Type(void);                              //Return the Symbol's type
    bool IsVariableSymbol(void);                  //Is the symbol a variable
    bool IsProgramSymbol(void);                   //Is the symbol a program
    bool IsTypeSymbol(void);                      //Is the symbol a type
};


class TypeSymbol: public Sym {
public:
    TypeSymbol(const char* id,Typ* t);
    TypeSymbol(string id,Typ* t);
    void Print(ostream& o,int indent);
};


class ConstantSymbol: public Sym {
    Constant* constant;
public:
    ConstantSymbol(const char* id,Typ* t,const char* v);
    ConstantSymbol(string id,Typ* t,const char* v);
    ConstantSymbol(const char* id,Typ* t,string v);
    ConstantSymbol(string id,Typ* t,string v);
    void Print(ostream& o,int indent);
};


class StandardSubprogramSymbol: public Sym {
    string cspid;                                 //Call Standard Procedure ID
public:
    StandardSubprogramSymbol(symkind sk,string id,string cid);
    void Print(ostream& id,int indent);
};


class StandardProcedureSymbol: public StandardSubprogramSymbol {
public:
    StandardProcedureSymbol(const char* id,const char* cid);
    StandardProcedureSymbol(const char* id,string cid);
    StandardProcedureSymbol(string id,const char* cid);
    StandardProcedureSymbol(string id,string cid);
    void Print(ostream& o,int indent);
};


class StandardFunctionSymbol: public StandardSubprogramSymbol {
public:
    StandardFunctionSymbol(const char* id,const char* cid);
    StandardFunctionSymbol(const char* id,string cid);
    StandardFunctionSymbol(string id,const char* cid);
    StandardFunctionSymbol(string id,string cid);
    void Print(ostream& o,int indent);
};


class VariableSymbol: public Sym {
    int lexicallevel;
    int address;
public:
    VariableSymbol(const char* id,Typ* t,int ll=0,int a=5);
    VariableSymbol(string id,Typ* t,int ll=0,int a=5);
    int LexicalLevel (void);
    int Address (void);
    void Print(ostream& o,int indent);
    void setLexicalLevel(int ll);
    void setAddress(int a);
};


class SubprogramSymbol: public Sym {
    int lexicallevel;                             //Lexical level of subprogram
    string elabel;                                //Entry label
    string splabel;                               //Stack pointer label
    string eplabel;                               //Extreme pointer label
public:
    SubprogramSymbol(symkind sk,string id,Typ* t,int ll);
    void Print(ostream& o,int indent);
    int LexicalLevel(void);
    string ELabel(void);
    string SPLabel(void);
    string EPLabel(void);
    Typ* ReturnType(void);
    int ParameterCount(void);
};


class ProcedureSymbol: public SubprogramSymbol {
public:
    ProcedureSymbol(const char* id,Typ* t,int ll);
    ProcedureSymbol(string id,Typ* t,int ll);
    void Print(ostream& o,int indent);
};


class FunctionSymbol : public SubprogramSymbol
{
  public:
  FunctionSymbol (const char* id, Typ* t, int ll);
  FunctionSymbol (string id, Typ* t, int ll);
  void Print (ostream& o, int indent);
};


class ProgramSymbol : public SubprogramSymbol
{
  public:
  ProgramSymbol (const char* id);
  ProgramSymbol (string id);
  void Print (ostream& o, int indent);
};
#endif
