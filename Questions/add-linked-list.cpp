#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    private:
    Node* reverse(Node* head) {
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void insertAtTail(struct Node* &head, struct Node* &tail, int val) {
        
        Node* temp = new Node(val);
        //empty list
        if(head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail -> next = temp;
            tail = temp;
        }
    }
    
    struct Node* add(struct Node* first, struct Node* second) {
        int carry = 0;
        
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0) {
            
            
            int val1 = 0;
            if(first != NULL)
                val1 = first -> data;
                
            int val2 = 0;
            if(second !=NULL)
                val2 = second -> data;
            
            
            int sum = carry + val1 + val2;
            
            int digit = sum%10;
            
            //create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            if(first != NULL)
                first = first -> next;
            
            if(second != NULL)
                second = second -> next;
        
        }
        return ansHead;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct  Node* addTwoLists(Node* first, Node* second) {
        // If one of the linked lists is empty, return the other one.
        if (first == nullptr) return second;
        if (second == nullptr) return first;

        // Reverse input linked lists.
        first = reverse(first);
        second = reverse(second);
        
        // Add two reversed linked lists.
        Node* result = add(first, second);
        
        // Reverse the result linked list.
        result = reverse(result);
        
        // Remove leading zeros
        while (result->next != nullptr && result->data == 0) {
            Node* temp = result;
            result = result->next;
            delete temp; // Free memory of leading zeros
        }
        
        return result;
    }
};