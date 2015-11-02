#include "Wall.h"
#include "WallPost.h"
#include "linkedlist.h"
#include <string>
#include "helpers.h"

using namespace std;

string Wall::getUsername() const{
    return username;
}

void Wall::setUsername(string newUsername){
    username=newUsername;
}

void Wall::addPost(WallPost newPost){
    posts.insert(1,newPost);
}

bool Wall::removePost(int index){
    return posts.remove(index);
}

string Wall::printAllPosts() const{
    if(posts.count()==0){
        return "Nothing here yet, post something!";
    }
    string postString;
    for(int i=0;i<posts.count()-1;i++){
        postString+=to_string(i)+") "+posts.get(i)->printPost()+"\n";
    }
    return postString;
}

string Wall::serializePosts() const{
    string postString="{";
    for(int i=0;i<posts.count();i++){
        WallPost* currentPost=posts.get(i);
        postString+=currentPost->printPostData();
        if(i<posts.count()-1){
            postString+="||";
        }
    }
    return postString;
}

void Wall::createWallFromString(string wallData){
    linkedlist<string> wall=split(wallData,"||");
    for(int j=0;j<wall.countNodes();j++){
        linkedlist<string> post=split(*wall.findAt(j),">>");
        int mood=atoi((*post.findAt(2)).c_str());
        string postText=*post.findAt(0);
        string timestamp = *post.findAt(1);
        addPost(WallPost(postText,mood,timestamp));
    }
}


Wall::Wall(){
    
};

Wall::~Wall(){
    
}