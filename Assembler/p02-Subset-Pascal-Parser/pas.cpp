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

void printToken (int t, ostream& o, Scan L)
{
  //if (t != 0) o << endl << "Token: Code=" << setw (3) << t << " Name=" << setw (10);
 
  if (t != 0) o << left << "Token: Code=" << setw (4) << t << " Line= " << setw (3) << L.fetchLine () << " Col= " << setw (4) << L.fetchCol () << " Name= " << setw (12);
  switch (t)
  {
    case PLUS:      o << "PLUS"; break;
    case MINUS:     o << "MINUS"; break;
    case STAR:      o << "STAR"; break;
    case SLASH:     o << "SLASH"; break;
    case ASSIGN:    o << "ASSIGN"; break;
    case PERIOD:    o << "PERIOD"; break;
    case COMMA:     o << "COMMA"; break;
    case SEMICOLON: o << "SEMICOLON"; break;
    case COLON:     o << "COLON"; break;
    case EQU:       o << "EQU"; break;
    case NEQ:       o << "NEQ"; break;
    case LES:       o << "LES"; break;
    case LEQ:       o << "LEQ"; break;
    case GRT:       o << "GRT"; break;
    case GEQ:       o << "GEQ"; break;
    case LPAREN:    o << "LPAREN"; break;
    case RPAREN:    o << "RPAREN"; break;
    case LBRACKET:  o << "LBRACKET"; break;
    case RBRACKET:  o << "RBRACKET"; break;
    case RANGE:     o << "RANGE"; break;
    case ID:        o << "ID"; break;
    case INTLIT:    o << "INTLIT"; break;
    case REALIT:    o << "REALIT"; break;
    case CHRLIT:    o << "CHRLIT"; break;
    case COMMENT:   o << "COMMENT"; break;
    case AND:       o << "AND"; break;
    case ARRAY:     o << "ARRAY"; break;
    case DIV:       o << "DIV"; break;
    case DO:        o << "DO"; break;
    case ELSE:      o << "ELSE"; break; 
    case END:       o << "END"; break;
    case FUNCTION:  o << "FUNCTION"; break;
    case IF:        o << "IF"; break;
    case MOD:       o << "MOD"; break;
    case NOT:       o << "NOT"; break;
    case OF:        o << "OF"; break;
    case OR:        o << "OR"; break;
    case PROCEDURE: o << "PROCEDURE"; break;
    case PROGRAM:   o << "PROGRAM"; break;
    case THEN:      o << "THEN"; break;
    case TO:        o << "TO"; break;
    case TYPE:      o << "TYPE"; break;
    case VAR:       o << "VAR"; break;
    case WHILE:     o << "WHILE"; break;
    case BEGIN_:    o << "BEGIN"; break;
  }
  o << " Spelling= '" << L.fetchSpelling () << "'" << endl;
}

void ScanMgr (FILE* i, ostream& o)
{
  o  << "       **Start of Scan**" << endl << endl;
  Scan L (i);
  for (;;)
  {
    int t = L.Lex ();
    if (t == 0) break;
    
    printToken (t, o, L);
  }
  o << endl << "       **End of Scan**" << endl << endl;
  cout << "End of scan" << endl;
}

void ParseMgr (FILE* i, ostream& o)
{
  o << endl << "       **Start of Parse**" << endl << endl;
  Parser P (i);
  P.Parse ();
  o << endl << "       **End of Parse**" << endl << endl;
  cout << "End of parse" << endl;
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

  ext = strrchr (ifn, '.') + '\0';
  if (!ext)
  {
    MissingExtensionException ();
  }
  else if (strcmp (ext, cmp) != 0)
  {
    IllegalExtensionException ();
  }

  strncpy (ofn, ifn, strlen(ifn));
  ofn[strlen (ifn)-4] = '\0';
  strcat (ofn, ".trc");

  FILE* inFile = fopen (ifn, "r"); if (!inFile) FileException (ifn);
  fout.open (ofn); if (!fout) FileException (ofn);

  cout << "Input file: " << ifn << "  |  Trace File: " << ofn << endl;

  ScanMgr (inFile, fout);
  fclose (inFile);

  inFile = fopen (ifn, "r"); if (!inFile) FileException (ifn);
  ParseMgr (inFile, fout);

  fout.close ();
  return 0;
}
