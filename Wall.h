#ifndef ____Wall__
#define ____Wall__

#include <string>
#include "linkedlist.h"
#include "WallPost.h"
#include <list>

class Wall{
private:
    //linkedlist<WallPost> posts;
    list<WallPost> posts;
    string username;
public:
    Wall();
    ~Wall();
    
    void addPost(WallPost newPost);
    bool removePost(int index); //remove by index. without index, remove last

    string getUsername () const;
    void setUsername(string newUsername);
    
    string printAllPosts () const;
    
    void createWallFromString(string wallData);
    
    string serializePosts() const;
    
    int countPosts(){
        return posts.size();
    };
    
    string printAllPostsFromAuthor(string author);
    
    bool removeFriendsPost(int i, string author);
    
    void addPostResponse(WallPost newPost, int index);
};

#endif