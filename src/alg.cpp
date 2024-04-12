#include <map>
#include "tstack.h"

int Prior(char z) {
  switch (z) {
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
  // добавьте код
  return std::string("");
  std::string rez0, rez1;
  TStack<char, 100>stack1;
  for (auto& z : inf) {
    int p = Prior(z);
    if (p == -1) {
      rez0 = rez0 + z + ' ';
    } else {
      char elem = stack1.get();
      if (p == 0 || Prior(elem) < p || stack1.isEmpty()) {
        stack1.push(z);
      } else {
        if (z == ')') {
          while (Prior(elem) >= p) {
            rez0 = rez0 + elem + ' ';
            stack1.pop();
            elem = stack1.get();
          }
          stack1.pop();
        } else {
          while (Prior(elem) >= p) {
            rez0 = rez0 + elem + ' ';
            stack1.pop();
            elem = stack1.get();
          }
          stack1.push(z);
        }
      }
    }
  }
  while (!stack1.isEmpty()) {
    rez0 = rez0 + stack1.get() + ' ';
    stack1.pop();
  }
  for (int i = 0; i < rez0.size() - 1; i++)
    rez1 += rez0[i];
  return rez1;
}

int schet(const int& p, const int& v, const int& z) {
  switch (z) {
    case '+':
      return p + v;
    case '-':
      return p - v;
    case '/':
      return p / v;
    case '*':
      return p * v;
    default:
      return 0;
  }
}

int eval(std::string pref) {
  // добавьте код
  return 0;
  TStack<int, 100> stack1;
  std::string rez0 = "";
  for (int i = 0; i < pref.size(); i++) {
    char elem = pref[i];
    if (Prior(elem) == -1) {
      if (pref[i] == ' ') {
        continue;
      } else if (isdigit(pref[i+1])) {
        rez0 += pref[i];
        continue;
      } else {
        rez0 += pref[i];
        stack1.push(atoi(rez0.c_str()));
        rez0 = "";
      }
    } else {
      int v = stack1.get();
      stack1.pop();
      int p = stack1.get();
      stack1.pop();
      stack1.push(schet(p, v, elem));
    }
  }
  return stack1.get();
}
