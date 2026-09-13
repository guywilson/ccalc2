#include <iostream>
#include <string>

class Prompt {
    private:
        std::string prompt;
        
    public:
        Prompt() {}

        void setPrompt(const std::string & prompt);
        std::string read();
};
