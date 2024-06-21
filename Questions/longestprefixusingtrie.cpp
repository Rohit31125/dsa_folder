
#include<iostream>
using namespace std;

class Trienode{
    public:
    char data;
    bool isTerminal;
    Trienode* children[26];
    int childcount;
    Trienode(char ch){
        data = ch;

        for(int i = 0;i<26;i++){
            children[i]=NULL;

        }
        isTerminal =  false;
        childcount = 0;
    }
};
class Trie{
    public:
    Trienode* root;

    Trie(char ch){
        root = new Trienode(ch);
    }
    void insertUtil(Trienode* root,string word){
    if(word.size()==0){
        root->isTerminal= true;
        return;
    }
    int index = word[0] - 'a';
    Trienode* child;
    if(root->children[index]!=NULL){
        child = root->children[index];

    } else {
        child = new Trienode(word[0]);
        root->childcount++;
        root->children[index] = child;
    }
    insertUtil(child, word.substr(1));
}
    void insert(string word){
        insertUtil(root,word);
    }
    void lcp(string str,string &ans){
        Trienode* temp = root;
        for(int i = 0;i<str.length();i++){
            char ch = str[i];

            if(temp->childcount==1){
                ans.push_back(ch);
                //move forward
                int index =  ch - 'a';
                temp = temp->children[index];

            }
            else{
                break;
            }
            if(temp->isTerminal){
                break;
            }
        }
    }


};
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    Trie* t = new Trie('0');
     string first = arr[0];
    for(int i = 0;i<n;i++){
         if(arr[i].empty()) // missing check to return in cases where the string is empty

            return ""; 
        t->insert(arr[i]);
        
    }
   
    string ans = "";

    t->lcp(first,ans);
    return ans;
    
}


