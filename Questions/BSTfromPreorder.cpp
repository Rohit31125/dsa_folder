#include<iostream>
using namespace std;
#include <bits/stdc++.h> 
#include<vector>

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

BinaryTreeNode<int>* solve(vector<int> &preorder,int max,int &i){
    if(i>=preorder.size()){
        return NULL;
    }
    if(preorder[i]>max){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);
    root->left = solve(preorder,root->data,i);
    root->right = solve(preorder,max,i);

    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int max = INT_MAX;
    int i = 0;
    return solve(preorder,max,i);
}