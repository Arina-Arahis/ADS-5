#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int maxsize>
class TStack {
 private:
  T data[maxsize];
  int top;

 public:
  TStack() {
    top = -1;
  }

  bool isEmpty() {
    return (top == -1);
  }

  bool isFull() {
    return (top == maxsize - 1);
  }

  void push(T val) {
    if (!isFull()) {
      top++;
      data[top] = val;
    }
  }

  void pop() {
    if (!isEmpty()) {
      top--;
    }
  }

  T get() {
    if (!isEmpty()) {
      return data[top];
    }
    return T();
  }
};

#endif  // INCLUDE_TSTACK_H_
