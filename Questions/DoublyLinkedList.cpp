#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;

    }
};
void print(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            cout << temp -> data << " ";
            temp = temp-> next;
        }
        
    }
int getLength(Node* head){
        Node* temp = head;
        int cnt = 1;
        while(temp!=NULL){
            temp = temp -> next;
            cnt++;
        }
        return cnt;
    }
void insertathead(Node* &tail,Node* &head,int d){
    if(head==NULL){
        Node* temp = new Node(d);
        head = temp;
        head = tail;
    }
    else{
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    }
}
void insertattail(Node* &head,Node* &tail,int d){
    if(head== NULL){
        Node* temp = new Node(d);
        head = temp;
        head = tail;
    }
    else{
        Node* temp = new Node(d);
        temp -> prev = tail;
        tail -> next = temp;
        tail = temp;
    }
    
}
void insertatposition(Node* &tail,Node* &head,int position,int d){
    if(position==1){
        insertathead(tail,head,d);
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count<position-1){
        temp = temp -> next;
        count++;
    }
    if(temp->next==NULL){
        insertattail(head,tail,d);
        return;
    }
    // new node
    Node* nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp ->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
    
    

}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1; 
    Node* tail = node1;
    

    getLength(head);

   

    insertathead(tail,head,23);
    print(head);

    insertattail(head,tail,5);
    print(head);

    cout << endl;

    insertatposition(tail,head,3,44);
    print(head);
    cout << endl;
    insertatposition(tail,head,2,45);
    print(head);

  
}