#include <string>
#include <vector>
#include <deque>

#include "token.h"

using namespace std;

#ifndef __INCL_EXPRESSION
#define __INCL_EXPRESSION

class Expression {
    private:
        string expression;

        deque<Token *> getRPNQueue(vector<Token *> & tokens);

    public:
        Expression(const string & expression) {
            this->expression = expression;
        }

        string evaluate(long precision);
};

#endif
