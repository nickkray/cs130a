#ifndef ____Wall__
#define ____Wall__


class Wall{
private:
    linkedlist<WallPost> posts;
    string username;
public:
    WallPost();
    ~WallPost();
    
    void addPost(WallPost newPost);
    void removePost(int index); //remove by index. without index, remove last

    string getUsername const();
    void setUsername(string newUsername);
    
    string printAllPosts const();
    
    WallPost createWallFromString();
};

#endif
