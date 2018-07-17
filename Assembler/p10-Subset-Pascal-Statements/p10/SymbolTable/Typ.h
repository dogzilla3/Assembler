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

#ifndef Typ_h 
#define Typ_h 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include "../slist.h"

using namespace std;

enum typekind
  {typekind_void                    //type void
  ,typekind_address                 //type address
  ,typekind_boolean                 //type Boolean
  ,typekind_character               //type character
  ,typekind_integer                 //type integer
  ,typekind_real                    //type real
  ,typekind_string                  //type string
  ,typekind_range                   //type range
  ,typekind_array                   //type array
  ,typekind_subprogram              //programs, functions, and procedures
  };

class Typ {
    typekind tk;                                  //type classification
public:
    Typ();
    Typ(typekind t);                              
    string TypekindSymbol(typekind tk);
    virtual void Print(ostream& o,int indent);
    virtual int Size();
    virtual int Alignment();
    bool IsBoolean (void);                         //determines if the type is Boolean
    bool IsCharacter (void);                       //determines if the type is character
    bool IsInteger (void);                         //determines if the type is an integer
    bool IsReal (void);                            //determines if the type is real
    bool IsString (void);                          //determines if the type is string
    bool IsArray (void);                           //determines if the type is an array
    bool IsRange (void);                           //determines if the type is a range type
    bool IsVoid (void);                            //determines if the type is a void type
    bool IsSubprogram (void);                      //determines if the type is a subprogram
    string TypeChar (void);                        //Returns the P-Code type-character
};

class Scalar: public Typ {
    int storeSize;            //Number of bits required to store an entity of
                              //this type
    int alignment;            //Alignment specification for this type
public: 
    Scalar(typekind tk);
    Scalar(typekind tk,int sz,int al);
    void Print(ostream& o,int indent);
    int Size(void);
    int Alignment(void);
   
};

/*
 * Boolean inherits from Scalar
 */
class Boolean:public Scalar {
public:
    Boolean();
    Boolean(int sz,int al);
    void Print(ostream& o,int indent);
    int Size(void);
    int Alignment(void);
};

/*
* Character inherits from Scalar
*/
class Character:public Scalar {
public:
    Character();
    Character(int sz,int al);
    void Print(ostream& o,int indent);
    int Size(void);
    int Alignment(void);
};

/*
* Integer inherits from Scalar
*/
class Integer:public Scalar {
public:
    Integer();
    Integer(int sz,int al);
    void Print(ostream& o,int indent);
    int Size(void);
    int Alignment(void);
};

/*
* Real inherits from Scalar
*/
class Real:public Scalar {
public:
    Real();
    Real(int sz,int al);
    void Print(ostream& o,int indent);
    int Size(void);
    int Alignment(void);
};

/*
* Void inherits from Scalar
*/
class Void:public Scalar {
public:
    Void();
    void Print(ostream& o,int indent);
    int Size(void);
    int Alignment(void);
};

class Address :public Scalar
{
  public:
  Address ();
  void Print (ostream& o, int indent);
  int Size (void);
  int Alignment (void);
};

class Constant {
    Typ* type;                //Constant type
    string value;                 //Constant value
public:
    Constant(Typ* T,string V);
    void Print(ostream& o,int indent);
    Typ* Type(void);
    int IntegerValue(void);
    int Size(void);
    int Alignment(void);
    string ConstantValue(void);
};

/*
* Range inherits from Typ
*/
class Range :public Typ{
    Constant *lo;
    Constant *hi;
public:
    Range(Typ* t,const char* l,const char* h);
    Range(Typ* t,string l,string h);
    void Print(ostream& o,int indent);
    int Size(void);
    int Alignment(void);
    int Cardinality(void);
    string LoBound(void);
};

/*
* Array inherits from Typ
*/
class Array: public Typ {
    Typ* index;
    Typ* element;
public:
    Array(typekind tk, Range* i, Typ* e);
    Array(Typ* i,Typ* e);
    void Print(ostream& o,int indent);
    int Size(void);
    int Alignment(void);
    Range* IndexType(void);
    Typ* ElementType(void);
    int Stride(void);
};

class String: public Array {
public:
	String(Range* i, Typ* e);
};
//-----------------------------------------------------------------------------
//class Subprogram characterizes both user and standard subprograms
//The first parameter is the return type.
//If the first parameter has type typekind_void then the subprogram is a procedure.
//If the first parameter does not have type typekind_void then the subprogram 
//is a function.
//-----------------------------------------------------------------------------
class Subprogram: public Typ {
    SList<Typ*>* parameters;                      //Parameters
    Typ* returntype;                              //Return type
public:
    Subprogram(SList<Typ*>* p,Typ* rt);
    void Print(ostream& o,int indent);
    int Size(void);
    int Alignment(void);
    Typ* ReturnType (void);
    int ParameterCount (void);
};
#endif

