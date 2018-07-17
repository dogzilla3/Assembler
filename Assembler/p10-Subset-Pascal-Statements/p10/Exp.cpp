

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

#include "PCode.h"
#include "Typ.h"
#include "Sym.h"
#include "Exp.h"

Exp::Exp(Exp* l, Exp* r, Typ* t, PCode* p) : LExp(l), RExp(r), T(t), P(p) {}

Exp::Exp(Typ* t, PCode* p) : LExp(0), RExp(0), T(t), P(p) {}

void Exp::PPrint(ostream& o) { P->Print(o); }

void Exp::TPrint(ostream& o, int depth) { T->Print(o,depth); }

void Exp::Print(ostream& o)
{
	if (LExp) LExp->Print(o);

	if (RExp) RExp->Print(o);

	P->Print(o);
}

Typ* Exp::Type(){ return T; }

void Exp::LeftAppend(Exp* L)
{
	Exp* e = this;
	Exp* p = e;
	while (e) {
		p = e;
		e = e->LExp;
	}
	p->LExp = L;
}
