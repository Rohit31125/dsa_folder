#include<iostream>
using namespace std;

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };


TreeNode<int> convertintoDLL(TreeNode* root1,TreeNode* head){
    if(head==NULL){
        return = NULL;
    }
    convertintoDLL(root->right, head);
    root->right = head;
    if(head!=NULL){
        head->left = root;
        
    }
    root=head;
    convertintoDLL(root->left,head);
}
TreeNode<int> mergelinkedlist(TreeNode* head1,TreeNode* head2){
     TreeNode<int>* head= NULL;
    TreeNode<int>* tail = NULL;

    while(head1!=NULL && head2!=NULL ){
        if(head1->data < head2->data){
            if(head==NULL){
                head = head1;
                tail=head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1=head1->right;
            }
        }
        else{
            if(head==NULL){
                head= head2;
                tail = head2;
                head2=head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        
    }

    }
        while(head1!=NULL){
         tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
    }
      while(head2!=NULL){
         tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
    }
    return head;
}
int NoofNodes(TreeNode<int>* head){
    int count = 0;
    TreeNode<int>* temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->right;
    }
    return count;
}
TreeNode<int>* linkedlisttoBST(TreeNode<int>* head,int n){
    if(n<=0 || head==NULL){
        return NULL;
    }
    TreeNode<int>* left =  linkedlisttoBST(head,n/2);

    TreeNode<int>* root = head;
    root->left =left;
    head = head->next;

    root->right = linkedlisttoBST(head,n-n/2-1);

    return root;
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
   TreeNode<int>* head1 = NULL;
   TreeNode<int>* head2 = NULL;
   convertintoDLL(root1,head1);
   convertintoDLL(root2,head2);
   TreeNode<int>* head = mergelinkedlist(head1,head2);
   
   int count = NoofNodes(head);
   linkedlisttoBST(head,count);
   
    
}