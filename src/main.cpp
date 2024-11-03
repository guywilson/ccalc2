#include <iostream>
#include <string>
#include <stdint.h>
#include <vector>

#include <gmp.h>
#include <mpfr.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "tokenizer.h"
#include "expression.h"
#include "prompt.h"
#include "version.h"

using namespace std;

const char * pszWarranty = 
    "This program comes with ABSOLUTELY NO WARRANTY.\n" \
    "This is free software, and you are welcome to redistribute it\n" \
    "under certain conditions.\n\n";

static void printVersion(void) {
    cout <<"CCALC version '" << getVersion() << "' - built [" << getBuildDate() << "]" << endl << endl;
}

static void printBanner(void) {
    int         year = 2024;

    // tmUpdate();
    // year = tmGetYear();

	cout << endl << "*** Welcome to CCALC v" << getVersion() << " ***" << endl << endl;
    cout << "A cmd line scientific calculator. Copyright © Guy Wilson " << year << endl;
	cout << "Type a calculation or command at the prompt, type 'help' for info." << endl << endl;
}

static void printUsage(void) {
    printBanner();
    cout << pszWarranty;

    cout << "Operators supported:" << endl;
    cout << "\t+, -, *, /, %% (Modulo)" << endl;
    // printf("\t& (AND), | (OR), ~ (XOR)\n");
    // printf("\t< (left shift), > (right shift)\n");
    // printf("\t^ (power, e.g. x to the power of y)\n");
    // printf("\t: (root, e.g. x : y - the yth root of x)\n\n");
    // printf("\tNesting is achieved with braces ()\n\n");
    // printf("Functions supported:\n");
    // printf("\tsin(x)\treturn the sine of the angle x degrees\n");
    // printf("\tcos(x)\treturn the cosine of the angle x degrees\n");
    // printf("\ttan(x)\treturn the tangent of the angle x degrees\n");
    // printf("\tasin(x)\treturn the angle in degrees of arcsine(x)\n");
    // printf("\tacos(x)\treturn the angle in degrees of arccosine(x)\n");
    // printf("\tatan(x)\treturn the angle in degrees of arctangent(x)\n");
    // printf("\tsinh(x)\treturn the hyperbolic sine of the angle x radians\n");
    // printf("\tcosh(x)\treturn the hyperbolic cosine of the angle x radians\n");
    // printf("\ttanh(x)\treturn the hyperbolic tangent of the angle x radians\n");
    // printf("\tasinh(x) return the inverse hyperbolic sine of angle x in radians\n");
    // printf("\tacosh(x) return the inverse hyperbolic cosine of angle x in radians\n");
    // printf("\tatanh(x) return the inverse hyperbolic tangent of angle x in radians\n");
    // printf("\tsqrt(x)\treturn the square root of x\n");
    // printf("\tlog(x)\treturn the log of x\n");
    // printf("\tln(x)\treturn the natural log of x\n");
    // printf("\tfact(x)\treturn the factorial of x\n");
    // printf("\trad(x)\tthe value in radians of x degrees\n");
    // printf("\tdeg(x)\tthe value in degrees of x radians\n");
    // printf("\tmem(n)\tthe value in memory location n, where n is 0 - 9\n\n");
    // printf("Constants supported:\n");
    // printf("\tpi\tthe ratio pi\n");
    // printf("\teu\tEulers constant\n");
    // printf("\tg\tThe gravitational constant G\n");
    // printf("\tc\tthe speed of light in a vacuum\n\n");
    // printf("Commands supported:\n");
    // printf("\tmemstn\tStore the last result in memory location n (0 - 9)\n");
    // printf("\tmemclrn\tClear the memory location n (0 - 9)\n");
    // printf("\tclrall\tClear all memory locations\n");
    // printf("\tlistall\tList all memory locations\n");
    // printf("\tdec\tSwitch to decimal mode\n");
    // printf("\thex\tSwitch to hexadecimal mode\n");
    // printf("\tbin\tSwitch to binary mode\n");
    // printf("\toct\tSwitch to octal mode\n");
    // printf("\tstat\tSwitch to statistical mode\n");
    // printf("\tsum\tStatistical sum function\n");
    // printf("\tavg\tStatistical average function\n");
    // printf("\tmin\tStatistical minimum function\n");
    // printf("\tmax\tStatistical maximum function\n");
    // printf("\tclrstat\tClear the statistic buffer of all values\n");
    // printf("\tsetpn\tSet the precision to n\n");
    // printf("\tfmton\tTurn on output formatting (on by default)\n");
    // printf("\tfmtoff\tTurn off output formatting\n");
    // printf("\thelp\tThis help text\n");
    // printf("\ttest\tRun a self test of the calculator\n");
    // printf("\tversion\tPrint the calculator version\n");
    // printf("\texit\tExit the calculator\n\n");
}

int main(int argc, char ** argv) {
    bool loop = true;

    printBanner();

    Prompt prompt;
    prompt.setPrompt("calc > ");

    while (loop) {
        string response = prompt.read();

        if (response.compare("quit") == 0 || response.compare("q") == 0 || response.compare("exit") == 0) {
            loop = false;
        }
        else if (response.compare("version") == 0) {
            printVersion();
        }
        else if (response.compare("help") == 0 || response.compare("?") == 0) {
            printUsage();
        }
        else {
            Expression e(response);

            cout << "Answer: " << e.evaluate() << endl;
        }
    }

    return 0;
}
