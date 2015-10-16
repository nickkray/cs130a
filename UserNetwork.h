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
        ~UserNetwork();
    
        void addUser(string newUsername, string newPass, string newName, string newGen);
        void removeUser(string userName); //remove by username
        User* findUser(string userName);//return a copy of the user

        string printUsers() const;
        linkedlist<User> readUsers() const;
    
};


#endif
