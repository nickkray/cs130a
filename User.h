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
    list<string> friends;
    list<string> friendRequests;
	
public:
    
     User(string newUsername, string newPass, string newName, string newGen);
     User(string s); // properly formatted string
    ~User();
    
     string getUsername () const;
     string getPassword () const;
     string getName () const;
     string getGender () const;
    
     list<string> * getFriends(){
         return & friends;
     }
	
     void setName(string newName);
     void setgender(string newGender);
     void setPassword(string newPass);
	
     void addWallPost(string author, string text);
     void addWallPost(string author, string text, int mood);
     bool deleteWallPost(int i);
    
     string printUserWall () const;
     void readUserWall(string userWall);
    
     string serializeUser() const;
    
     int countPosts();
    
     string serializeWall() const;
     void createWallFromString(string userData);
    
     void addFriend(string userIndex);

     string getFriendRequests();
     void addFriendRequest(string username);
    
     bool existsFriendRequest(string username);
    
     void deleteFriendRequest(string username);
    
     string printUserWallFromAuthor(string author);
    
    bool deleteFriendsWallPost(int i, string author);
    
    void addWallPostResponse(string author, string text, int mood, int i);
};
/*
bool operator==(const User& lhs, const User& rhs){
    if(lhs==rhs){
        return true;
    }
    return false;
}*/

#endif
