#include <iostream>

#include <string>
#include <sstream>

#include "linkedlist.h"

#include "WallPost.h"
#include "Wall.h"

#include "User.h"

#include "UserNetwork.h"

#include "helpers.h"
#include <time.h>
#include <cstdlib>
#include <cstdio>

#include "list.h"

using namespace std;

void createUser(UserNetwork &network);
void login(UserNetwork &network);
void loggedIn(UserNetwork &network, string username);
void mainMenu(UserNetwork &network);
void printLogo();
void printLine();



linkedlist<string> split(string s, string delimiter);

int main(int argc, const char * argv[]) {
    /*
    arrList<int> aa;
    cout<<aa.count()<<endl;
    int i;
    for(i=0;i<100;i++){
        aa.insert(1,i);//cannot be 0
    }
    cout << "our count:"<<aa.count()<<endl;
    for(i=0;i<100;i++){
        cout<<aa.get(i)<<endl;
    }
    
    cout<<aa.count();
    */
    UserNetwork network = UserNetwork("network.data");
    mainMenu(network);
    return 0;
}

void printLogo(){
   cout <<"***********************************************************************************************************\n";
    cout <<"     _______  _______  __   __  _______  __   __  _______  _______  _______  _______  ___   _ \n    |       ||   _   ||  | |  ||       ||  | |  ||       ||  _    ||       ||       ||   | | |\n    |    ___||  |_|  ||  | |  ||       ||  |_|  ||   _   || |_|   ||   _   ||   _   ||   |_| |\n    |   | __ |       ||  |_|  ||       ||       ||  | |  ||       ||  | |  ||  | |  ||      _|\n    |   ||  ||       ||       ||      _||       ||  |_|  ||  _   | |  |_|  ||  |_|  ||     |_ \n    |   |_| ||   _   ||       ||     |_ |   _   ||       || |_|   ||       ||       ||    _  |\n    |_______||__| |__||_______||_______||__| |__||_______||_______||_______||_______||___| |_|\n\n";
    cout <<"***********************************************************************************************************\n";

}



void mainMenu(UserNetwork &network){
    printLogo();
    while(true){
            switch(takeIntInput("To create a new user, press 1. To login, press 2. To exit, press 0")){
            case 0:
                exit(0);
                break;
            case 1:
                //create
                createUser(network);
            break;
            case 2://login
                login(network);
            break;
            default:
                cout <<"What?"<<endl;
            break;
        }
    }
}

void createUser(UserNetwork &network){
    
    string username;
    string password;
    string gender;
    string name;
    
    name=takeStringInput("Enter your full name(20 char max):", 20);
    username=takeStringInput("Enter a username(10 char max):", 10);
    password=takeStringInput("Enter a password(10 char max):", 10);
    gender=takeStringInput("Enter your gender:", 1);
    
    if(username!="" && password!="" && name !="" && gender!=""){
        cout<<"Creating user...\n";

    
        if(network.findUser(username)==NULL){// check for duplicate
                network.addUser(username, password, name, gender);
            cout<<"User creation successful("+username+")!"<<endl;
        }else{
            cout<<"Duplicate username. Try again: "<<endl;
        }
        printLine();
    }else{
        cout << "Username, password, and name cannot be blank.";
    }
}

void login(UserNetwork &network){
    string username;
    string password;
    
    username=takeStringInput("Username:", 10);
    password=takeStringInput("Password:", 10);
    
    if(User* thisUser = network.findUser(username)){
        if(thisUser->getPassword()==password){
            printLine();
            cout<<"What's good "+thisUser->getName()+"!!"<<endl; //we authenticated correctly!
            loggedIn(network, username);
        }else{
            cout<<"Account creds invalid."; //password mismatch
        }
    }else{
        cout<<"Account creds invalid."; // //username mismatch
    }
    printLine();
}



void loggedIn(UserNetwork &network, string username){
    
    User* thisUser = network.findUser(username);
    
    while(true){
        
        cout<<"\nWhat would you like to do?"<<endl;
        cout<<"1. Display Wall"<<endl;
        cout<<"2. Add new post"<<endl;
        cout<<"3. Delete new post"<<endl;
        cout<<"4. Save and Logout\n"<<endl;
    
        int index = takeIntInput("Enter a choice");
        
        if(index==4){
            network.writeToFile("network.data");
            cout << "Save successful. Goodbye!"<<endl;
            break;
        }else if(index==1){
            printLine();
            cout<<thisUser->printUserWall();
        }else if(index==2){
            string postText;
            int mood=-1;
            postText = takeStringInput("Enter your post(max 256 char): ", 256);
            mood = takeIntInput("Enter your mood(0-10)");
            thisUser->addWallPost(postText, mood);
            cout<<"Post added, breh!"<<endl;
        }else if(index==3){
            printLine();
            int i;
            cout<<thisUser->printUserWall();
            if(thisUser->countPosts()>0){
                i = takeIntInput("Which post would you like to delete:");
                if(thisUser->deleteWallPost(i)){
                    cout<<"Post deleted successfully!"<<endl;
                }else{
                    cout<<"Invalid index."<<endl;
                }
            }
        }else{
            cout<<"Illegal input."<<endl;
        }
        printLine();
    }
}


