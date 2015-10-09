#ifndef ____UserNetwork__
#define ____UserNetwork__

#include "UserNetwork.cpp"

class UserNetwork{
    private:
        linkedlist<User> userList;
    public:
        UserNetwork();
        ~UserNetwork();
    
        void addUser(User newUser);
        void removeUser(string userName); //remove by username

        string printUsers () const;
        linkedlist<User> readUsers () const;
};


#endif
