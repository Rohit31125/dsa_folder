// Linked list problem on codestudios-----Reverse Linked List(solved using iterative method)

#include<iostream>
using namespace std;
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


LinkedListNode<int> * reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head==NULL || head->next == NULL){
        return head;
    }
    LinkedListNode<int>* prev  = NULL;
    LinkedListNode<int>* forward = NULL;
    LinkedListNode<int>* curr = head;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
    
}