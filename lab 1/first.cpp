#include <iostream>
using namespace std;

class Stack {
    private:
    int* arr;
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
        arr = new int[size];
    }
    void push (int elem) {
        if (top == size-1) {
            throw Exceptions::StackOverflow();
        }
        arr[++top] = elem;
    }
    int pop () {
        if (top == -1) {
            throw Exceptions::StackUnderflow();
        }
        return arr[top--];
    }
    int peek () {
        if (top == -1) {
            throw Exceptions::StackUnderflow();
        }
        return arr[top];
    }
};

int main () {
    Stack* memory = new Stack(4);

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
    } catch (Stack::Exceptions::StackOverflow err) {
        cout << err.get_message();
    } catch (Stack::Exceptions::StackUnderflow err) {
        cout << err.get_message();
    } catch (...) {
        cout << "Unknown error";
    }
    return 0;
}