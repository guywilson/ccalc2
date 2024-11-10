#include <string>

#include <gmp.h>
#include <mpfr.h>

#include "token.h"
#include "operator.h"
#include "operand.h"

using namespace std;

#ifndef __INCL_FUNCTION
#define __INCL_FUNCTION

static inline bool isTokenFunctionSin(const string & token) {
    return (token.compare("sin") == 0);
}

static inline bool isTokenFunctionCos(const string & token) {
    return (token.compare("cos") == 0);
}

static inline bool isTokenFunctionTan(const string & token) {
    return (token.compare("tan") == 0);
}

static inline bool isTokenFunctionAsin(const string & token) {
    return (token.compare("asin") == 0);
}

static inline bool isTokenFunctionAcos(const string & token) {
    return (token.compare("acos") == 0);
}

static inline bool isTokenFunctionAtan(const string & token) {
    return (token.compare("atan") == 0);
}

static inline bool isTokenFunctionSinh(const string & token) {
    return (token.compare("sinh") == 0);
}

static inline bool isTokenFunctionCosh(const string & token) {
    return (token.compare("cosh") == 0);
}

static inline bool isTokenFunctionTanh(const string & token) {
    return (token.compare("tanh") == 0);
}

static inline bool isTokenFunctionAsinh(const string & token) {
    return (token.compare("asinh") == 0);
}

static inline bool isTokenFunctionAcosh(const string & token) {
    return (token.compare("acosh") == 0);
}

static inline bool isTokenFunctionAtanh(const string & token) {
    return (token.compare("atanh") == 0);
}

static inline bool isTokenFunctionSqrt(const string & token) {
    return (token.compare("sqrt") == 0);
}

static inline bool isTokenFunctionLog(const string & token) {
    return (token.compare("log") == 0);
}

static inline bool isTokenFunctionLn(const string & token) {
    return (token.compare("ln") == 0);
}

static inline bool isTokenFunctionFact(const string & token) {
    return (token.compare("fact") == 0);
}

static inline bool isTokenFunctionDeg(const string & token) {
    return (token.compare("deg") == 0);
}

static inline bool isTokenFunctionRad(const string & token) {
    return (token.compare("rad") == 0);
}

static inline bool isTokenFunctionNot(const string & token) {
    return (token.compare("not") == 0);
}

static inline bool isTokenFunction(const string & token) {
    return (isTokenFunctionSin(token) ||
            isTokenFunctionCos(token) ||
            isTokenFunctionTan(token) ||
            isTokenFunctionAsin(token) ||
            isTokenFunctionAcos(token) ||
            isTokenFunctionAtan(token) ||
            isTokenFunctionSinh(token) ||
            isTokenFunctionCosh(token) ||
            isTokenFunctionTanh(token) ||
            isTokenFunctionAsinh(token) ||
            isTokenFunctionAcosh(token) ||
            isTokenFunctionAtanh(token) ||
            isTokenFunctionSqrt(token) ||
            isTokenFunctionLog(token) ||
            isTokenFunctionLn(token) ||
            isTokenFunctionFact(token) ||
            isTokenFunctionDeg(token) ||
            isTokenFunctionRad(token) ||
            isTokenFunctionNot(token));
}

class Function : public Operator {
    private:
        enum function_id {
            function_sin,
            function_cos,
            function_tan,
            function_asin,
            function_acos,
            function_atan,
            function_sinh,
            function_cosh,
            function_tanh,
            function_asinh,
            function_acosh,
            function_atanh,
            function_sqrt,
            function_log,
            function_ln,
            function_fact,
            function_deg,
            function_rad,
            function_not,
            function_unkown
        };

        function_id functionId;
        Operand functionOperand;

    public:
        Function(const string & token) : Operator() {
            if (isTokenFunctionSin(token)) {
                functionId = function_sin;
            }
            else if (isTokenFunctionCos(token)) {
                functionId = function_cos;
            }
            else if (isTokenFunctionTan(token)) {
                functionId = function_tan;
            }
            else if (isTokenFunctionAsin(token)) {
                functionId = function_asin;
            }
            else if (isTokenFunctionAcos(token)) {
                functionId = function_acos;
            }
            else if (isTokenFunctionAtan(token)) {
                functionId = function_atan;
            }
            else if (isTokenFunctionSinh(token)) {
                functionId = function_sinh;
            }
            else if (isTokenFunctionCosh(token)) {
                functionId = function_cosh;
            }
            else if (isTokenFunctionTanh(token)) {
                functionId = function_tanh;
            }
            else if (isTokenFunctionAsinh(token)) {
                functionId = function_asinh;
            }
            else if (isTokenFunctionAcosh(token)) {
                functionId = function_acosh;
            }
            else if (isTokenFunctionAtanh(token)) {
                functionId = function_atanh;
            }
            else if (isTokenFunctionSqrt(token)) {
                functionId = function_sqrt;
            }
            else if (isTokenFunctionLog(token)) {
                functionId = function_log;
            }
            else if (isTokenFunctionLn(token)) {
                functionId = function_ln;
            }
            else if (isTokenFunctionFact(token)) {
                functionId = function_fact;
            }
            else if (isTokenFunctionDeg(token)) {
                functionId = function_deg;
            }
            else if (isTokenFunctionRad(token)) {
                functionId = function_rad;
            }
            else if (isTokenFunctionNot(token)) {
                functionId = function_not;
            }
            else {
                functionId = function_unkown;
            }

            opAssociativity = aLeft;
            opPrescedence = 5;
        }

        static const string CLASS_NAME() {
            return "Function";
        }

        const string className() override {
            return Function::CLASS_NAME();
        }

        void setOperand(Operand & o) {
            functionOperand = o;
        }

        static bool isFunction(const string & token) {
            return isTokenFunction(token);
        }

        string evaluate() override {
            string answer;

            Operand result;

            switch (functionId) {
                case function_sin:
                    result = functionOperand.sin();
                    break;
                
                case function_cos:
                    result = functionOperand.cos();
                    break;
                
                case function_tan:
                    result = functionOperand.tan();
                    break;

                case function_asin:
                    result = functionOperand.asin();
                    break;
                
                case function_acos:
                    result = functionOperand.acos();
                    break;
                
                case function_atan:
                    result = functionOperand.atan();
                    break;

                case function_sinh:
                    result = functionOperand.sinh();
                    break;
                
                case function_cosh:
                    result = functionOperand.cosh();
                    break;
                
                case function_tanh:
                    result = functionOperand.tanh();
                    break;

                case function_asinh:
                    result = functionOperand.asinh();
                    break;
                
                case function_acosh:
                    result = functionOperand.acosh();
                    break;
                
                case function_atanh:
                    result = functionOperand.atanh();
                    break;
                
                case function_sqrt:
                    result = functionOperand.sqrt();
                    break;

                case function_log:
                    result = functionOperand.log();
                    break;
                
                case function_ln:
                    result = functionOperand.ln();
                    break;
                
                case function_fact:
                    result = functionOperand.factorial();
                    break;
                
                case function_deg:
                    result = functionOperand.deg();
                    break;
                
                case function_rad:
                    result = functionOperand.rad();
                    break;
                
                case function_not:
                    result = functionOperand.bitwise_not();
                    break;

                default:
                    throw calc_error("Invalid function");
            }

            return result.toString(INTERMEDIATE_PRECISION);
        }
};

#endif
