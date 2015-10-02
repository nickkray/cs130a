#ifndef ____Wall__
#define ____Wall__


class Wall{
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

#endif
