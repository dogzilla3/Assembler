


#ifndef PCODE_H
#define PCODE_H


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class PCode 
{
	string label;
	string op;
	string rand1;
	string rand2;

public:
	PCode(string, string, string, string);
	PCode(string, string, int, int);
	PCode(string, string, string, int);
	PCode(string, string, int, string);
	//Getters
	string Label();
	string Op();
	string Rand1();
	string Rand2();
	//Setters
	void StoreLabel(string);
	void StoreOp(string);
	void StoreRand1(string);
	void StoreRand2(string);
	void Print(ostream&);
};

#endif
