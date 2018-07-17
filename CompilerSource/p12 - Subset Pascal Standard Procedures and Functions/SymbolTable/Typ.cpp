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
* Typ.cpp Implements Subset Pascal Types
* -------------------------------------------------------------------------
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Typ.h"

using namespace std;

Typ::Typ():tk(typekind_void){}

Typ::Typ(typekind t):tk(t){}

void Typ::Print(ostream& o,int indent)
{   o << endl;
    for (int i=0;i<indent;i++) o << "  ";
    o << "type(" << TypekindSymbol(tk) << ")";
}
string Typ::TypekindSymbol(typekind tk)
{   switch(tk) {
        case typekind_void              : return "Void";
        case typekind_address           : return "Address";
        case typekind_boolean           : return "Boolean";
        case typekind_character         : return "Character";
        case typekind_integer           : return "Integer";
        case typekind_real              : return "Real";
        case typekind_string            : return "String";
        case typekind_range             : return "Range";
        case typekind_array             : return "Array";
        case typekind_subprogram        : return "Subprogram";
        default                         : return "Unknown";
    }
}
int Typ::Size (void) { return 0; }
int Typ::Alignment (void) { return 0; }
bool Typ::IsBoolean (void) { return tk == typekind_boolean; }
bool Typ::IsCharacter (void) { return tk == typekind_character; }
bool Typ::IsInteger (void) { return tk == typekind_integer; }
bool Typ::IsReal (void) { return tk == typekind_real; }
bool Typ::IsString (void) { return tk == typekind_string; }
bool Typ::IsArray (void) { return tk == typekind_array; }
bool Typ::IsRange (void) { return tk == typekind_range; }
bool Typ::IsVoid (void) { return tk == typekind_void; }
bool Typ::IsSubprogram (void) { return tk == typekind_subprogram; }
string Typ::TypeChar(void)
{   switch(tk) {
        case typekind_void              : return "p";
        case typekind_address           : return "a";
        case typekind_boolean           : return "b";
        case typekind_character         : return "c";
        case typekind_integer           : return "i";
        case typekind_real              : return "r";
        case typekind_string            : return "s";
        case typekind_range             : return "u";
        case typekind_array             : return "u";
        case typekind_subprogram        : return "u";
        default                         : return "u";
    }
}


Scalar::Scalar(typekind tk):Typ(tk), storeSize(1),alignment(1){}
Scalar::Scalar(typekind tk,int sz,int al):Typ(tk), storeSize(sz),alignment(al){}
void Scalar::Print(ostream& o,int indent)
{   Typ::Print(o,indent);
    o << endl;
    for (int i=0;i<indent+1;i++) o << "  ";
    o << "size(" << storeSize << ")";
    o << " ";
    o << "alignment(" << alignment << ")";
}
int Scalar::Size(void){return storeSize;}
int Scalar::Alignment(void){return alignment;}


Boolean::Boolean():Scalar(typekind_boolean,1,1){}
Boolean::Boolean(int sz,int al):Scalar(typekind_boolean,sz,al){}
void Boolean::Print(ostream& o,int indent){Scalar::Print(o,indent);}
int Boolean::Size(void){return Scalar::Size();}
int Boolean::Alignment(void){return Scalar::Alignment();}


Character::Character():Scalar(typekind_character,1,1){}
Character::Character(int sz,int al):Scalar(typekind_character,sz,al){}
void Character::Print(ostream& o,int indent){Scalar::Print(o,indent);}
int Character::Size(void){return Scalar::Size();}
int Character::Alignment(void){return Scalar::Alignment();}


Integer::Integer():Scalar(typekind_integer,1,1){}
Integer::Integer(int sz,int al):Scalar(typekind_integer,sz,al){}
void Integer::Print(ostream& o,int indent){Scalar::Print(o,indent);}
int Integer::Size(void){return Scalar::Size();}
int Integer::Alignment(void){return Scalar::Alignment();}


Real::Real():Scalar(typekind_real,1,1){}
Real::Real(int sz,int al):Scalar(typekind_real,sz,al){}
void Real::Print(ostream& o,int indent){Scalar::Print(o,indent);}
int Real::Size(void){return Scalar::Size();}
int Real::Alignment(void){return Scalar::Alignment();}


