/*
//Dakota Crozier & Colin Buchko
//ENSC 251 ASSINGMENT 
//
//The main.cpp file for the program, where the classes will be put to use to read the data from a file of
//different students and their data, temporarily store it in an object of child student class, which shall be
//put into a linked list for storage.
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

//lab2 bubble sorting function kept for nostalgia purposes
void singleSort(int stu_count1, DomesticStudent *StudentD, char type);
void singleSort(int stu_count2, InternationalStudent *StudentI, char type);


int main() {
	//Intialize head and tail pointer for both domestic and international
	StudentList *domesticHeadNode = NULL;
	StudentList *internationalHeadNode = NULL;
	StudentList *domesticTailNode = NULL;
	StudentList *internationalTailNode = NULL;

	//will be given proper memory address when linked list is created
	//DOMESTIC STUDENT reading file and outputting

	//opening and checking to see if the file domestic-stu.txt opened and closing the program if opening failed.
	string line,fileName;
	
	char fileCheck = 'x';
	cout << "Enter 'Q' to open domestic file missing fields."<< endl;
	cin >> fileCheck;
	if (fileCheck == 'q' || fileCheck == 'Q') {
		fileName = "missingfielddom.txt";
	}
	else {
		fileName = "domestic-stu.txt";
	}

	ifstream domesticFile(fileName.c_str());

	if (!domesticFile.is_open()) {
		cout << "Unable to open txt file" << endl;
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
	


	//for going thru the while loop when reading the file, counting how many entries are made
	int stu_count1 = 0;

	while (getline(domesticFile, line)) {
		//process each line, get each field separated by a comma.
		 //use istringstream to handle it.
		DomesticStudent fakeStudent;
		string dump,line2;
		line2 = line;
		istringstream ss(line);
		istringstream ss2(line2);
		
		int counter = 0;
		while (getline(ss2, dump, ',')) {
			counter++;
		}
		if (counter < 5) {
			cout << "Missing Student data field. Exiting Program." << endl;
			exit(-2);
		}
		//all values read are inputted as strings, declare variables to hold them	

		string firstName, lastName, province, s_cgpa, s_researchScore;
		//variables to use once converted to float,for cgpa, and int, for research score 
		float cgpa;
		int researchScore;

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
		//checkes to see if values in range
		fakeStudent.errorcheck();
		insertNode(fakeStudent, &domesticHeadNode);
		//incrementing student number counter
		studentnum++;

		//incrementing while loop counter
		stu_count1++;
	}

	//closing the file
	domesticFile.close();

	//sort domestic linked list
	mergeSort(&domesticHeadNode, 'R');



	//set domestic tail node 
	tailNodeFinder(&domesticHeadNode, &domesticTailNode);


	//INTERNATIONAL STUDENT reading file and outputting

	//opening and checking to see if the file international-stu.txt opened, if not then closing the program
	fileCheck = 'x';
	cout << "Enter 'U' to open international file missing fields." << endl;
	cin >> fileCheck;
	if (fileCheck == 'u' || fileCheck == 'U') {
		fileName = "missingfieldint.txt";
	}
	else {
		fileName = "international-stu.txt";
	}

	ifstream InternationalFile(fileName.c_str());
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
		string dump, line2;
		line2 = line;
		istringstream ss(line);
		istringstream ss2(line2);

		int counter = 0;
		while (getline(ss2, dump, ',')) {//makes a copy of input buffer then checks number of strings seperated by ,
			counter++;
		}
		if (counter < 9) {//if there are under 9 iterations then theres a missing field
			cout << "Missing Student data field. Exiting Program." << endl;
			exit(-2);
		}
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

	cout << endl << "Linked lists have been intilialized and are sorted." << endl;

	//lab 3 sorting

	//initialize/reset variables for loop conditions
	int sorttries = 0;//tries for sorting
	char linkedSort = 'x';
	char sortAgain = 'x';

	while (sorttries < 50) {

			cout <<"Main Menu: " << endl<< "1 - view domestic list\n2 - view international list" << endl;
			cout << "S - search nodes\nA - add node \nD - delete node \nM - merge linked lists\nZ - delete head and tail node (at the same time!)" << endl;
			cin >> linkedSort;//TAKE USER INPUT
		if (linkedSort == 'M' || linkedSort == 'm') {
				break;
		}
		if (linkedSort == '1') {
			mergeSort(&domesticHeadNode, 'R');
			//formatting the output for reading the file, with headers for each category at the top
			cout << setw(20) << left << "Application ID" << setw(20) << left << "First Name" << setw(20) << left << "Last Name"
				<< setw(20) << left << "Research Score" << setw(20) << left << "CGPA" << setw(20) << left << "Province" << endl;
			//print linked list TESTING SORTING
			printLinkedList(&domesticHeadNode);
		}
		else if (linkedSort == '2') {
			mergeSort(&internationalHeadNode, 'R');
			//formatting the output to have header categories for each member
			cout << setw(20) << left << "Application ID" << setw(20) << left << "First Name" << setw(20) << left << "Last Name"
				<< setw(20) << left << "Research Score" << setw(20) << left << "CGPA" << setw(20) << left << "Country"
				<< setw(10) << left << "TOEFL" << setw(10) << left << "Reading" << setw(10) << left << "Writing"
				<< setw(10) << left << "Listening" << setw(10) << left << "Speaking" << endl;
			//print linked list
			printLinkedList(&internationalHeadNode);
		}
		else if (linkedSort == 's' || linkedSort == 'S') {
			char searchType;
			int inputFail = 1;
			while (inputFail == 1) {
				cout << "Insert what you would like to search by, 'C' for cgpa, 'A' for application ID, 'R' for research score, 'N' for first and last name" << endl;
				cin >> searchType;
				if (searchType == 'C' || searchType == 'c') {
					int inputFail = 1;
					while (inputFail) { //SEARCH BY CGPA 
						char studentType = 'x';
						cout << "Enter 'D' for domestic or 'I' for international" << endl;
						cin >> studentType;

						if (studentType == 'D' || studentType == 'd') {
							float CGPA;
							cout << "Input CGPA to search by ";
							cin >> CGPA;
							searchGPA(&domesticHeadNode, CGPA);
						}
						else if (studentType == 'I' || studentType == 'i') {
							float CGPA;
							cout << "Input CGPA to search by ";
							cin >> CGPA;
							searchGPA(&internationalHeadNode, CGPA);
						}
						else {
							cout << "Improper student type input, Try again" << endl;
							continue;
						}

						inputFail = 0;
					}
				}
				else if (searchType == 'A' || searchType == 'a') { //CODE FOR SEARCHING BY APPLICATION ID
					int inputFail = 1;
					while (inputFail) {
						char studentType = 'x';
						cout << "Enter 'D' for domestic or 'I' for international" << endl;
						cin >> studentType;

						if (studentType == 'D' || studentType == 'd') { //domestic student
							int AppID;
							cout << "Input Application ID Score to search by: ";
							cin >> AppID;
							searchApplicationID(&domesticHeadNode, AppID);
						}
						else if (studentType == 'I' || studentType == 'i') { //international
							int AppID;
							cout << "Input Application ID Score to search by: ";
							cin >> AppID;
							searchApplicationID(&internationalHeadNode, AppID);
						}
						else {
							cout << "Improper student type input, Try again" << endl;
							continue;
						}

						inputFail = 0;
					}
				}
				else if (searchType == 'R' || searchType == 'r') {//search by researchScore
					int inputFail = 1;
					while (inputFail) {
						char studentType = 'x';
						cout << "Enter 'D' for domestic or 'I' for international" << endl;
						cin >> studentType;

						if (studentType == 'D' || studentType == 'd') {
							int RScore;
							cout << "Input Research Score to search by: ";
							cin >> RScore;
							searchResearchScore(&domesticHeadNode, RScore);
						}
						else if (studentType == 'I' || studentType == 'i') {
							int RScore;
							cout << "Input Research Score to search by: ";
							cin >> RScore;
							searchResearchScore(&internationalHeadNode, RScore);
						}
						else {
							cout << "Improper student type input, Try again" << endl;
							continue;
						}

						inputFail = 0;
					}
				}
				else if (searchType == 'N' || searchType == 'n') { //SEARCH FOR NAME USING STRINGS
					int inputFail = 1;
					while (inputFail) {
						char studentType = 'x';
						cout << "Enter 'D' for domestic or 'I' for international" << endl;
						cin >> studentType;

						if (studentType == 'D' || studentType == 'd') { //domestic
							string firstName, lastName;
							cout << "Enter new student first name" << endl;
							cin >> firstName;
							cout << "Enter new student last name" << endl;
							cin >> lastName;
							searchName(&domesticHeadNode, firstName, lastName);
						}
						else if (studentType == 'I' || studentType == 'i') { //international
							string firstName, lastName;
							cout << "Enter new student first name" << endl;
							cin >> firstName;
							cout << "Enter new student last name" << endl;
							cin >> lastName;
							searchName(&internationalHeadNode, firstName, lastName);
						}
						else {
							cout << "Improper student type input, Try again" << endl;
							continue;
						}

						inputFail = 0;
					}
				}

				inputFail = 0;
			}

		}
		else if (linkedSort == 'a' || linkedSort == 'A') {
			//get user input for student info then create new student
			int inputFail = 1;
			while (inputFail) {
				char studentType = 'x';
				cout << "Enter 'D' for domestic or 'I' for international" << endl;
				cin >> studentType;
				if (studentType == 'D' || studentType == 'd') { //DOMESTIC

					string firstName, lastName, province;
					float cgpa;
					int researchScore;
					DomesticStudent fakeStudent;

					cout << "Enter new student first name" << endl; //MISC INFO
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
					fakeStudent.set_researchscore(researchScore); //FUNCTIONS TO SET INFO IN OBJECT
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

					cout << "Enter new student first name" << endl; //SAME AS ABOVE FOR INTERNATIONAL STUDENTS
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
					cout << "Improper student type input, Try again";
					continue;
				}

				inputFail = 0;
			}
		}
		else if (linkedSort == 'd' || linkedSort == 'D') {//Delete student node
			int inputFail = 1;
			while (inputFail) {
				char studentType = 'x';
				cout << "Enter 'D' for domestic or 'I' for international" << endl;
				cin >> studentType;

				if (studentType == 'D' || studentType == 'd') {
					string firstName, lastName;
					cout << "Enter student first name" << endl;
					cin >> firstName;
					cout << "Enter student last name" << endl;
					cin >> lastName;

					deleteByName(&domesticHeadNode, firstName, lastName);
					mergeSort(&domesticHeadNode, 'R');
					//printLinkedList(&domesticHeadNode);
				}
				else if (studentType == 'I' || studentType == 'i') {
					string firstName, lastName;
					cout << "Enter student first name" << endl;
					cin >> firstName;
					cout << "Enter student last name" << endl;
					cin >> lastName;

					deleteByName(&internationalHeadNode, firstName, lastName);
					mergeSort(&internationalHeadNode, 'R');
					//printLinkedList(&internationalHeadNode);
				}
				else {
					cout << "Improper student type input, Try again" << endl;
					continue;
				}

				inputFail = 0;
			}
		}
		else if (linkedSort == 'z' || linkedSort == 'Z') { //DELETE NODE FROM LIST
			int inputFail = 1;
			while (inputFail) {
				cout << "Which list would you like to delete the first and last node from, enter 'I' for international or 'D' for domestic." << endl;
				char studentType = 'x';
				cin >> studentType;
				if (studentType == 'D' || studentType == 'd') {
					tailNodeFinder(&domesticHeadNode, &domesticTailNode);
					specialDelete(&domesticHeadNode, &domesticTailNode);
					mergeSort(&domesticHeadNode, 'R');
					printLinkedList(&domesticHeadNode);
				}
				else if (studentType == 'I' || studentType == 'i') {
					tailNodeFinder(&internationalHeadNode, &internationalTailNode);
					specialDelete(&internationalHeadNode, &internationalTailNode);
					mergeSort(&internationalHeadNode, 'R');
					printLinkedList(&internationalHeadNode);
				}
				else {
					cout << "Improper student type input, Try again" << endl;
					continue;
				}
				inputFail = 0;
			}
		} else {
		cout << endl << endl << "Invalid Input... heres a more detailed list, read it over and try the main menu again." << endl;
		cout << "1 - print the domestic list\n2 - print the international list" << endl;
		cout << "S - search linked list nodes for students\nA - add student node to linked list \nD - delete student node(s) \nM - merge linked lists into one... " << endl;
		cout << "Z - delete head and tail node of a linked list (at the same time)" << endl << endl << endl;
		continue;
		}


		//allowing option to do multiple sorts at once
		cout << "Would you like to do something else? Enter Y for YES, and N for NO" << endl;
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
			cout << "Invalid entry. Terminating program" << endl;
			break;
		}
	}
	
	if (linkedSort == 'M' || linkedSort == 'm') {
		float cgpa_threshold;
		int rScore_threshold;
		//merge then sort with mergeSort but pass overall char
		tailNodeFinder(&domesticHeadNode, &domesticTailNode);
		tailNodeFinder(&internationalHeadNode, &internationalTailNode);
		domesticTailNode->nextNode = internationalHeadNode;

		//make international head and tail pointer equal to null as the linked list no longer exists
		internationalHeadNode = NULL;
		internationalTailNode = NULL;

		mergeSort(&domesticHeadNode, 'O');
		printLinkedList(&domesticHeadNode);
		char extraFeature = 'x'; //EXTRA FEATURE to sort merged list by location alphabetically
		cout << endl << "Above is all students (including ones that dont meet toefl requirements)." << endl << "To see which are addmitted to SFU in proper sorting order enter 'X', to sort merged list press by location for fun enter 'L'" << endl;
		cin >> extraFeature;
		if (extraFeature == 'L') {
			int inputFail = 1;
			while (inputFail == 1) {
				cout << "Enter 1 to sort by location solely or Enter 2 to sort by Lab2 priority of research score, cgpa and then location. Enter anything other single char when done."<< endl;
				cin >> extraFeature;
				if (extraFeature == '1') {
					mergeSort(&domesticHeadNode, 'L');
					printLinkedList(&domesticHeadNode);
				}
				else if (extraFeature == '2') {
					mergeSort(&domesticHeadNode, 'R');
					printLinkedList(&domesticHeadNode);
				}
				else {
					cout << "Invalid input, returning to SFU admission." << endl;
					break;
				}
			}
			inputFail = 0;
			cout << "Students admitted to SFU will be sorted by research score, cgpa, location instead of previous position in international and domestic list"<< endl;
			mergeSort(&domesticHeadNode, 'R');
		}
		cout << "Enter cgpa threshold" << endl;
		cin >> cgpa_threshold;
		cout << "Enter research score threshold" << endl;
		cin >> rScore_threshold;
		threshodldPrint(&domesticHeadNode, cgpa_threshold, rScore_threshold);
		cout << endl << "The students above shall be admitted to SFU!" << endl;
	}

	char something;
	cout << "Enter any char to delete all linked lists and close the program." << endl;
	cin >> something;
	//freeing up memory as program is over
	while (domesticHeadNode != NULL) {
		StudentList* soonToBeDeadNode = domesticHeadNode;
		domesticHeadNode = domesticHeadNode->nextNode;
		free(soonToBeDeadNode);

	}
	while (internationalHeadNode != NULL) {
		StudentList* soonToBeDeadNode = internationalHeadNode;
		internationalHeadNode = internationalHeadNode->nextNode;
		free(soonToBeDeadNode);
		}
	return 0;
}





void singleSort(int stu_count1, DomesticStudent *StudentD, char type) {
	//selection sort algorithm
	for (int i = 0; i < stu_count1 - 1; i++)
	{
		for (int j = i + 1; j < stu_count1; j++)
		{
			//if j element research score is larger, swap 
			if (
				((type == 'R') && (compareResearchScore(StudentD[i], StudentD[j]) == -1))
				|| ((type == 'F') && (compareFirstName(StudentD[i], StudentD[j]) == -1))
				|| ((type == 'C') && (compareCGPA(StudentD[i], StudentD[j]) == -1))
				|| ((type == 'L') && (compareLastName(StudentD[i], StudentD[j]) == -1))
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

*/
