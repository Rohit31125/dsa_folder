/// code 360 problem -- find the number of leaf node

#include<iostream>
using namespace std;

    template <typename T>
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
    

void inorder(BinaryTreeNode<int> *root,int &count){
    if(root==NULL){
        return;
    }
    inorder(root->left,count);
    inorder(root->right,count);
    if(root->left==NULL && root->right==NULL ){
        count++;
    }
  


}
int noOfLeafNodes(BinaryTreeNode<int> *root){
     int count = 0;
    inorder(root,count);
    return count;
}
