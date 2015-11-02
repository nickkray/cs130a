#include "User.h"
#include "Wall.h"
#include "helpers.h"

User::User(string newUsername, string newPass, string newName, string newGen){
    userWall = Wall();
	username = newUsername;
	password = newPass;
	name = newName;
	gender =  newGen;
}

User::User(string s){
    linkedlist<string> u=split(s,">>");
    
    userWall = Wall();
    username = *u.findAt(0);
    password = *u.findAt(1);
    name = *u.findAt(2);
    gender = *u.findAt(3);
    string t = *u.findAt(4);
    if(t.size()>0){
        linkedlist<string> tmpFriends = split(t,";");
        for(int i=0;i<tmpFriends.countNodes();i++){
            string a = *tmpFriends.findAt(i);
            friends.insert(1, atoi(a.c_str()) );
        }
    }
}

User::~User(){
    userWall.~Wall();
}

string User::getUsername () const{
	return username;
}

string User::getPassword () const{
	return password;
}

string User::getName () const{
	return name;
}

string User::getGender () const{
	return gender;
}

void User::setPassword(string newPass){
	password = newPass;
}

void User::setName(string newName){
	name = newName;
}

void User::setgender(string newGender){
	gender = newGender;
}

void User::addWallPost(string text){
    userWall.addPost(WallPost(text));
}

void User::addWallPost(string text, int mood){
    userWall.addPost(WallPost(text,mood));
}

bool User::deleteWallPost(int i){
    return userWall.removePost(i);
}

string User::printUserWall() const{
    return userWall.printAllPosts();
};

void User::createWallFromString(string userData){
    userWall.createWallFromString(userData);
}

int User::countPosts(){
    return userWall.countPosts();
}

string User::serializeWall() const{
    return userWall.serializePosts();
}

string User::serializeUser() const{
    string friendsString="";
    for(int i=0;i<friends.count();i++){
        friendsString+=*friends.get(i);
        if(i<friends.count()-1){
            friendsString+=";";
        }
    }
    return ""+username+">>"+password+">>"+name+">>"+gender+">>"+friendsString+"}";
}

void User::addFriend(int userIndex){
    friends.insert(1, userIndex);
}