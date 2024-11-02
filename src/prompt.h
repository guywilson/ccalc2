#include <iostream>
#include <string>

using namespace std;

class Prompt {
    private:
        string prompt;
        
    public:
        Prompt() {}

        void setPrompt(const string & prompt);
        string read();
};
