#include<iostream>
using namespace std;
#include<queue>
class node{
    public:
        int data;
        node* left;
        node* right;

        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;

        }
};
node* treebuild(node* root){
    int data;
    cout << "Enter the value of data" << endl;
    cin >> data;
    root = new node(data);
    if(data==-1){
        return NULL;
    }
    cout << "Enter the value of left side of data" <<endl;
    root->left = treebuild(root->left);
    cout << "Enter the right side of the data" << endl;
    root->right = treebuild(root->right);
    return root;
}
node* levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();


        if(temp==NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
            q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
    }
    
}
void inordertraversal(node* root){
    if(root==NULL){
        return;
    }
    
    inordertraversal(root->left);
    cout << root->data << " ";
    inordertraversal(root->right);
}
void preordertraversal(node* root){
    if(root==NULL){
        return;
    }
    cout << root->data << " ";
    inordertraversal(root->left);
    inordertraversal(root->right);
}
void postordertraversal(node* root){
    if(root==NULL){
        return;
    }
    
    inordertraversal(root->left);
    inordertraversal(root->right);
    cout << root->data << " ";
}
void buildFromLevelOrder(node* &root){
    queue<node*> q;
    int data;
    cout << "Enter the data to be entered into the root" <<endl;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter the left node for the data" <<endl;
        int leftnode;
        cin >> leftnode;
        if(leftnode!=-1){
            temp->left = new node(leftnode);
            q.push(temp->left);
        }
        cout << "Enter the data for the right node" << endl;
        int rightnode;
        cin >> rightnode;
        if(rightnode!=-1){
            temp->right = new node(rightnode);
            q.push(temp->right);
        }
    }
    }
int main(){
    node* root = NULL;
    root = treebuild(root);
    // data - 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTraversal(root);
    preordertraversal(root);
    postordertraversal(root);
    inordertraversal(root);
}