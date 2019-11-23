#include "linkedListStudent.hpp"
#include <iostream>
#include <iomanip>
#include <string>



//default constructor
StudentList::StudentList() {
	this->nextNode = NULL;
}

int compareListResearchScore(StudentList* student1, StudentList* student2) {
	int n1, n2;
	//create student objects to see which type student1 and student 2 is  if they match that means its the opposite.
	DomesticStudent emptyDomesticStudent;
	InternationalStudent emptyInternationalStudent;

	if (student1->domStudent == emptyDomesticStudent) {
		n1 = student1->intStudent.get_researchscore();
	}
	if (student1->intStudent == emptyInternationalStudent) {
		n1 = student1->domStudent.get_researchscore();
	}

	if (student2->domStudent == emptyDomesticStudent) {
		n2 = student2->intStudent.get_researchscore();
	}
	if (student2->intStudent == emptyInternationalStudent) {
		n2 = student2->domStudent.get_researchscore();
	}


	if (n1 > n2) return 1;
	if (n1 < n2) return -1;
	return 0;
}
int compareListLocation(StudentList* student1, StudentList* student2) {
	string temp1, temp2;
	//create student objects to see which type student1 and student 2 is  if they match that means its the opposite.
	DomesticStudent emptyDomesticStudent;
	InternationalStudent emptyInternationalStudent;

	if (student1->domStudent == emptyDomesticStudent) {
		temp1 = student1->intStudent.get_country();
	}
	if (student1->intStudent == emptyInternationalStudent) {
		temp1 = student1->domStudent.get_province();
	}

	if (student2->domStudent == emptyDomesticStudent) {
		temp2 = student2->intStudent.get_country();
	}
	if (student2->intStudent == emptyInternationalStudent) {
		temp2 = student2->domStudent.get_province();
	}
	//makes strings all capital letters for more reliable comparison
	for (int i = 0; i < temp1.size(); i++) if (temp1[i] >= 'a' && temp1[i] <= 'z') temp1[i] -= ('a' - 'A');
	for (int i = 0; i < temp2.size(); i++) if (temp2[i] >= 'a' && temp2[i] <= 'z') temp2[i] -= ('a' - 'A');
	if(temp1 > temp2) return -1;
	else if (temp1 == temp2) return 0;
	else return 1;

	//return temp2.compare(temp1);
}
int compareListFirstName(StudentList* student1, StudentList* student2) {
	string temp1, temp2;
	//create student objects to see which type student1 and student 2 is  if they match that means its the opposite.
	DomesticStudent emptyDomesticStudent;
	InternationalStudent emptyInternationalStudent;

	if (student1->domStudent == emptyDomesticStudent) {
		temp1 = student1->intStudent.get_firstname();
	}
	if (student1->intStudent == emptyInternationalStudent) {
		temp1 = student1->domStudent.get_firstname();
	}

	if (student2->domStudent == emptyDomesticStudent) {
		temp2 = student2->intStudent.get_firstname();
	}
	if (student2->intStudent == emptyInternationalStudent) {
		temp2 = student2->domStudent.get_firstname();
	}
	//makes strings all capital letters for more reliable comparison
	for (int i = 0; i < temp1.size(); i++) if (temp1[i] >= 'a' && temp1[i] <= 'z') temp1[i] -= ('a' - 'A');
	for (int i = 0; i < temp2.size(); i++) if (temp2[i] >= 'a' && temp2[i] <= 'z') temp2[i] -= ('a' - 'A');
	return temp2.compare(temp1);
}
int compareListLastName(StudentList* student1, StudentList* student2) {
	string temp1, temp2;
	//create student objects to see which type student1 and student 2 is  if they match that means its the opposite.
	DomesticStudent emptyDomesticStudent;
	InternationalStudent emptyInternationalStudent;

	if (student1->domStudent == emptyDomesticStudent) {
		temp1 = student1->intStudent.get_lastname();
	}
	if (student1->intStudent == emptyInternationalStudent) {
		temp1 = student1->domStudent.get_lastname();
	}

	if (student2->domStudent == emptyDomesticStudent) {
		temp2 = student2->intStudent.get_lastname();
	}
	if (student2->intStudent == emptyInternationalStudent) {
		temp2 = student2->domStudent.get_lastname();
	}
	//makes strings all capital letters for more reliable comparison
	for (int i = 0; i < temp1.size(); i++) if (temp1[i] >= 'a' && temp1[i] <= 'z') temp1[i] -= ('a' - 'A');
	for (int i = 0; i < temp2.size(); i++) if (temp2[i] >= 'a' && temp2[i] <= 'z') temp2[i] -= ('a' - 'A');
	return temp2.compare(temp1);

}
int compareListCGPA(StudentList* student1, StudentList* student2) {
	float n1, n2;
	//create student objects to see which type student1 and student 2 is  if they match that means its the opposite.
	DomesticStudent emptyDomesticStudent;
	InternationalStudent emptyInternationalStudent;
	if (student1->domStudent == emptyDomesticStudent) {
		n1 = student1->intStudent.get_cgpa();
	}
	if (student1->intStudent == emptyInternationalStudent) {
		n1 = student1->domStudent.get_cgpa();
	}

	if (student2->domStudent == emptyDomesticStudent) {
		n2 = student2->intStudent.get_cgpa();
	}
	if (student2->intStudent == emptyInternationalStudent) {
		n2 = student2->domStudent.get_cgpa();
	}
	if (n1 > n2) return 1;
	if (n1 < n2) return -1;
	return 0;

}

