#include<iostream>
using namespace std;

    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };


Node* floydDetection(Node* head){
    if(head==NULL){
        return NULL;
    }
    
    Node* fast = head;
    Node* slow =  head;
    while(fast!=NULL && slow!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(fast==slow){
            return slow;
        }
    }
    return NULL;
}
Node* gettingstartnode(Node* head){
    if(head==NULL){

        return NULL;
    }
    Node* intersection = floydDetection(head);
    if (intersection==NULL){
        return NULL;
    }
    Node* slow = head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
Node *removeLoop(Node *head)
{
    if(head==NULL){
        return NULL;
    }
    Node* startingloop = gettingstartnode(head);
    if(startingloop==NULL){
        return head;
    }
    Node* temp  = startingloop;
    while(temp->next!=startingloop){
        temp=temp->next;
    }
    temp->next = NULL;
    return head;
}