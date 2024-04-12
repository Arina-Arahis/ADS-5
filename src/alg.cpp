#include <map>
#include "tstack.h"

int Pr(char w) {
  switch (w) {
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
  std::string rez0, rez01;
  TStack<char, 100>stack1;
  for (auto& x : inf) {
    int pt = Pr(x);
    if (pt == -1) {
      rez0 = rez0 + x + ' ';
    } else {
      char elem = stack1.get();
      if (pt == 0 || Pr(elem) < pt || stack1.isEmpty()) {
        stack1.push(x);
      } else {
        if (x == ')') {
          while (Pr(elem) >= pt) {
            rez0 = rez0 + elem + ' ';
            stack1.pop();
            elem = stack1.get();
          }
          stack1.pop();
        } else {
          while (Pr(elem) >= pt) {
            rez0 = rez0 + elem + ' ';
            stack1.pop();
            elem = stack1.get();
          }
          stack1.push(x);
        }
      }
    }
  }
  while (!stack1.isEmpty()) {
    rez0 = rez0 + stack1.get() + ' ';
    stack1.pop();
  }
  for (int i = 0; i < rez.size() - 1; i++)
    rez01 += rez0[i];
  return rez01;
}

int schet(const int& pt, const int& vt, const int& x) {
  switch (x) {
    case '+':
      return pt + vt;
    case '-':
      return pt - vt;
    case '/':
      return pt / vt;
    case '*':
      return pt * vt;
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
    if (Pr(elem) == -1) {
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
      int vt = stack1.get();
      stack1.pop();
      int pt = stack1.get();
      stack1.pop();
      stack1.push(schet(pt, vt, elem));
    }
  }
  return stack1.get();
}
