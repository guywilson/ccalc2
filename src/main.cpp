#include <iostream>
#include <sstream>
#include <string>
#include <stdint.h>
#include <vector>
#include <time.h>
#include <sys/time.h>

#include <gmp.h>
#include <mpfr.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "calc_error.h"
#include "system.h"
#include "tokenizer.h"
#include "expression.h"
#include "prompt.h"
#include "version.h"
#include "test.h"

using namespace std;

// #define DEBUG_CALCULATION                   "2 + (3 * 4) ^ 2 - 13"

#define DEFAULT_PRECISION                   12

void test();

const char * pszWarranty = 
    "This program comes with ABSOLUTELY NO WARRANTY.\n" \
    "This is free software, and you are welcome to redistribute it\n" \
    "under certain conditions.\n\n";

static void printVersion(void) {
    cout <<"CCALC version '" << getVersion() << "' - built [" << getBuildDate() << "]" << endl << endl;
}

static void printBanner(void) {
    struct timeval tv;

    gettimeofday(&tv, NULL);
    time_t t = tv.tv_sec;
    struct tm * localTime = localtime(&t);

    int year = localTime->tm_year;

	cout << endl << "*** Welcome to CCALC v" << getVersion() << " ***" << endl << endl;
    cout << "A cmd line scientific calculator. Copyright © Guy Wilson " << year << endl;
	cout << "Type a calculation or command at the prompt, type 'help' for info." << endl << endl;
}

static void printUsage(void) {
    printBanner();
    cout << pszWarranty;

    cout << "Operators supported:" << endl;
    cout << "\t+, -, *, /, %% (Modulo)" << endl;
    cout << "\t& (AND), | (OR), ~ (XOR)" << endl;
    cout << "\t< (left shift), > (right shift)" << endl;
    cout << "\t^ (power, e.g. x to the power of y)" << endl;
    // cout << "\t: (root, e.g. x : y - the yth root of x)" << endl << endl;
    cout << "\tNesting is achieved with braces ()" << endl << endl;
    cout << "Functions supported:" << endl;
    cout << "\tsin(x)\treturn the sine of the angle x degrees" << endl;
    cout << "\tcos(x)\treturn the cosine of the angle x degrees" << endl;
    cout << "\ttan(x)\treturn the tangent of the angle x degrees" << endl;
    cout << "\tasin(x)\treturn the angle in degrees of arcsine(x)" << endl;
    cout << "\tacos(x)\treturn the angle in degrees of arccosine(x)" << endl;
    cout << "\tatan(x)\treturn the angle in degrees of arctangent(x)" << endl;
    cout << "\tsinh(x)\treturn the hyperbolic sine of the angle x radians" << endl;
    cout << "\tcosh(x)\treturn the hyperbolic cosine of the angle x radians" << endl;
    cout << "\ttanh(x)\treturn the hyperbolic tangent of the angle x radians" << endl;
    cout << "\tasinh(x) return the inverse hyperbolic sine of angle x in radians" << endl;
    cout << "\tacosh(x) return the inverse hyperbolic cosine of angle x in radians" << endl;
    cout << "\tatanh(x) return the inverse hyperbolic tangent of angle x in radians" << endl;
    cout << "\tsqrt(x)\treturn the square root of x" << endl;
    cout << "\tlog(x)\treturn the log of x" << endl;
    cout << "\tln(x)\treturn the natural log of x" << endl;
    cout << "\tfact(x)\treturn the factorial of x" << endl;
    cout << "\trad(x)\tthe value in radians of x degrees" << endl;
    cout << "\tdeg(x)\tthe value in degrees of x radians" << endl;
    cout << "Constants supported:" << endl;
    cout << "\tpi\tthe ratio pi" << endl;
    cout << "\teu\tEulers constant" << endl;
    cout << "\tc\tthe speed of light in a vacuum" << endl << endl;
    cout << "Commands supported:" << endl;
    cout << "\tdec\tSwitch to decimal mode" << endl;
    cout << "\thex\tSwitch to hexadecimal mode" << endl;
    cout << "\tbin\tSwitch to binary mode" << endl;
    cout << "\toct\tSwitch to octal mode" << endl;
    cout << "\tsetpn\tSet the precision to n" << endl;
    cout << "\thelp\tThis help text" << endl;
    cout << "\ttest\tRun a self test of the calculator" << endl;
    cout << "\tversion\tPrint the calculator version" << endl;
    cout << "\texit\tExit the calculator" << endl << endl;
}

string getRadixCode(int radix) {
    string code;

    switch (radix) {
        case DECIMAL:
            code.assign("DEC");
            break;

        case HEXADECIMAL:
            code.assign("HEX");
            break;

        case OCTAL:
            code.assign("OCT");
            break;

        case BINARY:
            code.assign("BIN");
            break;
    }

    return code;
}

string getPromptString(int radix) {
    stringstream s;

    s << "calc [" << getRadixCode(radix) << "]> ";

    return s.str();
}

