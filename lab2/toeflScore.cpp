#include "toeflScore.h"

//defining all ToeflScore functions
int ToeflScore::getReading() {
	return reading;
}
void ToeflScore::setReading(int newReading) {
	reading = newReading;
}
int ToeflScore::getListening() {
	return listening;
}
void ToeflScore::setListening(int newListening) {
	listening = newListening;
}
int ToeflScore::getSpeaking() {
	return speaking;
}
void ToeflScore::setSpeaking(int newSpeaking) {
	speaking = newSpeaking;
}
int ToeflScore::getWriting() {
	return writing;
}
void ToeflScore::setWriting(int newWriting) {
	writing = newWriting;
}
int ToeflScore::getScoreSum() {//calculates teoflscore sum
	int tempScoreSum = reading + listening + speaking + writing;
	return tempScoreSum;
}
//constructor
ToeflScore::ToeflScore()
{
	reading = 0;
	listening = 0;
	speaking = 0;
	writing = 0;
	scoreSum = 0;
}