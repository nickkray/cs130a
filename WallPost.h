#ifndef ____WallPost__
#define ____WallPost__

#include <string>
#include <sstream>

using namespace std;

class WallPost{
    private:
        string text;
        time_t timestamp;
        int mood;
    public:
                //const/deconst.
        WallPost();
        ~WallPost();
                //getters
        string getText();
        time_t getTime();
        int getMood();
                //setters
        setText(string newText);
        setTime(time_t newTime);
        setMood(int newMood);
                //print our post
        string printPost();
};

#endif
