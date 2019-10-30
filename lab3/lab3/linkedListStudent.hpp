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
//need to comment this properly...

int compareListFirstName(StudentList* student1, StudentList* student2);
int compareListLastName(StudentList* student1, StudentList* student2);
int compareListCGPA(StudentList* student1, StudentList* student2);
int compareListResearchScore(StudentList* student1, StudentList* student2);
int compareListLocation(StudentList* student1, StudentList* student2);
int compareListStudentTypes(StudentList* student1, StudentList* student2);

#endif