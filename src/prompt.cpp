#include <iostream>
#include <string>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "prompt.h"

using namespace std;

void Prompt::setPrompt(const string & prompt) {
    this->prompt = prompt;
}

string Prompt::read() {
    char * r = readline(this->prompt.c_str());
    
    add_history(r);

    string response = r;

    free(r);

    return response;
}
