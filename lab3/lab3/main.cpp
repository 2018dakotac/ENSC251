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

void insertNode(DomesticStudent Student1, StudentList **domesticHeadNode);
void insertNode(InternationalStudent Student1, StudentList **internationalHeadNode);

void frontBackSplit(StudentList*sourceNode, StudentList**frontRef, StudentList**backRef);
void mergeSort(StudentList**headRef, char type);
StudentList * SortedMerge(StudentList*a, StudentList*b, char type);
void tailNodeFinder(StudentList **headNode, StudentList **tailNode);
void printLinkedList(StudentList**headNode);


//void insertSort(DomesticStudent **domesticHeadNode, DomesticStudent **domesticTailNode);
//look on piazza to see if you actually need to sort the list each time you input a node or if you can do it after (when reading from file)
//TO DO but not required
//need basic input checking see cin.fail() exit program or clear input buffer, make a function then call it after each cin?
//there is some built in error checking for some of the set functions, maybe improve or add some (except for country too many countries)

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

	//creating pointer to dynamic array of domestic student objects, intially allocating 100 spaces
	DomesticStudent *Domestic = new DomesticStudent[100];

	//formatting the output for reading the file, with headers for each category at the top
	cout << setw(20) << left << "Application ID" << setw(20) << left << "First Name" << setw(20) << left << "Last Name"
		<< setw(20) << left << "Research Score" << setw(20) << left << "CGPA" << setw(20) << left << "Province" << endl;




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
		Domestic[stu_count1].set_firstname(firstName);
		fakeStudent.set_firstname(firstName);

		//get lastName separated by comma
		getline(ss, lastName, ',');
		Domestic[stu_count1].set_lastname(lastName);
		fakeStudent.set_lastname(lastName);

		//get province separated by comma
		getline(ss, province, ',');
		Domestic[stu_count1].set_province(province);
		fakeStudent.set_province(province);
		//get cpga separated by comma, and convert string to float
		getline(ss, s_cgpa, ',');
		cgpa = atof(s_cgpa.c_str());
		Domestic[stu_count1].set_cgpa(cgpa);
		fakeStudent.set_cgpa(cgpa);
		//get researchScore separated by comma, and convert it to int
		getline(ss, s_researchScore, ',');
		researchScore = atoi(s_researchScore.c_str());
		Domestic[stu_count1].set_researchscore(researchScore);
		fakeStudent.set_researchscore(researchScore);
		//setting the application ID
		Domestic[stu_count1].set_appID(studentnum);
		fakeStudent.set_appID(studentnum);
		//use overloaded operator to print out data each time
		cout << Domestic[stu_count1];
		cout << fakeStudent;
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

	//formatting the output to have header categories for each member
	cout << setw(20) << left << "Application ID" << setw(20) << left << "First Name" << setw(20) << left << "Last Name"
		<< setw(20) << left << "Research Score" << setw(20) << left << "CGPA" << setw(20) << left << "Country"
		<< setw(10) << left << "TOEFL" << setw(10) << left << "Reading" << setw(10) << left << "Writing"
		<< setw(10) << left << "Listening" << setw(10) << left << "Speaking" << endl;

	//while loop for reading the file and putting the data into the International object
	//for international student file reading, to keep track of how may entries are made
	int stu_count2 = 0;

	//creating pointer to dynamic array of international student objects, with 100 memory spaces allocated for memory
	InternationalStudent *International = new InternationalStudent[100];

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
		International[stu_count2].set_firstname(firstName);
		fakeStudent.set_firstname(firstName);

		//get lastName separated by comma
		getline(ss, lastName, ',');
		International[stu_count2].set_lastname(lastName);
		fakeStudent.set_lastname(lastName);

		//get country separated by comma
		getline(ss, country, ',');
		International[stu_count2].set_country(country);
		fakeStudent.set_country(country);
		//get cpga separated by comma, and convert string to float
		getline(ss, s_cgpa, ',');
		cgpa = atof(s_cgpa.c_str());
		International[stu_count2].set_cgpa(cgpa);
		fakeStudent.set_cgpa(cgpa);
		//get researchScore separated by comma, and convert it to int
		getline(ss, s_researchScore, ',');
		researchScore = atoi(s_researchScore.c_str());
		International[stu_count2].set_researchscore(researchScore);
		fakeStudent.set_researchscore(researchScore);
		//setting the application ID of the student
		International[stu_count2].set_appID(studentnum);
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
		International[stu_count2].set_Tread(reading);//reading 
		International[stu_count2].set_Twrite(writing);//writing
		International[stu_count2].set_Tlisten(listening);//listening
		International[stu_count2].set_Tspeak(speaking);//speaking
		International[stu_count2].set_Ttotal(reading, writing, listening, speaking);//total
		fakeStudent.set_Tread(reading);
		fakeStudent.set_Tlisten(listening);
		fakeStudent.set_Twrite(writing);
		fakeStudent.set_Tspeak(speaking);
		fakeStudent.set_Ttotal(reading, writing, listening, speaking);

		//output using overloaded output operator
		cout << International[stu_count2] << endl;
		cout << fakeStudent << endl;

		//pass student object to linked list
		insertNode(fakeStudent, &internationalHeadNode);
		
		//incrementing student number counter to ensure no 2 students have same number
		studentnum++;
		//incrementing loop counter
		stu_count2++;
	}

	//closing the file
	InternationalFile.close();

	//sort international linked list
	mergeSort(&internationalHeadNode, 'R');
	//set internatinonal tail node 
	tailNodeFinder(&internationalHeadNode, &internationalTailNode);

	//lab 3 sorting

	//initialize/reset variables for loop conditions
	int sorttries = 0;//tries for sorting
	char linkedSort = 'x';
	char sortAgain = 'x';

	while (sorttries<50){


		cout << endl << endl << "Linked lists have been intilialized while being continually sorted." << endl;
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




	DomesticStudent tempD; // temp object for swapping
	InternationalStudent tempI; //temp pbject for swapping
	char students = 'x'; //input for student type to sort
	int stutries = 0; //attempts for student type
	int categorytries = 0; //attempts for category
	int high2lowtries = 0;//attempts for high to low or low to high
	char HL = 'x'; //input for high to low choice
	char sorting = 'x';//input for sorting type
	sorttries = 0;//tries for sorting
	char sortyn = 'x';//resorting choice



	//lab 2 sorting
	while (sorttries < 50)//while loop for resorting option
	{

		while (stutries < 50) //while loop for choosing student type
		{

			cout << "Which group would you like to sort? Enter 'D' for Domestic Students, 'I' for International Student, and 'O' for an overall sort." << endl;
			cin >> students;//student type choice
		   //domestic student sort
			if (students == 'D' || students == 'd')
			{

				while (categorytries < 50) //while loop for choosing category
				{
					cout << "What would you like to sort? Enter C for sorting cgpa, R for research score, F for first name, "
						<< "P for province, and L for sorting last name" << endl;
					cin >> sorting;//category choice

					//sort cgpa from highest to lowest
					if (sorting == 'C' || sorting == 'c')
					{
						if (sorting == 'c')
							sorting = 'C';
						singleSort(stu_count1, Domestic, sorting);
						break;
					}

					//research score sort from highest to lowest
					else if (sorting == 'R' || sorting == 'r')
					{
						//sanitize input 
						if (sorting == 'r')
							sorting = 'R';
						singleSort(stu_count1, Domestic, sorting);
						break;
					}

					//first name sort in alphabetical order from A-Z
					else if (sorting == 'F' || sorting == 'f')
					{
						//sanitize input
						if (sorting == 'f')
							sorting = 'F';
						singleSort(stu_count1, Domestic, sorting);
						break;
					}

					//last name sort in alphabetical order from A-Z
					else if (sorting == 'L' || sorting == 'l')
					{
						//sanitize input
						if (sorting == 'l')
							sorting = 'L';
						singleSort(stu_count1, Domestic, sorting);
						break;
					}

					//province sort in alphabetical order from A-Z
					else if (sorting == 'P' || sorting == 'p')
					{
						//sanitize input
						if (sorting == 'p')
							sorting = 'P';
						singleSort(stu_count1, Domestic, sorting);
						break;
					}

					//invalid letter inputted for catergory
					else
					{
						categorytries++; //increment while loop counter
						cout << "Error: Invalid entry for category to sort. Please try again. You have " << 50 - categorytries << " tries remaining"
							<< endl;
					}
				}
				//break out of student loop
				break;
			}


			//international student sorting 

			else if (students == 'I' || students == 'i')
			{

				while (categorytries < 50) //category while loop
				{
					cout << "What would you like to sort? Enter C for sorting cgpa, R for research score, F for first name "
						<< " L for sorting last name, Z for sorting by country, and T for sorting ToeflScore." << endl;
					cin >> sorting;//choice for category sort

					//sort cgpa highest to lowest order
					if (sorting == 'C' || sorting == 'c')
					{
						//sanitize input
						if (sorting == 'c')
							sorting = 'C';
						singleSort(stu_count2, International, sorting);
						break;
					}

					//sort research score highest to lowest
					else if (sorting == 'R' || sorting == 'r')
					{
						//sanitize input
						if (sorting == 'r')
							sorting = 'R';
						singleSort(stu_count2, International, sorting);
						break;
					}

					//sort first name in alphabetical order from A-Z
					else if (sorting == 'F' || sorting == 'f')
					{
						//sanitize input
						if (sorting == 'f')
							sorting = 'F';
						singleSort(stu_count2, International, sorting);
						break;
					}

					//sort last name in alphabetical order from A-Z
					else if (sorting == 'L' || sorting == 'l')
					{
						//sanitize input
						if (sorting == 'l')
							sorting = 'L';
						singleSort(stu_count2, International, sorting);
						break;
					}

					//I for international/country sort, sorting them in alphabetical order from A-Z
					else if (sorting == 'Z' || sorting == 'z')
					{
						//sanitize input
						if (sorting == 'z')
							sorting = 'Z';
						singleSort(stu_count2, International, sorting);
						break;
					}

					//toefl score sort from highest to lowest number
					else if (sorting == 'T' || sorting == 't')
					{
						//sanitize input
						if (sorting == 't')
							sorting = 'T';
						singleSort(stu_count2, International, sorting);
						break;
					}

					//invalid category to sort by
					else
					{
						categorytries++; //increment while loop and retry
						cout << "Error: Invalid entry for category to sort. Please try again. You have " << 50 - categorytries << " tries remaining"
							<< endl;
					}
				}
				//break out of student while loop
				break;
			}

			//overall sorting, sorts both domestic and international students. Research score, cgpa, province/country is the precedence order
			else if (students == 'O' || students == 'o')
			{

				//overall for Domestic Students 
				 //selection sort algorithm
				for (int i = 0; i < stu_count1 - 1; i++)
				{
					for (int j = i + 1; j < stu_count1; j++)
					{
						//swap elements if element j has larger research score
						if (compareResearchScore(Domestic[i], Domestic[j]) == -1)
						{
							//swap using overloaded assignment operator
							tempD = Domestic[i];//use temp to swap
							Domestic[i] = Domestic[j];
							Domestic[j] = tempD;
						}
						//if research score is equal, check cgpa	
						if (compareResearchScore(Domestic[i], Domestic[j]) == 0)
						{
							//if element j has higher cgpa than element i, swap them
							if (compareCGPA(Domestic[i], Domestic[j]) == -1)
							{
								//swap using overloaded assingment operator
								tempD = Domestic[i];//use temp to swap
								Domestic[i] = Domestic[j];
								Domestic[j] = tempD;
							}
							//if cgpa is equal, check province
							if (compareCGPA(Domestic[i], Domestic[j]) == 0)
							{
								//if element j preceeds element i alphebetically, swap them
								if (compareProvince(Domestic[i], Domestic[j]) == -1)
								{
									//swap using overloaded assignment operator
									tempD = Domestic[i];//use temp to swap
									Domestic[i] = Domestic[j];
									Domestic[j] = tempD;
								}
							}
						}
					}
				}

				//overall for international students
				//selection sort algorithm
				for (int i = 0; i < stu_count2 - 1; i++)
				{
					for (int j = i + 1; j < stu_count2; j++)
					{
						//if element j has larger research score than element i, swap the two
						if (compareResearchScore(International[i], International[j]) == -1)
						{
							//swap using overloaded assignment operator
							tempI = International[i];//use temp to swap
							International[i] = International[j];
							International[j] = tempI;
						}
						//if research score is equal, check cgpa	
						if (compareResearchScore(International[i], International[j]) == 0)
						{
							//if element j has larger cgpa than element i, swap them
							if (compareCGPA(International[i], International[j]) == -1)
							{
								//swap using overloaded assignement operator
								tempI = International[i];//use temp to swap
								International[i] = International[j];
								International[j] = tempI;
							}
							//if cgpa is equal, check country
							if (compareCGPA(International[i], International[j]) == 0)
							{
								//if element j has country preceeding element i alphabetically, swap them
								if (compareCountry(International[i], International[j]) == -1)
								{
									//swap using overloaded assignment operator
									tempI = International[i];//use temp to swap
									International[i] = International[j];
									International[j] = tempI;
								}
							}
						}
					}
				}
				break;
			}

			//invalid entry for student type to sort
			else
			{
				stutries++;//increment loop counter
				cout << "Error: Invalid entry for student type to sort. Please try again. You have " << 50 - stutries << " tries remaining." << endl;
			}
		}


		//outputting the sorted arrays
		//domestic student outputting
		if (students == 'D' || students == 'd')
		{
			//order of sorting
			while (high2lowtries < 50)
			{
				cout << "What order would you like to sort by? Enter H for highest to lowest (or A-Z), and L for lowest to highest (or Z-A)" << endl;
				cin >> HL;//sorting order choice

			   //formatting category headers so clean look, used iomanip library to use setw
				cout << setw(20) << left << "Application ID" << setw(20) << left << "First Name" << setw(20) << left << "Last Name"
					<< setw(20) << left << "Research Score" << setw(20) << left << "CGPA" << setw(20) << left << "Province" << endl;

				//if choice is high to low or regular alphabetical
				if (HL == 'H' || HL == 'h')
				{
					//output array first to last element
					for (int i = 0; i < stu_count1; i++)
					{
						cout << Domestic[i];
					}
					break;
				}
				//if choice is low to high or backward alphabetical
				else if (HL == 'L' || HL == 'l')
				{
					//output from last element of array to first
					for (int i = stu_count1 - 1; i >= 0; i--)
					{
						cout << Domestic[i];
					}
					break;
				}

				else //invalid sorting order entry
				{
					high2lowtries++;
					cout << "Invalid entry for sorting order. Please try again. You have " << 50 - high2lowtries << " tries remaining" << endl;
				}
			}
		}

		//international student sorting ouput
		if (students == 'I' || students == 'i')
		{

			//order of sorting
			while (high2lowtries < 50)
			{
				cout << "What order would you like to sort by? Enter H for highest to lowest (or A-Z), and L for lowest to highest (or Z-A)" << endl;
				cin >> HL;//order of sorting input entry

			   //formatting category headers for sleek look, using setw from iomanip library
				cout << setw(20) << left << "Application ID" << setw(20) << left << "First Name" << setw(20) << left << "Last Name"
					<< setw(20) << left << "Research Score" << setw(20) << left << "CGPA" << setw(20) << left << "Country"
					<< setw(10) << left << "TOEFL" << setw(10) << left << "Reading" << setw(10) << left << "Writing"
					<< setw(10) << left << "Listening" << setw(10) << left << "Speaking" << endl;

				//high to low or alphabetical/
				if (HL == 'H' || HL == 'h')
				{
					//output first to last element, since thats how it is sorted originally
					for (int i = 0; i < stu_count2; i++)
					{
						cout << International[i] << endl;
					}
					break;
				}

				//low to high or reverse alphabetical
				else if (HL == 'L' || HL == 'l')
				{
					//output from last to first element
					for (int i = stu_count2 - 1; i >= 0; i--)
					{
						cout << International[i] << endl;
					}
					break;
				}

				//invalid entry for sorting order
				else
				{
					high2lowtries++;
					cout << "Invalid entry for sorting order. Please try again. You have " << 50 - high2lowtries << " tries remaining" << endl;
				}
			}
		}


		//overall sort choice
		if (students == 'O' || students == 'o')
		{

			//order of sorting
			while (high2lowtries < 50)
			{
				cout << "What order would you like to sort by? Enter H for highest to lowest (or A-Z), and L for lowest to highest (or Z-A)" << endl;
				cin >> HL;//choosing sorting order
				if (HL == 'H' || HL == 'h')
				{
					//seperating domestic students
					cout << endl << endl << "DOMESTIC STUDENTS---------------------------------------------------------------------------------" << endl << endl;

					//outputting the category headers for clean view, using setw from iomanip library
					cout << setw(20) << left << "Application ID" << setw(20) << left << "First Name" << setw(20) << left << "Last Name"
						<< setw(20) << left << "Research Score " << setw(20) << left << "CGPA" << setw(20) << left << "Province" << endl;

					//output array from first to last element
					for (int i = 0; i < stu_count1; i++)
					{
						cout << Domestic[i];
					}

					//seperating international students
					cout << endl << endl << "INTERNATIONAL STUDENTS-------------------------------------------------------------------" << endl << endl;

					//outputting the category headers for clean look, using setw from iomanip library
					cout << setw(20) << left << "Application ID" << setw(20) << left << "First Name" << setw(20) << left << "Last Name"
						<< setw(20) << left << "Research Score" << setw(20) << left << "CGPA" << setw(20) << left << "Country"
						<< setw(10) << left << "TOEFL" << setw(10) << left << "Reading" << setw(10) << left << "Writing"
						<< setw(10) << left << "Listening" << setw(10) << left << "Speaking" << endl;

					//output array from first to last element
					for (int i = 0; i < stu_count2; i++)
					{
						cout << International[i] << endl;
					}
					break;
				}

				//low to high or reverse alphabetical sort choice
				else if (HL == 'L' || HL == 'l')
				{

					//seperate domestic students
					cout << endl << endl << "DOMESTIC STUDENTS----------------------------------------------------------------------" << endl << endl;

					//output formatted category headers, usng setw from iomanip
					cout << setw(20) << left << "Application ID" << setw(20) << left << "First Name" << setw(20) << left << "Last Name"
						<< setw(20) << left << "Research Score " << setw(20) << left << "CGPA" << setw(20) << left << "Province" << endl;

					//output array from last to first element 
					for (int i = stu_count1 - 1; i >= 0; i--)
					{
						cout << Domestic[i];
					}

					//seperate international students
					cout << endl << endl << "INTERNATIONAL STUDENTS----------------------------------------------------------------" << endl << endl;

					//formatting category headers using setw from iomanip
					cout << setw(20) << left << "Application ID" << setw(20) << left << "First Name" << setw(20) << left << "Last Name"
						<< setw(20) << left << "Research Score" << setw(20) << left << "CGPA" << setw(20) << left << "Country"
						<< setw(10) << left << "TOEFL" << setw(10) << left << "Reading" << setw(10) << left << "Writing"
						<< setw(10) << left << "Listening" << setw(10) << left << "Speaking" << endl;

					//output from last to first element
					for (int i = stu_count2 - 1; i >= 0; i--)
					{
						cout << International[i] << endl;
					}
					break;
				}

				//invalid entry for sorting order
				else
				{
					high2lowtries++; //increment while loop counter
					cout << "Invalid entry for sorting order. Please try again. You have " << 50 - high2lowtries << " tries remaining" << endl;
				}
			}
		}

		//allowing option to do multiple sorts at once
		cout << "Would you like to sort again? Enter Y for YES, and N for NO" << endl;
		cin >> sortyn;//choice for sorting multiple times

		if (sortyn == 'Y' || sortyn == 'y')
		{
			sorttries++;//update attempts loop and sort again
			continue;
		}

		else if (sortyn == 'N' || sortyn == 'n')
			break;//stop sorting, just do once

		   //otherwise just sort once and not again
		else
		{
			cout << "Invalid entry. Outputting current sort " << endl;
			break;
		}
	}
	//delete allocated memory for the domestic and international arrays LAB23
	delete[] Domestic;
	delete[] International;



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
void insertNode(DomesticStudent Student1, StudentList **domesticHeadNode) {
	StudentList*newHead = new StudentList;
	newHead->domStudent = Student1;
	newHead->nextNode = (*domesticHeadNode);
	(*domesticHeadNode) = newHead;

}
void insertNode(InternationalStudent Student1, StudentList **internationalHeadNode) {
	StudentList*newHead = new StudentList;
	newHead->intStudent = Student1;
	newHead->nextNode = (*internationalHeadNode);
	(*internationalHeadNode) = newHead;

}
//void insertSort(DomesticStudent **domesticHeadNode, DomesticStudent **domesticTailNode);
void frontBackSplit(StudentList*sourceNode, StudentList**frontRef, StudentList**backRef) {
	StudentList *fast;
	StudentList* slow;
	slow = sourceNode;
	fast = sourceNode->nextNode;
	while (fast != NULL) {
		fast = fast->nextNode;
		if (fast != NULL) {
			slow = slow->nextNode;
			fast = fast->nextNode;
		}
	}

	*frontRef = sourceNode;
	*backRef = slow->nextNode;
	slow->nextNode = NULL;
}
void mergeSort(StudentList**headRef,char type) {
	StudentList* head = (*headRef);
	StudentList* a;
	StudentList* b;
	//base case check
	//try head.nextNode if this doesnt work
	if ((head == NULL) || (head->nextNode==NULL)) {
		return;
	}
	//split linked lists into two
	frontBackSplit(head, &a, &b);
		//recursively sorts
	mergeSort(&a,type);
	mergeSort(&b,type);

		// final merge result
	*headRef = SortedMerge(a, b,type);
}

StudentList * SortedMerge(StudentList * a, StudentList * b, char type)
{
	StudentList * result = NULL;
	if (type == 'R') {//lab 2 scheme
		
		//base case check
		if (a == NULL) {
			return (b);
		}
		if (b == NULL) {
			return (a);
		}
		if (compareListResearchScore(a, b) == -1) {
			result = a;
			result->nextNode = SortedMerge(a->nextNode, b,type);
		}
		else if ((compareListResearchScore(a, b) == 0) && (compareListCGPA(a, b) == -1)) {
			result = a;
			result->nextNode = SortedMerge(a->nextNode, b,type);
		}
		else if ((compareListResearchScore(a, b) == 0) && (compareListCGPA(a, b) == 0) && (compareListLocation(a, b) == -1)) {
			result = a;
			result->nextNode = SortedMerge(a->nextNode, b,type);
		}
		else {
			result = b;
			result->nextNode = SortedMerge(a, b->nextNode,type);
		}
		return (result);
	}
	if (type == 'O') {//for overall sort scheme
		return (result);
	}

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
	StudentList *tempPtr = *headNode;
	//create blank international and domestic students to compare and see which type each node is
	DomesticStudent blankDomesticStudent;
	InternationalStudent blankInternationalStudent;
	if (tempPtr == NULL) {//base case that there one or no nodes
		cout << "Linked list is empy..." << endl;
	}
	
	while (tempPtr != NULL) {//compares determins node type and prints object
		if (!(tempPtr->domStudent == blankDomesticStudent)) {
			cout << tempPtr->domStudent << endl;
	
		}
		if (!(tempPtr->intStudent == blankInternationalStudent)) {
			cout << tempPtr->intStudent << endl;
		}
		tempPtr = tempPtr->nextNode;
		
	}

}



