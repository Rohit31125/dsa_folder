// code studio problem -----Reverse linked list(solves using recursion)

#include <bits/stdc++.h>



    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
   

 void reverse(LinkedListNode<int>* &head,LinkedListNode<int>* &prev,LinkedListNode<int>* &curr){
        if(curr==NULL){
            head = prev;
            return;
        }
        LinkedListNode<int>* forward = curr -> next;
        reverse(head,curr,forward);
        curr->next=prev;

    }

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
   
    LinkedListNode<int>* prev  = NULL;
    LinkedListNode<int>* forward = NULL;
    LinkedListNode<int>* curr = head;
    reverse(head,prev,curr);
    
    
    return head;
    
}