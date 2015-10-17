#include "WallPost.h"
#include <string>
#include <ctime>
#include <sstream>
#include <time.h>

using namespace std;

string WallPost::getText() const{
    return text;
}

time_t WallPost::getTime() const{
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
    struct tm * timeinfo = localtime (&timestamp);
    string time=asctime(timeinfo);
    return text+" ["+time.substr(0,time.length()-1)+"] (Mood: "+to_string(mood)+")";
}

WallPost::WallPost(string newText, int newMood, time_t newTimestamp){
    text=newText;
    mood=newMood;
    timestamp = newTimestamp;
}

WallPost::WallPost(string newText, int newMood){
    text=newText;
    mood=newMood;
    timestamp = time(NULL);
}

WallPost::WallPost(string newText){
    text=newText;
    timestamp = time(NULL);
    mood = 5;
}

string WallPost::printPostData() const{
        ostringstream oss;
        oss << &timestamp;
    return text+">>"+oss.str()+">>"+to_string(mood);
}

WallPost::WallPost(){
    
}

WallPost::~WallPost(){
    
}
