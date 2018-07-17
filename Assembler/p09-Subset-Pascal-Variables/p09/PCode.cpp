

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <map>

using namespace std;

#include "PCode.h"

PCode::PCode(string l, string o, string r1, string r2)
	:label(l), op(o), rand1(r1), rand2(r2){}

PCode::PCode(string l,string o,string r1,int r2)
   :label(l),op(o),rand1(r1)
{
	ostringstream oss;
	oss << r2;
	rand2 = oss.str();
}

PCode::PCode(string l,string o,int r1,int r2)
   :label(l),op(o)
{
	ostringstream oss, oss2;
	
	oss << r1;
	rand1 = oss.str();
	
	oss2 << r2;
	rand2 = oss2.str();
}

PCode::PCode(string l,string o,int r1,string r2)
   :label(l),op(o),rand2(r2)
{
	ostringstream oss;
        oss << r1;
        rand1 = oss.str();
}

string PCode::Label(){ return label; }

string PCode::Op(){ return op; }

string PCode::Rand1(){ return rand1; }

string PCode::Rand2(){ return rand2; }

void PCode::StoreLabel(string l) { label=l; }

void PCode::StoreOp(string o){ op=o; }

void PCode::StoreRand1(string r1){ rand1=r1; }

void PCode::StoreRand2(string r2){ rand2=r2; }

void PCode::Print(ostream& o)
{	
	if (op == "arg") return;
	o << endl;
	o << setw(10) << left << label;
	o << setw(10) << left << op;
	o << setw(10) << left << rand1;
	o << setw(10) << left << rand2;
}

