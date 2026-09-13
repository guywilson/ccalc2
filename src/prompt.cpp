#include <iostream>
#include <string>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "prompt.h"

void Prompt::setPrompt(const std::string & prompt) {
    this->prompt = prompt;
}

std::string Prompt::read() {
    char * r = readline(this->prompt.c_str());
    
    add_history(r);

    std::string response = r;

    free(r);

    return response;
}
