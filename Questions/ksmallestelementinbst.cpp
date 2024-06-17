#include <bits/stdc++.h> 
#include<iostream>
using namespace std;
 
// coding studio probelm of finding the kth smallest element in the bst

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


int solve(BinaryTreeNode<int>* root,int &i,int k){
    if(root==NULL){
        return -1;
    }
    
    // in order traversal in LNR format
    int left = solve(root->left,i,k);
    if(left!=-1){
        return left;
    }
    //check for i
    i++;
    if(i==k){
        return root->data;
    }

    int right = solve(root->right,i,k);


}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i = 0;
    int ans = solve(root,i,k);
    return ans;
}