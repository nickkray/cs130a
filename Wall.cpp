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

bool Wall::removePost(int index){
    return posts.removeAt(index);
}

string Wall::printAllPosts() const{
    if(posts.countNodes()==0){
        return "Nothing here yet, post something!";
    }
    string postString;
    for(int i=0;i<posts.countNodes();i++){
        postString+=to_string(i)+") "+posts.findAt(i)->printPost()+"\n";
    }
    return postString;
}

string Wall::serializePosts() const{
    string postString="{";
    for(int i=0;i<posts.countNodes();i++){
        WallPost* currentPost=posts.findAt(i);
        postString+=currentPost->printPostData();
        if(i<posts.countNodes()-1){
            postString+="||";
        }
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