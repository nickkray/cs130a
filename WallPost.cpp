#include "WallPost.h"
#include <string>

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
    /*stringstream ss;
    ss<<timestamp;
    string timeStampStr = ss.str();
    return "Feeling "+to_string(mood)+" - "+text+" ("+timeStampStr+")";*/
    return getText();
}

WallPost::WallPost(string newText, int newMood){
    text=newText;
    mood=newMood;
    time_t timestamp = time(NULL);
}

WallPost::WallPost(string newText){
    text=newText;
    time_t timestamp = time(NULL);
    mood = 5;
}

string WallPost::printPostData() const{
    return text+">>"+to_string(timestamp)+">>"+to_string(mood);
}

WallPost::WallPost(){
    
}

WallPost::~WallPost(){
    
}

