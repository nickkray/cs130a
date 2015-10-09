#include "Wallpost.h"
#include "Wall.h"
#include <string>

using namespace std;

string Wall::getUsername () const{
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

string Wall::printAllPosts () const{
    
}

WallPost Wall::createWallFromString(){
    
}