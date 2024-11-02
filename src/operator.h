#include <string>

#include <gmp.h>
#include <mpfr.h>

#include "calc_error.h"
#include "token.h"
#include "operand.h"

using namespace std;

#ifndef __INCL_OPERATOR
#define __INCL_OPERATOR

static inline bool isTokenPlus(const string & token) {
    return (token.compare("+") == 0);
}

static inline bool isTokenMinus(const string & token) {
    return (token.compare("-") == 0);
}

static inline bool isTokenMultiply(const string & token) {
    return (token.compare("*") == 0);
}

static inline bool isTokenDivide(const string & token) {
    return (token.compare("/") == 0);
}

static inline bool isTokenMod(const string & token) {
    return (token.compare("%") == 0);
}

class Operator : public Token {
    private:
        enum op {
            operator_plus,
            operator_minus,
            operator_multiply,
            operator_divide,
            operator_mod,
            operator_unkown
        };

        Operand lhs;
        Operand rhs;
        op opType;

    public:
        Operator(const string & token) : Token(token) {
            if (isTokenPlus(token)) {
                opType = operator_plus;
            }
            else if (isTokenMinus(token)) {
                opType = operator_minus;
            }
            else if (isTokenMultiply(token)) {
                opType = operator_multiply;
            }
            else if (isTokenDivide(token)) {
                opType = operator_divide;
            }
            else if (isTokenMod(token)) {
                opType = operator_mod;
            }
            else {
                opType = operator_unkown;
            }
        }

        static bool isOperator(const string & token) {
            if (isTokenPlus(token) ||
                isTokenMinus(token) ||
                isTokenMultiply(token) ||
                isTokenDivide(token) ||
                isTokenMod(token))
            {
                return true;
            }

            return false;
        }

        void setLHOperand(Operand & l) {
            lhs = l;
        }

        void setRHOperand(Operand & r) {
            rhs = r;
        }

        void setOperands(Operand & lhs, Operand & rhs) {
            setLHOperand(lhs);
            setRHOperand(rhs);
        }

        string evaluate() override {
            Operand result;

            switch (opType) {
                case operator_plus:
                    result = lhs + rhs;
                    break;

                case operator_minus:
                    result = lhs - rhs;
                    break;

                case operator_multiply:
                    result = lhs * rhs;
                    break;

                case operator_divide:
                    result = lhs / rhs;
                    break;

                case operator_mod:
                    result = lhs % rhs;
                    break;

                default:
                    throw calc_error("Invalid operator");
            }

            return result.toString();
        }
};

#endif
