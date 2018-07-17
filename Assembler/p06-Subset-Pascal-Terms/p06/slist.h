/*
* -------------------------------------------------------------------------
* Author: Gregory Levy
* Student ID: *20444120
* E-Mail: glevy@uco.edu
* Course: CMSC 4173 – Translator Design
* CRN: 21175, Spring, 2017
* Project: p02 - Subset Pascal Parser
* Due: January 24, 2018
* Account: tt072
* -------------------------------------------------------------------------
*
*
* -------------------------------------------------------------------------
* The file slist.h defines a container for identifiers as well as overloaded
* brackets to access the data
* -------------------------------------------------------------------------
*/


#ifndef SLIST_H
#define SLIST_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct ListIndexException
{
  ListIndexException (int i, int m)
  {
    cout << endl;
    cout << "List index " << i << " is invalid.";
    cout << endl;
    cout << "Valid indexes are in the range 0 <= i < " << m << ".";
  }
};

struct ListException
{
  ListException (const char* m)
  {
    cout << endl;
    cout << "I am the List and I am " << m << ".";
    cout << endl;
  }
};

template <class T>
class SList
{
  int size;                           //Number of available elements
  int count;                          //Number of actual elements
  T* L;                               //Points to storage allocated for
                                      //the list.
  int cursor;                         //Contains the index of the current
                                      //element
  public:
  SList (int sz = 100) :size (sz), count (0), cursor (0) { L = new T[size]; }
  ~SList () {}
  bool IsFull (void) { return count>size - 1; }
  bool IsEmpty (void) { return count == 0; }
  void Insert (T v)
  {
    if (IsFull ()) throw ListException ("full");
    L[count++] = v;
  }
  void Append (SList* L)
  {
    for (L->First (); !L->IsEol (); L->Next ())
    {
      Insert (L->Member ());
    }
  }
  void Scan (istream& i)
  {
    for (;;)
    {
      T v;
      i >> v;
      if (i.eof ()) break;
      Insert (v);
    }
  }

  void Print (ostream& o, const char* title)
  {
    o << title << "{";
    for (int a = 0; a<count; a++)
    {
      if (a>0) o << ",";
      o << L[a];
    }
    o << "}";
  }

  string PrintList ()
  {
    string list = " {";

    for (int i = 0; i < count; i++)
    {
      if (i > 0)
      {
        list += ", ";
        list += L[i];
      }
      else
      {
        list += L[i];
      }
    }
    list += "}";
    return list;

  }

  void Print (ostream& o)
  {
    for (int a = 0; a<count; a++)
    {
      L[a]->Print (o);
    }
  }


  T operator[](int i)
  {
    if (i<0 || i >= count) throw ListIndexException (i, count);
    return L[i];
  }
  int Count (void) { return count; }
  void First (void) { cursor = 0; }
  void Next (void) { if (cursor<count) cursor++; }
  bool IsEol (void) { return cursor >= count; }
  T Member (void)
  {
    if (cursor<0 || cursor >= count) throw ListIndexException (cursor, count);
    return L[cursor];
  }
};
#endif

