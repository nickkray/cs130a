#ifndef ____User__
#define ____User__


class User{
private:
    Wall userWall;
    string username;
    string password;
    string name;
    string gender;
	
public:
     User(string newName, string newPass, string newName, string newGen);
     User(string newName, string newPass, string newName); //chillin on gender
    ~User();
    
     string getUsername cosnt();
     string getPassword const();
     string getName const();
     string getGender const();
	
     void setName(string newName);
     void setgender(string newGender);
	
     void addWallPost(string text);
     void addWallPost(string text, int mood);
     void deleteWallPost();
     
     string printUserWall const();
     void readUserWall(string userWall);
};

#endif