int main(int argc, char ** argv) {
    long precision = DEFAULT_PRECISION;

    printBanner();

    System & system = System::getInstance();
    system.setRadix(DECIMAL);

    Prompt prompt;
    string answer = "0.00";

    bool loop = true;

    while (loop) {
#ifndef DEBUG_CALCULATION
        prompt.setPrompt(getPromptString(system.getRadix()));
        string response = prompt.read();
#else
        string response = DEBUG_CALCULATION;
        loop = false;
#endif

        if (response.compare("quit") == 0 || response.compare("q") == 0 || response.compare("exit") == 0) {
            loop = false;
        }
        else if (response.compare("version") == 0) {
            printVersion();
        }
        else if (response.compare("help") == 0 || response.compare("?") == 0) {
            printUsage();
        }
        else if (response.find("setp", 0) == 0) {
            string p = response.substr(4);
            precision = strtol(p.c_str(), NULL, 10);
        }
        else if (response.compare("test") == 0) {
            test();
        }
        else if (response.compare("dec") == 0) {
            int oldRadix = system.getRadix();

            if (oldRadix != DECIMAL) {
                system.setRadix(DECIMAL);

                Operand o(answer);
                cout << "Last answer = " << o.toString(precision) << endl << endl;
            }
        }
        else if (response.compare("hex") == 0) {
            int oldRadix = system.getRadix();

            if (oldRadix != HEXADECIMAL) {
                system.setRadix(HEXADECIMAL);

                Operand o(answer);
                cout << "Last answer = " << o.toString(precision) << endl << endl;
            }
         }
        else if (response.compare("oct") == 0) {
            int oldRadix = system.getRadix();

            if (oldRadix != OCTAL) {
                system.setRadix(OCTAL);

                Operand o(answer);
                cout << "Last answer = " << o.toString(precision) << endl << endl;
            }
        }
        else if (response.compare("bin") == 0) {
            int oldRadix = system.getRadix();

            if (oldRadix != BINARY) {
                system.setRadix(BINARY);

                Operand o(answer);
                cout << "Last answer = " << o.toString(precision) << endl << endl;
            }
        }
        else {
            try {
                Expression e(precision);
                answer = e.evaluate(response);

                cout << response << " = " << answer << endl << endl;
            }
            catch (calc_error & e) {
                cout << "Error: " << e.what() << endl << endl;
            }
        }
    }

    return 0;
}

void test() {
    const int testPrecision = 6;

    TestFramework t;

    t.addTest("2 + (3 * 4) ^ 2 - 13",                           "133.000000",   DECIMAL);
    t.addTest("2+(3*4)^2-13",                                   "133.000000",   DECIMAL);
    t.addTest("12 - ((2 * 3) - (8 / 2) / 0.5) / 12.653",        "12.158065",    DECIMAL);
    t.addTest("2 ^ 16 - 1",                                     "65535.000000", DECIMAL);
    t.addTest("(((((((1 + 2 * 3)-2)*4)/2)-12)+261)/12) - 5.25", "16.333333",    DECIMAL);
    t.addTest("pi + sin(45 + 45)",                              "4.141593",     DECIMAL);
    t.addTest("pi * (2 ^ 2)",                                   "12.566371",    DECIMAL);
    t.addTest("84 * -15 + sin(47)",                             "-1259.268646", DECIMAL);
    t.addTest("16 / (3 - 5 + 8) * (3 + 5 - 4)",                 "10.666667",    DECIMAL);
    t.addTest("sin(90) * cos(45) * tan(180) + asin(1) + acos(0) + atan(25)",    "267.709390",    DECIMAL);
    t.addTest("asin(sin(90)) + acos(cos(90))",                  "180.000000",   DECIMAL);
    t.addTest("fact(12) + 13",                                  "479001613.000000", DECIMAL);
    t.addTest("sin(45 + 45) + pi",                              "4.141593",     DECIMAL);
    t.addTest("-232 * 647.19",                                  "-150148.080000", DECIMAL);
    t.addTest("2 ^ 32 - 1",                                     "4294967295.000000",DECIMAL);
    t.addTest("sin(90)-1",                                      "0.000000",     DECIMAL);
    t.addTest("(F100 < 3) + (AA > 1)",                          "0000000000078855", HEXADECIMAL);
    t.addTest("10101010 | 1010101",                             "11111111",     BINARY);
    t.addTest("(1 < 111) | (1 < 110)",                          "11000000",     BINARY);

    int numTests = t.numTests();
    int numPassed = 0;
    int numFailed = 0;

    System & system = System::getInstance();

    int originalRadix = system.getRadix();
    
    Expression expression(testPrecision);

    for (int i = 0;i < numTests;i++) {
        string testExpression = t.getTestExpression(i);

        system.setRadix(t.getRadix(i));

        cout << "Testing: '" << testExpression << "'..." << endl;

        string actualResult = expression.evaluate(testExpression);

        if (t.assertTest(i, actualResult)) {
            cout << "    Test passed :)" << endl << endl;
            numPassed++;
        }
        else {
            cout << "    Test failed :(" << endl << endl; 
            numFailed++;
        }
    }

    system.setRadix(originalRadix);

    cout << "Total tests ran: " << numTests << ", passed: " << numPassed << ", failed: " << numFailed << endl << endl;
}
