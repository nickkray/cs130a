#ifndef ____Wall__
#define ____Wall__

#include <string>
#include "linkedlist.h"
#include "WallPost.h"

class Wall{
private:
    linkedlist<WallPost> posts;
    string username;
public:
    Wall();
    ~Wall();
    
    void addPost(WallPost newPost);
    bool removePost(int index); //remove by index. without index, remove last

    string getUsername () const;
    void setUsername(string newUsername);
    
    string printAllPosts () const;
    
    void createWallFromString(string wallString);
    
    string serializePosts() const;
    
    int countPosts(){
        return posts.countNodes();
    };
};

#endif