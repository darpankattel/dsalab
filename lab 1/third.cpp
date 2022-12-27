// 3.	Evaluate the postfix expression
#include <iostream>


template <class T>
class Stack {
    private:
    T* arr;
    int top;
    int size;
    public:
    class Exceptions {
        public:
        class StackOverflow {
            public: const char* get_message () {return "StackOverflow: Stack is full";}
        };
        class StackUnderflow {
            public: const char* get_message () {return "StackUnderflow: Stack is empty";}
        };
    };
    Stack (int size) {
        top = -1;
        this->size = size;
        arr = new T[size];
    }
    void push (T elem) {
        if (top == size-1) {
            throw typename Exceptions::StackOverflow();
        }
        arr[++top] = elem;
    }
    T pop () {
        if (top == -1) {
            throw typename Exceptions::StackUnderflow();
        }
        return arr[top--];
    }
    int peek () {
        if (top == -1) {
            throw typename Exceptions::StackUnderflow();
        }
        return arr[top];
    }
};


int main () {
    Stack<char *> memory(5);
    return 0;
}