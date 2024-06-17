#include<iostream>
using namespace std;
#include <bits/stdc++.h> 

    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };
void solve(TreeNode<int>* root,vector<int> &v){
    if(root==NULL){
        return;
    }
    solve(root->left,v);
    v.push_back(root->data);
    solve(root->right,v);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> v;
    solve(root,v);
    TreeNode<int>* newtree = new TreeNode<int>(v[0]);

    TreeNode<int>* curr = newtree;

    for(int i =1;i<v.size();i++){
        TreeNode<int>* temp = new TreeNode<int>(v[i]);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;

    return newtree;
}
