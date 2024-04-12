#include <map>
#include "tstack.h"

static int get_pr(char el) {
  if (el == '(') {
    return 0;
  } else if (el == ')') {
    return 1;
  } else if ((el == '+') || (el == '-')) {
    return 2;
  } else if ((el == '*') || (el == '/')) {
    return 3;
  } else {
    throw "Unknown Symbol!";
  }
}

std::string infx2pstfx(std::string inf) {
  // добавьте код
  return std::string("");
  std::string outa = "";
  TStack<char, 100> chars;
  for (int i = 0; i < inf.length(); i++) {
    if (isdigit(inf[i])) {
      outa += inf[i];
      if (i != inf.length() - 1) {
        outa += " ";
      }
    } else if (inf[i] == '(') {
      chars.push(inf[i]);
    } else if (chars.isempty()) {
      chars.push(inf[i]);
    } else if (inf[i] == ')') {
      while (true) {
        if (chars.isempty()) {
          break;
        } else if (chars.check() == '(') {
          break;
        }
        outa += chars.pop();
        if (i != inf.length() - 1) {
          outa += " ";
        }
      }
      chars.pop();
    } else if (get_pr(inf[i]) > get_pr(chars.check())) {
      chars.push(inf[i]);
    } else {
      while (true) {
        if (chars.isempty()) {
          break;
        } else if (!(get_pri(inf[i]) <= get_pr(chars.check()))) {
          break;
        }
        outa += chars.pop();
        if (i != inf.length() - 1) {
          outa += " ";
        }
      }
      chars.push(inf[i]);
    }
  }
  while (!chars.isempty()) {
    outa += " ";
    outa += chars.pop();
  }
  return outa;
}

int eval(std::string pref) {
  // добавьте код
  return 0;
  std::string time = "";
  TStack<int, 100> ints;
  for (int i = 0; i < pref.length(); i++) {
    if (isdigit(pref[i])) {
      time += pref[i];
    } else if (time.length() && pref[i] == ' ') {
      ints.push(atoi(time.c_str()));
      time = "";
    } else if (pref[i] == '+') {
      int two = ints.pop();
      int one = ints.pop();
      ints.push(one + two);
    } else if (pref[i] == '-') {
      int two = ints.pop();
      int one = ints.pop();
      ints.push(one - two);
    } else if (pref[i] == '*') {
      int two = ints.pop();
      int one = ints.pop();
      ints.push(one * two);
    } else if (pref[i] == '/') {
      int two = ints.pop();
      int one = ints.pop();
      ints.push(one / two);
    }
  }
  return ints.pop();
}
