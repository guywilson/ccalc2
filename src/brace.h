#include <string>

#include "token.h"

using namespace std;

#ifndef __INCL_BRACE
#define __INCL_BRACE

class Brace : public Token {
    private:
        bool isLeft;

    public:
        Brace(const string & token) : Token(token) {
            if (Brace::isLeftBrace(token[0])) {
                isLeft = true;
            }
            else {
                isLeft = false;
            }
        }

        virtual const string className() override {
            return "Brace";
        }

        static bool isLeftBrace(char ch) {
            return (ch == '(' || ch == '[' || ch == '{');
        }

        static bool isRightBrace(char ch) {
            return (ch == ')' || ch == ']' || ch == '}');
        }

        static bool isBrace(char ch) {
            return (isLeftBrace(ch) || isRightBrace(ch));
        }

        static bool isBrace(const string & token) {
            return isBrace(token[0]);
        }

        static const string CLASS_NAME() {
            return "Brace";
        }

        bool isLeftBrace() {
            return isLeft;
        }
};

#endif