Void::Void():Scalar(typekind_void,0,0){}
void Void::Print(ostream& o,int indent){Scalar::Print(o,indent);}
int Void::Size(void){return Scalar::Size();}
int Void::Alignment(void){return Scalar::Alignment();}

Address::Address () : Scalar (typekind_address, 0, 0) {}
void Address::Print (ostream& o, int indent)
{
  Scalar::Print (o, indent);
}
int Address::Size (void) { return Scalar::Size (); }
int Address::Alignment (void) { return Scalar::Alignment (); }

Constant::Constant(Typ* T,string V):type (T),value(V){}
Typ* Constant::Type(void){return type;}
void Constant::Print(ostream& o,int indent)
{   o << endl;
    for (int a=0;a<indent;a++) o << "  ";
    o << "Constant value(" << value << ")";
    type->Print(o,indent+1);
}
int Constant::IntegerValue(void)
{   istringstream s(value);
    int i;
    s >> i;
    return i;
}
int Constant::Size(void){return type->Size();}
int Constant::Alignment(void){return type->Alignment();}
string Constant::ConstantValue(void){return value;}

Range::Range(Typ* t,const char* l,const char *h):Typ(typekind_range)
{   
    lo=new Constant(t,l);
    hi=new Constant(t,h);
}
Range::Range(Typ* t,string l,string h):Typ(typekind_range)
{   lo=new Constant(t,l);
    hi=new Constant(t,h);
}
void Range::Print(ostream& o,int indent)
{   Typ::Print(o,indent);
    lo->Print(o,indent+1);
    hi->Print(o,indent+1);
}
int Range::Cardinality(void)
{   int h=hi->IntegerValue();
    int l=lo->IntegerValue();
    return h-l+1;
}
int Range::Size(void){return lo->Size();}
int Range::Alignment(void){return lo->Alignment();}
string Range::LoBound(void){return lo->ConstantValue();}

Array::Array(Typ* i,Typ* e):Typ(typekind_array),index(i),element(e){}
Array::Array(typekind tk, Range* i, Typ* e): Typ(typekind_array),index(i),element(e){}
void Array::Print(ostream& o,int indent)
{   Typ::Print(o,indent);
    o << endl;
    for (int a=0;a<indent+1;a++) o << "  ";
    o << "Size(" << Size() << ")";
    o << endl;
    for (int a=0;a<indent+1;a++) o << "  ";
    o << "Index Type";
    index->Print(o,indent+2);
    o << endl;
    for (int a=0;a<indent+1;a++) o << "  ";
    o << "Element Type";
    element->Print(o,indent+2);
}
struct ArrayException {
    ArrayException(Array* a)
    {   cout << endl;
        cout << "Array Exception - the index type is not a range.";
        cout << endl;
        a->Print(cout,0);
        cout << endl;
    }
};
int Array::Size(void)
{   if (!(index->IsRange())) throw ArrayException(this); 
    Range* i=(Range*)index;
    int elementcount=i->Cardinality();
    int elementsize=element->Size();
    return elementcount*elementsize;
}
int Array::Alignment(void)
{   return element->Alignment();
}
Range* Array::IndexType(void){return (Range*) index;}
Typ* Array::ElementType(void){return element;}
int Array::Stride(void){return element->Size();}

String::String(Range* i, Typ* e):Array(typekind_string, i, e){}

Subprogram::Subprogram(SList<Typ*>* p,Typ* r)
    :Typ(typekind_subprogram),parameters(p),returntype(r){}
void Subprogram::Print(ostream& o,int indent)
{
    Typ::Print(o,indent);
    //------------------------------------------------------------------------
    //Process return type
    //------------------------------------------------------------------------
    o << endl;
    for (int a=0;a<indent+2;a++) o << "  ";
    o << "Return Type";  
    returntype->Print(o,indent+3);
    //------------------------------------------------------------------------
    //Process parameter types
    //------------------------------------------------------------------------
    o << endl;
    for (int a=0;a<indent+2;a++) o << "  ";
    o << "Parameter Types";  
    for (parameters->First();!parameters->IsEol();parameters->Next()) {
        Typ* p=parameters->Member();
        p->Print(o,indent+3);
    }
}
int Subprogram::Size(void){return 0;}
int Subprogram::Alignment(void){return 0;}
Typ* Subprogram::ReturnType (void) { return returntype; }
int Subprogram::ParameterCount (void) { return parameters->Count (); }
