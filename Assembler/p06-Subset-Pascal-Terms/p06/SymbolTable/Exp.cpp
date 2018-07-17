

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

#include "PCode.h"
#include "Typ.h"
#include "Sym.h"
#include "Exp.h"

Exp::Exp(Exp* l, Exp* r, Typ* t, PCode* p) : leftExp (l), rightExp (r), typ(t), pCode(p) {}

Exp::Exp(Typ* t, PCode* p) : leftExp(0), rightExp (0), typ (t), pCode (p) {}

void Exp::PPrint(ostream& o) { pCode->Print(o); }

void Exp::TPrint(ostream& o, int depth) { typ->Print(o,depth); }

void Exp::Print(ostream& o)
{
	if (leftExp) leftExp->Print(o);

	if (rightExp) rightExp->Print(o);

  pCode->Print(o);
}

Typ* Exp::Type(){ return typ; }

void Exp::LeftAppend(Exp* L)
{
	Exp* e = this;
	Exp* p = e;
	while (e) {
		p = e;
		e = e->leftExp;
	}
  p->leftExp = L;
}

bool Exp::IsBoolean (void) { return typ->IsBoolean (); }
bool Exp::IsCharacter (void) { return typ->IsCharacter (); }
bool Exp::IsInteger (void) { return typ->IsInteger (); }
bool Exp::IsReal (void) { return typ->IsReal (); }