void insertNode(DomesticStudent &Student1, StudentList **domesticHeadNode) { //insert node function for domestic student list
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
void insertNode(InternationalStudent &Student1, StudentList **internationalHeadNode) { //Insert node function for international student list
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


void mergeSort(StudentList**headRef, char type) {//very fast speed of O(n*Logn) 
	StudentList* head = *headRef;
	StudentList* a;
	StudentList* b;
	//base case check
	if (head == NULL || head->nextNode == NULL) {
		return;
	}
	//split linked lists into two
	frontBackSplit(head, &a, &b);
	//recursively sort itself with split lists
	mergeSort(&a, type);
	mergeSort(&b, type);

	//merge result
	*headRef = SortedMerge(a, b, type);
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
		if (compareListResearchScore(a, b) == -1) {//all comparison functions returns -1 if second is bigger, 0 if equal and 1 if in correct order
			newHead = b;
			newHead->nextNode = SortedMerge(a, b->nextNode, type);

		}
		else if (compareListResearchScore(a, b) == 0 && compareListCGPA(a, b) == -1) {
			newHead = b;
			newHead->nextNode = SortedMerge(a, b->nextNode, type);
		}
		else if (compareListResearchScore(a, b) == 0 && compareListCGPA(a, b) == 0 && compareListLocation(a, b) == -1) {
			newHead = b;
			newHead->nextNode = SortedMerge(a, b->nextNode, type);
		}
		else {
			newHead = a;
			newHead->nextNode = SortedMerge(a->nextNode, b, type);
		}
		return (newHead);
	}
	if (type == 'O') {//for overall sort scheme
		//base case check
		if (a == NULL) {
			return (b);
		}
		if (b == NULL) {
			return (a);
		}
		if (compareListResearchScore(a, b) == -1) {
			newHead = b;
			newHead->nextNode = SortedMerge(a, b->nextNode, type);

		}
		else if (compareListResearchScore(a, b) == 0 && compareListCGPA(a, b) == -1) {
			newHead = b;
			newHead->nextNode = SortedMerge(a, b->nextNode, type);
		}//assignment asks for them to be in domestic then international but program has capabilities to sort by location alpabetically regardless of student type
		//else if (compareListResearchScore(a, b) == 0 && compareListCGPA(a, b) == 0 && compareListLocation(a, b) == -1) {
		//	newHead = b;
		//	newHead->nextNode = SortedMerge(a, b->nextNode, type);
		//}
		else {
			newHead = a;
			newHead->nextNode = SortedMerge(a->nextNode, b, type);
		}

		return (newHead);
	}
	if (type == 'L') {//lab 2 scheme research score, then cgpa, then province or country

		//base case check
		if (a == NULL) {
			return (b);
		}
		if (b == NULL) {
			return (a);
		}
		if (compareListLocation(a, b) == -1) {//all comparison functions returns -1 if second is bigger, 0 if equal and 1 if in correct order
			newHead = b;
			newHead->nextNode = SortedMerge(a, b->nextNode, type);

		}
		else {
			newHead = a;
			newHead->nextNode = SortedMerge(a->nextNode, b, type);
		}
		return (newHead);
	}
	cout << "control path shouldnt reach here in sorted merge...";
	return (newHead);

}
void frontBackSplit(StudentList*sourceNode, StudentList**frontRef, StudentList**backRef) { //split front back 
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

	if (tempPtr == NULL|| tempPtr->nextNode == NULL) {//base case that there one or no nodes
		*tailNode = *headNode;
	}
	else {
		while (tempPtr != NULL) {
			tempPtr = tempPtr->nextNode;
			if (tempPtr->nextNode == NULL) {
				*tailNode = tempPtr;
				//this breaks the loop so tempPtr points the the last node that points to null
				break;
			}
		}
	}
}
void printLinkedList(StudentList**headNode) {
	StudentList *tempPtr = (*headNode);
	//create blank international and domestic students to compare and see which type each node is
	DomesticStudent blankDomesticStudent;
	InternationalStudent blankInternationalStudent;
	if (tempPtr == NULL) {//base case that there one or no nodes
		cout << "Linked list is empty...can't print" << endl;
	}
	while (tempPtr != NULL) {//compares determins node type and prints object
		if (tempPtr->domStudent == blankDomesticStudent) {
			cout << tempPtr->intStudent << endl;

		}
		else if (tempPtr->intStudent == blankInternationalStudent) {
			cout << tempPtr->domStudent;
		}
		tempPtr = tempPtr->nextNode;

	}

}
void searchGPA(StudentList**headNode, float cgpa) {
	StudentList *tempPtr = (*headNode);
	//create blank international and domestic students to compare and see which type each node is
	DomesticStudent blankDomesticStudent;
	InternationalStudent blankInternationalStudent;
	if (tempPtr == NULL) {//base case that there one or no nodes
		cout << "Linked list is empy..." << endl;
	}
	while (tempPtr != NULL) {//compares determins node type and prints object
		if (tempPtr->domStudent == blankDomesticStudent) {
			if (tempPtr->intStudent.get_cgpa() == cgpa) {
				cout << tempPtr->intStudent << endl;
			}

		}
		else if (tempPtr->intStudent == blankInternationalStudent) {
			if (tempPtr->domStudent.get_cgpa() == cgpa) {
				cout << tempPtr->domStudent << endl;
			}

		}
		tempPtr = tempPtr->nextNode;

	}
}
void searchResearchScore(StudentList**headNode, int rScore) {
	StudentList *tempPtr = (*headNode);
	//create blank international and domestic students to compare and see which type each node is
	DomesticStudent blankDomesticStudent;
	InternationalStudent blankInternationalStudent;
	if (tempPtr == NULL) {//base case that there one or no nodes
		cout << "Linked list is empy..." << endl;
	}
	while (tempPtr != NULL) {//compares determins node type and prints object
		if (tempPtr->domStudent == blankDomesticStudent) {
			if (tempPtr->intStudent.get_researchscore() == rScore) {
				cout << tempPtr->intStudent << endl;
			}

		}
		else if (tempPtr->intStudent == blankInternationalStudent) {
			if (tempPtr->domStudent.get_researchscore() == rScore) {
				cout << tempPtr->domStudent << endl;
			}

		}
		tempPtr = tempPtr->nextNode;

	}
}
void searchApplicationID(StudentList**headNode, int appID) {
	StudentList *tempPtr = (*headNode);
	//create blank international and domestic students to compare and see which type each node is
	DomesticStudent blankDomesticStudent;
	InternationalStudent blankInternationalStudent;
	if (tempPtr == NULL) {//base case that there one or no nodes
		cout << "Linked list is empty..." << endl;
	}
	while (tempPtr != NULL) {//compares determins node type and prints object
		if (tempPtr->domStudent == blankDomesticStudent) {
			if (tempPtr->intStudent.get_appID() == appID) {
				cout << tempPtr->intStudent << endl;
			}

		}
		else if (tempPtr->intStudent == blankInternationalStudent) {
			if (tempPtr->domStudent.get_appID() == appID) {
				cout << tempPtr->domStudent << endl;
			}

		}
		tempPtr = tempPtr->nextNode;

	}
}
void searchName(StudentList**headNode, string firstName, string lastName) {
	//make input strings capital
	for (int i = 0; i < firstName.size(); i++) if (firstName[i] >= 'a' && firstName[i] <= 'z') firstName[i] -= ('a' - 'A');
	for (int i = 0; i < lastName.size(); i++) if (lastName[i] >= 'a' && lastName[i] <= 'z') lastName[i] -= ('a' - 'A');

	StudentList *tempPtr = (*headNode);
	//create blank international and domestic students to compare and see which type each node is
	DomesticStudent blankDomesticStudent;
	InternationalStudent blankInternationalStudent;
	if (tempPtr == NULL) {//base case that there one or no nodes
		cout << "Linked list is empty..." << endl;
	}
	while (tempPtr != NULL) {//compares determins node type and prints object
		if (tempPtr->domStudent == blankDomesticStudent) {
			string temp1, temp2;
			temp1 = tempPtr->intStudent.get_firstname();
			temp2 = tempPtr->intStudent.get_lastname();
			for (int i = 0; i < temp1.size(); i++) if (temp1[i] >= 'a' && temp1[i] <= 'z') temp1[i] -= ('a' - 'A');
			for (int i = 0; i < temp2.size(); i++) if (temp2[i] >= 'a' && temp2[i] <= 'z') temp2[i] -= ('a' - 'A');
			if (temp1 == firstName && temp2 == lastName) {
				cout << tempPtr->intStudent << endl;
			}

		}
		else if (tempPtr->intStudent == blankInternationalStudent) {
			string temp1, temp2;
			temp1 = tempPtr->domStudent.get_firstname();
			temp2 = tempPtr->domStudent.get_lastname();
			for (int i = 0; i < temp1.size(); i++) if (temp1[i] >= 'a' && temp1[i] <= 'z') temp1[i] -= ('a' - 'A');
			for (int i = 0; i < temp2.size(); i++) if (temp2[i] >= 'a' && temp2[i] <= 'z') temp2[i] -= ('a' - 'A');
			if (temp1 == firstName && temp2 == lastName) {
				cout << tempPtr->domStudent << endl;
			}

		}
		tempPtr = tempPtr->nextNode;

	}
}

void deleteByName(StudentList**headNode, string firstName, string lastName) {
	for (int i = 0; i < firstName.size(); i++) if (firstName[i] >= 'a' && firstName[i] <= 'z') firstName[i] -= ('a' - 'A');
	for (int i = 0; i < lastName.size(); i++) if (lastName[i] >= 'a' && lastName[i] <= 'z') lastName[i] -= ('a' - 'A');
	StudentList *tempPtr = (*headNode);
	StudentList *previousNode = (*headNode);
	//create blank international and domestic students to compare and see which type each node is
	DomesticStudent blankDomesticStudent;
	InternationalStudent blankInternationalStudent;
	if (tempPtr == NULL) {//base case that there one or no nodes
		cout << "Linked list is empty..." << endl;
	}
	if (tempPtr->nextNode == NULL) {//checks if there is only one node
		*headNode = NULL;
		free(tempPtr);//free memory
		cout << "Linked list is now empty."<< endl;
	}
	else {
		while (tempPtr != NULL) {//compares determins node type and prints object

			if (tempPtr->domStudent == blankDomesticStudent) {
				string temp1, temp2;
				temp1 = tempPtr->intStudent.get_firstname();
				temp2 = tempPtr->intStudent.get_lastname();
				for (int i = 0; i < temp1.size(); i++) if (temp1[i] >= 'a' && temp1[i] <= 'z') temp1[i] -= ('a' - 'A');
				for (int i = 0; i < temp2.size(); i++) if (temp2[i] >= 'a' && temp2[i] <= 'z') temp2[i] -= ('a' - 'A');
				if (temp1 == firstName && temp2 == lastName) {

					char check = 'x';
					cout << "Do you want to delete " << endl << tempPtr->intStudent << endl << "Enter 'N' if you don't or any char if you do." << endl;
					cin >> check;
					if (check != 'N' && check != 'n') {
						cout << "Student has been Deleted" << endl;
						if (tempPtr->nextNode == NULL) {// if its the last node
							previousNode->nextNode = NULL;
							free(tempPtr);//free memory
							break;
						}
						previousNode->nextNode = tempPtr->nextNode;
						StudentList*deletedNode = tempPtr;
						tempPtr = previousNode->nextNode;
						free(deletedNode);//free memory
						continue;
					}
				}

			}
			else if (tempPtr->intStudent == blankInternationalStudent) {
				string temp1, temp2;
				temp1 = tempPtr->domStudent.get_firstname();
				temp2 = tempPtr->domStudent.get_lastname();
				for (int i = 0; i < temp1.size(); i++) if (temp1[i] >= 'a' && temp1[i] <= 'z') temp1[i] -= ('a' - 'A');
				for (int i = 0; i < temp2.size(); i++) if (temp2[i] >= 'a' && temp2[i] <= 'z') temp2[i] -= ('a' - 'A');
				if (temp1 == firstName && temp2 == lastName) {
					char check = 'x';
					cout << "Do you want to delete " << endl << tempPtr->domStudent << endl << "Enter 'N' if you don't or any char if you do." << endl;
					cin >> check;
					if (check != 'N' && check != 'n') {
						cout << "Student has been Deleted" << endl;
						if (tempPtr->nextNode == NULL) {//checks if its the last node
							previousNode->nextNode = NULL;
							free(tempPtr);//free memory
							break;
						}
						previousNode->nextNode = tempPtr->nextNode;
						StudentList*deletedNode = tempPtr;
						tempPtr = previousNode->nextNode;
						free(deletedNode);//free memory
						continue;
					}
				}

			}
			previousNode = tempPtr;
			tempPtr = tempPtr->nextNode;

		}
	}
}
void specialDelete(StudentList**headNode, StudentList **tailNode) {
	StudentList *tempPtr = *headNode;
	if (*headNode == NULL) {//base case that there one or no nodes
		cout << "Error can't special delete empty list." << endl;
		//exit(1);
	}
	//if there is only one node
	else if (tempPtr->nextNode == NULL) {//checks if there is only one node
		*headNode = NULL;
		*tailNode = NULL;
		free(tempPtr);//free memory
		cout << "Linked list is now empty."<< endl;
	}
	else {
		//this deletes the first and last node of the linked list
		StudentList *oldheadPtr = (*headNode);
		StudentList *oldtailPtr = (*headNode);

		//find node before tailnode 
		while (oldtailPtr != NULL) {
			oldtailPtr = oldtailPtr->nextNode;
			if (oldtailPtr->nextNode == (*tailNode)) {
				oldtailPtr->nextNode = NULL;
				free(*tailNode);
				*tailNode = oldtailPtr;
				//this breaks the loop so tempPtr points the the last node that points to null
				break;
			}
		}
		*headNode = oldheadPtr->nextNode;
		free(oldheadPtr);
	}

}

void threshodldPrint(StudentList**headNode, float cgpaThreshold, int researchScoreThreshold) {
	StudentList *tempPtr = (*headNode);
	//create blank international and domestic students to compare and see which type each node is
	DomesticStudent blankDomesticStudent;
	InternationalStudent blankInternationalStudent;
	if (tempPtr == NULL) {//base case that there one or no nodes
		cout << "Linked list is empy..." << endl;
	}
	while (tempPtr != NULL) {//compares determins node type and prints object
		if (tempPtr->domStudent == blankDomesticStudent) {
			if (tempPtr->intStudent.get_cgpa() >= cgpaThreshold && tempPtr->intStudent.get_researchscore() >= researchScoreThreshold) {
				//checks toeflscore requirment is met
				if (tempPtr->intStudent.checkTOEFLreq(tempPtr->intStudent.get_Tread(), tempPtr->intStudent.get_Twrite(), tempPtr->intStudent.get_Tspeak(), tempPtr->intStudent.get_Tlisten())) {
					cout << tempPtr->intStudent << endl;
				}
			}

		}
		else if (tempPtr->intStudent == blankInternationalStudent) {
			if (tempPtr->domStudent.get_cgpa() >= cgpaThreshold && tempPtr->domStudent.get_researchscore() >= researchScoreThreshold) {
				cout << tempPtr->domStudent;
			}
		}
		tempPtr = tempPtr->nextNode;

	}

}

