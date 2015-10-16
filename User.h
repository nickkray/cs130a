#ifndef ____User_h
#define ____User_h

#include <string>
#include "Wall.h"
using namespace std;

class User{
private:
    Wall userWall;
    string username;
    string password;
    string name;
    string gender;
	
public:
     User(string newUsername, string newPass, string newName, string newGen);
     User(string newUsername, string newPass, string newName); //chillin on gender
    ~User();
    
     string getUsername () const;
     string getPassword () const;
     string getName () const;
     string getGender () const;
	
     void setName(string newName);
     void setgender(string newGender);
     void setPassword(string newPass);
	
     void addWallPost(string text);
     void addWallPost(string text, int mood);
     bool deleteWallPost(int i);
    
     string printUserWall () const;
     void readUserWall(string userWall);
    
     int User::countPosts();
};

#endif
