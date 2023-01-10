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

using namespace std;
struct Node {
  int data;
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

  // Creates a new node and returns a pointer to it.
  Node* GetNewNode(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
  }

  // Inserts a node at the head of the linked list.
  void InsertAtHead(int x) {
    Node* newNode = GetNewNode(x);
    if (head == NULL) {
      head = newNode;
      return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
  }

  // Inserts a node at the tail of the linked list.
  void InsertAtTail(int x) {
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

  // Inserts a node after a given node.
  void InsertAfter(Node* prevNode, int x) {
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

  // Inserts a node before a given node.
  void InsertBefore(Node* nextNode, int x) {
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

  // Deletes a node from the head of the linked list.
  void DeleteAtHead() {
    Node* temp = head;
    if (head == NULL) return;  // empty list
    if (head->next != NULL) head->next->prev = NULL;
    head = head->next;
    delete temp;
  }

  // Deletes a node from the tail of the linked list.
  // Deletes a node from the tail of the linked list.
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


  // Deletes a node after a given node.
  void DeleteAfter(Node* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) return;
    Node* temp = prevNode->next;
    prevNode->next = temp->next;
    if (temp->next != NULL) temp->next->prev = prevNode;
    delete temp;
  }

  // Deletes a node before a given node.
  void DeleteBefore(Node* nextNode) {
    if (nextNode == NULL || nextNode->prev == NULL) return;
    Node* temp = nextNode->prev;
    nextNode->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = nextNode;
    else head = nextNode;
    delete temp;
  }

};
