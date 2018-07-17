#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <algorithm>

using namespace std;

bool compare_files (const string&, const string&);

int main (int argc, char* argv[])
{
	string ifn; //Input File Name
	string tfn; //Trace File Name

	ifn = argv[1];
	tfn = argv[2];

	cout << "My File: " << ifn << "  |  Check File: " << tfn;

	bool result = compare_files (ifn, tfn);

	if (result == true) {
		cout << "  |  **Status: OK**" << endl;
	}
	else
	{
		cout << "  |  **Status: File mismatch, check ya code**" << endl;
	}
}

bool compare_files (const string& filename1, const string& filename2)
{
	ifstream file1 (filename1.c_str ());
	ifstream file2 (filename2.c_str ());

	istreambuf_iterator<char> begin1 (file1);
	istreambuf_iterator<char> begin2 (file2);

	return equal (begin1, istreambuf_iterator<char> (), begin2); //Second argument is end-of-range iterator
}