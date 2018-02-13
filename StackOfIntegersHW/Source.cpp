#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "parseTools.h"
using namespace std;

int main() {
	parseTools parse;

	string LineA = "void main(){"; // this should fail, i.e. print an error "rejected"
	string LineB = " a  = b + (c*d);";  // this should work, i.e. print "accepted" 

	cout << "(LineA)" << endl;
	parse.parseString(LineA);
	parse.checkStack();
	

	parse.cleanStack();
	cout << "(LineB)" << endl;
	parse.parseString(LineB);
	parse.checkStack();

	//read file 1 good program example
	string line;
	ifstream myfile("C:\\fileAccess\\goodProgram.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			parse.parseString(line);
		}
		cout << "(correct program): " << endl;
		parse.checkStack();
		myfile.close();
	}
	else cout << "Unable to open file";
	//read file 2 bad program example missing close paren
	string line2;
	ifstream myfile2("C:\\fileAccess\\badProgram.txt");
	if (myfile2.is_open())
	{
		parse.cleanStack();
		while (getline(myfile2, line2))
		{
			parse.parseString(line2);
		}
		cout << endl << "(wrong program 1): " << endl;
		parse.checkStack();
		myfile2.close();
	}
	else cout << "Unable to open file";
	//read file 3 bad program example missing open paren
	string line3;
	ifstream myfile3("C:\\fileAccess\\badProgram2.txt");
	if (myfile3.is_open())
	{
		parse.cleanStack();
		while (getline(myfile3, line3))
		{
			parse.parseString(line3);
		}
		cout << endl << "(wrong program 2): " << endl;
		parse.checkStack();
		myfile2.close();
	}
	else cout << "Unable to open file";



	cin.ignore();
	cin.get();
	return 0;
}

