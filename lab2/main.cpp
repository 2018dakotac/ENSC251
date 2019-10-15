
//standard libraries
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <string>
#include "student.hpp"
#include "sfuSort.h"
#include "toeflScore.h"

using namespace std;

int main() {
	//check if the text files can be opened
	string line;
	ifstream domesticFile("domestic-stu.txt");
	if (!domesticFile.is_open()) {
		cout << "Unable to open file domestic-stu.txt" << endl;
		return -1;
	}
	ifstream internationalFile("international-stu.txt");
	if (!internationalFile.is_open()) {
		cout << "Unable to open file international-stu.txt" << endl;
		return -1;
	}

	//get number of lines in each file and then resets position in the file
	int domesticLineNum = -1;
	while (getline(domesticFile, line))
	{
		domesticLineNum++;
	}
	domesticFile.clear();
	domesticFile.seekg(0, ios::beg);

	int internationalLineNum = -1;
	while (getline(internationalFile, line))
	{
		internationalLineNum++;
	}
	internationalFile.clear();
	internationalFile.seekg(0, ios::beg);

	//user selection algorithim
	string groupSelection, sortType;
	cout << "Which group would you like to sort?\nInput 'D' for Domestic Students, 'I' for International Students, or 'A' for all students.\n ";
	cin >> groupSelection;
	//For not overall we must know type of sorting
	if (groupSelection != "O") {
		cout << "Enter what you would like to sort by: 'F' First Name, 'L' Last Name, 'C' Country, 'R' Research Score, 'P' Province, 'Z' Country\n";
		cin >> sortType;
	}
	if (groupSelection == "D") {
		//sort domestic based on sortType
		//declare some dynamic memory to the number of students in the file
		DomesticStudent *DomesticStudents = new DomesticStudent[domesticLineNum];
		int i = 0;
		while (getline(domesticFile, line)) {
			istringstream ss(line);
			ss >> DomesticStudents[i++];//uses user defined >> operator to pass information
		}
		if (groupSelection == "O") {
			sortType == "RGP";//sorts by research score than cgpa then province
		}
		sortBy(DomesticStudents, domesticLineNum, sortType);
		//print results
		cout << "\nSorted DomesticStudentArray:" << endl << endl;
		for (int i = 0; i < domesticLineNum; i++) {
			cout << setw(5) << left << i + 1 << DomesticStudents[i];
		}
		//cleanup
		domesticFile.close();
		delete[] DomesticStudents;
	}

	if (groupSelection == "I" || groupSelection == "O") {
		InternationalStudent *InternationalStudents = new InternationalStudent[internationalLineNum];
		InternationalStudent *filteredInternationalStudents = new InternationalStudent[internationalLineNum];
		int i = 0;
		while (getline(internationalFile, line)) {
			istringstream ss(line);
			ss >> InternationalStudents[i++];
		}
		//if overall sorting, gpa, rscore,province
		if (groupSelection == "O") {
			sortType = "RGC";//sorts by research score than cgpa then country
			sortBy(InternationalStudents, internationalLineNum, sortType);
			//filter out the internation students below toefl score threshold ONLY FOR OVERAL SORT
			int filteredIndex = 0;
			if (groupSelection == "0") {
				for (int j = 0; j < internationalLineNum; j++) {
					if (InternationalStudents[j].getScoreSum() >= 93
						&& InternationalStudents[j].getReading() >= 20
						&& InternationalStudents[j].getListening() >= 20
						&& InternationalStudents[j].getSpeaking() >= 20
						&& InternationalStudents[j].getWriting() >= 20) {
						filteredInternationalStudents[filteredIndex++] = InternationalStudents[j];
					}
				}
			}
			else {
				filteredInternationalStudents = InternationalStudents;
				filteredIndex = internationalLineNum;
			}
			//print the results
			cout << endl << endl << "Sorted InternationalStudent Array:" << endl << endl;
			for (int i = 0; i < filteredIndex; i++)
			{
				cout << setw(5) << left << i + 1 << filteredInternationalStudents[i];
			}
			//cleanup
			internationalFile.close();
			if (filteredInternationalStudents != InternationalStudents) {
				delete[] filteredInternationalStudents;
			}
			delete[] InternationalStudents;
		}
		return 0;
	}
}
	
