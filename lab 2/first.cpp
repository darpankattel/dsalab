// 1.	Perform enqueue and dequeue operations in Linear Queue  

#include <iostream>
using namespace std;

template <class T>
class Q {
    private:
    const int size;
    T* items;
    int rear, front;
    public:
    class Exceptions {
        public:
        class Overflow {};
        class Underflow {};
    };
    Q (int s): size(s) {
        items = new T[size];
        front = -1;
        rear = -1;
    }
    ~Q () {
        delete []items;
    }
    void enqueue (T elem) {
        // check if overflow
        if (is_full()) {
            throw typename Exceptions::Overflow();
        }
        if (front < 0)
            front = 0;
        items[++rear] = elem;
    }
    T dequeue () {
        // check if underflow
        if (is_empty()) {
            throw typename Exceptions::Underflow();
        }
        return items[front++];
    }
    int current_size () {
        if (rear < 0)
            return 0;
        return rear - front + 1;
    }
    bool is_empty () {
        // return rear < front;
        return current_size() == 0;
    }
    bool is_full () {
        return rear == size - 1;
        // return current_size() == size; // Not good option
    }
};

int main () {
    Q<int>* queue = new Q<int>(5);
    cout << queue->is_empty() << endl;

    queue->enqueue(100);
    cout << queue->is_empty() << endl;
    cout << queue->dequeue() << endl;
    cout << queue->is_empty() << endl;

    queue->enqueue(100);
    queue->enqueue(120);
    queue->enqueue(140);
    queue->enqueue(160);
    // queue->enqueue(180); // will raise Q::Exceptions::Overflow
    cout << queue->is_empty() << endl;
    cout << queue->current_size() << endl;
    cout << queue->is_full() << endl;

    return 0;
}