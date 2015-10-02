#include "WallPost.h"

/*

 using namespace std;
 
 class WallPost{
 private:
 string text;
 time_t timestamp;
 int mood;
 public:
 //const/deconst.
 WallPost();
 ~WallPost();
 //getters
 string getText();
 time_t getTime();
 int getMood();
 //setters
 setText(string newText);
 setTime(time_t newTime);
 setMood(int newMood);
 //print our post
 string printPost();
 };

*/


string WallPost::getText(){
    return text;
}

time_c WallPost::getTime(){
    return timestamp;
}

int WallPost::getMood(){
    return mood;
}

WallPost::setText(string newText){
    text=newText;
}

WallPost::setTime(time_t newTime){
    timestamp=newTime;
}

WallPost::setMood(int newMood){
    mood=newMood;
}

WallPost::printPost(){
    stringstream ss;
    ss<<timestamp;
    string timeStampStr = ss.str();
    return "Feeling "+to_string(mood)+" - "+text+" ("+timeStampStr+")"
}

WallPost::WallPost(string newText, int newMood){
    text=newText;
    mood=newMood;
    time_t = time(NULL);
}

WallPost::WallPost(string newText){
    text=newText;
    time_t = time(NULL);
}

WallPost::~WallPost(){
    
}

