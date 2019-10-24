
//Luka Cuk & Ritesh Nandakumar
//ENSC 251 Lab Assingment 
//Due:October 13th, 2019
//
//header file student.hpp to declare the class ToeflScore, the class Student, and child classes of 
//student called DomesticStudent and InternationalStudent.
//DomesicStudent contains the unique member variable 'province', and InternationalStudent contains
//the unique member varibles 'country' and 'TOEFL'. The other variables, like first and last name,
//student number, researchscore, etc are inherited from parent class Student. 
                 
#ifndef STUDENT_H //to avoid multiple class definitions
#define STUDENT_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;


//ToeflScore class is used to be able to access and set the different fields of the total toefl score
//for each international student, which includes seperate reading, writing, listening and speaking scores
class ToeflScore
{
  public:
        //constructor
	//pre condition: input values for initializing private member variables
	//post condition: initialized private member variables
	ToeflScore(int read, int listen, int speak, int write); 

        //default constructor
        //post condition: inititalizes toefl member variables to default values 
	ToeflScore();

        //pre condition: pass integer value for reading score
        //post condition: assigns the passed value to private member variable reading
	void set_reading(int read);

        //post condition: returns toefl reading score integer
	int get_reading() const;

        //pre condition: pass integer value for writing score
        //post condition: assigns the passed value to private member variable writing
	void set_writing(int write);

        //post condition: returns toefl writing score integer
	int get_writing() const;

        //pre condition: paas integer value for speaking score
        //post condition: assigns the passed value to provate member variable speaking
	void set_speaking(int speak);

        //post condition: returns toefl speaking score integer
 	int get_speaking() const;

        //pre condition: pass integer value for listening score
        //post condition: assings the pased value to private member variable listening
	void set_listening(int listen);
 
        //post condition: retruns toefl listening score integer
	int get_listening() const;

        //pre condition: passes 4 integer parameters representing individual toefl scores
        //post condition: assigns the sum of the scores to the private member varibale total
	void set_total(int read, int listen, int speak, int write);

        //post condition: returns total toefl score as integer
        int get_total() const;

        //post condition: error checks if the 4 scores are valid, and if not, exits the program.
	void errorcheck();

  private:
	//private members are all variables, for encapsulation/creating ADT
	int reading;
	int writing;
	int speaking;
	int listening;
	int total;
};

//the class Student contains the basic elements/info obtained for generic students, including things like
//the first and last names, and cgpa. These are general to all students, and is therefore used for both
//international and domestic studets (hence why its the parent class)
class Student 
{
  public:
        //constructor used to initialize basic elements of a student, with FN = first name, LN = last name, gradept = cgpa, research = research score, id = application id
        //pre condition: pass 5 parameters to describe a student, with first name, last name, cgpa, research score and application ID
        //post condition: assigns the parameters to their corresponding private member variable
        Student(string FN, string LN, float gradept, int research, int ID);
	
	
        //default student constructor
        //post condition: initializes values to default ones
	Student(); 
	
        //pre condition: pass string input parameter to use for assiging the first name of a student
        //post condition: assigns the passed name to private member variable first name
	void set_firstname(string name1);	

        //post condition:return the first name of the student
	string get_firstname() const;

        //pre condition: pass a string parameter for changing the last name of the student
        //post condition: assign the parameter to the last name varibale for the student
	void set_lastname(string name2);

        //post condition: return the first name of the student
	string get_lastname() const;

        //pre condition: pass a float value for the cgpa of the student
        //post condition:changed the value of the cgpa of the student
	void set_cgpa(float grade);

        //post condition: return the value of the cgpa of the student
	float get_cgpa() const;

        //pre condition: pass an integer value for the research score of the student, to use as the new score
        //post condition:changed the value of the research score of the student
	void set_researchscore(int RS);

        //post condition: return the research score of the student
	int get_researchscore() const ;

        //pre condition: pass the integer value of the student id number for changing the current one
        //post condition: changed the value of the student id number
	void set_appID(int IDnum); 	

        //post condition:return the value of the application id/student number of the student
	int get_appID() const;

        //pre condition:pass 2 student objects(or children of student) for comparing their cgpa's
        //post condition:return 1 if stu1 has a greater cgpa, 0 if theyre equal, -1 if stu2 has a greater cgpa
        friend int compareCGPA(Student stu1, Student stu2);

        //pre condition: pass 2 student/student children objects to compare their research scores
        //post condition:return 1 if stu1 has a greater RS, 0 if theyre equal, -1 if stu2 has a greater RS
	friend int compareResearchScore(Student stu1, Student stu2);

        //pre condition: pass 2 student/student children objects to compare their first names
        //post condition:return 1 if stu1 preceeds in alphabet, 0 if theyre the same, and -1 if stu2 preceeds
	friend int compareFirstName(Student stu1, Student stu2);

        //pre condition: pass 2 student/student children objects to compare their last names
        //post condition:return 1 if stu1 preceeds in alphabet, 0 if theyre the same, and -1 if stu2 preceeds
	friend int compareLastName(Student stu1, Student stu2); 

       //post condition: checks cgpa, research score, and application ID for validity. If either fails, exit the program
	void errorcheck();

  private:
	//private member variables, where appID is the assigned application ID of the student
	string firstname;
	string lastname;
	float cgpa;
	int researchscore;
	int appID; 
};

