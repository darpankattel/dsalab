// 2.	Convert  : 
//     a.	Infix expression to postfix expression
//     b.	Infix expression to prefix expression

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
        // if (top == -1) {
        //     throw typename Exceptions::StackUnderflow();
        // }
        return arr[top];
    }
    bool is_empty () {
        return top == -1;
    }
};

class Converter {
    private:
    public:
    bool is_operator (char a) {
        const string operators = "+-*/%^()";
        for (int i = 0; i < operators.length(); i++) {
            if (a == operators[i]) return true;
        }
        return false;
    }
    string reverse(string str)
    {
        string rev;
        for (int i = str.length() - 1; i >= 0; i--)
            rev += str[i];
        return rev;
    }
    int get_precedence(char opr) {
        switch (opr)
        {
        case '+':
            return 0;
        case '-':
            return 0;
        case '/':
            return 1;
        case '*':
            return 1;
        case '%':
            return 1;
        case '^':
            return 2;
        default:
            return -1;
        }
    }
    string get_postfix(string expr) {
        Stack<char> memory(expr.length());
        string postfix = "";
        for (int i = 0; i < expr.length(); i++) {
            if (is_operator(expr[i])) {
                if (memory.is_empty())
                    memory.push(expr[i]);
                else if (expr[i] == '(')
                    memory.push(expr[i]);
                else if (expr[i] == ')') {
                    try {
                        while (memory.peek() != '(') {
                            postfix += memory.pop();
                        }
                        memory.pop();
                    } catch (Stack<char>::Exceptions::StackUnderflow) {}
                }
                else{
                    try {
                        while(get_precedence(memory.peek()) >= get_precedence(expr[i])) {
                            postfix += memory.pop();
                        }
                    } catch (Stack<char>::Exceptions::StackUnderflow) {}
                    memory.push(expr[i]);
                }
            } else {
                postfix += expr[i];
            }
        }
        while (!(memory.is_empty()))
            postfix += memory.pop();
        return postfix;
    }
    string get_prefix(string expr) {
        return reverse(get_postfix(reverse(expr)));
    }
};


int main () {
    Converter converter;
    string expression = "a+b*c^(d-f/g)*h-i";
    cout << converter.get_postfix(expression) << endl;
    cout << converter.get_prefix(expression) << endl;
    return 0;
}