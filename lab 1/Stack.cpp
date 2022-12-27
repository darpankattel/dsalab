#include <iostream>
#include "Stack.h"
using namespace std;

template <class T>
Stack::Stack (int size) {
    top = -1;
    this->size = size;
    arr = new T[size];
}
template <class T>
void Stack::push (T elem) {
    if (top == size-1) {
        throw typename Exceptions::StackOverflow();
    }
    arr[++top] = elem;
}
template <class T>
T Stack::pop () {
    if (top == -1) {
        throw typename Exceptions::StackUnderflow();
    }
    return arr[top--];
}
template <class T>
int Stack::peek () {
    if (top == -1) {
        throw typename Exceptions::StackUnderflow();
    }
    return arr[top];
}
