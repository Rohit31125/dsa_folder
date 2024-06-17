#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    private:
    int findposition(int in[],int element,int instart,int inend,int n){
        for(int i=instart;i<=inend;i++){
            if(in[i]==element){
                return i;
            }
        }
        return -1;
    }
    Node* solve(int in[],int post[],int &postindex,int instart,int inend,int n){
        if(postindex<0 || instart>inend){
            return NULL;
        }
        int element = post[postindex--];
        Node* root = new Node(element);
        int position = findposition(in,element,instart,inend,n);
        root->right = solve(in,post,postindex,position+1,inend,n);
        root->left  = solve(in,post,postindex,instart,position-1,n);
        
        return root;
    }
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        int postorderindex = n-1;
        Node* ans = solve(in,post,postorderindex,0,n-1,n);
        return ans;
    }
};