#include<iostream>
using namespace std;
class Trienode{
    public:
    char data;
    Trienode* children[26];
    bool isTerminal;
    Trienode(char ch){
        data = ch;
        for(int i = 0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }

};
class Trie{
    public:
    Trienode* root;
    Trie(){
        root = new Trienode('\0');
    }
    void insertUtil(Trienode* root,string word){
        if(word.length()==NULL){
            root->isTerminal = true;
            return;
        }
        //assuming only in caps
        int index = word[0] - 'A';
        Trienode* child;
        //present
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        //absent
        else{
            child = new Trienode(word[0]);
            root->children[index] = child;
        }
        //recursion

        insertUtil(child,word.substr(1));

    }
    void insertWord(string word){
        insertUtil(root,word);

    }
    bool searchUtil(Trienode* root,string word){
        //base case
        if(word.length()==0){
            return root->isTerminal;
        }
        //initialisation
        Trienode* child;
        int index = word[0] - 'A';
        //present
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        // absent
        else{
            return false;
        }
        searchUtil(child,word.substr(1));
    }
    bool searchword(string word){
        searchUtil(root,word);
    }
};
int main(){
    Trie* t = new Trie();
    t->insertWord("abcd");

    cout << "Present or not " << t->searchword("abcd");

}