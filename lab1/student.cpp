//student.cpp to implement your classes
#include <string>
#include <iostream>
#include "student.hpp"
using namespace std;


//Defining Student get and set functions
string Student::getFirstName(){
    return firstName;
}
void Student::setFirstName(string newFirstName){
    firstName = newFirstName;
}
string Student::getLastName(){
    return lastName;
}
void Student::setLastName(string newLastName){
    lastName = newLastName;
}
float Student::getCGPA(){
    return CGPA;
}
void Student::setCGPA(float newCGPA){
    CGPA = newCGPA;
}
int Student::getrScore(){
    return rScore;
}
void Student::setrScore(int newrScore){
    rScore = newrScore;
}
int Student::getAppID(){
    return AppID;
}
void Student::setAppID(int newAppID){
    AppID = newAppID;
}

//defining all ToeflScore functions
int ToeflScore::getReading(){
    return reading;
}
void ToeflScore::setReading(int newReading){
    reading = newReading;
}
int ToeflScore::getListening(){
    return listening;
}
void ToeflScore::setListening(int newListening){
    listening = newListening;
}
int ToeflScore::getSpeaking(){
    return speaking;
}
void ToeflScore::setSpeaking(int newSpeaking){
    speaking = newSpeaking;
}
int ToeflScore::getWriting(){
    return writing;
}
void ToeflScore::setWriting(int newWriting){
	writing = newWriting;
}
int ToeflScore::getScoreSum(){//calculates teoflscore sum
 int tempScoreSum = reading+listening+speaking+writing;
    return tempScoreSum;
}

//defining all domestic student functions
string DomesticStudent::getProvince(){
    return province;
}
void DomesticStudent::setProvince(string newProvince) {
    province = newProvince;
}
//all international student functions
string InternationalStudent::getHomeCountry(){
    return homeCountry;
}
void InternationalStudent::setHomeCountry(string newHomeCountry){
    homeCountry = newHomeCountry;
}
int InternationalStudent::getScoreSum(){
    return scoreSum;
}
void InternationalStudent::setScoreSum(int newScoreSum){
scoreSum = newScoreSum;
}

