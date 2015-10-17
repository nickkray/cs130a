#ifndef __cs130a__helpers__
#define __cs130a__helpers__

#include <string>
#include <sstream>

#include <limits>
#include "linkedlist.h"

using namespace std;

void writeStringToFile(string filename, string input);
string readFromFile(string filename);
string takeStringInput(string prompt, int maxLen);
int takeIntInput(string prompt);
linkedlist<string> split(string s, string delimiter);


#endif