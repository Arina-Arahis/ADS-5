#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
template <typename T, int SIZE>
class TStack {
  // добавьте код стека
 private:
  T *data = new T[100];
  int topa = 0, size = 100;

 public:
  TStacK() {
    data = new T[SIZE];
    size = SIZE;
    topa = 0;
  }
  ~TStacK() { delete[] data; }
  void push(T item) {
    data[topa] = item;
    topa++;
  }
  T pop() {
    if (top == 0) {
      throw "Stack is empty!";
    } else {
      topa -= 1;
      return data[topa];
    }
  }
  T check() {
    if (topa == 0) {
      throw "Stack is empty!";
    } else {
      return data[topa - 1];
    }
  }
  bool isempty() {
    if (topa == 0) {
      return true;
    } else {
      return false;
    }
  }
};

#endif  // INCLUDE_TSTACK_H_
