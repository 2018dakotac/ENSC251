#include "sfuSort.h"

using namespace std;

void singleSort(DomesticStudent* DomesticStudents, int num, char type)
{
	
	// if the type is not specifically "ascending", then sort in descending order
	
	// implement bubble sort algorithm
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - 1; j++)
		{
			if (((type == 'F') && (compareFirstName(DomesticStudents[j], DomesticStudents[j + 1])))
				|| ((type == 'L') && (compareLastName(DomesticStudents[j], DomesticStudents[j + 1])))
				|| ((type == 'G') && (compareCGPA(DomesticStudents[j], DomesticStudents[j + 1])))
				|| ((type == 'R') && (compareResearchScore(DomesticStudents[j], DomesticStudents[j + 1])))
				|| ((type == 'P') && (compareProvince(DomesticStudents[j], DomesticStudents[j + 1]))))
			{
				DomesticStudent tmpStudent;
				tmpStudent = DomesticStudents[j];
				DomesticStudents[j] = DomesticStudents[j + 1];
				DomesticStudents[j + 1] = tmpStudent;
			}
		}
	}
}

void singleSort(InternationalStudent* InternationalStudents, int num, char type)
{
	// implement bubble sort algorithm
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - 1; j++)
		{
			if (((type == 'F') && (compareFirstName(InternationalStudents[j], InternationalStudents[j + 1])))
				|| ((type == 'L') && (compareLastName(InternationalStudents[j], InternationalStudents[j + 1])))
				|| ((type == 'G') && (compareCGPA(InternationalStudents[j], InternationalStudents[j + 1])))
				|| ((type == 'R') && (compareResearchScore(InternationalStudents[j], InternationalStudents[j + 1])))
				|| ((type == 'C') && (compareCountry(InternationalStudents[j], InternationalStudents[j + 1]))))
			{
				InternationalStudent tmpStudent;
				tmpStudent = InternationalStudents[j];
				InternationalStudents[j] = InternationalStudents[j + 1];
				InternationalStudents[j + 1] = tmpStudent;
			}
		}
	}
}

void sortBy(DomesticStudent* DomesticStudents, int num, string type)
{
	// repeat single sort for all the characters in the string
	// do it backwards so the first chat the user types has the highest priority
	for (int i = sizeof(type) - 1; i >= 0; i--) singleSort(DomesticStudents, num, type[i]);
}

void sortBy(InternationalStudent* InternationalStudents, int num, string type)
{
	// repeat single sort for all the characters in the string
	// do it backwards so the first chat the user types has the highest priority
	for (int i = sizeof(type) - 1; i >= 0; i--) singleSort(InternationalStudents, num, type[i]);
}
