#include <string>

#include <ctype.h>

#include <gmp.h>
#include <mpfr.h>

#include "token.h"

using namespace std;

#ifndef __INCL_OPERAND
#define __INCL_OPERAND

#define MPFR_BASE_PRECISION           1024L

#define FORMAT_STRING_LENGTH             32
#define OUTPUT_MAX_STRING_LENGTH       4096

#define BASE2_OUTPUT_LEN               (sizeof(uint32_t) * 8)

#define BASE_10                          10
#define BASE_16                          16
#define BASE_8                            8
#define BASE_2                            2

#define DECIMAL                         BASE_10
#define HEXADECIMAL                     BASE_16
#define OCTAL                           BASE_8
#define BINARY                          BASE_2

class Operand : public Token {
    protected:
        mpfr_t value;

    private:
        int radix;

        string toBase2() {
            char szBinaryString[BASE2_OUTPUT_LEN + 1];
            char szOutputString[BASE2_OUTPUT_LEN + 1];
            int i = BASE2_OUTPUT_LEN - 1;
            int bit = 0;
            uint32_t uiValue = mpfr_get_ui(value, MPFR_RNDA);

            szBinaryString[BASE2_OUTPUT_LEN] = 0;

            while (uiValue > 0) {
                bit = uiValue % 2;

                uiValue = uiValue >> 1;

                szBinaryString[i--] = ((char)bit + '0');
            }

            strncpy(szOutputString, &szBinaryString[i + 1], BASE2_OUTPUT_LEN);

            string output = szOutputString;

            return output;
        }

    public:
        Operand() {
            mpfr_init2(value, MPFR_BASE_PRECISION);
        }

        Operand(const string & token) : Token(token) {
            Operand();
            mpfr_strtofr(value, token.c_str(), NULL, 10, MPFR_RNDA);
        }

        static bool isOperand(const string & token) {
            for (int i = 0;i < token.length();i++) {
                char ch = token[i];

                if (!isdigit(ch) && ch != '-' && ch != '.') {
                    return false;
                }
            }

            return true;
        }

        string toString() {
            char szOutputString[OUTPUT_MAX_STRING_LENGTH];
            char szFormatString[FORMAT_STRING_LENGTH];
            string output;

            switch (radix) {
                case DECIMAL:
                    snprintf(szFormatString, FORMAT_STRING_LENGTH, "%%.%ldRf", MPFR_BASE_PRECISION);
                    mpfr_snprintf(szOutputString, OUTPUT_MAX_STRING_LENGTH, szFormatString, value);
                    output.assign(szOutputString);
                    break;

                case HEXADECIMAL:
                    snprintf(szOutputString, OUTPUT_MAX_STRING_LENGTH, "%016lX", mpfr_get_ui(value, MPFR_RNDA));
                    output.assign(szOutputString);
                    break;

                case OCTAL:
                    snprintf(szOutputString, OUTPUT_MAX_STRING_LENGTH, "%lo", mpfr_get_ui(value, MPFR_RNDA));
                    output.assign(szOutputString);
                    break;

                case BINARY:
                    output.assign(toBase2());
                    break;
            }

            // lgLogDebug(
            //     "Output string = '%s', radix = %d, precision = %ld", 
            //     outputStr.c_str(), 
            //     radix, 
            //     getPrecision());

            return output;
        }

        virtual string evaluate() override {
            return toString();
        }

        const Operand operator+(const Operand & rhs) {
            Operand result;
            mpfr_add(result.value, this->value, rhs.value, MPFR_RNDA);
            return result;
        }

        const Operand operator-(const Operand & rhs) {
            Operand result;
            mpfr_sub(result.value, this->value, rhs.value, MPFR_RNDA);
            return result;
        }

        const Operand operator*(const Operand & rhs) {
            Operand result;
            mpfr_mul(result.value, this->value, rhs.value, MPFR_RNDA);
            return result;
        }

        const Operand operator/(const Operand & rhs) {
            Operand result;
            mpfr_div(result.value, this->value, rhs.value, MPFR_RNDA);
            return result;
        }

        const Operand operator%(const Operand & rhs) {
            Operand result;
            mpfr_remainder(result.value, this->value, rhs.value, MPFR_RNDA);
            return result;
        }
};

#endif
