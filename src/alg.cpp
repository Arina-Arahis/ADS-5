#include "tstack.h"
#include <string>

std::string infx2pstfx(std::string inf) {
    std::string postfix;
    TStack<char, 100> stack;
    std::map<char, int> priority;
    priority['+'] = 1;
    priority['-'] = 1;
    priority['*'] = 2;
    priority['/'] = 2;

    for (char c : inf) {
        if (isdigit(c)) {
            postfix += c;
            postfix += ' ';
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.get() != '(') {
                postfix += stack.get();
                postfix += ' ';
                stack.pop();
            }
            stack.pop();
        } else if (priority.count(c)) {
            while (!stack.isEmpty() && priority[c] <= priority[stack.get()]) {
                postfix += stack.get();
                postfix += ' ';
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.isEmpty()) {
        postfix += stack.get();
        postfix += ' ';
        stack.pop();
    }

    if (!postfix.empty()) {
        postfix.pop_back(); // Remove the last space
    }

    return postfix;
}

int eval(std::string post) {
    TStack<int, 100> stack;

    for (char c : post) {
        if (isdigit(c)) {
            stack.push(c - '0'); // Convert char to int
        } else if (c == ' ') {
            continue;
        } else {
            int operand2 = stack.get();
            stack.pop();
            int operand1 = stack.get();
            stack.pop();

            switch (c) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
            }
        }
    }

    return stack.get();
}
