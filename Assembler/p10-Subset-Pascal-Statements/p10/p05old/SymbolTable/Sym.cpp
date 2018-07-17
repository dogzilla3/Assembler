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
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Typ.h"
#include "Sym.h"
#include "Label.h"
#include "yyerror.h"

extern Typ* TypeVoid;
extern Typ* TypeAddress;
extern Typ* TypeBoolean;
extern Typ* TypeChar;
extern Typ* TypeInteger;
extern Typ* TypeReal;
Label label;

using namespace std;



static Typ* tvoid=new Void();
//-----------------------------------------------------------------------------
//class Sym member functions
//-----------------------------------------------------------------------------
Sym::Sym(symkind k,const char* i,Typ* u):symbolkind(k),id(i),type(u){}
Sym::Sym(symkind k,string i,Typ* u):symbolkind(k),id(i),type(u){}
//-----------------------------------------------------------------------------
string Sym::SymkindSymbol(symkind sk) 
{   switch (sk) {
        case symkind_constant          : return "Constant Symbol";
        case symkind_variable          : return "Variable Symbol";
        case symkind_type              : return "Type Symbol";
        case symkind_procedure         : return "Procedure Symbol";
        case symkind_function          : return "Function Symbol";
        case symkind_program           : return "Program Symbol";
        case symkind_standardprocedure : return "Standard Procedure Symbol";
        case symkind_standardfunction  : return "Standard Function Symbol";
        default                        : return "Unknown Symbol";
    }
}
symkind Sym::Symkind (void) { return symbolkind; }
//-----------------------------------------------------------------------------
void Sym::Print(ostream& o,int indent)
{   o << endl;
    for (int a=0;a<indent;a++) o << "  ";    
    o << "Symbol(" << SymkindSymbol(symbolkind) << ")";
    o << " ";
    o << "id(" << id << ")";
    type->Print(o,indent+1);
}
//-----------------------------------------------------------------------------
string Sym::Id(void){return id;}
//-----------------------------------------------------------------------------
Typ* Sym::Type(void){return type;}
//-----------------------------------------------------------------------------
bool Sym::IsVariableSymbol(void){return symbolkind==symkind_variable;}
bool Sym::IsProgramSymbol(void){return symbolkind==symkind_program;}
bool Sym::IsTypeSymbol(void){return symbolkind==symkind_type;}
//-----------------------------------------------------------------------------
//class TypeSymbol
//-----------------------------------------------------------------------------
TypeSymbol::TypeSymbol(const char* id, Typ* t):Sym(symkind_type,id,t){}
TypeSymbol::TypeSymbol(string id, Typ* t):Sym(symkind_type,id,t){}
void TypeSymbol::Print(ostream& o,int indent)
{   Sym::Print(o,indent);
}
//-----------------------------------------------------------------------------
//class ConstantSymbol
//-----------------------------------------------------------------------------
ConstantSymbol::ConstantSymbol(const char* id,Typ* t,const char* v)
    :Sym(symkind_constant,id,t){constant=new Constant(t,v);}
ConstantSymbol::ConstantSymbol(string id,Typ* t,const char* v)
    :Sym(symkind_constant,id,t){constant=new Constant(t,v);}
ConstantSymbol::ConstantSymbol(const char* id,Typ* t,string v)
    :Sym(symkind_constant,id,t){constant=new Constant(t,v);}
ConstantSymbol::ConstantSymbol(string id,Typ* t,string v)
    :Sym(symkind_constant,id,t){constant=new Constant(t,v);}
void ConstantSymbol::Print(ostream& o,int indent)
{   Sym::Print(o,indent);
    constant->Print(o,indent+1);
}
//-----------------------------------------------------------------------------
//class StandardSubprogramSymbol
//-----------------------------------------------------------------------------
StandardSubprogramSymbol::StandardSubprogramSymbol(symkind sk,string id,string cid)
    :Sym(sk,id,TypeVoid),cspid(cid){}
void StandardSubprogramSymbol::Print(ostream& o,int indent)
{   Sym::Print(o,indent);
    o << endl;
    for (int a=0;a<indent+1;a++) o << "  ";
    o << "cspid(" << cspid << ")";
}
//-----------------------------------------------------------------------------
//class StandardProcedureSymbol
//-----------------------------------------------------------------------------
StandardProcedureSymbol::StandardProcedureSymbol(const char* id,const char* cid)
   :StandardSubprogramSymbol(symkind_standardprocedure,id,cid){}
StandardProcedureSymbol::StandardProcedureSymbol(const char* id,string cid)
   :StandardSubprogramSymbol(symkind_standardprocedure,id,cid){}
StandardProcedureSymbol::StandardProcedureSymbol(string id,const char* cid)
   :StandardSubprogramSymbol(symkind_standardprocedure,id,cid){}
StandardProcedureSymbol::StandardProcedureSymbol(string id,string cid)
   :StandardSubprogramSymbol(symkind_standardprocedure,id,cid){}
