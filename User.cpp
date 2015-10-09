#include "User.h"


#include <string>
#include <sstream>

/*
class User{
private:
    Wall userWall;
    string username;
	string password;
	string name;
	string gender;
	
public:
	User(string newName, string newPass, string newName, string newGen);
	User(string newName, string newPass, string newName); //chillin on gender
    ~User();
    
	string getUsername cosnt();
	string getPassword () const;
	string getName () const;
	string getGender () const;
	
	void setPassword(string newPass);
	void setName(string newName);
	void setgender(string newGender);
	
	void addWallPost(string text);
	void addWallPost(string text, int mood);
	void deleteWallPost();
	
	string printUserWall () const;
	void readUserWall(string userWall);
	
};
*/

User::User(string newUsername, string newPass, string newName, string newGen){
	userWall = new Wall(newName);
	username = newUsername;
	password = newPass;
	name = newName;
	gender =  newGen;
}

User::User(string newUsername, string newPass, string newName){
	userWall = new Wall;
	username = newUsername;
	password = newPass;
	name = newName;
	gender =  "chillin";
}

User::~User(){
	delete userWall;
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

void setPassword(string newPass){
	password = newPass;
}

void setName(string newName){
	name = newName;
}

void setgender(string newGender){
	gender = newGender;
}

void User::addWallPost(string text){
}

void User::addWallPost(string text, int mood){
}

void User::deleteWallPost(){
}

string User::printUserWall () const{
}

void User::readUserWall(string userWall){
}
