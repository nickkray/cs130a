#include "helpers.h"
#include <iostream>
#include <fstream>
#include <string>



void printLine(){
    cout << endl;
    cout <<"---------------------------------------------------------------------------------------------------"<<endl;
}

string takeStringInput(string prompt, int maxLen){
    cout<<prompt<<endl;
    string input;
    while(true){
        if(cin>>input && input.length()>0 && input!="\n"){
            return input;
        }else{
            cout<<"Please enter valid input.";
            cin.clear();
            cin.ignore(maxLen, '\n');
        }
    }
}

int takeIntInput(string prompt){
    cout<<prompt<<endl;
    int choice;
    while(true){
        if(cin>>choice){
            return choice;
        }else{
            cout<<"Please enter a valid choice:";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}


linkedlist<string> split(string s, string delimiter){ // "hey whats up" " ", ["hey","whats","up"]
    size_t pos = 0;
    linkedlist<string> tokens;
    string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        tokens.add(token);
        s.erase(0, pos + delimiter.length());
    }
    tokens.add(s);
    return tokens;
}

void writeStringToFile(string filename, string input){
    ofstream out(filename.c_str());
    out << input;
    out.close();
}

string readFromFile(string filename){
    std::ifstream t(filename.c_str());
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}
