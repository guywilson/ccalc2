#include <string>
#include <vector>
#include <deque>

#include "token.h"

using namespace std;

#ifndef __INCL_EXPRESSION
#define __INCL_EXPRESSION

#define TOKEN_CLASSNAME_OPERAND                 "Operand"
#define TOKEN_CLASSNAME_OPERATOR                "Operator"
#define TOKEN_CLASSNAME_FUNCTION                "Function"
#define TOKEN_CLASSNAME_BRACE                   "Brace"

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
