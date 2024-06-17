#include<iostream>
using namespace std;
#include<vector>

    template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

void inorder(TreeNode<int>* root,vector<int> &v){
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
TreeNode<int>* inorderBST(int s,int e,vector<int> &v){
    if(s>e){
        return NULL;
    }
     int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(v[mid]);
   
    root->left = inorderBST(s, mid-1,v);
    root->right=inorderBST(mid+1,e, v);
    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> v;
    inorder(root,v);
    int s = 0;
    int e = v.size()-1;

    return inorderBST(s,e,v);
}
