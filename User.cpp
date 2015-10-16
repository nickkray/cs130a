#include "User.h"
#include "Wall.h"

User::User(string newUsername, string newPass, string newName, string newGen){
    userWall = Wall();
	username = newUsername;
	password = newPass;
	name = newName;
	gender =  newGen;
}

User::User(string newUsername, string newPass, string newName){
	userWall = Wall();
	username = newUsername;
	password = newPass;
	name = newName;
	gender =  "chillin";
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

void User::readUserWall(string userWall){
}

int User::countPosts(){
    return userWall.countPosts();
}
