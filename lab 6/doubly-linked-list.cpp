// WRITE AN ALGORITHM AND PROGRAM FOR FOLLOWING CASES IN DOUBLY LINEAR LINKED LIST:
//     1.	INSERTION OPERATIONS
//         a.	INSERT NODE AT BEGINNING OF THE LIST
//         b.	INSERT NODE AT END OF THE LIST
//         c.	INSERT NODE AFTER SPECIFIC NODE
//         d.	INSERT NODE BEFORE SPECIFIC NODE

//     2.	DELETION OPERATIONS
//         a.	DELETE NODE FROM BEGINNING OF THE LIST
//         b.	DELETE NODE FROM END OF THE LIST
//         c.	DELETE NODE AFTER SPECIFIC NODE
//         d.	DELETE NODE BEFORE SPECIFIC NODE

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    double data;
    Node* prev;
    Node* next;
};

class LinkedList {
    private:
    Node* head;  // pointer to head node.

    public:
    // Constructor
    LinkedList() {
        head = NULL;
    }

    Node* GetNewNode(double x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->prev = NULL;
        newNode->next = NULL;
        return newNode;
    }

    void InsertAtHead(double x) {
        Node* newNode = GetNewNode(x);
        if (head == NULL) {
            head = newNode;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    void InsertAtTail(double x) {
        Node* temp = head;
        Node* newNode = GetNewNode(x);
        if (head == NULL) {
            head = newNode;
            return;
        }
        while (temp->next != NULL) temp = temp->next;  // Go to last node.
        temp->next = newNode;
        newNode->prev = temp;
    }

    void InsertAfter(int index, double x) {
        Node* prevNode = head;
        for (int i = 0; i < index; i++) {
          prevNode = prevNode -> next;
        }
        if (prevNode == NULL) {
            cout << "the given previous node cannot be NULL" << endl;
            return;
        }
        Node* newNode = GetNewNode(x);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        if (newNode->next != NULL) newNode->next->prev = newNode;
    }

    void InsertBefore(int index, double x) {
        Node* nextNode = head;
        for (int i = 0; i < index; i++) {
          nextNode = nextNode -> next;
        }
        if (nextNode == NULL) {
            cout << "the given next node cannot be NULL" << endl;
            return;
        }
        Node* newNode = GetNewNode(x);
        newNode->prev = nextNode->prev;
        nextNode->prev = newNode;
        newNode->next = nextNode;
        if (newNode->prev != NULL) newNode->prev->next = newNode;
        else head = newNode;
    }

    void DeleteAtHead() {
        Node* temp = head;
        if (head == NULL) return;  // empty list
        if (head->next != NULL) head->next->prev = NULL;
        head = head->next;
        delete temp;
    }

    void DeleteAtTail() {
        Node* temp = head;
        if (head == NULL) return;  // empty list
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        while (temp->next != NULL) temp = temp->next;  // Go to last node.
        temp->prev->next = NULL;
        delete temp;
    }


    void DeleteAfter(int index) {
        Node* prevNode = head;
        for (int i = 0; i < index; i++) {
          prevNode = prevNode -> next;
        }
        if (prevNode == NULL || prevNode->next == NULL) return;
        Node* temp = prevNode->next;
        prevNode->next = temp->next;
        if (temp->next != NULL) temp->next->prev = prevNode;
        delete temp;
    }

    void DeleteBefore(int index) {
        Node* nextNode = head;
        for (int i = 0; i < index; i++) {
          nextNode = nextNode -> next;
        }
        if (nextNode == NULL || nextNode->prev == NULL) return;
        Node* temp = nextNode->prev;
        nextNode->prev = temp->prev;
        if (temp->prev != NULL) temp->prev->next = nextNode;
        else head = nextNode;
        delete temp;
    }
    void print() {
        Node* temp = head;
        if (temp == nullptr) return;
        while (temp != nullptr) {
          cout << temp -> data << " ";
          temp = temp -> next;
        }
        cout << endl;
    }
};

// int main () {
//     LinkedList* list = new LinkedList();
//     list -> InsertAtHead(12);
//     list -> InsertAtHead(11);
//     list -> InsertAtTail(13);

//     list -> print();

//     list -> InsertAfter(1, 12.5);
//     list -> InsertBefore(3, 12.7);

//     list -> print();

//     list -> DeleteAtHead();
//     list -> DeleteAtTail();

//     list -> print();

//     list -> DeleteAfter(1);
//     list -> DeleteBefore(1);

//     list -> print();

//     return 0;
// }

int main () {
    LinkedList* list = new LinkedList();
    cout << "Doubly Linear Linked List" << endl;
    char entered;
    double data;
    int index;
    while (true)
    {
        cout << "Enter the numbers for action:" << endl
            << "1. Insert at head" << endl
            << "2. Insert at tail" << endl
            << "3. Insert after index" << endl
            << "4. Insert before index" << endl
            << "5. Delete at head" << endl
            << "6. Delete at tail" << endl
            << "7. Delete after index" << endl
            << "8. Delete before index" << endl;
        cin >> entered;
        switch (entered)
        {
        case '1':
            cin >> data;
            list -> InsertAtHead(data);
            break;
        case '2':
            cin >> data;
            list -> InsertAtTail(data);
            break;
        case '3':
            cout << "Data then Index: ";
            cin >> data;
            cin >> index;
            list -> InsertAfter(index, data);
            break;
        case '4':
            cout << "Data then Index: ";
            cin >> data;
            cin >> index;
            list -> InsertBefore(index, data);
            break;
        
        case '5':
            list -> DeleteAtHead();
            break;
        case '6':
            list -> DeleteAtTail();
            break;
        case '7':
            cout << "Index: ";
            cin >> index;
            list -> DeleteAfter(index);
            break;
        case '8':
            cout << "Index: ";
            cin >> index;
            list -> DeleteBefore(index);
            break;
        case '9':
            list -> print();
            break;
        
        default:
            exit(0);
        }
    }
    
    return 0;
}