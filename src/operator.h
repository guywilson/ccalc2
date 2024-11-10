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

static inline bool isTokenPower(const string & token) {
    return (token.compare("^") == 0);
}

static inline bool isTokenRoot(const string & token) {
    return (token.compare(":") == 0);
}

static inline bool isTokenAND(const string & token) {
    return (token.compare("&") == 0);
}

static inline bool isTokenOR(const string & token) {
    return (token.compare("|") == 0);
}

static inline bool isTokenXOR(const string & token) {
    return (token.compare("~") == 0);
}

static inline bool isTokenLShift(const string & token) {
    return (token.compare("<") == 0);
}

static inline bool isTokenRShift(const string & token) {
    return (token.compare(">") == 0);
}

static inline bool isTokenOperator(const string & token) {
    return (isTokenPlus(token) ||
            isTokenMinus(token) ||
            isTokenMultiply(token) ||
            isTokenDivide(token) ||
            isTokenMod(token) ||
            isTokenPower(token) ||
            isTokenRoot(token) ||
            isTokenAND(token) ||
            isTokenOR(token) ||
            isTokenXOR(token) ||
            isTokenLShift(token) ||
            isTokenRShift(token));
}

class Operator : public Token {
    public:
        enum associativity {
            aLeft,
            aRight
        };

    private:
        enum op {
            operator_plus,
            operator_minus,
            operator_multiply,
            operator_divide,
            operator_mod,
            operator_power,
            operator_root,
            operator_and,
            operator_or,
            operator_xor,
            operator_lshift,
            operator_rshift,
            operator_unkown
        };

        Operand lhs;
        Operand rhs;
        op opType;

    protected:
        associativity opAssociativity;
        int opPrescedence;

    public:
        Operator() : Token() {
            opType = operator_unkown;
        }

        Operator(const string & token) : Token(token) {
            if (isTokenPlus(token)) {
                opType = operator_plus;
                opPrescedence = 2;
                opAssociativity = aLeft;
            }
            else if (isTokenMinus(token)) {
                opType = operator_minus;
                opPrescedence = 2;
                opAssociativity = aLeft;
            }
            else if (isTokenMultiply(token)) {
                opType = operator_multiply;
                opPrescedence = 3;
                opAssociativity = aLeft;
            }
            else if (isTokenDivide(token)) {
                opType = operator_divide;
                opPrescedence = 3;
                opAssociativity = aLeft;
            }
            else if (isTokenMod(token)) {
                opType = operator_mod;
                opPrescedence = 3;
                opAssociativity = aLeft;
            }
            else if (isTokenPower(token)) {
                opType = operator_power;
                opPrescedence = 4;
                opAssociativity = aRight;
            }
            else if (isTokenRoot(token)) {
                opType = operator_root;
                opPrescedence = 4;
                opAssociativity = aLeft;
            }
            else if (isTokenAND(token)) {
                opType = operator_and;
                opPrescedence = 4;
                opAssociativity = aLeft;
            }
            else if (isTokenOR(token)) {
                opType = operator_or;
                opPrescedence = 4;
                opAssociativity = aLeft;
            }
            else if (isTokenXOR(token)) {
                opType = operator_xor;
                opPrescedence = 4;
                opAssociativity = aLeft;
            }
            else if (isTokenLShift(token)) {
                opType = operator_lshift;
                opPrescedence = 4;
                opAssociativity = aRight;
            }
            else if (isTokenRShift(token)) {
                opType = operator_rshift;
                opPrescedence = 4;
                opAssociativity = aRight;
            }
            else {
                opType = operator_unkown;
                opPrescedence = 0;
                opAssociativity = aLeft;
            }
        }

        static bool isOperator(const string & token) {
            return isTokenOperator(token);
        }

        static const string CLASS_NAME() {
            return "Operator";
        }

        virtual const string className() override {
            return Operator::CLASS_NAME();
        }

        int getPrescedence() {
            return opPrescedence;
        }

        associativity getAssociativity() {
            return opAssociativity;
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

                case operator_power:
                    result = lhs ^ rhs;
                    break;

                case operator_root:
                    result = lhs.root(rhs);
                    break;

                case operator_and:
                    result = lhs & rhs;
                    break;

                case operator_or:
                    result = lhs | rhs;
                    break;

                case operator_xor:
                    result = lhs.bitwise_xor(rhs);
                    break;

                case operator_lshift:
                    result = lhs << rhs;
                    break;

                case operator_rshift:
                    result = lhs >> rhs;
                    break;

                default:
                    throw calc_error("Invalid operator");
            }

            return result.toString(INTERMEDIATE_PRECISION);
        }
};

#endif
