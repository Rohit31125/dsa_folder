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


class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        if(node==NULL){
            return 0;
            
        }
        int leftheight = height(node->left);
        int rightheight = height(node->right);
        int ans = max(leftheight,rightheight) + 1;
        return ans;
    }
};