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
    Stack (int);
    void push (T);
    T pop ();
    int peek ();
};
