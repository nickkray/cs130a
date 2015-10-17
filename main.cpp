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
void mainMenu(UserNetwork &network);
void printLogo();
void printLine();
void writeStringToFile(string filename, string input);
string readFromFile(string filename);

linkedlist<string> split(string s, string delimiter);

int main(int argc, const char * argv[]) {
    
    UserNetwork network = UserNetwork("network.data");
    
    /*
     testing***********************
     */
    /*
    network1.addUser("boris", "pass", "boris", "m");
    network1.findUser("boris")->addWallPost("test post", 1);
    network1.findUser("boris")->addWallPost("test post3", 5);
    network1.findUser("boris")->addWallPost("test pos235235t", 2);
    network1.findUser("boris")->addWallPost("t235235est post", 9);
    network1.findUser("boris")->addWallPost("no mood post");
    network1.findUser("boris")->addWallPost("no mood post2");
    
    network1.addUser("nick", "pass", "nick", "m");
    network1.findUser("nick")->addWallPost("t4est post", 1);
    network1.findUser("nick")->addWallPost("te3st post3", 5);
    network1.findUser("nick")->addWallPost("te1st pos235235t", 2);
    network1.findUser("nick")->addWallPost("t235235est 343post", 9);
    network1.findUser("nick")->addWallPost("no 34moo3d post");
    network1.findUser("nick")->addWallPost("n2o m4ood 3po4st2");
    
    network1.writeToFile("network.data");
    
    UserNetwork network = UserNetwork("network.data");
    */
//    UserNetwork network
    
    //**********************
    
    mainMenu(network);
    return 0;
}

void printLogo(){
   cout <<"***********************************************************************************************************\n";
    cout <<"     _______  _______  __   __  _______  __   __  _______  _______  _______  _______  ___   _ \n    |       ||   _   ||  | |  ||       ||  | |  ||       ||  _    ||       ||       ||   | | |\n    |    ___||  |_|  ||  | |  ||       ||  |_|  ||   _   || |_|   ||   _   ||   _   ||   |_| |\n    |   | __ |       ||  |_|  ||       ||       ||  | |  ||       ||  | |  ||  | |  ||      _|\n    |   ||  ||       ||       ||      _||       ||  |_|  ||  _   | |  |_|  ||  |_|  ||     |_ \n    |   |_| ||   _   ||       ||     |_ |   _   ||       || |_|   ||       ||       ||    _  |\n    |_______||__| |__||_______||_______||__| |__||_______||_______||_______||_______||___| |_|\n";
    cout <<"***********************************************************************************************************";

}

void mainMenu(UserNetwork &network){
    printLogo();
    while(true){
        
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
    }
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
    cout<<"Gender?";
    cin>>gender;
    
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
    
    cout <<"\nUsername:";
    cin>>username;
    cout<<"Password:";
    cin>>password;
    
    User* thisUser = network.findUser(username);
    
    if(thisUser->getUsername()!=""){
        if(thisUser->getPassword()==password){
            printLine();
            cout<<"What's good "+thisUser->getName()+"!!"<<endl; //we authenticated correctly!
            loggedIn(network, username);
        }else{
            cout<<"fuck..pw mismatch"; //password mismatch
        }
    }else{
        cout<<"fuck..user mismatch"; // //username mismatch
    }
    printLine();
}

void printLine(){
    cout<<"\n\n---------------------------------------------------------------------------------------------------\n"<<endl;
}

void loggedIn(UserNetwork &network, string username){
    
    User* thisUser = network.findUser(username);
    
    while(true){
        
        cout<<"\nWhat would you like to do?"<<endl;
        cout<<"1. Display Wall"<<endl;
        cout<<"2. Add new post"<<endl;
        cout<<"3. Delete new post"<<endl;
        cout<<"4. Save and Logout\n"<<endl;
    
        string index;
        cin>>index;
        if(index=="4"){
            network.writeToFile("network.data");
            cout << "Save successful. Goodbye!"<<endl;
            break;
        }else if(index=="1"){
            printLine();
            cout<<thisUser->printUserWall();
        }else if(index=="2"){
            string postText;
            int mood=-1;
            cout<<"Enter your post:"<<endl;
            cin>>postText;
            cout<<"How are you feeling (0-10):"<<endl;
            cin>>mood;
            if(mood!=-1){
                thisUser->addWallPost(postText);
            }else{
                thisUser->addWallPost(postText, mood);
            }
            cout<<"Post added, breh!"<<endl;
        }else if(index=="3"){
            printLine();
            int i;
            cout<<thisUser->printUserWall();
            if(thisUser->countPosts()>0){
                cout<<"Which post would you like to delete:";
                cin>>i;
                if(thisUser->deleteWallPost(i)){
                    cout<<"Post deleted successfully!"<<endl;
                }else{
                    cout<<"Invalid index."<<endl;
                }
            }
        }else{
            cout<<"Illegal input. Press enter to continue."<<endl;
            cin.ignore();
        }

    }
}


