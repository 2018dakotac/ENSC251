//Luka Cuk and Ritesh Nandakumar
//ENSC 251 Assignment 1
//
//student.cpp to define our classes, including member functions like an error check
//and constructors
#include "student.hpp" //header file where classes are declared
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>

//TOEFL SCORE DEFINITION

//ToeflScore constructor where the 4 scores are initialized, and the total score
//is initialized as their sum.
ToeflScore::ToeflScore(int read, int listen, int speak, int write) 
{
 writing = write;
 reading = read;
 speaking = speak;
 listening = listen;
 total = writing + reading + speaking + listening;
 errorcheck(); //error checking function call
}

//the default toeflscore constructor to initialize all the scores to 0;
ToeflScore::ToeflScore() 
{
 writing = 0;
 reading = 0;
 speaking = 0;
 listening = 0;
 total = 0;
}

//The error checking function of class toeflscore, where each of the
//4 scores is checked to be between 0 and 30. Note the total score is not
//checked to be between 0 and 120, because if it were to be larger than 120 or less 
//than 0, then that would be as a result of an error in one of the scores.
void ToeflScore::errorcheck()
{ 
 if((writing<0)||(writing>30)) 
 {
  cout << "Error: Invalid Writing Score. Exiting program";
  exit(-1);
 }

 if((reading<0)||(reading>30)) 
 {
  cout << "Error: Invalid Reading Score. Exiting program";
  exit(-1);
 }

 if((speaking<0)||(speaking>30)) 
 {
  cout << "Error: Invalid Speaking Score. Exiting program";
  exit(-1);
 }

 if((listening<0)||(listening>30)) 
 {
  cout << "Error: Invalid Listening Score. Exiting program";
  exit(-1);
 }
}

//mutator/set function for reading score, includes error check so that even
//if the initalized value was error checked, any new values entered after the 
//initialization are checked to be valid
void ToeflScore::set_reading(int read)
{
 reading = read;
 if((reading<0)||(reading>30)) 
 {
  cout << "Error: Invalid Reading Score. Exiting program";
  exit(-1);
 }
}

//accessor/get function for reading score
int ToeflScore::get_reading() const 
{
 return(reading);
}

//mutator/set function for writing score, also checks for valdity of entry
void ToeflScore::set_writing(int write)
{
 writing = write;
 if((writing<0)||(writing>30)) 
 {
  cout << "Error: Invalid Writing Score. Exiting program";
  exit(-1);
 }
}

//acessor/get function for the writing score
int ToeflScore::get_writing() const
{
 return(writing);
}

//mutaotr/set function for the speaking score, ensuring passed value is valid
void ToeflScore::set_speaking(int speak)
{
 speaking = speak;
 if((speaking<0)||(speaking>30)) 
 {
  cout << "Error: Invalid Speaking Score. Exiting program";
  exit(-1);
 }
}

//accessor/get function for speaking score
int ToeflScore::get_speaking() const
{
 return(speaking);
}

//mutator/set function for listening score, where the score passed is 
//checked to be within the valid range
void ToeflScore::set_listening(int listen)
{
 listening = listen;
 if((listening<0)||(listening>30)) 
 {
  cout << "Error: Invalid Listening Score. Exiting program";
  exit(-1);
 }
}

//accessor/get function for the listening score
int ToeflScore::get_listening() const
{
 return(listening);
}

//mutator/set function for the total score, where the 4 parameters are the individual
//scores and are summed to get the total. There is no error checking involved since 
//the four scores were each individually check for validity prior.
void ToeflScore::set_total(int read, int listen,int speak, int write)
{
 total = reading + writing + listening + speaking;
}

//accessor/get function for the total toefl score
int ToeflScore::get_total() const
{
 return(total);
}

//STUDENT DEFINITION

//basic student constructor where FN is first name, LN is lastname, gradept is cgpa, and
//research and ID are researchscore and application ID values. Includes a call to the error
//check function for the cgpa, gradept, and research score parameters.
Student::Student(string FN, string LN, float gradept, int research, int ID)
{      
 firstname = FN;
 lastname = LN;
 cgpa = gradept;
 researchscore = research;
 appID = ID;
 errorcheck();
}

