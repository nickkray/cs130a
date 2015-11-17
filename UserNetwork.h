#ifndef ____UserNetwork__
#define ____UserNetwork__

#include "User.h"

class UserNetwork{
    private:
        list<User> userList;
        list<string> usernames;
    public:
        UserNetwork();
        UserNetwork(string s);
        ~UserNetwork();
    
        void addUser(string newUsername, string newPass, string newName, string newGen);
        void addUser(string newUsername, string newPass, string newName);
        void addUserFromString(string s);
        void removeUser(string userName); //remove by username
        User* findUser(string userName);//return a copy of the user
    
        string serializeUserByUsername(string username);
        string serializeAllUsers();
    
        void writeToFile(string filename);
    
        list<string> findUserByQuery(string partial);
    
        int findUserIndex(string userName);
        string printFriends(User* thisUser);
    
        void createFriendRequest(User* from, User* to);
};


#endif