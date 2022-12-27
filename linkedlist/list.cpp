#include <iostream>
using namespace std;

template <class T>
class Node {
    private:
    T data;
    Node* next;

    public:
    Node(T d) : data(d) {}
    void set_next (Node* n) {
        next = n;
    }
    Node* get_next() {
        return next;
    }
    T get_data() {
        return data;
    }
};

template <class T>
class LinkedList {
    private:
    Node<T>* head;

    public:
    LinkedList(Node<T>* h) {
        head = h;
    }
};

template <class T>
LinkedList<T>* get_linked_list(T arr[]) {
    return LinkedList(Node n(2));
}

int main () {
    Node<int>* first = new Node<int>(1);
    // int arr[] = ;
    LinkedList<int>* list = get_linked_list<int>({1, 5, 8, 3, 6});

    return 0;
}