//default student constructor that intializes the member variables to the specified values 
Student::Student()
{ 
 firstname = "NAME";
 lastname = "SURNAME";
 cgpa = 0.00;
 researchscore = 0;
 appID = 20200000;
}

//student error checking function to make sure the cgpa is not less than 0 or greater than
//4.33, the research score is not less than 0 or more than 100, and the application id is 
//not more than 20210000 or less than 20200000
void Student::errorcheck() 
{ 
 if((cgpa < 0.00) || (cgpa > 4.33))
 {
  cout << "Error: Invalid CGPA. Exiting program";
  exit(1);
}

 if((researchscore < 0) || (researchscore > 100))
 {
  cout << "Error: Invalid Research Score. Exiting program";
  exit(1);
 }

 if((appID < 20200000) || (appID >20210000 )) 
 {
  cout << "Error: Invalid Application ID. Exiting program";
  exit(1);
 }
}

//mutator/set function for the first name. Assume for lab1 that there are no issues
//in the string name provided
void Student::set_firstname(string name1) 
{ 
 firstname = name1;
}

//accessor/get function for the first name variable
string Student::get_firstname() const 
{
 return (firstname);
}

//mutator/set function for the last name. Assume for lab1 that there are no issues 
//with the string name provided
void Student::set_lastname(string name2) 
{
 lastname = name2;
}

//accessor/get function for the last name variable
string Student::get_lastname() const
{ 
 return (lastname);
}

//mutator/set function for the cgpa variable, where when wanting to set a new value
//for the cgpa, it is error checked each time to ensure the value is not less than 
//0.00 or more than 4.33 (4 point scale)
void Student::set_cgpa(float grade) 
{
 cgpa = grade;
 if((cgpa < 0.00) || (cgpa > 4.33))
 {
  cout << "Error: Invalid CGPA. Exiting program";
  exit(1);
 }
}

//accessor/get function to get the cgpa varibale
float Student::get_cgpa() const
{
 return (cgpa);
}

//mutator/set function for the research score variable, where the value RS, standing for
//research score, is assigned to researchscore (the private member var of student) and is 
//checked to be between 0 and 100, the min and max possible scores
void Student::set_researchscore(int RS) 
{
 researchscore = RS;
 if((researchscore < 0) || (researchscore > 100))
 {
  cout << "Error: Invalid Research Score. Exiting program";
  exit(1);
 }
}

//accessor/get function for the researchscore variable
int Student::get_researchscore() const 
{
 return (researchscore);
}

//mutator/set function for the application ID number, where the value passed
//is checked to be between 20200000(first student) and 20210000 (10000th student)
void Student::set_appID(int IDnum) 
{
 appID = IDnum;
 if((appID < 20200000) || (appID >20210000 )) 
 {
  cout << "Error: Invalid Application ID. Exiting program";
  exit(1);
 }
}

//accessor/get function for the application id variable
int Student::get_appID() const 
{ 
 return (appID);
}

//compare cgpa of two students, by returning 1 if the first obj has a greater value, 0 if equal, and -1 of second obj is greater
int compareCGPA(Student stu1, Student stu2)
{
 if(stu1.get_cgpa()>stu2.get_cgpa())
 {
  return(1);//1 is first obj parameter is greater
 }
 if(stu1.get_cgpa()==stu2.get_cgpa())
 {
  return(0);//0 if equal
 }
 if(stu1.get_cgpa()<stu2.get_cgpa())
 {
  return(-1);//-1 if second obj parameter is greater
 }
}

//compare research score of two students, returning 1 if first obj parameter is greater, 0 if equal, -1 if second is greater
int compareResearchScore(Student stu1, Student stu2)
{
 if(stu1.get_researchscore()>stu2.get_researchscore())
 {
  return(1);//1 if first obj parameter is greater
 }
 if(stu1.get_researchscore()==stu2.get_researchscore())
 {
  return(0);//0 if theyr equal
 }
 if(stu1.get_researchscore()<stu2.get_researchscore())
 {
  return(-1);//-1 if second obj parameter is greater
 }
}

