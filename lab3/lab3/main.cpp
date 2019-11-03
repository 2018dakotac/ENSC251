//Dakota Crozier & Colin Buchko
//ENSC 251 ASSINGMENT 
//
//The main.cpp file for the program, where the classes will be put to use to read the data from a file of
//different students and their data, temporarily store it in an object (of which class depends on the type 
//of students listed) then outputting all the data using the get functions.
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

//declare functions to be used in main
void singleSort(int stu_count1, DomesticStudent *StudentD, char type);
void singleSort(int stu_count2, InternationalStudent *StudentI, char type);
//linked list functions

void insertNode(DomesticStudent &Student1, StudentList **domesticHeadNode);
void insertNode(InternationalStudent &Student1, StudentList **internationalHeadNode);

void frontBackSplit(StudentList*sourceNode, StudentList**frontRef, StudentList**backRef);
void mergeSort(StudentList**headRef, char type);
StudentList * SortedMerge(StudentList*a, StudentList*b, char type);
void tailNodeFinder(StudentList **headNode, StudentList **tailNode);
void printLinkedList(StudentList**headNode);


//void insertSort(DomesticStudent **domesticHeadNode, DomesticStudent **domesticTailNode);




//READ ME COLIN
//TODO:
//double checking user input error checking (there should be some in the get/set functions)
//make sure our names are on files not luka and ritesh (used theres as code basis from lab2)


//TO DO LATER
//comment code and remove code thats commmented out (when were done)
//look on piazza to see if you actually need to sort the list each time you input a node or if you can do it after (when reading first linked list from)
//need basic input checking see cin.fail() exit program or clear input buffer, make a function then call it after each cin?
//*********************************************MAKE IT ASCENDING OR DESCENDING SORT ORDER FOR TOP LAB(can add to merge sort after lab works)

