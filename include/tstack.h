// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>

const int size = 100;
template<typename T, const int size>
class TStack {
 private:
  T arr[size] = {};
  int top;

 public:
Tstack() {
  arr = new T[size];
  top = -1;
}
  void push(const T& value) {
    if (isFull()) {
      throw std::string("Full");
    } else {
        arr[++top] = value;
    }
  }
  const T& pop() {
    if (isEmpty()) {
      throw std::string("Empty");
    } else {
        return arr[top--];
    }
  }
  const T& get() {
    return arr[top];
  }
  int isEmpty() {
    return top == -1;
  }
  int isFull() {
    return top == size;
  }
  ~TStack() {
    delete[] arr;
  }
};

#endif  // INCLUDE_TSTACK_H_
