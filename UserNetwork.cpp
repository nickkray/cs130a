#include "UserNetwork.h"
#include "linkedlist.h"
#include "helpers.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>

#include "User.h"




UserNetwork::UserNetwork(string filename){
    string s = readFromFile(filename);
    linkedlist<string> users=split(s,"\n");
    int userCount=users.countNodes();
    string username, wallData;
    for(int i=0;i<userCount;i++){
        string userString=*users.findAt(i);
        linkedlist<string> userData=split(userString,"},{"); //userData should have user},{wall
        string firstUserString=*userData.findAt(0);//get our string with user data in it
        
        addUserFromString(firstUserString); //construct user object form this string
        username=*usernames.Last(); //get the username since its the last one added
        wallData=*userData.findAt(1); //get walldata from this
        
        findUser(username)->createWallFromString(wallData);//use the User->Wall function to build this
    }
}

UserNetwork::UserNetwork(){
    userList = linkedlist<User>();
}

UserNetwork::~UserNetwork(){
    userList.~linkedlist();
}

arrList<string> UserNetwork::findUserByQuery(string partial){
    arrList<string> matches;
    for(int i=0;i<usernames.countNodes();i++){
        size_t found = usernames.findAt(i)->find(partial);
        if (found!=std::string::npos){
            matches.insert(1,*usernames.findAt(i));
        }
    }
    return matches;
}

void UserNetwork::addUser(string newUsername, string newPass, string newName, string newGen){
    userList.add(User(newUsername,newPass,newName,newGen));
    usernames.add(newUsername);
}

void UserNetwork::addUserFromString(string s){
    User tmp=User(s);
    userList.add(tmp);
    usernames.add(tmp.getUsername());
}

User* UserNetwork::findUser(string userName){
    int index=usernames.find(userName);
    if(index!=-1){
        return userList.findAt(index);
    }else{
        return NULL;
    }
    return NULL;
}

int UserNetwork::findUserIndex(string userName){
    int index=usernames.find(userName);
    return index;
}

void UserNetwork::removeUser(string userName){
    userList.removeAt(usernames.find(userName));
    usernames.removeAt(usernames.find(userName));
}

string UserNetwork::serializeUserByUsername(string username){
    User* thisUser = findUser(username);
    if(thisUser!=NULL){
        return thisUser->serializeUser()+","+thisUser->serializeWall()+"";
    }
        return "";
}

string UserNetwork::serializeAllUsers(){
    string serialization="";
    for(int i=0;i<usernames.countNodes();i++){
        serialization+=serializeUserByUsername(*usernames.findAt(i));
        if(i<usernames.countNodes()-1){
            serialization+="\n";
        }
    }
    return serialization;
}

void UserNetwork::writeToFile(string filename){
    writeStringToFile(filename,serializeAllUsers());
}

string UserNetwork::printPendingRequests(User* thisUser){
    string requests="";
    int thisUserIndex = findUserIndex(thisUser->getUsername());
    arrList<int> * indexList = thisUser->getFriends();
    for(int i=0;i<indexList->count();i++){
        if(userList.findAt(*indexList->get(i))->getFriends()->find(thisUserIndex)==-1) //make sure this is one-way
            requests+= *usernames.findAt(*indexList->get(i)) + "\n";
    }
    return requests;
}

string UserNetwork::printFriends(User* thisUser){
    string requests="";
    int thisUserIndex = findUserIndex(thisUser->getUsername());
    arrList<int> * indexList = thisUser->getFriends();
    for(int i=0;i<indexList->count();i++){
        if(userList.findAt(*indexList->get(i))->getFriends()->find(thisUserIndex)!=-1) //make sure this is one-way
            requests+= *usernames.findAt(*indexList->get(i)) + "\n";
    }
    return requests;
}

