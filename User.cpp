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
            friends.push_back(a.c_str());
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

void User::addWallPost(string author, string text){
    userWall.addPost(WallPost(author, text));
}

void User::addWallPost(string author, string text, int mood){
    userWall.addPost(WallPost(author, text,mood, author));
}

void User::addWallPostResponse(string author, string text, int mood, int i){
    userWall.addPostResponse(WallPost(author, "  |____"+text,mood, author),i);
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
    int j=0;
    for(auto i = friends.begin();i!=friends.end();i++){
        friendsString+=*i;
        if(j<friends.size()-1){
            friendsString+=";";
        }
        j++;
        // we removed the checking if second to last for the , thing uhhhh
    }
    return ""+username+">>"+password+">>"+name+">>"+gender+">>"+friendsString+"}";
}

void User::addFriend(string userIndex){
    friends.push_back(userIndex);
}

string User::getFriendRequests(){
    string requests="";
    for(auto it = friendRequests.begin();it!=friendRequests.end();++it){
        requests+=*it+"\n";
    }
    return requests;
}

bool User::existsFriendRequest(string username){
    for(auto it = friendRequests.begin();it!=friendRequests.end();++it){
        if(*it == username){
            return true;
        }
    }
    return false;
}

void User::deleteFriendRequest(string username){
    friendRequests.remove(username);
}

void User::addFriendRequest(string username){
    friendRequests.push_back(username);
}

string User::printUserWallFromAuthor(string author){
        return userWall.printAllPostsFromAuthor(author);
}

bool User::deleteFriendsWallPost(int i, string author){
    return userWall.removeFriendsPost(i, author);
}