#include <string>
#include <vector>

using namespace std;

#ifndef __INCL_TEST_FRAMEWORK
#define __INCL_TEST_FRAMEWORK

typedef struct {
    string expression;
    string expectedResult;

    int radix;
}
calc_test_t;

class TestFramework {
    private:
        vector<calc_test_t *> tests;

    public:
        ~TestFramework() {
            for (calc_test_t * t : tests) {
                delete t;
            }
        }

        void addTest(const string & expression, const string & expectedResult, int radix) {
            calc_test_t * test = new calc_test_t;

            test->expression = expression;
            test->expectedResult = expectedResult;
            test->radix = radix;

            tests.push_back(test);
        }

        int numTests() {
            return tests.size();
        }

        string getTestExpression(int i) {
            return tests[i]->expression;
        }

        string getExpectedResult(int i) {
            return tests[i]->expectedResult;
        }

        int getRadix(int i) {
            return tests[i]->radix;
        } 

        bool assertTest(int i, string & actualResult) {
            if (actualResult.compare(tests[i]->expectedResult) == 0) {
                return true;
            }

            return false;
        }
};

#endif
