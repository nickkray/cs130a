#include "UserNetwork.h"
#include "linkedlist.h"
#include "helpers.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <algorithm>


UserNetwork::UserNetwork(string filename){
    string s = readFromFile(filename);
    linkedlist<string> users=split(s,"\n");
    int userCount=users.countNodes();
    string username, wallData;
    for(int i=0;i<userCount;i++){
        if(username=="")
            continue;
        string userString=*users.findAt(i);
        linkedlist<string> userData=split(userString,"},{"); //userData should have user},{wall
        string firstUserString=*userData.findAt(0);//get our string with user data in it
        
        addUserFromString(firstUserString); //construct user object form this string
        username=usernames.back(); //get the username since its the last one added
        wallData=*userData.findAt(1); //get walldata from this
        
        findUser(username)->createWallFromString(wallData);//use the User->Wall function to build this
    }
}

UserNetwork::UserNetwork(){
    userList = list<User>();
}

UserNetwork::~UserNetwork(){
    userList.~list();
}

list<string> UserNetwork::findUserByQuery(string partial){
    list<string> matches;
    for(auto usernamesIt = usernames.begin();usernamesIt!=usernames.end();++usernamesIt){
        size_t found = (*usernamesIt).find(partial);
        if (found!=std::string::npos){
            auto it = matches.begin();
            matches.insert(it,*usernamesIt);
        }
    }
    return matches;
}

void UserNetwork::addUser(string newUsername, string newPass, string newName, string newGen){
    userList.push_back(User(newUsername,newPass,newName,newGen));
    usernames.push_back(newUsername);
}

void UserNetwork::addUserFromString(string s){
    User tmp=User(s);
    userList.push_back(tmp);
    usernames.push_back(tmp.getUsername());
}

User* UserNetwork::findUser(string userName){
    if(userName =="")
        return nullptr;
    for(auto usernamesIt = userList.begin();usernamesIt!=userList.end();++usernamesIt){
        if(userName == usernamesIt->getUsername()){
            return &(*usernamesIt);
        }
    }
    return nullptr;
}

int UserNetwork::findUserIndex(string userName){
    int i=0;
    for(auto usernamesIt = userList.begin();usernamesIt!=userList.end();++usernamesIt){
        if(userName == usernamesIt->getUsername()){
            return i;
        }
        i++;
    }
    return -1;
}

void UserNetwork::removeUser(string userName){
    usernames.remove(userName);
    for(auto usernamesIt = userList.begin();usernamesIt!=userList.end();++usernamesIt){
        if(userName == usernamesIt->getUsername()){
            userList.erase(usernamesIt);
        }
    }
}

string UserNetwork::serializeUserByUsername(string username){
    User* thisUser = findUser(username);
    if(thisUser!=nullptr){
        return thisUser->serializeUser()+","+thisUser->serializeWall()+"";
    }
        return "";
}

string UserNetwork::serializeAllUsers(){
    string serialization="";
    int i=0;
    for(auto usernamesIt = userList.begin();usernamesIt!=userList.end();++usernamesIt){
        serialization+=serializeUserByUsername(usernamesIt->getUsername());
        if(i<usernames.size()-1){
            serialization+="\n";
        }
        i++;
    }
    return serialization;
}

void UserNetwork::writeToFile(string filename){
    writeStringToFile(filename,serializeAllUsers());
}

void UserNetwork::createFriendRequest(User* from, User* to){
    to->addFriendRequest(from->getUsername());
}

string UserNetwork::printFriends(User* thisUser){
    string requests="";
    list<string> * friends = thisUser->getFriends();
    for(auto it = friends->begin();it!=friends->end();++it){
            requests+=*it+"\n";
    }
    return requests;
}

