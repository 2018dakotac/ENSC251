//main.cpp, put your driver code here,
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <string>
#include "student.hpp"


/*I provide example code here to help you read the input
 *data from a file, so that you can focus on creating
 *and manipulating classes and objects
 */
int main(){
    //Read the domestic-stu.txt file and exit if failed
    string line;
    ifstream domesticFile("domestic-stu.txt");
    if(!domesticFile.is_open()) {
        cout << "Unable to open file domestic-stu.txt" << endl;
        return -1;
    }

    //Read the first line of domestic-stu.txt, which specifies
    //the file format. And then print it out to the screen
    getline(domesticFile, line);
    cout << "File format: " << line << endl;

    /*Keep reading the rest of the lines in domestic-stu.txt.
     *In the example code here, I will read each data separated
     *by a comma, and then print it out to the screen.
     *In your lab assignment 1, you should use these read data
     *to initialize your DomesticStudent object. Then you can
     *use get and set functions to manipulate your object, and
     *print the object content to the screen
     */
    int stu_count = 1;
    while( getline(domesticFile, line) ) {
        /*process each line, get each field separated by a comma.
         *We use istringstream to handle it.
         *Note in this example code here, we assume the file format
         *is perfect and do NOT handle error cases. We will leave the
         *error and exception handling of file format to Lab Assignment 4
         */
        istringstream ss(line);

        string firstName, lastName, province, s_cgpa, s_researchScore;
        float cgpa;
        int researchScore;
        int stuID;

        //get firstName separated by comma
        getline(ss, firstName, ',');

        //get lastName separated by comma
        getline(ss, lastName, ',');

        //get province separated by comma
        getline(ss, province, ',');

        //get cpga separated by comma, and convert string to float
        getline(ss, s_cgpa, ',');
        cgpa = atof(s_cgpa.c_str());

        //get researchScore separated by comma, and convert it to int
        getline(ss, s_researchScore, ',');
        researchScore = atoi(s_researchScore.c_str());
        //basic error checking here
        if(cgpa < 0 || cgpa > 4.33){
            cout << "invalid cgpa" << endl;
            continue;
        }

        if(researchScore < 0 || researchScore > 100){
            cout << "invalid research score" << endl;
            continue;
        }
        stuID = 20200000 - 1 + stu_count;//make student ID
        //print the student info to the screen
        cout << "Domestic student " << " " << firstName << " "
             << lastName << " from " << province << " province has cgpa of "
             << cgpa << ", and research score of " << researchScore << " and student ID of "<< stuID<< endl;

        //SET FUNCTIONS
        DomesticStudent testDomStudent;
        testDomStudent.setFirstName(firstName);
        testDomStudent.setLastName(lastName);
        testDomStudent.setCGPA(cgpa);
        testDomStudent.setrScore(researchScore);
        testDomStudent.setAppID(stuID);
        testDomStudent.setProvince(province);
        //GET FUNCTIONS
        string firstName1 = testDomStudent.getFirstName();
        string lastName1 = testDomStudent.getLastName();
        float cgpa1 = testDomStudent.getCGPA();
        int researchScore1 = testDomStudent.getrScore();
        int stuID1 = testDomStudent.getAppID();
        string province1 = testDomStudent.getProvince();
        /* to test functionality of get/set functions we make a domestic student object
             and then pass the values from the file to the object and retrieve them to a different variable with
             the set function. the retrieved values are then printed again to show they are the same.
             */
        cout << "Repeated values from object:"<< endl;
        cout << "Domestic student " << " " << firstName1 << " "
             << lastName1 << " from " << province1 << " province has cgpa of "
             << cgpa1 << ", and research score of " << researchScore1<< " and student ID of "<< stuID1 << endl;
        stu_count++;

    }

    //close your file
    domesticFile.close();

    string line1;
    ifstream internationalFile("international-stu.txt");
    if(!internationalFile.is_open()) {
        cout << "Unable to open file international-stu.txt" << endl;
        return -1;
    }

    //Read the first line of domestic-stu.txt, which specifies
    //the file format. And then print it out to the screen
    getline(internationalFile, line);
    cout << "File format: " << line << endl;

    /*Keep reading the rest of the lines in domestic-stu.txt.
     *In the example code here, I will read each data separated
     *by a comma, and then print it out to the screen.
     *In your lab assignment 1, you should use these read data
     *to initialize your DomesticStudent object. Then you can
     *use get and set functions to manipulate your object, and
     *print the object content to the screen
     */

    while( getline(internationalFile, line) ) {
        /*process each line, get each field separated by a comma.
         *We use istringstream to handle it.
         *Note in this example code here, we assume the file format
         *is perfect and do NOT handle error cases. We will leave the
         *error and exception handling of file format to Lab Assignment 4
         */
        istringstream ss(line);

        string firstName, lastName, country, s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;

        float cgpa;
        int researchScore;
        int reading;
        int listening;
        int speaking;
        int writing;
        int totalScore;
        int stuID;

        //get firstName separated by comma
        getline(ss, firstName, ',');

        //get lastName separated by comma
        getline(ss, lastName, ',');

        //get country separated by comma
        getline(ss, country, ',');

        //get cpga separated by comma, and convert string to float
        getline(ss, s_cgpa, ',');
        cgpa = atof(s_cgpa.c_str());

        //get researchScore separated by comma, and convert it to int
        getline(ss, s_researchScore, ',');
        researchScore = atoi(s_researchScore.c_str());

        getline(ss, s_reading, ',');
        reading = atoi(s_reading.c_str());

        getline(ss, s_listening, ',');
        listening = atoi(s_listening.c_str());

        getline(ss, s_speaking, ',');
        speaking = atoi(s_speaking.c_str());

        getline(ss, s_writing, ',');
        writing = atoi(s_writing.c_str());

        //basic error checking
        if(cgpa < 0 || cgpa > 4.33){
            cout << "invalid cgpa" << endl;
            continue;
        }

        if(researchScore < 0 || researchScore > 100){
            cout << "invalid research score" << endl;
            continue;
        }

        if(reading < 0 || reading > 30){
            cout << "invalid reading toeflscore" << endl;
            continue;
        }
        if(listening < 0 || listening > 30){
            cout << "invalid listening toeflscore" << endl;
            continue;
        }
        if(speaking < 0 || speaking > 30){
            cout << "invalid speaking toeflscore" << endl;
            continue;
        }
        if(writing < 0 || writing > 30){
            cout << "invalid writing toeflscore" << endl;
            continue;
        }

        stuID = 20200000-1 + stu_count; //make student id
        totalScore = reading + listening + speaking + writing; //calculate total toeflscore

        //print the student info to the screen
        cout << "International student "<< stuID << " " << firstName << " "
             << lastName << " from " << country << " has cgpa of "
             << cgpa << ", research score of " << researchScore << " and Toefl Scores of " << reading << ","
             << listening << "," << speaking << "," << writing << " for a total of " << totalScore << endl;


        //SET FUNCTIONS
       	ToeflScore testToeflScore;
        testToeflScore.setListening(listening);
        testToeflScore.setReading(reading);
        testToeflScore.setSpeaking(speaking);
        testToeflScore.setWriting(writing);
	

        InternationalStudent testIntStudent;
        testIntStudent.setFirstName(firstName);
        testIntStudent.setLastName(lastName);
        testIntStudent.setCGPA(cgpa);
        testIntStudent.setrScore(researchScore);
        testIntStudent.setAppID(stuID);
        testIntStudent.setHomeCountry(country);
	testIntStudent.setScoreSum(testToeflScore.getScoreSum()); //passes teofl score value to international student

        //GET FUNCTIONS
        string firstName1 = testIntStudent.getFirstName();
        string lastName1 = testIntStudent.getLastName();
        float cgpa1 = testIntStudent.getCGPA();
        int researchScore1 = testIntStudent.getrScore();
        int stuID1 = testIntStudent.getAppID();
        string country1 = testIntStudent.getHomeCountry();
        int totalScore1 = testIntStudent.getScoreSum();

        //toeflscore
        int listening1 = testToeflScore.getListening();
        int reading1 = testToeflScore.getReading();
        int speaking1 = testToeflScore.getSpeaking();
        int writing1 = testToeflScore.getWriting();
        /* to test functionality of get/set functions we make an international student obj and toefl score object
                  and then pass the values from the file to the objects and retrieve them to a different variable with
                  the set function. the retrieved values are then printed again to show they are the same.
                  */
        cout<< "Repeated values form object: "<<endl;
        cout << "International student " << stuID1 << " " << firstName1 << " "
             << lastName1 << " from " << country1 << " has cgpa of "
             << cgpa1 << ", research score of " << researchScore1 << " and Toefl Scores of " << reading1 << ","
             << listening1 << "," << speaking1 << "," << writing1 << " for a total of " << totalScore1<< endl;


        stu_count++;

    }

    //close your file
    internationalFile.close();

    return 0;
}
