#include <iostream>

#include <string>
#include <sstream>
#include <algorithm>

#include "WallPost.h"
#include "Wall.h"

#include "User.h"

#include "UserNetwork.h"

#include "helpers.h"
#include <time.h>
#include <cstdlib>
#include <cstdio>


using namespace std;

void createUser(UserNetwork &network);
void login(UserNetwork &network);
void loggedIn(UserNetwork &network, string username);
void mainMenu(UserNetwork &network);
void printLogo();
void printLine();



linkedlist<string> split(string s, string delimiter);

int main(int argc, const char * argv[]) {
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
        
        cout<< "Pending friend requests: \n " << thisUser->getFriendRequests()<<endl;
        
        cout<<"\nWhat would you like to do?"<<endl;

        cout<<"1. Display Wall"<<endl;
        cout<<"2. Add new post"<<endl;
        cout<<"3. Delete new post"<<endl;
        cout<<"4. Search for a user"<<endl;
        cout<<"5. Accept a friend request"<<endl;
        cout<<"6. See friends list"<<endl;
        cout<<"7. Save and Logout"<<endl;
        cout<<"8. Delete your account"<<endl;
        cout<<"9. Post on a friend's wall\n"<<endl;
        cout<<"10. Delete a post on a friend's wall"<<endl;
        cout<<"11. Post responses to a post on your wall"<<endl;
        cout<<"12. Post responses to a post on a friend's wall"<<endl;
        cout<<"13. View a friend's wall\n"<<endl;
        cout<<"14. Degree of separation between you and who?\n"<<endl;
        
    
        int index = takeIntInput("Enter a choice");
        
        if (index == 14){
            string f= takeStringInput("Enter the name of a friend", 1);
            if(network.findUser(f)!=nullptr){
                auto it = std::find(thisUser->getFriends()->begin(), thisUser->getFriends()->end(), f);
                if(it!=thisUser->getFriends()->end()){
                    cout << 2;
                }else{
                    cout << 4;
                }
            }else{
                cout<<"User does not exist.";
            }
            
        }else
        if(index == 13){

            string f= takeStringInput("Enter the name of a friend", 1);
            if(network.findUser(f)!=nullptr){
                auto it = std::find(thisUser->getFriends()->begin(), thisUser->getFriends()->end(), f);
                if(it!=thisUser->getFriends()->end()){
                    cout<<network.findUser(f)->printUserWall();
                }else{
                    cout <<"You are not friends with this user. You should add them first.";
                }
            }else{
                cout<<"User does not exist.";
            }

            
        }else
        if (index == 12){
            
            
            string f= takeStringInput("Enter the name of a friend", 1);
            if(network.findUser(f)!=nullptr){
                auto it = std::find(thisUser->getFriends()->begin(), thisUser->getFriends()->end(), f);
                if(it!=thisUser->getFriends()->end()){
                    cout<<network.findUser(f)->printUserWall();
                    int index = takeIntInput("Respond to which post?");
                    string postText;
                    int mood=-1;
                    postText = takeStringInput("Enter your post(max 256 char): ", 256);
                    mood = takeIntInput("Enter your mood(0-10)");
                    network.findUser(f)->addWallPostResponse(thisUser->getUsername(), postText, mood,index);
                    cout << "Posted!";
                }else{
                    cout <<"You are not friends with this user. You should add them first.";
                }
            }else{
                cout<<"User does not exist.";
            }

        }else
        if (index == 11){
            int index = takeIntInput("Respond to which post?");
            string postText;
            int mood=-1;
            postText = takeStringInput("Enter your post(max 256 char): ", 256);
            mood = takeIntInput("Enter your mood(0-10)");
            thisUser->addWallPostResponse(thisUser->getUsername(), postText, mood,index);
            cout<<"Post added, breh!"<<endl;
        }else if(index ==10){
            string f= takeStringInput("Enter the name of a friend", 1);
            if(network.findUser(f)!=nullptr){
                auto it = std::find(thisUser->getFriends()->begin(), thisUser->getFriends()->end(), f);
                if(it!=thisUser->getFriends()->end()){
                    cout<<network.findUser(*it)->printUserWallFromAuthor(thisUser->getUsername());
                    int i = takeIntInput("Which post would you like to delete:");
                    if(network.findUser(*it)->deleteFriendsWallPost(i, f)){
                        cout<<"Post deleted successfully!"<<endl;
                    }else{
                        cout<<"Invalid index."<<endl;
                    }
                }else{
                    cout <<"You are not friends with this user. You should add them first.";
                }
            }else{
                cout<<"User does not exist.";
            }
        }else if(index == 9){
            string f= takeStringInput("Enter the name of a friend", 1);
            if(network.findUser(f)!=nullptr){
                auto it = std::find(thisUser->getFriends()->begin(), thisUser->getFriends()->end(), f);
                if(it!=thisUser->getFriends()->end()){
                    string postText;
                    int mood=-1;
                    postText = takeStringInput("Enter your post(max 256 char): ", 256);
                    mood = takeIntInput("Enter your mood(0-10)");
                    network.findUser(f)->addWallPost(thisUser->getUsername(), postText, mood);
                    cout << "Posted!";
                }else{
                    cout <<"You are not friends with this user. You should add them first.";
                }
            }else{
                cout<<"User does not exist.";
            }
        }else
        if(index ==8){
            string q= takeStringInput("Are you sure? (y/N)", 1);
            if(q=="y"){
                network.removeUser(thisUser->getUsername());
                network.writeToFile("network.data");
                cout << "Delete successful. Goodbye!"<<endl;
                break;
            }
        }
        
        if(index==7){
            network.writeToFile("network.data");
            cout << "Save successful. Goodbye!"<<endl;
            break;
        }else if(index==6){
            cout<< "Friends:\n"<<network.printFriends(thisUser)<<endl;
        }else if(index==5){
            string q = takeStringInput("Type the name of the friend request you'd like to accept: ", 256);
            if(thisUser->existsFriendRequest(q)){
                thisUser->addFriend(q);
                thisUser->deleteFriendRequest(q);
                network.findUser(q)->addFriend(q);
                cout <<"Success!";
            }else{
                cout<< "This user has not added you as a friend.";
            }
            thisUser->getFriends();
        }else if(index==4){
            string q = takeStringInput("Enter your search query (name of user): ", 256);
            list<string> matches = network.findUserByQuery(q);
            int i=0;
            for(auto it = matches.begin(); it!=matches.end();it++){
                cout<< i << ") "<<*it<<endl;
                i++;
            }
            int q2 = takeIntInput("To add user as friend, enter corresponding number. Otherwise, enter -1: ");
            if(q2==-1)
                continue;
            i=0;
            string thisUsername;
            for(auto it = matches.begin(); it!=matches.end();it++){
                if(i==q2){
                    thisUsername = *it;
                }
                i++;
            }
            network.createFriendRequest(thisUser, network.findUser(thisUsername));
            cout << "Friend request sent!"<<endl;
        }else if(index==1){
            printLine();
            cout<<thisUser->printUserWall();
        }else if(index==2){
            string postText;
            int mood=-1;
            postText = takeStringInput("Enter your post(max 256 char): ", 256);
            mood = takeIntInput("Enter your mood(0-10)");
            thisUser->addWallPost(thisUser->getUsername(), postText, mood);
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


