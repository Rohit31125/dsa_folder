#include<iostream>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
class Solution{
  private:
  Node* findmiddle(Node* head){
      Node* fast = head->next;
      Node* slow = head;
      while(fast!=NULL && fast->next!=NULL){
          fast=fast->next->next;
          slow=slow->next;
      }
      return slow;   
  }
  Node* reverse(Node* head){
      Node* prev = NULL;
      Node* next = NULL;
      Node* temp = head;
      while(temp!=NULL){
          next= temp->next;
          temp->next = prev;
          prev= temp;
          temp=next;
      }
      return prev;
  }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node* middle = findmiddle(head);
        Node* nextnode = middle->next;
        middle->next = reverse(nextnode);
        Node* head1 = head;
        Node* head2 = middle->next;
        while(head2!=NULL){
            if(head2->data!=head1->data){
                return false;
            }
            head2=head2->next;
            head1=head1->next;
        }
        return true;
    }
};