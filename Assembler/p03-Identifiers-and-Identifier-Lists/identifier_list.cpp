

#include "identifier_list.h"

extern ofstream fout;

SList<string>* id_list(string* s)
{
	SList<string>* l = new SList<string>;
	l->insert(*s);
	l->printList(" identifier_list =", fout);	
	return l; 
}

SList<string>* id_list(SList<string>* l, string* s)
{
        l->insert(*s);
	l->printList(" identifier_list =", fout);
        return l;
}


