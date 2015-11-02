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
    arrList<int> friends;
	
public:
    
     User(string newUsername, string newPass, string newName, string newGen);
     User(string s); // properly formatted string
    ~User();
    
     string getUsername () const;
     string getPassword () const;
     string getName () const;
     string getGender () const;
    
     arrList<int> * getFriends(){
         return & friends;
     }
	
     void setName(string newName);
     void setgender(string newGender);
     void setPassword(string newPass);
	
     void addWallPost(string text);
     void addWallPost(string text, int mood);
     bool deleteWallPost(int i);
    
     string printUserWall () const;
     void readUserWall(string userWall);
    
     string serializeUser() const;
    
     int countPosts();
    
     string serializeWall() const;
     void createWallFromString(string userData);
    
     void addFriend(int userIndex);
};

#endif
