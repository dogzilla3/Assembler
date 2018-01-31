#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class ListException
{ 
public:
	ListException(const char* error)
	{
		cout << "The List is " << error << "!!" << endl;
	}
};

class LIndexException
{
public:
	LIndexException(int error)
	{
		cout << endl << "List index " << error << "cannot be found!!" << endl;	
	}
};

template <class T>
class SList {

	int maxSize;
	int curCount;
	int index;
	T* l;

public:
	SList(int s = 100):maxSize(s), curCount(0), index(0) 
	{ l = new T[maxSize]; }

	~SList(){}
	
	bool isEmpty(void){ return curCount == 0; }
	bool isFull(void){ return curCount == maxSize - 1; }
	
	void insert(T v) 
	{
		if(isFull()) throw ListException("full");
		l[curCount] = v;
		curCount++;
	}	

	string printList()
	{
	 string list = "{";
	
	    for (int i = 0; i < curCount; i++)
	    {
	      if (i > 0)
	      {
	        list += ", ";
	        list += l[i];
	      }
	      else
		{
		list += l[i];
		}
	    }
	    list += "}";
	    return list;
	}

	void printList(const char* begin, ostream& o)
	{
		o << begin << "{";
		for (int i = 0; i < curCount; i++)
		{
			if (i > 0) o << ", ";
			o << l[i]; 
		}
		o << "}";
	}


	T operator[](int x)
	{
		if (x < 0 || x > curCount) throw LIndexException(x);
		return l[x];
	}

	
};

#endif
