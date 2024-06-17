#include <bits/stdc++.h> 
#include<iostream>
using namespace std;
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
    
};

void solve(BinaryTreeNode<int>* root,vector<int> &v){
    if(root==NULL){
        return;
    }
    solve(root->left,v);
    v.push_back(root->data);
    solve(root->right,v);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> v;
    solve(root,v);

    int i = 0;
    int j = v.size()-1;

    while(i<j){
        int sum = v[i] + v[j];
        if(sum==target){
            return true;
        }  
        else if(sum > target){
            j--;
        }
        else{
            i++;
        }

          }
          return false;
}