int main() {
	//Intialize head and tail pointer for both domestic and international

	//will be given proper memory address when linked list is created
	//DOMESTIC STUDENT reading file and outputting

	//opening and checking to see if the file domestic-stu.txt opened and closing the program if opening failed.
	string line;
	ifstream domesticFile("domestic-stu.txt");

	if (!domesticFile.is_open()) {
		cout << "Unable to open file domestic-stu.txt" << endl;
		return -1;
	}

	//Read the first line of domestic-stu.txt, which specifies
	//the file format. And then print it out to the screen
	getline(domesticFile, line);
	cout << endl << endl;
	cout << "DOMESTIC STUDENTS" << endl;
	cout << "File format: " << line << endl << endl;

	//initializing the first student number as 20200000, for the first student. This variable will be used to
	//assign student numbers in the while loop for reading the fi;e
	int studentnum = 20200000;
	StudentList *domesticHeadNode = NULL;
	StudentList *internationalHeadNode = NULL;
	StudentList *domesticTailNode = NULL;
	StudentList *internationalTailNode = NULL;



	//for going thru the while loop when reading the file, counting how many entries are made
	int stu_count1 = 0;

	while (getline(domesticFile, line)) {
		//process each line, get each field separated by a comma.
		 //use istringstream to handle it.
		DomesticStudent fakeStudent;
		istringstream ss(line);

		//all values read are inputted as strings, declare variables to hold them	
		string firstName, lastName, province, s_cgpa, s_researchScore;
		//variables to use once converted to float,for cgpa, and int, for research score 
		float cgpa;
		int researchScore;

		//since dynamic array automatically uses default constructor to initialize, use set functions to change data andvoid creating new anonymous objects
		//get firstName separated by comma
		getline(ss, firstName, ',');
		fakeStudent.set_firstname(firstName);

		//get lastName separated by comma
		getline(ss, lastName, ',');
		fakeStudent.set_lastname(lastName);

		//get province separated by comma
		getline(ss, province, ',');
		fakeStudent.set_province(province);
		//get cpga separated by comma, and convert string to float
		getline(ss, s_cgpa, ',');
		cgpa = atof(s_cgpa.c_str());
		fakeStudent.set_cgpa(cgpa);
		//get researchScore separated by comma, and convert it to int
		getline(ss, s_researchScore, ',');
		researchScore = atoi(s_researchScore.c_str());
		fakeStudent.set_researchscore(researchScore);
		//setting the application ID
		fakeStudent.set_appID(studentnum);
		//use overloaded operator to print out data each time
		insertNode(fakeStudent, &domesticHeadNode);
		//incrementing student number counter
		studentnum++;

		//incrementing while loop counter
		stu_count1++;
	}

	//closing the file
	domesticFile.close();
	
	//sort domestic linked list
	//formatting the output for reading the file, with headers for each category at the top
	cout << setw(20) << left << "Application ID" << setw(20) << left << "First Name" << setw(20) << left << "Last Name"
		<< setw(20) << left << "Research Score" << setw(20) << left << "CGPA" << setw(20) << left << "Province" << endl;
	//print linked list TESTING SORTING
	printLinkedList(&domesticHeadNode);
	cout << endl << endl << endl << "testing sorting function....currently broken :( " << endl;
	mergeSort(&domesticHeadNode, 'R');
	printLinkedList(&domesticHeadNode);


	//set domestic tail node 
	tailNodeFinder(&domesticHeadNode, &domesticTailNode);


	//INTERNATIONAL STUDENT reading file and outputting

	//opening and checking to see if the file international-stu.txt opened, if not then closing the program
	ifstream InternationalFile("international-stu.txt");

	if (!InternationalFile.is_open()) {
		cout << "Unable to open file international-stu.txt" << endl;
		return -1;
	}

	//Read the first line of international-stu.txt, which specifies
	//the file format. And then print it out to the screen
	getline(InternationalFile, line);
	cout << endl << endl << "INTERNATIONAL STUDENTS" << endl;
	cout << "File format: " << line << endl << endl;

	

	//while loop for reading the file and putting the data into the International object
	//for international student file reading, to keep track of how may entries are made
	int stu_count2 = 0;

	while (getline(InternationalFile, line)) {

		//process each line, get each field separated by a comma.
		 //use istringstream to handle it.
		istringstream ss(line);

		//all data read as a string, so declare variables to store the strings
		string firstName, lastName, country, s_cgpa, s_researchScore, s_reading, s_writing, s_speaking, s_listening;
		//variables to hold float/int values once converted from strings
		float cgpa;
		int researchScore, reading, writing, speaking, listening;
		//temporary student object
		InternationalStudent fakeStudent;

		//since the objects have already been initialized by the default constructor, to avoid creating another anonymous obejct, use the set functions to input data
		//get firstName separated by comma
		getline(ss, firstName, ',');
		
		fakeStudent.set_firstname(firstName);

		//get lastName separated by comma
		getline(ss, lastName, ',');
		
		fakeStudent.set_lastname(lastName);

		//get country separated by comma
		getline(ss, country, ',');
		
		fakeStudent.set_country(country);
		//get cpga separated by comma, and convert string to float
		getline(ss, s_cgpa, ',');
		cgpa = atof(s_cgpa.c_str());
		
		fakeStudent.set_cgpa(cgpa);
		//get researchScore separated by comma, and convert it to int
		getline(ss, s_researchScore, ',');
		researchScore = atoi(s_researchScore.c_str());
		
		fakeStudent.set_researchscore(researchScore);
		//setting the application ID of the student
		
		fakeStudent.set_appID(studentnum);
		//get reading, writng, listening and speaking scores and cast to int
		getline(ss, s_reading, ',');
		reading = atoi(s_reading.c_str());

		getline(ss, s_listening, ',');
		listening = atoi(s_listening.c_str());

		getline(ss, s_speaking, ',');
		speaking = atoi(s_speaking.c_str());

		getline(ss, s_writing, ',');
		writing = atoi(s_writing.c_str());

		//setting the individualy toefl scores and the total
		
		fakeStudent.set_Tread(reading);
		fakeStudent.set_Tlisten(listening);
		fakeStudent.set_Twrite(writing);
		fakeStudent.set_Tspeak(speaking);
		fakeStudent.set_Ttotal(reading, writing, listening, speaking);

		//output using overloaded output operator
		//cout << fakeStudent << endl;

		//pass student object to linked list
		insertNode(fakeStudent, &internationalHeadNode);
		
		
		//incrementing student number counter to ensure no 2 students have same number
		studentnum++;
		//incrementing loop counter
		stu_count2++;
	}

	//closing the file
	InternationalFile.close();

	//set internatinonal tail node 
	tailNodeFinder(&internationalHeadNode, &internationalTailNode);
	//sort international linked list
	mergeSort(&internationalHeadNode, 'R');
	

	//formatting the output to have header categories for each member
	cout << setw(20) << left << "Application ID" << setw(20) << left << "First Name" << setw(20) << left << "Last Name"
		<< setw(20) << left << "Research Score" << setw(20) << left << "CGPA" << setw(20) << left << "Country"
		<< setw(10) << left << "TOEFL" << setw(10) << left << "Reading" << setw(10) << left << "Writing"
		<< setw(10) << left << "Listening" << setw(10) << left << "Speaking" << endl;
	//print linked list
	printLinkedList(&internationalHeadNode);

	cout << endl << endl << "Linked lists have been intilialized while being continually sorted." << endl;

	//lab 3 sorting

	//initialize/reset variables for loop conditions
	int sorttries = 0;//tries for sorting
	char linkedSort = 'x';
	char sortAgain = 'x';

	while (sorttries<50){


	
		cout << "Insert 'S' to search nodes, 'A' to add a student node, 'D' to delete a student node, 'Z' to delete head and tail node (at the same time!), or 'M' to merge linked lists." << endl;
		cin >> linkedSort;
		if (linkedSort == 'M'|| linkedSort == 'm') {
			break;
		} 
		else if (linkedSort == 's' || linkedSort == 'S') {
			char searchType;
			int inputFail = 1;
			while (inputFail == 1) {
				cout << "Insert what you would like to search by, 'C' for cgpa, 'A' for application ID, 'R' for research score, 'N' for first and last name" << endl;
				cin >> searchType;
				if (searchType == 'C' || searchType == 'c') {

				}
				else if (searchType == 'A' || searchType == 'a') {
					//error message fo rapp id requested application id doesnt exit or belongs to a student that has been deleted***
				}
				else if (searchType == 'R' || searchType == 'r') {

				}
				else if (searchType == 'N' || searchType == 'n') {

				}

				inputFail = 0;
			}
		
		} 
		else if (linkedSort == 'a' || linkedSort == 'A') {
			//get user input for student info with checks alone the way maybe do while loop until the idiot user gets it right
			int inputFail = 1;
			while (inputFail) {
				char studentType= 'x';
				cout << "Enter 'D' for domestic or 'I' for international" << endl;
				cin >> studentType;
				if (studentType == 'D' || studentType == 'd') { 

					string firstName, lastName, province;
					float cgpa;
					int researchScore;
					DomesticStudent fakeStudent;

					cout << "Enter new student first name" << endl;
					cin >> firstName;
					cout << "Enter new student last name" << endl;
					cin >> lastName;
					cout << "Enter student province" << endl;
					cin >> province;
					cout << "Enter student cgpa" << endl;
					cin >> cgpa;
					cout << "Enter student research score" << endl;
					cin >> researchScore;

					fakeStudent.set_firstname(firstName);
					fakeStudent.set_lastname(lastName);
					fakeStudent.set_province(province);
					fakeStudent.set_cgpa(cgpa);
					fakeStudent.set_researchscore(researchScore);
					fakeStudent.set_appID(studentnum);
					insertNode(fakeStudent, &domesticHeadNode);
					mergeSort(&domesticHeadNode, 'R');
					printLinkedList(&domesticHeadNode);
					studentnum++;
				}
				else if (studentType == 'I' || studentType == 'i') {
					string firstName, lastName, country;
					float cgpa;
					int researchScore, reading, writing, speaking, listening;
					InternationalStudent fakeStudent;

					cout << "Enter new student first name" << endl;
					cin >> firstName;
					cout << "Enter new student last name" << endl;
					cin >> lastName;
					cout << "Enter student country" << endl;
					cin >> country;
					cout << "Enter student cgpa" << endl;
					cin >> cgpa;
					cout << "Enter student research score" << endl;
					cin >> researchScore;
					cout << "Enter student TOEFL reading score" << endl;
					cin >> reading;
					cout << "Enter student TOEFL listening score" << endl;
					cin >> listening;
					cout << "Enter student TOEFL speaking score" << endl;
					cin >> speaking;
					cout << "Enter student TOEFL writing score" << endl;
					cin >> writing;

					fakeStudent.set_firstname(firstName);
					fakeStudent.set_lastname(lastName);
					fakeStudent.set_country(country);
					fakeStudent.set_cgpa(cgpa);
					fakeStudent.set_researchscore(researchScore);
					fakeStudent.set_appID(studentnum);

					fakeStudent.set_Tread(reading);
					fakeStudent.set_Tlisten(listening);
					fakeStudent.set_Twrite(writing);
					fakeStudent.set_Tspeak(speaking);
					fakeStudent.set_Ttotal(reading, writing, listening, speaking);
					insertNode(fakeStudent, &internationalHeadNode);
					mergeSort(&internationalHeadNode, 'R');
					printLinkedList(&internationalHeadNode);
				}
				else {
					cout << "Improper input, Try again";
					continue;
				}
			
				inputFail = 0;
			}
		} 
		else if (linkedSort == 'd' || linkedSort == 'D') {

			//ask for first name and last name (maybe use search function?) then call delete function
		}
		else if (linkedSort == 'z' || linkedSort == 'Z') {

			//find tail node again just in case?
			//delete head and tail node 
		}
		

		//allowing option to do multiple sorts at once
		cout << "Would you like to sort again? Enter Y for YES, and N for NO" << endl;
		cin >> sortAgain;//choice for sorting multiple times

		if (sortAgain == 'Y' || sortAgain == 'y')
		{
			sorttries++;//update attempts loop and sort again
			continue;
		}

		else if (sortAgain == 'N' || sortAgain == 'n')
			break;//stop sorting, just do once

		   //otherwise just sort once and not again
		else
		{
			cout << "Invalid entry. Outputting current sort " << endl;
			break;
		}
	}
	if (linkedSort == 'M' || linkedSort == 'm') {
		//merge then sort with mergeSort but pass overall char
		//NEED TO PROGRAM Mergesort for overall sort (different priority)

	}
	

	//freeing up memory as program is over
	while (domesticHeadNode != NULL) {
		StudentList* soonToBeDeadNode = domesticHeadNode;
		domesticHeadNode = domesticHeadNode->nextNode;
		delete soonToBeDeadNode;

	}
	while (internationalHeadNode != NULL) {
		StudentList* soonToBeDeadNode = internationalHeadNode;
		internationalHeadNode = internationalHeadNode->nextNode;
		delete soonToBeDeadNode;
	}
	// do this for merged student headnode if you make one





	

	return 0;
}





