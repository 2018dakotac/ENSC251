//header file student.hpp to declare your classes
#pragma once
#include <string> //you will have to use string in C++
#include <iostream>
using namespace std; //use namespace std

class Student
{
	public:
		
		//initializing get functions
		string getFirstName();
		string getLastName();
		float getCGPA();
		int getrScore();
		int getAppID();
		//initializing set functions
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setCGPA(float CGPA);
		void setrScore(int rScore);
		void setAppID(int AppID);

	private:
		string firstName;
		string lastName;
		float CGPA; //4.33 scale
		int rScore; //research score 1-100
		int AppID; //student ID 20200000-20209999
};
class ToeflScore {
	public:
		
		//initializing get functions
		int getReading();
		int getListening();
		int getSpeaking();
		int getWriting();
		int getScoreSum();//returns total ToeflScore

		//initializing set functions
		void setReading(int reading);
		void setListening(int listening);
		void setSpeaking(int speaking);
		void setWriting(int writing);
		//void setScoreSum(int scoreSum);
	private:
		int reading; //0-30
		int listening;
		int speaking;
		int writing;
		int scoreSum; //0-120
};

class DomesticStudent : public Student
{
	public:
		//initializing domestic get and set functions
		string getProvince();
		void  setProvince(string province);
	private:
		string province;
};

class InternationalStudent : public Student
{
	public:

		//initializing international get and set functions
		string getHomeCountry();
		int getScoreSum();
		void setHomeCountry(string homeCountry);
		void setScoreSum(int ScoreSum);
		
	private:
		string homeCountry;
		int scoreSum;	
};

