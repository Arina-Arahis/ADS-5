#include <map>
#include "tstack.h"

int Priora(char symbol) {
    switch (symbol) {
    case '(':
        return 0;
    case ')':
        return 1;
    case '+': case '-':
        return 2;
    case '*': case '/':
        return 3;
    default:
        return -1;
    }
}

std::string infx2pstfx(std::string inf) {
    std::string postfix = "";
    TStack<char, 100> stack;
    for (auto& symbol : inf) {
        int priority = Priora(symbol);
        if (priority == -1) {
            postfix += symbol + ' ';
        } else {
            char top = stack.get();
            if (priority == 0 || (Priora(top) < priority && stack.isEmpty())) {
                stack.push(symbol);
            } else {
                if (symbol == ')') {
                    while (Priora(top) >= priority) {
                        postfix += top + ' ';
                        stack.pop();
                        top = stack.get();
                    }
                    stack.pop();
                } else {
                    while (Priora(top) >= priority) {
                        postfix += top + ' ';
                        stack.pop();
                        top = stack.get();
                    }
                    stack.push(symbol);
                }
            }
        }
    }
    while (!stack.isEmpty()) {
        postfix += stack.get() + ' ';
        stack.pop();
    }
    std::string cleanPostfix = "";
    for (int i = 0; i < postfix.size() - 1; i++)
        cleanPostfix += postfix[i];
    return cleanPostfix;
}

int schet(const int& operand1, const int& operand2, const int& operation) {
    switch (operation) {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '/':
        return operand1 / operand2;
    case '*':
        return operand1 * operand2;
    default:
        return 0;
    }
}

int eval(std::string pref) {
    TStack<int, 100> stack;
    std::string result = "";
    for (int i = 0; i < pref.size(); i++) {
        char symbol = pref[i];
        if (Priora(symbol) == -1) {
            if (pref[i] == ' ') {
                continue;
            } else if (isdigit(pref[i + 1])) {
                result += pref[i];
                continue;
            } else {
                result += pref[i];
                stack.push(atoi(result.c_str()));
                result = "";
            }
        } else {
            int operand2 = stack.get();
            stack.pop();
            int operand1 = stack.get();
            stack.pop();
            stack.push(schet(operand1, operand2, symbol));
        }
    }
    return stack.get();
}