//compare firstnames of two objects by going thru while loop examining each character. If tbey are the same but one is shoter length, ie Zoe vs Zoey, the one with less letters preceeds
//Z has a larger ASCII value than A, so if its greater then it means the lesser value one preceeds
int compareFirstName(Student stu1, Student stu2)
{
 int i = 0;
 while(stu1.get_firstname()[i]!='\0' && stu2.get_firstname()[i]!='\0')
 {
  if(stu1.get_firstname()[i]<stu2.get_firstname()[i])
  {
   return(1);//return 1 if the stu1 object preceeds alphabetically, meaning it has a lesser string value
  }
  if(stu1.get_firstname()[i]>stu2.get_firstname()[i])
  {
   return(-1); //return -1 if stu2 preceeds alphabetically (lower ASCII)
  }
  i++;//increment while loop
 }
 //check for if the strings are have same first few letters but one has ended and other did not. Shrter length one preceeds
 if(stu1.get_firstname()[i]=='\0' && stu2.get_firstname()[i]!='\0')
  {
   return(1);
  }
 if(stu1.get_firstname()[i]!='\0' && stu2.get_firstname()[i]=='\0')
  {
   return(-1);
  }

 return(0);
}

//comapare last names in same manner as first name. Lower ASCII value character preceeds alphabetically, check with loop counter for each character
int compareLastName(Student stu1, Student stu2)
{
 int i = 0;
 while(stu1.get_lastname()[i]!='\0' && stu2.get_lastname()[i]!='\0')
 {
  if(stu1.get_lastname()[i]<stu2.get_lastname()[i])
  {
   return(1);//return 1 if stu1 preceeds alphabetically
  }
  if(stu1.get_lastname()[i]>stu2.get_lastname()[i])
  {
   return(-1);//return -1 if stu2 preceeds alphabetically
  }
 i++;
 }
 //check if the last names are identicaly except one is shorter length. Shorter length one preceeds alphabetically
 if(stu1.get_lastname()[i]=='\0' && stu2.get_lastname()[i]!='\0')
  {
   return(1);
  }
 if(stu1.get_lastname()[i]!='\0' && stu2.get_lastname()[i]=='\0')
  {
   return(-1);
  }
 return(0);
}



//DOMESTIC STUDENT DEFINTION

//Domestic student constructor, which takes FN(firstname), LN (lastname), gradept(cgpa), research (researchscore)
//Id(application number), prov(province),and uses them to initialize member variables. Set functions are used to 
//initialize variables that are in the parent class Student, where we alternitivley could have called the
//Student constructor in the initialization section. Set is used since the parent constructor cant be called in the
//function body
DomesticStudent::DomesticStudent(string FN, string LN, float gradept, int research, int ID, string prov)
{      
 set_firstname(FN);//using set since the constructor for student cant be calld in the body
 set_lastname(LN);
 set_cgpa(gradept);
 set_researchscore(research);
 set_appID(ID);
 province = prov;
 //province error check
 if(province!="BC" && province!="AB" && province!="NS" &&  province!="NU" &&  province!="ON" &&  province!="PE" &&  province!="QC" &&  province!="SK" &&  province!="YT" && province!="MB" && province!="NB" && province!="NL" && province!="NT")
 {
  cout << "Error: Invalid province. Exiting Program.";
    exit(-1);
 }
 errorcheck();//calling the error check function to ensure the initialized values are valid. The error checking function 
//is in parent class Student
}

//Default domestic student constructor, where the set functions are used to initialize the variables that are a part of
//parent class Student, instead of calling the Student constructor in the initalization section.
DomesticStudent::DomesticStudent()
{  
 set_firstname("NAME");
 set_lastname("SURNAME");
 set_cgpa(0.00);
 set_researchscore(0);
 set_appID(20200000);
 province = "ab";
}

//mutator/set function for the varibale province of domestic student, with errror checking included
void DomesticStudent::set_province(string provi)  
{
 province = provi;
 //checking province entered is valid pair of letters
 if(province!="BC" && province!="AB" && province!="NS" && province!="NU" && province!="ON" && province!="PE" && province!="QC" && province!="SK" && province!="YT" &&  province!="MB" &&  province!="NB" &&  province!="NL" && province!="NT")
 {
  cout << "Error: Invalid province. Exiting Program.";
    exit(-1);
 }
}

