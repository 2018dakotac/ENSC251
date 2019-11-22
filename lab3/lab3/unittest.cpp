
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
/*
ifstream openFile(string fileName) {
	ifstream file(fileName.c_str());
	if (!file.is_open()) {
		cout << "Unable to open/find file " << fileName << ". Terminating Program.";
		exit(-1);
	}
	return file;
}
*/

int main() {
	
	string fileName;
	ifstream domesticFile(fileName.c_str());
	ifstream InternationalFile(fileName.c_str());

	//pointers
	StudentList *domesticHeadNode = NULL;
	StudentList *internationalHeadNode = NULL;
	StudentList *domesticTailNode = NULL;
	StudentList *internationalTailNode = NULL;
	//blank students
	DomesticStudent blankDOM;
	InternationalStudent blankINT;
	char choice1 = 'x';
	char choice2 = 'x';
	char choice3 = 'x';
	cout << "1 - insert\n2 - search AppID,cgpa,ressearchScore\n3 - search by name\n4 - delete node(s)\n5 - delete head and tail node at same time\n6 - Merge\n7 - search merged list via threshold.\n";
	cin >> choice1;
	if (choice1 == '1') {//insert test
		cout << "1 - test domestic insert" << endl << "2 - test international insert"<< endl;
		cin >> choice2;
		if (choice2 == '1') {
			cout << "1- normal case\n2 - boundary case\n3 - illegal case\n";
			cin >> choice3;
			if (choice3 == '1') {
				cout << "normal case: adding student to exisint list";
				blankDOM.set_appID(20200001);
				blankDOM.set_cgpa(2.5);
				blankDOM.set_firstname("Dakota");
				blankDOM.set_lastname("Crozier");
				blankDOM.set_province("bc");
				blankDOM.set_researchscore(96);
				insertNode(blankDOM, &domesticHeadNode);
				mergeSort(&domesticHeadNode, 'R');
				printLinkedList(&domesticHeadNode);//prints current list
				cout << "current list" << endl;
				blankDOM.set_appID(20200002);
				blankDOM.set_cgpa(3);
				blankDOM.set_firstname("Colin");
				blankDOM.set_lastname("Buchko");
				blankDOM.set_province("ab");
				blankDOM.set_researchscore(80);
				insertNode(blankDOM, &domesticHeadNode);//make add node to list
				mergeSort(&domesticHeadNode, 'R');
				printLinkedList(&domesticHeadNode);//print list as proof
			}
			else if (choice3 == '2') {
				cout << "boundary case: adding student to empty list";
				blankDOM.set_appID(20200001);
				blankDOM.set_cgpa(2.5);
				blankDOM.set_firstname("Dakota");
				blankDOM.set_lastname("Crozier");
				blankDOM.set_province("bc");
				blankDOM.set_researchscore(71);
				printLinkedList(&domesticHeadNode);//check if list is made
				insertNode(blankDOM, &domesticHeadNode);//make list from nothing
				printLinkedList(&domesticHeadNode);//print list as proof

			}
			else if (choice3 == '3') {
				cout << "Illegal case of adding empty student. Program will close as default constructor values will trigger built in in error checking (the same as inputing wrong values).";
				printLinkedList(&domesticHeadNode);//check if list is made
				insertNode(blankINT, &domesticHeadNode);//make list from nothing
			}
			else {
				cout << "Invalid Input ending unittest" << endl;
				exit(-10);
			}
			
		}
		else if (choice2 == '2') {//international
			cout << "1- normal case\n2 - boundary case\n3 - illegal case\n";
			cin >> choice3;
			if (choice3 == '1') {
				cout << "normal case: adding student to exisint list";
				blankINT.set_appID(20200001);
				blankINT.set_cgpa(2.5);
				blankINT.set_firstname("Dakota");
				blankINT.set_lastname("Crozier");
				blankINT.set_country("India");
				blankINT.set_researchscore(96);
				blankINT.set_Tlisten(20);
				blankINT.set_Tread(20);
				blankINT.set_Tspeak(20);
				blankINT.set_Twrite(20);
				blankINT.set_Ttotal(20, 20, 20, 20);
				insertNode(blankINT, &internationalHeadNode);
				mergeSort(&internationalHeadNode, 'R');
				printLinkedList(&internationalHeadNode);//prints current list
				cout << "current list"<< endl;
				blankINT.set_appID(20200002);
				blankINT.set_cgpa(3);
				blankINT.set_firstname("Colin");
				blankINT.set_lastname("Buchko");
				blankINT.set_country("korea");
				blankINT.set_researchscore(80);
				blankINT.set_Tlisten(21);
				blankINT.set_Tread(20);
				blankINT.set_Tspeak(20);
				blankINT.set_Twrite(20);
				blankINT.set_Ttotal(20, 21, 20, 20);
				insertNode(blankINT, &internationalHeadNode);//adds node
				mergeSort(&internationalHeadNode, 'R');
				printLinkedList(&internationalHeadNode);//prints current list to prove functionality
			}
			else if (choice3 == '2') {
				cout << "boundary case: adding student to empty list";
				blankINT.set_appID(20200001);
				blankINT.set_cgpa(2.5);
				blankINT.set_firstname("Dakota");
				blankINT.set_lastname("Crozier");
				blankINT.set_country("India");
				blankINT.set_country("India");
				blankINT.set_researchscore(96);
				blankINT.set_Tlisten(20);
				blankINT.set_Tread(20);
				blankINT.set_Tspeak(20);
				blankINT.set_Twrite(20);
				blankINT.set_Ttotal(20, 20, 20, 20);
				printLinkedList(&internationalHeadNode);//check if list is made
				insertNode(blankINT, &internationalHeadNode);//make list from nothing
				printLinkedList(&internationalHeadNode);//print list as proof

			}
			else if (choice3 == '3') {
				cout << "Illegal case of adding empty student. Program will close as default constructor values will trigger built in in error checking (the same as inputing wrong values).";
				printLinkedList(&internationalHeadNode);//check if list is made
				insertNode(blankINT, &internationalHeadNode);//make list from nothing
			}
			else {
				cout << "Invalid Input ending unittest" << endl;
				exit(-10);
			}
		}
		else {
			cout << "Invalid Input ending unittest"<< endl;
			exit(-10);
		}
	}
	else if (choice1 == '2') {
		cout << "1 - test domestic search (application ID, CGPA, researchScore)" << endl << "2 - test international search (application ID, CGPA, researchScore)"<< endl;
		cin >> choice2;
		if (choice2 == '1') {
			
			cout << "boundary case: search for one student" << endl;
			blankDOM.set_appID(20200005);
			blankDOM.set_cgpa(2.5);
			blankDOM.set_firstname("Dakota");
			blankDOM.set_lastname("Crozier");
			blankDOM.set_province("bc");
			blankDOM.set_researchscore(96);
			insertNode(blankDOM, &domesticHeadNode);
			blankDOM.set_appID(20200006);
			blankDOM.set_cgpa(4);
			blankDOM.set_firstname("Yeet");
			blankDOM.set_lastname("McGuy");
			blankDOM.set_province("AB");
			blankDOM.set_researchscore(80);
			insertNode(blankDOM, &domesticHeadNode);
			mergeSort(&domesticHeadNode, 'R');
			cout << "testing search by application ID";
			searchApplicationID(&domesticHeadNode, 20200005);
			cout << "testing search by cgpa";
			searchGPA(&domesticHeadNode, 4);
			cout << "testing search by researchScore";
			searchResearchScore(&domesticHeadNode, 96);
			
			cout << "normal case search for multiple students" << endl;
			blankDOM.set_appID(20200005);
			blankDOM.set_cgpa(2.5);
			blankDOM.set_firstname("Dakota");
			blankDOM.set_lastname("Crozier");
			blankDOM.set_province("bc");
			blankDOM.set_researchscore(96);
			insertNode(blankDOM, &domesticHeadNode);
			blankDOM.set_appID(20200006);
			blankDOM.set_cgpa(4);
			blankDOM.set_firstname("Yeet");
			blankDOM.set_lastname("McGuy");
			blankDOM.set_province("AB");
			blankDOM.set_researchscore(80);
			insertNode(blankDOM, &domesticHeadNode);
			mergeSort(&domesticHeadNode, 'R');
			cout << "testing search by application ID";
			searchApplicationID(&domesticHeadNode, 20200005);
			cout << "testing search by cgpa";
			searchGPA(&domesticHeadNode, 4);
			cout << "testing search by researchScore";
			searchResearchScore(&domesticHeadNode, 96);
			cout << "boundary case: search for one student" << endl;
			cout << "Illegal case will always return nothing as nothing will match in the linked list" << endl;
			searchApplicationID(&domesticHeadNode, 0);
			searchGPA(&domesticHeadNode, 0);
			searchResearchScore(&domesticHeadNode, 0);

		}
		else if (choice2 == '2') {
			blankINT.set_appID(20200002);
			blankINT.set_cgpa(3);
			blankINT.set_firstname("Colin");
			blankINT.set_lastname("Buchko");
			blankINT.set_country("korea");
			blankINT.set_researchscore(80);
			blankINT.set_Tlisten(21);
			blankINT.set_Tread(20);
			blankINT.set_Tspeak(20);
			blankINT.set_Twrite(20);
			blankINT.set_Ttotal(20, 21, 20, 20);
			insertNode(blankINT, &domesticHeadNode);
			cout << "testing search by application ID";
			searchApplicationID(&domesticHeadNode, 20200002);
			cout << "testing search by cgpa";
			searchGPA(&domesticHeadNode, 3);
			cout << "testing search by researchScore";
			searchResearchScore(&domesticHeadNode, 80);
		}
		else {
			cout << "Invalid Input ending unittest"<< endl;
			exit(-11);
		}
	}
	else if (choice1 == '3') {
		cout << "1 - test domestic name search" << endl << "2 - test international name search"<< endl;
		cin >> choice2;
		if (choice2 == '1') {
			blankDOM.set_appID(20200006);
			blankDOM.set_cgpa(4);
			blankDOM.set_firstname("Yeet");
			blankDOM.set_lastname("McGuy");
			blankDOM.set_province("AB");
			blankDOM.set_researchscore(80);
			insertNode(blankDOM, &domesticHeadNode);
			blankDOM.set_appID(20200006);
			blankDOM.set_cgpa(4);
			blankDOM.set_firstname("Yeet");
			blankDOM.set_lastname("McGuy");
			blankDOM.set_province("AB");
			blankDOM.set_researchscore(81);
			insertNode(blankDOM, &domesticHeadNode);
			blankDOM.set_appID(20200006);
			blankDOM.set_cgpa(4);
			blankDOM.set_firstname("Yeet");
			blankDOM.set_lastname("McGuy");
			blankDOM.set_province("AB");
			blankDOM.set_researchscore(82);
			insertNode(blankDOM, &domesticHeadNode);
			mergeSort(&domesticHeadNode, 'R');
			searchName(&domesticHeadNode, "Yeet", "McGuy");
		}
		else if (choice2 == '2') {
			blankINT.set_appID(20200002);
			blankINT.set_cgpa(3);
			blankINT.set_firstname("Colin");
			blankINT.set_lastname("Buchko");
			blankINT.set_country("korea");
			blankINT.set_researchscore(80);
			blankINT.set_Tlisten(21);
			blankINT.set_Tread(20);
			blankINT.set_Tspeak(20);
			blankINT.set_Twrite(20);
			blankINT.set_Ttotal(20, 21, 20, 20);
			insertNode(blankINT, &domesticHeadNode);
		}
		else {
			cout << "Invalid Input ending unittest" << endl;
			exit(-12);
		}
	}
	else if (choice1 == '4') {
		cout << "1 - test domestic insert" << endl << "2 - test international insert"<< endl;
		cin >> choice2;
		if (choice2 == '1') {

		}
		else if (choice2 == '2') {

		}
		else {
			cout << "Invalid Input ending unittest"<< endl;
			exit(-13);
		}
	}
	else if (choice1 == '5') {
		cout << "1 - test domestic insert" << endl << "2 - test international insert"<< endl;
		cin >> choice2;
		if (choice2 == '1') {

		}
		else if (choice2 == '2') {

		}
		else {
			cout << "Invalid Input ending unittest" << endl;
			exit(-14);
		}
	}
	else if (choice1 == '6') {
		float cgpa_threshold;
		int rScore_threshold;
		//merge then sort with mergeSort but pass overall char
		tailNodeFinder(&domesticHeadNode, &domesticTailNode);
		tailNodeFinder(&internationalHeadNode, &internationalTailNode);
		domesticTailNode->nextNode = internationalHeadNode;

		mergeSort(&domesticHeadNode, 'O');
		printLinkedList(&domesticHeadNode);
		//make international head and tail pointer equal to null as the linked list no longer exists
		internationalHeadNode = NULL;
		internationalTailNode = NULL;
		cout << "Enter cgpa threshold" << endl;
		cin >> cgpa_threshold;
		cout << "Enter research score threshold" << endl;
		cin >> rScore_threshold;
		threshodldPrint(&domesticHeadNode, cgpa_threshold, rScore_threshold);
		cout << endl << "The students above shall be admitted to SFU!" << endl;
	
	}
	else if (choice1 == '7') {
		float cgpa_threshold;
		int rScore_threshold;
		//merge then sort with mergeSort but pass overall char
		tailNodeFinder(&domesticHeadNode, &domesticTailNode);
		tailNodeFinder(&internationalHeadNode, &internationalTailNode);
		domesticTailNode->nextNode = internationalHeadNode;

		mergeSort(&domesticHeadNode, 'O');
		printLinkedList(&domesticHeadNode);
		//make international head and tail pointer equal to null as the linked list no longer exists
		internationalHeadNode = NULL;
		internationalTailNode = NULL;
		cout << "Enter cgpa threshold" << endl;
		cin >> cgpa_threshold;
		cout << "Enter research score threshold" << endl;
		cin >> rScore_threshold;
		threshodldPrint(&domesticHeadNode, cgpa_threshold, rScore_threshold);
		cout << endl << "The students above shall be admitted to SFU!" << endl;
	}
	else {
		cout << "Invalid Input ending unittest";
		exit(-1);
	}
	string something;
	cout << "enter something to close";
	cin >> something;
	
	
	return 0;
}

