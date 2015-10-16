#include "UserNetwork.h"
#include "linkedlist.h"
#include <iostream>
  
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

string UserNetwork::printUsers () const{
    return "hey";
}

linkedlist<User> UserNetwork::readUsers () const{
    return linkedlist<User>();
}