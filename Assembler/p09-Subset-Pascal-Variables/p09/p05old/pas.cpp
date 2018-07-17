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
 * File pas.cpp contains function main and processes command line arguments
 * -------------------------------------------------------------------------
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include "pastkn.h"
#include "paslex.h"
#include "paspar.h"

using namespace std;

ofstream fout;

void CommandLineException (int max, int actual)
{
  cout << endl;
  cout << "Too many command line arguments." << endl;
  cout << "A maximum of " << max << " arguments are permitted." << endl;
  cout << actual << " arguments were entered." << endl;
  cout << "Program terminated." << endl;
  exit (EXIT_FAILURE);
}

void IllegalExtensionException ()
{
  cout << endl;
  cout << "Input file must have the extension '.pas'" << endl;
  cout << "Program terminated." << endl;
  exit (EXIT_FAILURE);
}

void MissingExtensionException ()
{
  cout << endl;
  cout << "Input file must have the extension '.pas'" << endl;
  cout << "Did you forget to add the extension?" << endl;
  cout << "Program terminated." << endl;
  exit (EXIT_FAILURE);
}

void FileException (char* fn)
{
  cout << endl;
  cout << "File " << fn << " could not be opened." << endl;
  cout << "Program terminated." << endl;
  exit (EXIT_FAILURE);
}

void ScanMgr (FILE* i, ostream& o)
{
  o  << "       **Start of Scan**" << endl << endl;
  Scan L (i);
  for (;;)
  {
    int t = L.Lex ();
    if (t == 0) break;
    
   // printToken (t, o, L);
  }
  o << endl << "       **End of Scan**" << endl << endl;
  cout << "End of scan" << endl;
}

void ParseMgr (FILE* i, ostream& o)
{
  o << endl << "       **Start of Parse**" << endl;
  Parser P (i);
  P.Parse ();
  o << endl << "       **End of Parse**" << endl << endl;
  cout << "End of parse" << endl;
}

void CompilerMgr (FILE* i)
{
  Parser P (i);
  int rc = P.Parse ();
}

int main (int argc, char* argv[])
{
  char ifn[255]; //Input File Name
  char ofn[255]; //Output File Name
  char cmp[5] = ".pas";
  const char *ext; // Input File Extension

  switch (argc)
  {
    case 1: //Prompt for file name
      cout << "Enter the input file name. ";
      cin >> ifn;
      break;
    case 2: //File name is an argument
      strcpy (ifn, argv[1]);
      break;
    default:
      CommandLineException (2, argc - 1);
      break;
  }
  //Add /0 if doesnt compile
  ext = strrchr (ifn, '.');
  if (!ext)
  {
    MissingExtensionException ();
  }
  else if (strcmp (ext, cmp) != 0)
  {
    cout << ext << endl;
    cout << cmp << endl;
    IllegalExtensionException ();
  }

  strncpy (ofn, ifn, strlen(ifn));
  ofn[strlen (ifn)-4] = '\0';
  strcat (ofn, ".trc");
  FILE* inFile = fopen (ifn, "r"); if (!inFile) FileException (ifn);
  fout.open (ofn); if (!fout) FileException (ofn);
  cout << "Input file: " << ifn << "  |  Trace File: " << ofn << endl;
  fclose (inFile);
  inFile = fopen (ifn, "r"); if (!inFile) FileException (ifn);
  //ScanMgr  (inFile, fout);
  //ParseMgr (inFile, fout);
  CompilerMgr (inFile);
  fout.close ();
  return 0;
}