void singleSort(int stu_count1, DomesticStudent *StudentD,char type) {
	//selection sort algorithm
	for (int i = 0; i < stu_count1 - 1; i++)
	{
		for (int j = i + 1; j < stu_count1; j++)
		{
			//if j element research score is larger, swap 
			if (
				((type =='R')&&(compareResearchScore(StudentD[i], StudentD[j]) == -1))
				|| ((type == 'F') &&(compareFirstName(StudentD[i], StudentD[j]) == -1))
				|| ((type == 'C') &&(compareCGPA(StudentD[i], StudentD[j]) == -1))
				|| ((type == 'L') &&(compareLastName(StudentD[i], StudentD[j]) == -1))
				|| ((type == 'P') && (compareProvince(StudentD[i], StudentD[j]) == -1))
				)
			{
				DomesticStudent tempD;
				//swap elements using overloaded assignment operator
				tempD = StudentD[i];//use temp to swap
				StudentD[i] = StudentD[j];
				StudentD[j] = tempD;
			}
		}
	}
}
void singleSort(int stu_count2, InternationalStudent *StudentI, char type) {
	//selection sort algorithm
	for (int i = 0; i < stu_count2 - 1; i++)
	{
		for (int j = i + 1; j < stu_count2; j++)
		{
			//if j element research score is larger, swap 
			if (
				((type == 'R') && (compareResearchScore(StudentI[i], StudentI[j]) == -1))
				|| ((type == 'F') && (compareFirstName(StudentI[i], StudentI[j]) == -1))
				|| ((type == 'C') && (compareCGPA(StudentI[i], StudentI[j]) == -1))
				|| ((type == 'L') && (compareLastName(StudentI[i], StudentI[j]) == -1))
				|| ((type == 'Z') && (compareCountry(StudentI[i], StudentI[j]) == -1))
				|| ((type == 'T') && (compareToeflScore(StudentI[i], StudentI[j]) == -1))
				) 
			{
				InternationalStudent tempI;
				//swap elements using overloaded assignment operator
				tempI = StudentI[i];//use temp to swap
				StudentI[i] = StudentI[j];
				StudentI[j] = tempI;
			}
		}
	}
}
void insertNode(DomesticStudent &Student1, StudentList **domesticHeadNode) {
	if (*domesticHeadNode == NULL) {
		
		StudentList *newHead = new StudentList;
		newHead->domStudent = Student1;
		(*domesticHeadNode) = newHead;
	}
	else {
		
		StudentList*newHead = new StudentList;
		newHead->domStudent = Student1;
		newHead->nextNode = *domesticHeadNode;
		*domesticHeadNode = newHead;
	}

}
void insertNode(InternationalStudent &Student1, StudentList **internationalHeadNode) {
	if (*internationalHeadNode == NULL) {
		StudentList *newHead = new StudentList;
		newHead->intStudent = Student1;
		(*internationalHeadNode) = newHead;
	}
	else {
		StudentList*newHead = new StudentList;
		newHead->intStudent = Student1;
		newHead->nextNode = *internationalHeadNode;
		*internationalHeadNode = newHead;
	}

}
//void insertSort(DomesticStudent **domesticHeadNode, DomesticStudent **domesticTailNode);

