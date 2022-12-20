// 3.	Perform operations in Deque( Double ended queue) for:
//      a.	Add at beginning
//      b.	Add at end
//      c.	Delete from beginning
//      d.	Delete from end

#include <iostream>
using namespace std;

template <class T>
class DQ {
    private:
    const int size;
    int front, rear;
    T* items;

    public:
    class Exceptions {
        public:
        class Overflow {};
        class Underflow {};
    };
    DQ (int s): size(s) {
        items = new T[size];
        front = -1;
        rear = 0;
    }
    void insert (T elem, bool at_rear = true) {
        if (is_full()) throw typename Exceptions::Overflow();
        if (at_rear) {
            if (front == -1) {
                front = 0;
                rear = 0;
            }
            else if (rear == size - 1)
                rear = 0;
            else
                rear++;
            items[rear] = elem;
        } else {
            if (front == -1) {
                front = 0;
                rear = 0;
            }
            else if (front == 0)
                front = size - 1;
            else
                --front;
            items[front] = elem;
        }
    }
    T remove (bool at_rear = true) {
        if (is_empty()) throw typename Exceptions::Underflow();
        if (at_rear) {
            T elem = items[rear];
            if (front == rear) {
                front = -1;
                rear = 0;
            } else if ((rear == 0) && (rear < front)) {
                rear = size - 1;
            }
            else {
                --rear;
            }
            return elem;
        } else {
            T elem = items[front];
            if (front == rear) {
                front = -1;
                rear = 0;
            } else if ((front == size - 1) && (rear < front)) {
                front = 0;
            }
            else {
                ++front;
            }
            return elem;
        }
    }
    bool is_empty () {
        return (front == -1);
    }
    bool is_full () {
        return ((front == 0 && rear == size - 1) || (front == rear + 1));
    }
    // for JUST checking
    void print () {
        // cout << "Inside print\nPrinting from " << front << " to " << rear << endl;
        int i = front;
        if (front < rear) {
            while (i <= rear) {
                cout << i << ". " << items[i] << endl;
                i++;
            }
        } else {
            while (i != rear) {
                cout << i << ". " << items[i] << endl;
                if (i == size - 1) {
                    i = 0;
                } else {
                    i++;
                }
            }
            cout << i << ". " << items[i] << endl;
        }
    }
};

int main () {
    DQ<int> queue(5);
    queue.insert(100);
    queue.insert(200);
    queue.insert(300, false);
    queue.insert(400, false);
    queue.insert(500);
    queue.print();
    cout << queue.remove(false) << endl;
    cout << queue.remove() << endl;
    cout << queue.remove(false) << endl;
    cout << queue.remove() << endl;
    cout << queue.remove(false) << endl;
    return 0;
}