void StandardProcedureSymbol::Print(ostream& o,int indent)
{   StandardSubprogramSymbol::Print(o,indent);
}
//-----------------------------------------------------------------------------
//class StandardFunctionSymbol
//-----------------------------------------------------------------------------
StandardFunctionSymbol::StandardFunctionSymbol(const char* id,const char* cid)
   :StandardSubprogramSymbol(symkind_standardfunction,id,cid){}
StandardFunctionSymbol::StandardFunctionSymbol(const char* id,string cid)
   :StandardSubprogramSymbol(symkind_standardfunction,id,cid){}
StandardFunctionSymbol::StandardFunctionSymbol(string id,const char* cid)
   :StandardSubprogramSymbol(symkind_standardfunction,id,cid){}
StandardFunctionSymbol::StandardFunctionSymbol(string id, string cid)
   :StandardSubprogramSymbol(symkind_standardfunction,id,cid){}
void StandardFunctionSymbol::Print(ostream& o,int indent)
{   StandardSubprogramSymbol::Print(o,indent);
}
//-----------------------------------------------------------------------------
//class VariableSymbol
//-----------------------------------------------------------------------------
VariableSymbol::VariableSymbol (const char* id, Typ* t, int ll, int a)
  :Sym (symkind_variable, id, t), lexicallevel (ll), address (a)
{}
VariableSymbol::VariableSymbol (string id, Typ* t, int ll, int a)
  : Sym (symkind_variable, id, t), lexicallevel (ll), address (a)
{}
void VariableSymbol::Print (ostream& o, int indent)
{
  Sym::Print (o, indent);
  o << endl;
  for (int a = 0; a<indent + 1; a++) o << "  ";
  o << "lexicallevel(" << lexicallevel << ") address(" << address << ")";
}
void VariableSymbol::setLexicalLevel (int ll) { lexicallevel = ll; }
void VariableSymbol::setAddress (int a) { address = a; }
int VariableSymbol::LexicalLevel (void) { return lexicallevel; }
int VariableSymbol::Address (void) { return address; }
//-----------------------------------------------------------------------------
//class SubprogramSymbol
//-----------------------------------------------------------------------------
SubprogramSymbol::SubprogramSymbol(symkind sk,string id,Typ* t,int ll)
    :Sym(sk,id,t),lexicallevel(ll){elabel=label.New();splabel=label.New();eplabel=label.New();}

void SubprogramSymbol::Print(ostream& o,int indent)
{
    Sym::Print(o,indent);
    o << endl;
    for (int a=0;a<indent+1;a++) o << "  ";
    o << "lexicallevel(" << lexicallevel << ")";
    o << " ";
    o << "elabel(" << elabel << ")";
    o << " ";
    o << "splabel(" << splabel << ")";
    o << " ";
    o << "eplabel(" << eplabel << ")";
}
int SubprogramSymbol::LexicalLevel(void){return lexicallevel;}
string SubprogramSymbol::ELabel(void){return elabel;}
string SubprogramSymbol::SPLabel(void){return splabel;}
string SubprogramSymbol::EPLabel(void){return eplabel;}
int SubprogramSymbol::ParameterCount(void)
{    Typ* T=Sym::Type();
     Subprogram* ST=0;
     if (T->IsSubprogram()) {
         ST=(Subprogram*)T; 
         return ST->ParameterCount();
     } else {
         yyerror("Semantic error: no return type."); 
     }
}
Typ* SubprogramSymbol::ReturnType(void)
{    Typ* T=Sym::Type();
     Subprogram* ST=0;
     if (T->IsSubprogram()) {
         ST=(Subprogram*)T; 
         return ST->ReturnType();
     } else {
         yyerror("Semantic error: no return type."); 
     }
}

//-----------------------------------------------------------------------------
//class ProcedureSymbol
//-----------------------------------------------------------------------------
ProcedureSymbol::ProcedureSymbol(const char* id,Typ* t,int ll)
    :SubprogramSymbol(symkind_procedure,id,t,ll){}
ProcedureSymbol::ProcedureSymbol(string id,Typ* t,int ll)
    :SubprogramSymbol(symkind_procedure,id,t,ll){}
void ProcedureSymbol::Print(ostream& o,int indent)
{   SubprogramSymbol::Print(o,indent);
}
//-----------------------------------------------------------------------------
//class FunctionSymbol
//-----------------------------------------------------------------------------
FunctionSymbol::FunctionSymbol(const char* id,Typ* t,int ll)
    :SubprogramSymbol(symkind_function,id,t,ll){}
FunctionSymbol::FunctionSymbol(string id,Typ* t,int ll)
    :SubprogramSymbol(symkind_function,id,t,ll){}
void FunctionSymbol::Print(ostream& o,int indent)
{   SubprogramSymbol::Print(o,indent);
}
//-----------------------------------------------------------------------------
//class ProgramSymbol
//-----------------------------------------------------------------------------
ProgramSymbol::ProgramSymbol(const char* id)
    :SubprogramSymbol(symkind_program,id,TypeVoid,0){}
ProgramSymbol::ProgramSymbol(string id)
    :SubprogramSymbol(symkind_program,id,TypeVoid,0){}
void ProgramSymbol::Print(ostream& o,int indent)
{   SubprogramSymbol::Print(o,indent);
}
