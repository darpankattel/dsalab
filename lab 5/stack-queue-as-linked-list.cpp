// WRITE AN ALGORITHM AND PROGRAM FOR THE FOLLOWING:
// 1.	IMPLEMENT STACK AS LINKED LIST

// 2.	IMPLEMENT QUEUE AS LINKED LIST

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class Node {
    public:
    T data;
    Node<T>* next;

    Node(T d) {
        data = d;
        next = nullptr;
    }
};

template <class T>
class LinkedList {
    public:
    Node<T>* head;
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    T deleteFromBeginning() {
        if (head == nullptr) {
            return head->data;
        }
        T temp = head->data;
        head = head->next;
        return temp;
    }

    T deleteFromEnd() {
        if (head == nullptr) {
            return head->data;
        }
        Node<T>* current = head;
        if (head->next == nullptr) {
            head = nullptr;
            return current->next->data;
        }
        while (current->next->next != nullptr) {
            current = current->next;
        }
        T temp = current->next->data;
        current->next = nullptr;
        return temp;
    }

    void print () {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

template <class T>
class Stack {
    private:
    LinkedList<T>* list;

    public:
    Stack () {
        list = new LinkedList<T>();
    }
    void push (T d) {
        return list->insertAtEnd(d);
    }
    T pop () {
        return list->deleteFromEnd();
    }
    void print () {
        cout << "Inside print stack" << endl;
        list->print();
    }
};

template <class T>
class Queue {
    private:
    LinkedList<T>* list;

    public:
    Queue () {
        list = new LinkedList<T>();
    }
    void enqueue (T d) {
        return list->insertAtEnd(d);
    }
    T dequeue () {
        return list->deleteFromBeginning();
    }
    void print () {
        cout << "Inside print queue" << endl;
        list->print();
    }
};

int main () {
    Stack<double>* memory = new Stack<double>();
    memory->push(1);
    memory->push(2);
    memory->push(3);
    memory->print();
    memory->pop();
    memory->pop();
    memory->print();

    Queue<double>* my_q = new Queue<double>();
    my_q->enqueue(1);
    my_q->enqueue(2);
    my_q->enqueue(3);
    my_q->print();
    my_q->dequeue();
    my_q->dequeue();
    my_q->print();
    return 0;
}