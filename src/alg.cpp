// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
  // добавьте код
  return std::string("");
}

int getPriority(char operand) {
    if (operand == '+' || operand == '-') return 1;
    if (operand == '*' || operand == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int evaluate(std::string pref) {
  // добавьте код
  return 0;
}

std::string infixToPostfix(std::string inf) {
    std::string postfix;
    TStack<char, 100> stack;
    for (char c : inf) {
        if (isdigit(c)) {
            postfix += c;
            postfix += ' ';
        } else if (c == '(') {
            stack.push(c);
        } else if (isOperator(c)) {
            while (!stack.isEmpty() && getPriority(stack.get()) >= getPriority(c)) {
                postfix += stack.get();
                postfix += ' ';
                stack.pop();
            }
            stack.push(c);
        } else if (c == ')') {
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
    for (char c : post) {
        if (isdigit(c)) {
            number += c;
        } else if (!number.empty()) {
            stack.push(std::atoi(number.c_str()));
            number.clear();
        }
        if (isOperator(c)) {
            int op2 = stack.get();
            stack.pop();
            int op1 = stack.get();
            stack.pop();
            switch (c) {
                case '+':
                    stack.push(op1 + op2);
                    break;
                case '-':
                    stack.push(op1 - op2);
                    break;
                case '*':
                    stack.push(op1 * op2);
                    break;
                case '/':
                    stack.push(op1 / op2);
                    break;
            }
        }
    }
    if (!number.empty()) {
        stack.push(std::atoi(number.c_str()));
    }
    return stack.get();
}
