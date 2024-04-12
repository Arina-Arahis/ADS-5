// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>

template<typename T, int size>
class TStack {
  // добавьте код стека
 private:
    T arr1[100];
    int top1;

 public:
    TStack(): top1(-1) {}
    void push(T value) {
      if (!isFull())
        arr1[++top1] = value;
      else
        throw std::string("Full");
    }
    T get() const {
      return arr1[top1];
    }
    T pop() {
      if (isEmpty())
        throw std::string("Empty");
      else
        return arr1[top1--];
    }
    bool isEmpty() const {
      return top1 == -1;
    }
    bool isFull() const {
      return top1 == size - 1;
    }
};

#endif  // INCLUDE_TSTACK_H_
