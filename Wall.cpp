#include "Wall.h"
/*

 class WallPost{
 private:
 linkedlist<WallPost> posts;
 string username;
 public:
 WallPost();
 ~WallPost();
 
 addPost(WallPost newPost);
 removePost(int index); //remove by index. without index, remove last
 
 string getUsername();
 setUsername(string newUsername);
 
 string printAllPosts();
 
 createWallFromString();
 };

*/


string Wall::getUsername const(){
    return username;
}

void Wall::setUsername(string newUsername){
    username=newUsername;
}

void Wall::addPost(WallPost newPost){
    posts.add(newPost);
}

void Wall::removePost(int index){
    if(index==NULL){
        index=-1;
    }
    posts.removeAt(index);
}

string Wall::printAllPosts const(){
    
}

WallPost createWallFromString(){
    
}