//accessor/get function for the province variable
string DomesticStudent::get_province() const
{
 return(province);
}


//compare province strings so that a while loop increments thru the array of characters and if one is lesser than the other, ie has lower ASCII value, then it preceeds alphabetically
int compareProvince(const DomesticStudent &stu1, const DomesticStudent &stu2)
{
 int i = 0;
 while(stu1.get_province()[i]!='\0' && stu2.get_province()[i]!='\0')
 {
  //greater ASCII number means closer to z
  if(stu1.get_province()[i]<stu2.get_province()[i])
  {
  
   return(1);//return 1 if stu1 preceeds alphabetically
  }
  if(stu1.get_province()[i]>stu2.get_province()[i])
  {
   return(-1);// return -1 if stu2 preceeds
  }
  i++;
 }
 //check if the strings are same value but have different lengths. In that case print shorter one with alphabetical precedence
 //stu2 is longer
 if(stu1.get_province()[i]=='\0' && stu2.get_province()[i]!='\0')
  {
   return(1);
  }
 //stu1 is longer
 if(stu1.get_province()[i]!='\0' && stu2.get_province()[i]=='\0')
  {
   return(-1);
  }
 return(0);
}

//overloading the output operator to print the data of domestic students
ostream& operator <<(ostream& outs, const DomesticStudent& stu)
{
 outs << setw(20) << left << stu.get_appID() //using setw to format for consistent spacing
      << setw(20) << left << stu.get_firstname()
      << setw(20) << left << stu.get_lastname() 
      << setw(20) << left << stu.get_researchscore() //research score before cgpa since it has precedence in sorting
      << setw(20) << left << stu.get_cgpa() 
      << setw(20) << left << stu.get_province() << endl;
 return(outs);//return the output stream, now with all the data written to it
}

//overloading equals operator to allow for simple swapping of objects
void DomesticStudent::operator =(const DomesticStudent& right_side)
{ 
 //no dot operator for set since the object on the left side of the equals is being changed by default
 //set the left side values to that of the rigt side
 set_firstname(right_side.get_firstname());
 set_lastname(right_side.get_lastname());
 set_researchscore(right_side.get_researchscore());
 set_cgpa(right_side.get_cgpa());
 set_appID(right_side.get_appID());
 set_province(right_side.get_province());
} 

//copy constructor where the object passed has its values copied to a new domestic student object
DomesticStudent::DomesticStudent(const DomesticStudent& Dstu)
{
 DomesticStudent domobj;//object to hold the values of Dstu
 domobj.set_firstname(Dstu.get_firstname());
 domobj.set_lastname(Dstu.get_lastname());
 domobj.set_researchscore(Dstu.get_researchscore());
 domobj.set_cgpa(Dstu.get_cgpa());
 domobj.set_appID(Dstu.get_appID());
 domobj.set_province(Dstu.get_province());
}

//default destructor to allow for deleting memort of dynamic member variables
DomesticStudent::~DomesticStudent()
{
 //internationally empty
}


//INTERNATIONAL STUDENT DEFINITION

//International student constructor. Member variables of parent class Student, like the first and last name, are initialzed using the set
//functions, as the parent constructor cant be called in the function body. The member variable unique to international student, the country, is
//also initialized. In addition, the individual toefl score elements are initialized using the TOEFL variable, of class ToeflScore, and using
//its set member functiion
InternationalStudent::InternationalStudent(string FN, string LN, float gradept, int research, int ID, string homecountry, int read, int listen, int speak, int write)
{     
 set_firstname(FN); //FN = firstname, LN = lastname, gradept = cgpa,research = researchscore
 set_lastname(LN);
 set_cgpa(gradept);
 set_researchscore(research);
 set_appID(ID);
 errorcheck();//calling error checking function to ensure valid values
 TOEFL.set_reading(read);//TOEFL, which is a private member variable of InternationalStudent of type ToeflScore, uses its
//set member function to initialize the individual scores, and the total. The reason the constructor of ToeflScore is not 
//used is because it creates another object, an anonymous one.
 TOEFL.set_listening(listen);
 TOEFL.set_speaking(speak);
 TOEFL.set_writing(write);
 TOEFL.set_total(read,listen,speak,write);
 country = homecountry;//initializing the member function unique to international student
}

