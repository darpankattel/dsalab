// 1.	Perform push and pop operations in stack

#include <iostream>
using namespace std;

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
    Stack<int>* memory = new Stack<int>(4);

    try {    // pushing
        memory->push(1);
        cout << memory->peek() << endl;
        memory->push(2);
        cout << memory->peek() << endl;
        memory->push(3);
        cout << memory->peek() << endl;
        memory->push(4);
        cout << memory->peek() << endl;
        // raises Exceptions::StackOverflow
        // memory->push(5);
        // cout << memory->peek() << endl;

        // popping
        memory->pop();
        cout << memory->peek() << endl;
        memory->pop();
        cout << memory->peek() << endl;
        memory->pop();
        cout << memory->peek() << endl;
        memory->pop();

        // raises Exceptions::StackUnderflow
        // cout << memory->peek() << endl;
        // memory->pop();
    } catch (Stack<int>::Exceptions::StackOverflow err) {
        cout << err.get_message();
    } catch (Stack<int>::Exceptions::StackUnderflow err) {
        cout << err.get_message();
    } catch (...) {
        cout << "Unknown error";
    }
    return 0;
}