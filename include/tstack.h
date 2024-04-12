// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
  // добавьте код стека
 private:
    T stackArray[100];
    int topIndex;

 public:
    TStack() : topIndex(-1) {}
    void push(T value) {
        if (!isFull())
            stackArray[++topIndex] = value;
        else
            throw std::string("Stack is full");
    }
    T get() const {
        return stackArray[topIndex];
    }
    T pop() {
        if (isEmpty()) {
            throw std::string("Stack is empty");
        } else {
            return stackArray[topIndex--];
        }
    }
    bool isEmpty() const {
        return topIndex == -1;
    }
    bool isFull() const {
        return topIndex == StackSize - 1;
    }
};
};

#endif  // INCLUDE_TSTACK_H_
