//header file student.hpp to declare your classes
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string> //you will have to use string in C++
#include <iostream>
#include <iomanip>
#include "toeflScore.h"
using namespace std; //use namespace std

class Student
{
	public:
		
		//initializing get functions
		string getFirstName()const;
		string getLastName()const;
		float getCGPA()const;
		int getrScore()const;
		int getAppID()const;
		//initializing set functions
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setCGPA(float CGPA);
		void setrScore(int rScore);
		void setAppID(int AppID);
	
		//initializing friend functions
		friend int compareCGPA(Student student1, Student student2);
		friend int compareResearchScore(Student student1, Student student2);
		friend int compareFirstName(Student student1, Student student2);
		friend int compareLastName(Student student1, Student student2);
		Student();

	private:
		//abstract data type
		string firstName;
		string lastName;
		float CGPA; //4.33 scale
		int rScore; //research score 1-100
		int AppID; //student ID 20200000-20209999
};
//common comparison functions to domestic and international
int compareTwoInts(int n1, int n2);
int compareTwoFloats(float n1, float n2);
int compareTwoStrings(string s1, string s2);



class DomesticStudent : public Student
{
	public:
		//initializing domestic get and set functions
		string getProvince()const;
		void  setProvince(string province);
		//friend function for comparing province
		friend int compareProvince(DomesticStudent student1, DomesticStudent student2);
		friend ostream& operator << (ostream& outs, const DomesticStudent &object);
		friend istream& operator >> (istream &ins, DomesticStudent &object);
		DomesticStudent();
	private:
		string province;
};

class InternationalStudent : public Student
{
	public:

		//initializing international get and set functions
		string getHomeCountry()const;
		
		ToeflScore getToeflScore()const;
		int getReading()const;
		int getListening()const; 
		int getSpeaking()const; 
		int getWriting()const; 
		int getScoreSum()const;
		//set
		void setHomeCountry(string homeCountry);
		void setToeflScore(ToeflScore newToeflScore);//sets toeflscore member to new toeflscore
		void setToeflScore(int reading, int listening, int speaking, int writing);
		void setReading(int newReading); 
		void setListening(int newListening); 
		void setSpeaking(int newSpeaking); 
		void setWriting(int newWriting); 
		InternationalStudent();
		
		//friend function for comparing Country
		friend int compareCountry(InternationalStudent student1, InternationalStudent student2);
		friend ostream& operator << (ostream& outs, const InternationalStudent &object);
		friend istream& operator >> (istream &ins, InternationalStudent &object);
		
		
	private:
		string homeCountry;
		ToeflScore toeflScore;
};
#endif // !STUDENT_HPP
