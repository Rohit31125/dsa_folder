#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Insert data at the head of the linked list
void InsertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Insert data at a specific position in the linked list
void InsertAtPosition(Node* &head, int position, int d) {
    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }
    Node* nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

// Print the linked list
void Print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;

    // Set head pointer to node1
    Node* head = node1;

    // Print the linked list
    Print(head);

    // Insert data at the head of the linked list
    InsertAtHead(head, 12);
    Print(head);

    // Insert data at the head of the linked list
    InsertAtHead(head, 15);
    Print(head);

    // Insert data at position 3 in the linked list
    InsertAtPosition(head, 3, 22);
    Print(head);

    return 0;
}
