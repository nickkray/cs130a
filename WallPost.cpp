#include "WallPost.h"
#include <string>
#include <ctime>
#include <sstream>
#include <time.h>

using namespace std;
/*
 string text;
 string timestamp;
 int mood;
 
 */




string WallPost::getText() const{
    return text;
}

string WallPost::getTime() const{
    return timestamp;
}

int WallPost::getMood() const{
    return mood;
}

void WallPost::setText(string newText){
    text=newText;
}

void WallPost::setTime(time_t newTime){
    timestamp=newTime;
}

void WallPost::setMood(int newMood){
    mood=newMood;
}

string WallPost::printPost() const{
    return text+" ["+timestamp+"] (Mood: "+to_string(mood)+")";
}

WallPost::WallPost(string newText, int newMood, string newTimestamp){
    text=newText;
    mood=newMood;
    timestamp = newTimestamp;
}

WallPost::WallPost(string newText, int newMood){
    text=newText;
    mood=newMood;
    time_t t = time(NULL);
    struct tm * timeinfo = localtime (&t);
    string time=asctime(timeinfo);
    time = time.substr(0,time.length()-1);
    timestamp = time;
}

WallPost::WallPost(string newText){
    text=newText;
    time_t t = time(NULL);
    struct tm * timeinfo = localtime (&t);
    string time=asctime(timeinfo);
    time = time.substr(0,time.length()-1);
    timestamp = time;
    mood = 5;
}

string WallPost::printPostData() const{
    return text+">>"+timestamp+">>"+to_string(mood);
}

WallPost::WallPost(){
    
}

WallPost::~WallPost(){
    
}
