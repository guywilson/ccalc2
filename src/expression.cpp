#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>

#include "calc_error.h"
#include "token.h"
#include "operator.h"
#include "brace.h"
#include "tokenizer.h"
#include "expression.h"

using namespace std;

deque<Token *> Expression::getRPNQueue(vector<Token *> & tokens) {
    deque<Token *> tokenQueue;
    stack<Token *> operatorStack;

    for (int i = 0;i < tokens.size();i++) {
        Token * token = tokens[i];

        if (token->className() == "Operand") {
            tokenQueue.push_back(token);
        }
        else if (token->className() == "Operator") {
            Operator * o1 = dynamic_cast<Operator *>(token);

            while (!operatorStack.empty()) {
                Token * topToken = operatorStack.top();
                Operator * o2 = dynamic_cast<Operator *>(topToken);

                if ((o1->getAssociativity() == Operator::aLeft && o1->getPrescedence() <= o2->getPrescedence()) ||
                    (o1->getAssociativity() == Operator::aRight && o1->getPrescedence() < o2->getPrescedence()))
                {
                    tokenQueue.push_back(operatorStack.top());
                    operatorStack.pop();
                }
            }

            operatorStack.push(token);
        }
        else if (token->className() == "Brace") {
            Brace * brace = dynamic_cast<Brace *>(token);
            
            if (brace->isLeftBrace()) {
                operatorStack.push(brace);
            }
            else {
                /*
                If the token is a right parenthesis (i.e. ")"):
                    Until the token at the top of the stack is a left parenthesis, pop
                    operators off the stack onto the output queue.
                    Pop the left parenthesis from the stack, but not onto the output queue.
                    If the token at the top of the stack is a function token, pop it onto
                    the output queue.
                    If the stack runs out without finding a left parenthesis, then there
                    are mismatched parentheses.
                */
                bool foundLeftParenthesis = false;

                while (!operatorStack.empty()) {
                    Token * stackToken = operatorStack.top();
                    operatorStack.pop();

                    if (stackToken->className() == "Brace") {
                        Brace * b = dynamic_cast<Brace *>(stackToken);

                        if (b->isLeftBrace()) {
                            foundLeftParenthesis = true;
                            break;
                        }
                    }
                    else {
                        tokenQueue.push_back(stackToken);
                    }
                }

                if (!foundLeftParenthesis) {
                    throw calc_error("getRPNQueue(): Error unmatched parenthesis");
                }
            }
        }
        else {
            throw calc_error("getRPNQueue(): Invalid token");
        }
    }

    /*
        While there are still operator tokens in the stack:
        If the operator token on the top of the stack is a parenthesis,
        then there are mismatched parentheses.
        Pop the operator onto the output queue.
    */
    while (!operatorStack.empty()) {
        Token * stackToken = operatorStack.top();
        operatorStack.pop();

        if (stackToken->className() == "Brace") {
            /*
            ** If we've got here, we must have unmatched parenthesis...
            */
            throw calc_error("getRPNQueue(): Error unmatched parenthesis");
        }
        else {
            tokenQueue.push_back(stackToken);
        }
    }

    return tokenQueue;
}

string Expression::evaluate(long precision) {
    Tokenizer t(expression);

    vector<Token *> tokens = t.tokenize();
    deque<Token *> tokenQueue = getRPNQueue(tokens);

    stack<Token *> tokenStack;

    while (!tokenQueue.empty()) {
        Token * t = tokenQueue.front();
        tokenQueue.pop_front();

        if (t->className() == "Operand") {
            tokenStack.push(t);
        }
        else if (t->className() == "Operator") {
            Operator * o = dynamic_cast<Operator *>(t);

            Operand * op1 = dynamic_cast<Operand *>(tokenStack.top());
            tokenStack.pop();

            Operand * op2 = dynamic_cast<Operand *>(tokenStack.top());
            tokenStack.pop();

            o->setOperands(*op1, *op2);
            string r = o->evaluate();

            delete op1;
            delete op2;

            Operand * result = new Operand(r);
            tokenStack.push(result);
        }
    }

    /*
    ** If there is one and only one item left on the stack,
    ** it is the result of the calculation. Otherwise, we
    ** have too many tokens and therefore an error...
    */
    string answer;

    if (tokenStack.size() == 1) {
        Operand * result = dynamic_cast<Operand *>(tokenStack.top());
        tokenStack.pop();

        answer = result->toString(precision);

        delete result;
    }
    else {
        throw calc_error("Invalid items on stack", __FILE__, __LINE__);
    }

    return answer;
}