//Default student constructor. The set functions for member varibales of parent class Student are called
//and TOEFL member functions are used to set the individual scores to 0. Member varibale country, unique to
//international student is initialized too
InternationalStudent::InternationalStudent()
{  
 set_firstname("NAME");
 set_lastname("SURNAME");
 set_cgpa(0.00);
 set_researchscore(0);
 set_appID(20200000);
 TOEFL.set_reading(0);
 TOEFL.set_listening(0);
 TOEFL.set_speaking(0);
 TOEFL.set_writing(0);
 country = "COUNTRY";
}

//mutator/set function for the member varibale country, unique to international student. No error checking for strings.
void InternationalStudent::set_country(string home) 
{ 
 country = home;
}

//accessor/get function for the member varibale country
string InternationalStudent::get_country() const
{ 
 return(country);
}

//mutator/set function for setting the value of the reading score of the overall toeflscore. This is 
//acheived by using the set_reading function of the TOEFL object. No error checking in this function since
//it is done in the member function of Toefl, set_reading.
void InternationalStudent::set_Tread(int read) 
{
 TOEFL.set_reading(read);
}

//accessor/get function for getting the value of the reading score of the toefl score. Returned is the 
//value that is returned when the get_reading function of the class toeflscore is called, for object TOEFL.
int InternationalStudent::get_Tread() const
{
 return(TOEFL.get_reading());
}

//mutator/set function for listening score, using TOEFL.set_listening so that each international student
//object has acccess to the indiviudal scores
void InternationalStudent::set_Tlisten(int listen) 
{
 TOEFL.set_listening(listen);
}

//accessor/get function to return the value of the listening score, using the get_listening function
//of the TOEFL class
int InternationalStudent::get_Tlisten() const
{
 return(TOEFL.get_listening());
}

//mutator/set function for the speaking score of the overall Toefl score for that student
void InternationalStudent::set_Tspeak(int speak) 
{
 TOEFL.set_speaking(speak);
}

//accessor/get function for the speaking score, calling the get_speaking function of class ToeflScore
int InternationalStudent::get_Tspeak() const
{
 return(TOEFL.get_speaking());
}

//mutator/set function for the writing score, calling the set_writing function of obejct TOEFL
void InternationalStudent::set_Twrite(int write) 
{
 TOEFL.set_writing(write);
}

//accessor/get function of writing score, so that each international student object can access the individual scores
int InternationalStudent::get_Twrite() const
{
 return(TOEFL.get_writing());
}

//mutator/set function of total toefl score, which calls the set_total member function of object toefl, which adds the parameters
//passed (individual scores) to get the total
void InternationalStudent::set_Ttotal(int read, int write, int listen, int speak) 
{
 TOEFL.set_total(read,write,listen,speak);
}

//accessor/get function for the total score, which returns the returned value from the TOEFL objects function, get_total 
int InternationalStudent::get_Ttotal() const
{
 return(TOEFL.get_total());
}

//comparing the countries of two international student objects to eventually sort them alphabetically
//sort based on ASCII values such that if stu1 has a lower ASCII value (closer to A) then return 1. Return 0 if theyre equal, and -1 if stu2 preceeds stu1 in country alphabetical sorting
int compareCountry(const InternationalStudent &stu1,const InternationalStudent &stu2)
{
 int i = 0;
 while(stu1.get_country()[i]!='\0' && stu2.get_country()[i]!='\0')
 {
  //greater ASCII values means closer to Z
  if(stu1.get_country()[i]<stu2.get_country()[i])
  {
   return(1);//return 1 as stu1 country preceeds alphabetically
  }
  if(stu1.get_country()[i]>stu2.get_country()[i])
  {
   return(-1);//return -1 as stu2 country preceeds alphabetically
  }
  i++;
 }
 //check that if they are the same value, but one is shorter, return 1 if stu1 is shorter, -1 if stu2 is
 //stu1 is shorter
 if(stu1.get_country()[i]=='\0' && stu2.get_country()[i]!='\0')
  {
   return(1);
  }
 //stu2 is shorter
 if(stu1.get_country()[i]!='\0' && stu2.get_country()[i]=='\0')
  {
   return(-1);
  }
 return(0);
}


