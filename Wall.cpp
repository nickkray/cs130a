#include "Wall.h"
#include "WallPost.h"
#include "linkedlist.h"
#include <string>
using namespace std;

string Wall::getUsername() const{
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

string Wall::printAllPosts() const{
    WallPost *ourPosts=posts.returnEverything();
    string postString;
    for(int i=0;i<sizeof(ourPosts)/sizeof(*ourPosts);i++){
        postString=postString+"\n"+ourPosts[i].printPost();
    }
    return postString;
}

void Wall::createWallFromString(string wallString){
    
}


Wall::Wall(){
    
};

Wall::~Wall(){
    
}

/*
 "WallPost::WallPost()", referenced from:
 linkedlist<WallPost>::node::node() in Wall.o
*/