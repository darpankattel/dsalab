// LINKED LIST:
// WRITE AN ALGORITHM AND PROGRAM FOR FOLLOWING CASES IN SINGLY LINEAR LINKED LIST:
// 1.	INSERTION OPERATIONS
//      a.	INSERT NODE AT BEGINNING OF THE LIST
//      b.	INSERT NODE AT END OF THE LIST
//      c.	INSERT NODE AFTER SPECIFIC NODE
//      d.	INSERT NODE BEFORE SPECIFIC NODE

// 2.	DELETION OPERATIONS
//      a.	DELETE NODE FROM BEGINNING OF THE LIST
//      b.	DELETE NODE FROM END OF THE LIST
//      c.	DELETE NODE AFTER SPECIFIC NODE

#include <iostream>
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
    void set_next(Node<T>* n) {
        next = n;
    }
};

template <class T>
class LinkedList {
    public:
    Node<T>* head;
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data) {
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

    void insertAfter(int data, Node<T>* prev) {
        if (prev == nullptr) {
            std::cout << "Previous node cannot be null" << std::endl;
            return;
        }
        Node<T>* newNode = new Node<T>(data);
        newNode->next = prev->next;
        prev->next = newNode;
    }

    void insertBefore(int data, Node<T>* next) {
        if (next == nullptr) {
            std::cout << "Next node cannot be null" << std::endl;
            return;
        }
        Node<T>* newNode = new Node<T>(data);
        if (head == next) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node<T>* current = head;
        while (current->next != next) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            return;
        }
        head = head->next;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            head = nullptr;
            return;
        }
        Node<T>* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        current->next = nullptr;
    }

    void deleteAfter(Node<T>* prev) {
        if (prev == nullptr || prev->next == nullptr) {
            return;
        }
        prev->next = prev->next->next;
    }

    void printList() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList<double> list;

    // Inserting nodes
    list.insertAtBeginning(3);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAfter(2.5, list.head->next);
    list.insertBefore(1.5, list.head->next->next);

    // Printing the list
    std::cout << "Linked list: ";
    list.printList();

    // Deleting nodes
    list.deleteFromBeginning();
    list.deleteFromEnd();
    list.deleteAfter(list.head->next);

    // Printing the list
    std::cout << "Linked list after deletions: ";
    list.printList();

    return 0;
}
