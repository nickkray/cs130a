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

User UserNetwork::findUser(string userName) const{  //return a copy of the user and their wall posts
    cout<<"the first element in our usernames is "+usernames.First();
    int index=usernames.find(userName);
    std::cout<<"\n("+to_string(index)+") is the index where we found it\n";
    if(index!=-1){
        User tmp=userList.findAt(index);
        return tmp;
    }else{
        return User("","","","");
    }
}

void UserNetwork::removeUser(string userName){

}

string UserNetwork::printUsers () const{
    return "hey";
}

linkedlist<User> UserNetwork::readUsers () const{
    return linkedlist<User>();
}