#ifndef ____WallPost__
#define ____WallPost__

#include <string>

using namespace std;

class WallPost{
    private:
        string text;
        time_t timestamp;
        int mood;
    public:
                //const/deconst.
        WallPost();
        WallPost(string newText, int newMood);
        WallPost(string newText);
        ~WallPost();
                //getters
        string getText() const;
        time_t getTime() const;
        int getMood() const;
                //setters
        void setText(string newText);
        void setTime(time_t newTime);
        void setMood(int newMood);
                //print our post
        string printPost() const;
        string printPostData() const;
};

#endif
