// 2.	Perform enqueue and dequeue operations in Circular Queue

#include <iostream>
using namespace std;

template <class T>
class CQ {
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
    CQ (int s): size(s) {
        items = new T[size];
        front = -1;
        rear = -1;
    }
    ~CQ () {
        delete []items;
    }
    void enqueue (T elem) {
        // check if overflow
        if (is_full()) {
            throw typename Exceptions::Overflow();
        }
        if (front < 0)
            front = 0;
        rear = (rear + 1) % size;
        items[rear] = elem;
    }
    T dequeue () {
        // check if underflow
        if (is_empty()) {
            throw typename Exceptions::Underflow();
        }
        T elem = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return elem;
    }
    bool is_empty () {
        // return rear < front;
        return front == -1;
    }
    bool is_full () {
        return ((front == 0) && (rear == size - 1)) || (front == rear + 1);
        // return current_size() == size; // Not good option
    }
};

int main () {
    CQ<int>* queue = new CQ<int>(10);
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
    cout << queue->is_full() << endl;

    return 0;
}