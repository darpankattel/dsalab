#include <iostream>
#include <cstring>
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
    // T peek () {
    //     if (top == -1) {
    //         throw typename Exceptions::StackUnderflow();
    //     }
    //     return arr[top];
    // }
    bool is_empty () {
        return bool(top < 0);
    }
};

int main () {
    try {
        cout << "Enter expression: ";
        char exprsn[100];
        cin >> exprsn;
        int i = 0;
        const int l = strlen(exprsn);
        Stack<char>* memory = new Stack<char>(l);
        while (i < l) {
            // cout<< exprsn[i];
            if (exprsn[i] == '(')
                memory->push(exprsn[i]);
            else if (exprsn[i] == ')')
                memory->pop();
            i++;
        }
        if (memory->is_empty())
            cout << "Brackets pair matched";
        else
            cout << "Brackets pair unmatched";
    } catch (typename Stack<char>::Exceptions::StackOverflow err) {
        cout << err.get_message();
    } catch (typename Stack<char>::Exceptions::StackUnderflow err) {
        cout << "Brackets pair unmatched";
    } catch (...) {
        cout << "Unknown error";
    }
    return 0;
}