//student.cpp to implement your classes
#include <string>
#include <iostream>
#include "student.hpp"
using namespace std;


//Defining Student get and set functions
string Student::getFirstName()const{
    return firstName;
}
void Student::setFirstName(string newFirstName){
    firstName = newFirstName;
}
string Student::getLastName()const{
    return lastName;
}
void Student::setLastName(string newLastName){
    lastName = newLastName;
}
float Student::getCGPA()const{
    return CGPA;
}
void Student::setCGPA(float newCGPA){
    CGPA = newCGPA;
}
int Student::getrScore()const{
    return rScore;
}
void Student::setrScore(int newrScore){
    rScore = newrScore;
}
int Student::getAppID()const{
    return AppID;
}
void Student::setAppID(int newAppID){
	AppID = newAppID;
}
ostream& operator << (ostream& outs, const DomesticStudent &object)
{
	outs << setw(14) << left << object.getFirstName() << " " << setw(18) << left << object.getLastName();
	outs << setw(10) << left << object.getProvince();
	outs << setw(6) << left << object.getCGPA();
	outs << setw(4) << left << object.getrScore() << endl;
	return outs;
}

istream& operator >> (istream &ins, DomesticStudent &object)
{
	string s_tmp;
	getline(ins, s_tmp, ',');
	object.setFirstName(s_tmp);
	getline(ins, s_tmp, ',');
	object.setLastName(s_tmp);
	getline(ins, s_tmp, ',');
	object.setProvince(s_tmp);
	getline(ins, s_tmp, ',');
	object.setCGPA(atof(s_tmp.c_str()));
	getline(ins, s_tmp, ',');
	object.setrScore(atoi(s_tmp.c_str()));
	return ins;
}
//constructor
Student::Student() {
	firstName = "";
	lastName = "";
	CGPA = 0;
	rScore = 0;
}

//common functions for Domestic and International student
// returnign -1,0,1 is defined as <,=,> respectively
int compareTwoInts(int n1, int n2){
	if (n1 > n2) return 1;
	if (n1 < n2) return -1;
	return 0;
}

int compareTwoFloats(float n1, float n2){
	if (n1 > n2) return 1;
	if (n1 < n2) return -1;
	return 0;
}

int compareTwoStrings(string s1, string s2){
	for (int i = 0; i < s1.size(); i++) if (s1[i] >= 'a' && s1[i] <= 'z') s1[i] -= ('a' - 'A');
	for (int i = 0; i < s2.size(); i++) if (s2[i] >= 'a' && s2[i] <= 'z') s2[i] -= ('a' - 'A');
	return s1.compare(s2);
}
//Friend Functions of student class
int compareCGPA(Student student1, Student student2){
	return compareTwoFloats(student1.CGPA, student2.CGPA);
}

int compareResearchScore(Student student1, Student student2){
	return compareTwoInts(student1.rScore, student2.rScore);
}

int compareFirstName(Student student1, Student student2){
	return compareTwoStrings(student1.firstName, student2.firstName);
}

int compareLastName(Student student1, Student student2){
	return compareTwoStrings(student1.lastName, student2.lastName);
}






//defining all domestic student functions
string DomesticStudent::getProvince()const{
    return province;
}
void DomesticStudent::setProvince(string newProvince) {
    province = newProvince;
}
DomesticStudent::DomesticStudent() {
	province = "";
}
//Friend Function for domestic student
int compareProvince(DomesticStudent student1, DomesticStudent student2) {
	return compareTwoStrings(student1.province, student2.province);
}



//all international student functions
string InternationalStudent::getHomeCountry()const{
    return homeCountry;
}
void InternationalStudent::setHomeCountry(string newHomeCountry){
    homeCountry = newHomeCountry;
}
ToeflScore InternationalStudent::getToeflScore() const{
	ToeflScore test;
	test.setReading(toeflScore.getReading());
	test.setListening(toeflScore.getListening());
	test.setSpeaking(toeflScore.getSpeaking());
	test.setWriting(toeflScore.getWriting());
	return test;
}
void InternationalStudent::setToeflScore(ToeflScore test) {
	toeflScore.setReading(test.getReading());
	toeflScore.setListening(test.getListening());
	toeflScore.setSpeaking(test.getSpeaking());
	toeflScore.setWriting(test.getWriting());
}
void InternationalStudent::setToeflScore(int reading, int listening, int speaking, int writing) {
	toeflScore.setReading(reading);
	toeflScore.setListening(listening);
	toeflScore.setSpeaking(speaking);
	toeflScore.setWriting(writing);

}
int InternationalStudent::getReading() const{
	return toeflScore.getReading();
}
void InternationalStudent::setReading(int reading) {
	toeflScore.setReading(reading);
}
int InternationalStudent::getListening() const{
	return toeflScore.getListening();
}
void InternationalStudent::setListening(int listening) {
	toeflScore.setListening(listening);
}
int InternationalStudent::getSpeaking() const{
	return toeflScore.getSpeaking();
}
void InternationalStudent::setSpeaking(int speaking) {
	toeflScore.setSpeaking(speaking);
}
int InternationalStudent::getWriting() const{
	return toeflScore.getWriting();
}
void InternationalStudent::setWriting(int writing) {
	toeflScore.setWriting(writing);
}
int InternationalStudent::getScoreSum() const{
	int sum = 0;
	sum = sum + toeflScore.getReading();
	sum = sum + toeflScore.getListening();
	sum = sum + toeflScore.getSpeaking();
	sum = sum + toeflScore.getWriting();
    return sum;
}
ostream& operator << (ostream& outs, const InternationalStudent &object)
{
	outs << setw(14) << left << object.getFirstName() << " " << setw(18) << left << object.getLastName();
	outs << setw(10) << left << object.getHomeCountry();
	outs << setw(6) << left << object.getCGPA();
	outs << setw(4) << left << object.getrScore();
	outs << setw(4) << left << object.getReading();
	outs << setw(4) << left << object.getListening();
	outs << setw(4) << left << object.getSpeaking();
	outs << setw(4) << left << object.getWriting();
	outs << object.getScoreSum() << endl;
	return outs;
}

istream& operator >> (istream &ins, InternationalStudent &object)
{
	string s_tmp;
	getline(ins, s_tmp, ',');
	object.setFirstName(s_tmp);
	getline(ins, s_tmp, ',');
	object.setLastName(s_tmp);
	getline(ins, s_tmp, ',');
	object.setHomeCountry(s_tmp);
	getline(ins, s_tmp, ',');
	object.setCGPA(atof(s_tmp.c_str()));
	getline(ins, s_tmp, ',');
	object.setrScore(atoi(s_tmp.c_str()));
	getline(ins, s_tmp, ',');
	object.setReading(atoi(s_tmp.c_str()));
	getline(ins, s_tmp, ',');
	object.setListening(atoi(s_tmp.c_str()));
	getline(ins, s_tmp, ',');
	object.setSpeaking(atoi(s_tmp.c_str()));
	getline(ins, s_tmp, ',');
	object.setWriting(atoi(s_tmp.c_str()));
	return ins;
}
//constructor
InternationalStudent::InternationalStudent() {
	homeCountry = "";
}
//Friend Function
int compareCountry(InternationalStudent student1, InternationalStudent student2) {
	return compareTwoStrings(student1.homeCountry, student2.homeCountry);
}




