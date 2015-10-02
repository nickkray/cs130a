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


Wall::getUsername(){
    return username;
}

Wall::setUsername(string newUsername){
    username=newUsername;
}

Wall::addPost(WallPost newPost){
    posts.add(newPost);
}

Wall::removePost(int index){
    if(index==NULL){
        index=-1;
    }
    posts.removeAt(index);
}

string Wall::printAllPosts(){
    
}

createWallFromString(){
    
}

