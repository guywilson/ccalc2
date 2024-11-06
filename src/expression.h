#include <string>
#include <vector>
#include <deque>

#include "container.h"
#include "token.h"

using namespace std;

#ifndef __INCL_EXPRESSION
#define __INCL_EXPRESSION

class Expression {
    private:
        long precision;

        TokenQueue getRPNQueue(TokenArray & tokens);

    public:
        Expression(long precision) {
            this->precision = precision;
        }

        string evaluate(const string & expression);
};

#endif
