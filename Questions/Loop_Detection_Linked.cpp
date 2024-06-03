#include<iostream>
#include <map>
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
bool loopdeterction(Node* head){
    if(head==NULL){
        return false;
    }
    map<Node*,bool> visited;
    Node* temp=head;
    while(temp!=NULL ){
        if(visited[temp]==true){
            return true;
        }
        visited[temp]=true;
        temp = temp ->next;
    }
    return false;
}

int main(){
    Node* newnode = new Node(10);
}