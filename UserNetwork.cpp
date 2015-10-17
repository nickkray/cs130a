#include "UserNetwork.h"
#include "linkedlist.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>

linkedlist<string> split(string s, string delimiter){ // "hey whats up" " ", ["hey","whats","up"]
    size_t pos = 0;
    linkedlist<string> tokens;
    string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        tokens.add(token);
        s.erase(0, pos + delimiter.length());
    }
    tokens.add(s);
    return tokens;
}

void writeStringToFile(string filename, string input){
    ofstream out(filename);
    out << input;
    out.close();
}

string readFromFile(string filename){
    std::ifstream t(filename);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}


UserNetwork::UserNetwork(string filename){
    string s = readFromFile(filename);
    
    linkedlist<string> users=split(s,"\n");
    int userCount=users.countNodes();
    string username, pass, name, g;
    for(int i=0;i<userCount;i++){
        string userString=*users.findAt(i);
        linkedlist<string> userData=split(userString,"},{"); //userData should have user},{wall
        string firstUserString=*userData.findAt(0);
        linkedlist<string> user=split(firstUserString,">>");
        linkedlist<string> wall=split(*userData.findAt(1),"||");
        
        username = *user.findAt(0);
        pass = *user.findAt(1);
        name = *user.findAt(2);
        g = *user.findAt(3);
        
        addUser(username, pass, name ,g);
        for(int j=0;j<wall.countNodes();j++){
            linkedlist<string> post=split(*wall.findAt(j),">>");
            findUser(username)->addWallPost(*post.findAt(0));
        }
    }
}

UserNetwork::UserNetwork(){
    userList = linkedlist<User>();
}

UserNetwork::~UserNetwork(){
    userList.~linkedlist();
}

void UserNetwork::addUser(string newUsername, string newPass, string newName, string newGen){
    userList.add(User(newUsername,newPass,newName,newGen));
    usernames.add(newUsername);
}

void UserNetwork::addUser(string newUsername, string newPass, string newName){
    userList.add(User(newUsername,newPass,newName,"chillin"));
    usernames.add(newUsername);
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

void UserNetwork::removeUser(string userName){

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

string UserNetwork::printUsers () const{
    return "hey";
}

linkedlist<User> UserNetwork::readUsers () const{
    return linkedlist<User>();
}

void UserNetwork::writeToFile(string filename){
    writeStringToFile(filename,serializeAllUsers());
}