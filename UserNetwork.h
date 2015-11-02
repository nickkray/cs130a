#ifndef ____UserNetwork__
#define ____UserNetwork__
#include "linkedlist.h"
#include "User.h"

class UserNetwork{
    private:
        linkedlist<User> userList;
        linkedlist<string> usernames;
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
    
        arrList<string> findUserByQuery(string partial);
    
        int findUserIndex(string userName);
    
        string printPendingRequests(User* thisUser);
        string printFriends(User* thisUser);
};


#endif