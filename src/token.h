#include <string>

using namespace std;

#ifndef __INCL_TOKEN
#define __INCL_TOKEN

class Token {
    private:
        string token;

    public:
        Token(const string & token) {
            this->token = token;
        }

        virtual ~Token() {}
        
        virtual string evaluate() {
            return this->token;
        }
};

#endif
