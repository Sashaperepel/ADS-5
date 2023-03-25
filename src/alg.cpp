// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int getPrior(char op) {
  switch (op) {
    case '(':
      return 0;
    case ')':
      return 1;
    case '*':
      return 3;
    case '/':
      return 3;
    case '+':
      return 2;
    case '-':
      return 2;
    default:
      return op;
  }
}

std::string infx2pstfx(std::string inf) {
  std:: string out = "";
  bool flag = true;
  Tstack <char, 100> stack1;
  for (int i = 0; i < inf.length(); i++) {
    if (getPrior(inf[i]) == inf[i]) {
      out = out + inf[i] + ' ';
      continue;
    } else {
      if (getPrior(inf[i]) == 0) {
        stack1.push(inf[i]);
        continue;
      }
      if (stack1.isEmpty()) {
        stack1.push(inf[i]);
        continue;
      }
      if (getPrior(inf[i]) > getPrior(stack1.get())) {
        stack1.push(inf[i]);
        continue;
      }
      if (getPrior(inf[i]) <= getPrior(stack1.get()) && getPrior(inf[i]) != 0) {
        out = out + stack1.get() + ' ';
        stack1.pop();
      }
      if (getPrior(inf[i]) == 1) {
        stack1.pop();
      } else {
        stack1.push(inf[i]);
      }
    }
  }
  while (!stack1.isEmpty()) {
    out = out + stack1.get() + ' ';
    stack1.pop();
  }
  return out;
}

int eval(std::string pref) {
  int sum = 0;
  int x = 0;
  int i = 0;
  Tstack <int, 100> stack1;
  while (i < pref.length()){
    if (getPrior(pref[i]) == pref[i]) {
      stack1.push(pref[i] - 48);
    }
    else {
      if (pref[i] == '+') {
        x = stack1.get();
        stack1.pop();
        sum = x + stack1.get();
        stack1.pop();
        stack1.push(sum);
      }
      if (pref[i] == '-') {
        x = stack1.get();
        stack1.pop();
        sum = stack1.get() - x;
        stack1.pop();
        stack1.push(sum);
      }
      if (pref[i] == '*') {
        x = stack1.get();
        stack1.pop();
        sum = x * stack1.get();
        stack1.pop();
        stack1.push(sum);
      }
      if (pref[i] == '/') {
        x = stack1.get();
        stack1.pop();
        sum = stack1.get() / x;
        stack1.pop();
        stack1.push(sum);
      }
    }
    ++i;
    ++i;
  }
  return stack1.get();
}
