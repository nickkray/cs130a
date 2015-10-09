#include "UserNetwork.h"
#include "User.h"

UserNetwork::UserNetwork(){
    userList = new linkedlist<User>();
}

UserNetwork::~UserNetwork(){
    delete userList;
}

void UserNetwork::addUser(User newUser){
    
}

void UserNetwork::removeUser(string userName){
    
}

string UserNetwork::printUsers () const{
    return "hey";
}

linkedlist<User> UserNetwork::readUsers () const{
    return NULL;
}