//comparing the toefl scores of two international student objects. return 1 if stu1 is larger, 0 if equal, -1 if stu2 is greater
int compareToeflScore(const InternationalStudent &stu1, const InternationalStudent &stu2)
{
 if(stu1.get_Ttotal()>stu2.get_Ttotal())
 {
  return(1);//1 if stu1 is greater
 }
 if(stu1.get_Ttotal()==stu2.get_Ttotal())
 {
  return(0);//0 if theyre equal
 }
 if(stu1.get_Ttotal()<stu2.get_Ttotal())
 {
  return(-1);//-1 if stu2 is greater
 }
}

//checking to see if the given international students scores meet minimum requirements for entry
bool InternationalStudent::checkTOEFLreq(int read, int write, int speak, int listen)
{
 int tot = read+write+speak+listen; //creating the total value
 if(read<20||write<20||speak<20||listen<20)//all must be atleast 20, individually
 return false;
 else if(tot<93)//must add to atleast 93
 return false;
 else return true; //true if meets all requirments
}

//overloading the ouput operator for easy use of << in main. Pass outputstream and object to output
ostream& operator <<(ostream& outs, const InternationalStudent& stu)
{
 outs << setw(20) << left << stu.get_appID() //use iomanip library to incorporate setw for spacing outputs
      << setw(20) << left << stu.get_firstname() 
      << setw(20) << left << stu.get_lastname() 
      << setw(20) << left << stu.get_researchscore() //research score first since it has precedence over cgpa
      << setw(20) << left << stu.get_cgpa() 
      << setw(20) << left << stu.get_country() 
      << setw(10) << left << stu.get_Ttotal() 
      << setw(10) << left << stu.get_Tread()
      << setw(10) << left << stu.get_Twrite() 
      << setw(10) << left << stu.get_Tlisten()
      << setw(10) << left << stu.get_Tspeak(); 
 return(outs);//return the output stream to be printed
}

//overloading equals operator to allow for easy swapping of objects or assigning to one another
void InternationalStudent::operator =(const InternationalStudent& right_side)
{ 
 //the set functions are setting the values of the object on the LEFT side of the equals sign implicitly
 set_firstname(right_side.get_firstname());
 set_lastname(right_side.get_lastname());
 set_researchscore(right_side.get_researchscore());
 set_cgpa(right_side.get_cgpa());
 set_appID(right_side.get_appID());
 set_Twrite(right_side.get_Twrite()); 
 set_Tread(right_side.get_Tread());  
 set_Tlisten(right_side.get_Tlisten());  
 set_Tspeak(right_side.get_Tspeak());  
 set_Ttotal(right_side.get_Tspeak(), right_side.get_Tlisten(), right_side.get_Twrite(), right_side.get_Tread());//pass all scores to set total
 set_country(right_side.get_country());
} 

//copy constructor to copy the member variables of the international student object Istu to avoid pointing to the same memory, then deleting one pointer and losing another
InternationalStudent::InternationalStudent(const InternationalStudent& Istu)
{
 InternationalStudent Intobj;//creating an international student object to hold the copied values
 Intobj.set_firstname(Istu.get_firstname());//copy each element using the set function for Intobj and get fucntions for the passed object
 Intobj.set_lastname(Istu.get_lastname());
 Intobj.set_researchscore(Istu.get_researchscore());
 Intobj.set_cgpa(Istu.get_cgpa());
 Intobj.set_appID(Istu.get_appID());
 Intobj.set_Twrite(Istu.get_Twrite()); 
 Intobj.set_Tread(Istu.get_Tread());
 Intobj.set_Tlisten(Istu.get_Tlisten()); 
 Intobj.set_Tspeak(Istu.get_Tspeak()); 
 Intobj.set_Ttotal(Istu.get_Tread(), Istu.get_Twrite(), Istu.get_Tlisten(), Istu.get_Tspeak()); 
 Intobj.set_country(Istu.get_country());
}

//default destuctor to ensure dynamic member variables are destroyed properly when passed by value to member functions
InternationalStudent::~InternationalStudent()
{
// intentionally empty
}
