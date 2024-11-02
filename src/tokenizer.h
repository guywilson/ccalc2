#include <string>
#include <vector>
#include <string.h>
#include <stdint.h>

#include "token.h"

using namespace std;

#ifndef __INCL_TOKENIZER
#define __INCL_TOKENIZER

class Tokenizer {
    private:
        uint32_t startIndex;
        uint32_t endIndex;

        string expression;
        
        int findNextTokenPos();
        int getTokenLength();

    public:
        vector<Token> tokens;

        Tokenizer(const string & expression);
};

#endif
