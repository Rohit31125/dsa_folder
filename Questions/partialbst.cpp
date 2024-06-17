#include<iostream>
using namespace std;
#include <bits/stdc++.h> 

 


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
bool solve(BinaryTreeNode<int> *root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->data >= min && root->data <= max){
        bool left = solve(root->left,min,root->data);
        bool right = solve(root->right,root->data,max);
            return left && right;
    }
    else{
        return false;
    }

}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return solve(root,INT_MIN,INT_MAX);

}