// construct tree from inorder and preorder gfg ----medium level question

#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
};

class Solution{

    int findelement(int in[],int element,int instart,int inend){
        for(int i=instart;i<=inend;i++){
            if(in[i]==element){
                return i;
            }
            
        }
        return -1;
    }
    Node* solve(int in[],int pre[],int &preindex,int instart,int inend,int n){
        if(preindex>=n || instart>inend){
            return NULL;
        }
        int element = pre[preindex++];
        Node* root = new Node(element);
        int position = findelement(in,element,instart,inend);
         if (position == -1) {
         
             return NULL;
         }
        
        root->left = solve(in,pre,preindex,instart,position-1,n);
        root->right = solve(in,pre,preindex,position+1,inend,n);
        
        return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preorderindex = 0;
        Node* ans = solve(in,pre,preorderindex,0,n-1,n);
        return ans;
        
    }
};