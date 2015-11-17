#ifndef ____WallPost__
#define ____WallPost__

#include <string>
#include <list>

using namespace std;

class WallPost{
    private:
        string text;
        string timestamp;
        int mood;
        string author;
    
    public:
        bool isResponse = false;
        int responses = 0;
                //const/deconst.
        WallPost();
        WallPost(string author, string newText, int newMood, string newTimestamp);
        WallPost(string author, string newText, int newMood);
        WallPost(string author, string newText);
    
        ~WallPost();
                //getters
        string getText() const;
        string getTime() const;
        int getMood() const;
                //setters
        void setText(string newText);
        void setTime(time_t newTime);
        void setMood(int newMood);
                //print our post
        string printPost() const;
        string printPostData() const;
        string getAuthor() const;
};

#endif