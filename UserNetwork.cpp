/*
#ifndef ____UserNetwork__
#define ____UserNetwork__

class UserNetwork{
private:
    linkedlist<User> userList;
public:
    UserNetwork();
    ~UserNetwork();
    
    void addUser(User newUser);
    void removeUser(string userName); //remove by username

    string printUsers const();
	linkedlist<User> readUsers const();
   };


#endif
*/

UserNetwork::UserNetwork(){
	userList = new linkedlist<User>();
}

UserNetwork::~UserNetwork(){
	delete userList;
}

void UserNetwork::addUser(User newUser){
	
}

void UserNetwork::removeUser(string userName){
	
}

string UserNetwork::printUsers const(){
	
}

linkedlist<User> UserNetwork::readUsers const(){

}


