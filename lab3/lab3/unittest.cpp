/*
//Dakota Crozier & Colin Buchko
//ENSC 251 ASSINGMENT 
//
//unittest.cpp is for unit testing functions
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include "student.hpp" //header files
#include "domesticStudent.hpp"
#include "internationalStudent.hpp"
#include "toeflScore.hpp"
#include "linkedListStudent.hpp"
#include <string>
#include <iomanip>

using namespace std;

ifstream openFile(string fileName) {
	ifstream file(fileName.c_str());
	if (!file.is_open()) {
		cout << "Unable to open/find file " << fileName << ". Terminating Program.";
		exit(-1);
	}
	return file;
}

int main() {
	cout << "1 - test missing field domestic" << endl <<"2 - test missing field international";
	//unit test for insert 
	//normal case


	//unit test for search (cgpa, rscore,apid)

	//unit test for search name

	//unit test delete

	//unit test special delete

	//unit test merge

	//unit test threshold print
	return 0;
}

*/