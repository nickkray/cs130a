#include <iostream>

#include <string>
#include <sstream>

#include "linkedlist.h"

#include "WallPost.h"
#include "Wall.h"

#include "User.h"

#include "UserNetwork.h"

using namespace std;

void createUser(UserNetwork &network);
void login(UserNetwork &network);
void loggedIn(UserNetwork &network, string username);

int main(int argc, const char * argv[]) {
    
        UserNetwork network = UserNetwork();
    
    
    cout <<"***********************************************************************************************************\n";
    cout <<"     _______  _______  __   __  _______  __   __  _______  _______  _______  _______  ___   _ \n    |       ||   _   ||  | |  ||       ||  | |  ||       ||  _    ||       ||       ||   | | |\n    |    ___||  |_|  ||  | |  ||       ||  |_|  ||   _   || |_|   ||   _   ||   _   ||   |_| |\n    |   | __ |       ||  |_|  ||       ||       ||  | |  ||       ||  | |  ||  | |  ||      _|\n    |   ||  ||       ||       ||      _||       ||  |_|  ||  _   | |  |_|  ||  |_|  ||     |_ \n    |   |_| ||   _   ||       ||     |_ |   _   ||       || |_|   ||       ||       ||    _  |\n    |_______||__| |__||_______||_______||__| |__||_______||_______||_______||_______||___| |_|\n";
    cout <<"***********************************************************************************************************";
    
    cout<<"\nTo create a new user, press 1. To login, press 2. To exit, press 0.";
    cout<<"\nEnter choice:\n";
    int choice;
    cin>>choice;
    switch(choice){
        case 0:
            //exit
            exit(0);
            break;
        case 1:
            //create
            createUser(network);
            break;
        case 2://login
            login(network);
            break;
    }
    return 0;
}

void createUser(UserNetwork &network){
    
    string username;
    string password;
    string gender;
    string name;
    
    cout<<"Enter your full name:";
    cin>>name;
    cout<<"Create a username:";
    cin>>username;
    cout<<"Create a password:";
    cin>>password;
    cout<<"Gender? (Press enter to skip):";
    cin>>gender;
    cout<<"Creating user...\n";
    //string newUsername, string newPass, string newName, string newGen){
    if(gender!=""){
        network.addUser(username, password, name, gender);
        network.findUser(username).addWallPost("hello world");
        
    }else{
        //network.addUser(username, password, name); put in this constructor later
    }
    //new user is createn

    //made a demo post
    cout<<"User creation successful("+username+")!\n";
    cout<<"Login below:\n";
    login(network);
}

void login(UserNetwork &network){
    string username;
    string password;
    
    cout <<"\nUsername:";
    cin>>username;
    cout<<"Password:";
    cin>>password;
    
    User thisUser = network.findUser(username);
    
    if(thisUser.getUsername()!=""){
        if(thisUser.getPassword()==password){
            cout<<"fuck yeah!\n";
            cout<<"What's good "+thisUser.getName()+"!\n"; //we authenticated correctly!
            loggedIn(network, username);
        }else{
            cout<<"fuck..pw mismatch"; //password mismatch
        }
    }else{
        cout<<"fuck..user mismatch"; // //username mismatch
    }
    
    
}


void loggedIn(UserNetwork &network, string username){
    
    User thisUser = network.findUser(username);
    cout<<"What would you like to do?\n";
    cout<<"0. Exit\n";
    cout<<"1. Display Wall\n";
    cout<<"2. Add new post\n";
    
    string index;
    cin>>index;
    if(index=="0"){
        exit(0);
    }else if(index=="1"){
        cout<<"Wall";
        cout<<thisUser.printUserWall();
    }else{
        cout<<"Illegal input.";
    }
}
