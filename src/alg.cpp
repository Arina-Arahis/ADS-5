#include <map>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
  // добавьте код
  return std::string("");
}

int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int evaluate(std::string pref) {
  // добавьте код
  return 0;
}

std::string infixToPostfix(std::string inf) {
    std::string postfix;
    TStack<char, 100> stack;
    for (char ch : inf) {
        if (isdigit(ch)) {
            postfix += ch;
            postfix += ' ';
        } else if (ch == '(') {
            stack.push(ch);
        } else if (isOperator(ch)) {
            while (!stack.isEmpty() && getPriority(stack.get()) >= getPriority(ch)) {
                postfix += stack.get();
                postfix += ' ';
                stack.pop();
            }
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.isEmpty() && stack.get() != '(') {
                postfix += stack.get();
                postfix += ' ';
                stack.pop();
            }
            stack.pop();
        }
    }
    while (!stack.isEmpty()) {
        postfix += stack.get();
        postfix += ' ';
        stack.pop();
    }
    if (!postfix.empty()) {
        postfix.pop_back();
    }
    return postfix;
}

int evaluate(std::string post) {
    TStack<int, 100> stack;
    std::string number;
    for (char ch : post) {
        if (isdigit(ch)) {
            number += ch;
        } else if (!number.empty()) {
            stack.push(std::atoi(number.c_str()));
            number.clear();
        }
        if (isOperator(ch)) {
            int operand2 = stack.get();
            stack.pop();
            int operand1 = stack.get();
            stack.pop();
            switch (ch) {
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
    if (!number.empty()) {
        stack.push(std::atoi(number.c_str()));
    }
    return stack.get();
}
