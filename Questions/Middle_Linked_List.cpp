#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

int getlength(Node* head){
    int count = 0;
    while(head!=NULL){
        
        head=head->next;
        count++;
    }
    return count;
}

Node *findMiddle(Node *head) {
    int len = getlength(head);
    int mid=len/2;
    Node* temp =head;
    int count=0;
    while(count<mid){
        temp = temp->next;
        count++;
    }
    return temp;

}

