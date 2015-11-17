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
    auto it = posts.begin();
    posts.insert(it,newPost);
}

bool Wall::removePost(int index){
    if(index>=posts.size())
        return false;
    auto it = posts.begin();
    for(int i=0;i<index;i++){
        ++it;
    }
    posts.erase(it);
    return true;
}

string Wall::printAllPosts() const{
    if(posts.size()==0){
        return "Nothing here yet, post something!";
    }
    string postString;
    int i=0;
    for(auto it = posts.begin();it!=posts.end();++it){
        postString+=to_string(i)+") "+it->printPost()+"\n";
        i++;
    }
    return postString;
}

string Wall::serializePosts() const{
    string postString="{";
    int i=0;
    for(auto it = posts.begin();it!=posts.end();++it){
        i++;
        WallPost currentPost=*it;
        postString+=currentPost.printPostData();
        if(i<posts.size()-1){
            postString+="||";
        }
    }
    return postString;
}

void Wall::createWallFromString(string wallData){
    linkedlist<string> wall=split(wallData,"||");
    for(int j=0;j<wall.countNodes();j++){
        linkedlist<string> post=split(*wall.findAt(j),">>");
        int mood=atoi((*post.findAt(3)).c_str());
        string author=*post.findAt(0);
        string postText=*post.findAt(1);
        string timestamp = *post.findAt(2);
        addPost(WallPost(author,postText,mood,timestamp));
    }
}

string Wall::printAllPostsFromAuthor(string author){
    if(posts.size()==0){
        return "Nothing here yet, post something!";
    }
    string postString;
    int i=0;
    for(auto it = posts.begin();it!=posts.end();++it){
        if(it->getAuthor() == author){
            postString+=to_string(i)+") "+it->printPost()+"\n";
            i++;
        }
    }
    return postString;
}


Wall::Wall(){
    
};

Wall::~Wall(){
    
}

bool Wall::removeFriendsPost(int j, string author){
    if(posts.size()==0){
        return false;
    }
    string postString;
    int i=0,realIndex=0;
    for(auto it = posts.begin();it!=posts.end();++it){
        if(i==j){
            return removePost(realIndex);
        }
        if(it->getAuthor() == author){
            i++;
        }
        realIndex++;
    }
    return false;
}

void Wall::addPostResponse(WallPost newPost, int index){
    
    auto it = posts.begin();
    for(int i=0;i<index;i++){
        it++;
    }
    it->responses++;
    for(int i=0;i<it->responses-1;i++){
        it++;
    }
    newPost.isResponse=true;
    posts.insert(it,newPost);
}