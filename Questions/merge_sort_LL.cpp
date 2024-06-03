// que - merge sort on a linked list -   coding ninjas;
// https://www.naukri.com/code360/problems/mergesort-linked-list_630514?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_CodestudioLovebabbar5thfeb&leftPanelTabValue=PROBLEM


#include<iostream>
using namespace std;

    
    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };

node* findmid(node* head){
    node* slow = head;
    node* fast = head->next;
    while(fast!=NULL && fast -> next !=NULL){
        slow = slow->next;
        fast  = fast ->next ->next;
    }
    return slow;
    
}
node* merge(node* left,node* right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    node* ans = new node(-1);
    node* temp = ans;
    while(left!=NULL && right!=NULL){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;

        }
        
    }
    while(left!=NULL){
             temp->next = left;
            temp = left;
            left = left->next;
        }
        while(right!=NULL){
            temp->next = right;
            temp=right;
            right=right->next;
        }
        ans=ans->next;
        return ans;
        
}
node* mergeSort(node *head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* mid = findmid(head);
    node* left = head;
    node* right = mid ->next;
    mid->next=NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    node* result = merge(left,right);

    return result;
}
