#pragma once
using namespace std;
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
	//default constructor
	ToeflScore();
private:
	int reading; //0-30
	int listening;
	int speaking;
	int writing;
	int scoreSum; //0-120
};