void mergeSort(StudentList**headRef,char type) {
	StudentList* head = *headRef;
	StudentList* a;
	StudentList* b;
	//base case check
	if (head == NULL || head->nextNode==NULL) {
		return;
	}
	//split linked lists into two
	frontBackSplit(head, &a, &b);
		//recursively sorts
	mergeSort(&a,type);
	mergeSort(&b,type);

		//merge result
	*headRef = SortedMerge(a, b,type);
}

StudentList * SortedMerge(StudentList * a, StudentList * b, char type)
{
	StudentList * newHead = NULL;
	if (type == 'R') {//lab 2 scheme research score, then cgpa, then province or country
		
		//base case check
		if (a == NULL) {
			return (b);
		}
		if (b == NULL) {
			return (a);
		}
		if (compareListResearchScore(a, b) == -1) {
			newHead = a;
			newHead->nextNode = SortedMerge(a->nextNode, b,type);
		}
		else if (compareListResearchScore(a, b) == 0 && compareListCGPA(a, b) == -1) {
			newHead = a;
			newHead->nextNode = SortedMerge(a->nextNode, b, type);
		}
		else if (compareListResearchScore(a, b) == 0 && compareListCGPA(a, b) == 0 && compareListLocation(a, b) == -1) {
			newHead = a;
			newHead->nextNode = SortedMerge(a->nextNode, b,type);
		}
		else {
			newHead = b;
			newHead->nextNode = SortedMerge(a, b->nextNode,type);
		}
		return (newHead);
	}
	if (type == 'O') {//for overall sort scheme
		return (newHead);
	}

}
void frontBackSplit(StudentList*sourceNode, StudentList**frontRef, StudentList**backRef) {
	StudentList *fast = sourceNode->nextNode;
	StudentList* slow = sourceNode;

	while (fast != NULL) {
		fast = fast->nextNode;
		if (fast != NULL) {
			slow = slow->nextNode;
			fast = fast->nextNode;
		}
		
	}

	*frontRef = sourceNode;
	*backRef = slow->nextNode;
	//splits
	slow->nextNode = NULL;
}

void tailNodeFinder(StudentList **headNode, StudentList **tailNode) {
	//goes through linked list to get tail node pointer
	StudentList *tempPtr = *headNode;
	while (tempPtr != NULL) {
		tempPtr = tempPtr->nextNode;
		if (tempPtr->nextNode == NULL) {
			*tailNode = tempPtr;
			//this breaks the loop so tempPtr points the the last node that points to null
			break;
		}
	}
	if (tempPtr == NULL) {//base case that there one or no nodes
		*tailNode = *headNode;
	}
}
void printLinkedList(StudentList**headNode) {
	StudentList *tempPtr = (*headNode);
	//create blank international and domestic students to compare and see which type each node is
	DomesticStudent blankDomesticStudent;
	InternationalStudent blankInternationalStudent;
	if (tempPtr == NULL) {//base case that there one or no nodes
		cout << "Linked list is empy..." << endl;
	}
	while (tempPtr != NULL) {//compares determins node type and prints object
		if (tempPtr->domStudent == blankDomesticStudent) {
			cout << tempPtr->intStudent << endl;
	
		}
		else if (tempPtr->intStudent == blankInternationalStudent) {
			cout <<tempPtr->domStudent << endl;
		}
		tempPtr = tempPtr->nextNode;
		
	}

}