//the class DomesticStudent is for students that are from canada, with their specific province indicated.
//it is a child class of the class Student
class DomesticStudent : public Student
{
  public:
	//constructor used to initialize the inputs, with FN = firstname, LN = last name, gradept = cgpa, research = research score, ID = application ID, prov = province
        //pre condition: pass values to use for initialzing domestic student object
        //post condition:initialized a domestic student object with these parameters
        DomesticStudent(string FN, string LN, float gradept, int research, int ID, string prov);

	//default constructor used when initializing values are not known
        //post condition:domestic student objedct intialized with default values
	DomesticStudent();

        //pre condition: pass string values to change province for a domestic student
        //post condition:changed the province member variable for a domestic student
	void set_province(string prov); 

        //post condition:return the value of the province for the given student
	string get_province() const;

        //pre condition: pass two domestic student objects by reference to compare their provinces
        //post condition:return 1 if the province of stu1 preceeds stu2 in alphabet, 0 if they are equal, -1 if stu2's province preceeds stu1
	friend int compareProvince(const DomesticStudent &stu1,const DomesticStudent &stu2);
	
        //pre condition: pass the output stream for priting to, and a domestic student object whose information is to be printed
        //post condition:return the output stream containing info of stu to be printed
        friend ostream& operator <<(ostream& outs, const DomesticStudent& stu);

        //pre condition: pass an object whose member variables values are to be assinged to another object
        //post condition:object on the left of the equals sign holds the same values as the one on the right
	void operator =(const DomesticStudent& right_side);	
	
        //copy constructor
        //pre condition: pass a domestic student object whose member variables are to be copied to another object
        //post condition:member varibales of Dstu copied to another object
	DomesticStudent(const DomesticStudent& Dstu); 
	
	//default destructor
	//delete dyanmic memory allocated for dynamic member variables
	~DomesticStudent();

  private:
	//unique member variable to DomesticStudent
	string province;
};

//the class International student, a child of the class Student, contains two unique private member varibales,
//one for the country of which the student is from, and an object of class ToeflScore, so that the reading, 
//writing, speaking, listening, and total scores may be accessed.
class InternationalStudent : public Student
{
  public: 
	//constructor used to initialize the inputs, with FN = firstname, LN = last name, gradept = cgpa, research = research score, ID = application ID, homecountry = country
        //pre condition: pass values to use for initialzing international student object
        //post condition:initialized a international student object with these parameters
        InternationalStudent(string FN, string LN, float gradept, int research, int ID, string homecountry, int read, int listen, int speak, int write);
	
	//default constructor to initialize values when no parameters for initialization are passed
	//post condition: initialize international student objects to default values
	InternationalStudent();
	
	//pre condition: pass string to use to change country of the international student object
	//post condition: changed country of an international student
        void set_country(string home);

	//post condition:return the country of the international student object
	string get_country() const;
	
	//pre condition:pass reading score to change member of toefl score object
	//post condition: changed toefl reading score for the object
	void set_Tread(int read);

	//post condition: return toefl reading score
	int get_Tread() const;

	//pre condition: pass integer writing score to change for the international student object
	//post condition:changed the toefl writing score
	void set_Twrite(int write);

	//post condition:return toefl writing score
	int get_Twrite() const;

	//pre condition: pass integer listeining score to change it for the international student object
	//post condition:changed the toefl listening score
	void set_Tlisten(int listen);

	//post condition:return toefl listening score
	int get_Tlisten() const;

	//pre condition:pass the integer speaking score to change it for the international student object 
	//post condition:changed the toefl speaking score
	void set_Tspeak(int speak);

	//post condition:return the speaking score
	int get_Tspeak() const;

	//pre condition: pass integer values for individual scores to change total for the international student object
	//post condition:changed the toefl total score
	void set_Ttotal(int read, int write, int listen, int speak);

	//post condition:return the total toefl score
	int get_Ttotal() const;

	//pre condition:pass the 4 individual toefl scores, where total is represented by their sum, to check their validity
	//post condition:return true if they meet minimum requirements, false if not
        bool checkTOEFLreq(int read, int write, int speak, int listen);
	
	//pre condition: pass two international student objects to compare the alphabetic order of their country
	//post condition:return 1 if stu1's country preceeds stu2's alphabetically, return 0 if they are equal, and return -1 if stu2's preceeds
	friend int compareCountry(const InternationalStudent &stu1, const InternationalStudent &stu2);

	//pre condition: pass two international student objects to compare their total toefl scores
	//post condition: return 1 if stu1's is greater, 0 if theyre equal, and -1 if stu2's is greater
        friend int compareToeflScore(const InternationalStudent &stu1,const InternationalStudent &stu2);
	
	//pre condition: pass the output stream to write to and the international student object to print out
	//post condition: return the outpput stream with the information of stu written to it
        friend ostream& operator <<(ostream& outs, const InternationalStudent& stu);
 
	//pre condition:pass the object whose values are to be assinged to the other object
	//post condition:value of member variables of object on left side equal that of the left side
	void operator =(const InternationalStudent& right_side);	
	
        //copy constructor
	//pre condition:pass the object to be copied to another
	//post condition:created identical copy of the international student object
	InternationalStudent(const InternationalStudent& Istu); 
	
	//destructor
	//post condition: delete dynamic member varibale memory allocated for the international student object
	~InternationalStudent();


  private:
	//private member varibales unique to InternationalStudent, where the TOEFL score is of type ToeflScore, so each InternationStudent class
	//has the ability to hold the individual scores of the Toefl, not just the total.
	string country;
	ToeflScore TOEFL;
};


#endif //STUDENT_H
