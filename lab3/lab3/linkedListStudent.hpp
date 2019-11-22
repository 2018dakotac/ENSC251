#ifndef LINKEDLISTSTUDENT
#define LINKEDLISTSTUDENT

#include <iostream>
#include <iomanip>
#include "domesticStudent.hpp"
#include "internationalStudent.hpp"
#include "student.hpp"
#include "toeflScore.hpp"

//Studentlist class can hold both international and domestic objects making overal sorting easier
class StudentList
{
public:
	//public to allow easier list manipulation 
	DomesticStudent domStudent;
	InternationalStudent intStudent;
	//pointer to next node
	StudentList *nextNode;


	StudentList();

private:
};

//FUNCTIONS TO COMPARE FIRSTNAME, LASTNAME, CGPA, RESEARCHSCORE, LOCATION
int compareListFirstName(StudentList* student1, StudentList* student2);
int compareListLastName(StudentList* student1, StudentList* student2);
int compareListCGPA(StudentList* student1, StudentList* student2);
int compareListResearchScore(StudentList* student1, StudentList* student2);
int compareListLocation(StudentList* student1, StudentList* student2);

//linked list functions
void insertNode(DomesticStudent &Student1, StudentList **domesticHeadNode);
void insertNode(InternationalStudent &Student1, StudentList **internationalHeadNode);
void specialDelete(StudentList**headNode, StudentList **tailNode);
void deleteByName(StudentList**headNode, string firstName, string lastName);

//sorting functions
void frontBackSplit(StudentList*sourceNode, StudentList**frontRef, StudentList**backRef);
void mergeSort(StudentList**headRef, char type);
StudentList * SortedMerge(StudentList*a, StudentList*b, char type);

//linked list manipulation functions
void tailNodeFinder(StudentList **headNode, StudentList **tailNode);
void printLinkedList(StudentList**headNode);
void searchResearchScore(StudentList**headNode, int rScore);
void searchGPA(StudentList**headNode, float cgpa);
void searchName(StudentList**headNode, string firstName, string lastName);
void searchApplicationID(StudentList**headNode, int appID);
void threshodldPrint(StudentList**headNode, float cgpaThreshold, int researchScoreThreshold);

#endif