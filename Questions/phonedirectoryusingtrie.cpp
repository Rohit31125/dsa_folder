#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Trienode {
public:
    char data;
    Trienode* children[26];
    bool isTerminal;
    Trienode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    Trienode* root;
    Trie() {
        root = new Trienode('\0');
    }
    void insertUtil(Trienode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        //assuming only in lowercase
        int index = word[0] - 'a';
        Trienode* child;
        //present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        //absent
        else {
            child = new Trienode(word[0]);
            root->children[index] = child;
        }
        //recursion
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word) {
        insertUtil(root, word);
    }

    void printSuggestions(Trienode* curr, vector<string> &temp, string prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            Trienode* next = curr->children[ch - 'a'];
            if (next != NULL) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str) {
        Trienode* prev = root;
        string prefix = "";
        vector<vector<string>> output;

        for (int i = 0; i < str.length(); i++) {
            char lastch = str[i];
            prefix.push_back(lastch);

            Trienode* curr = prev->children[lastch - 'a'];
            if (curr == NULL) {
                break;
            }
            vector<string> temp;
            printSuggestions(curr, temp, prefix);
            output.push_back(temp);
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>& contactList, string &queryStr) {
    Trie* t = new Trie();
    for (int i = 0; i < contactList.size(); i++) {
        string str = contactList[i];
        t->insertWord(str);
    }
    return t->getSuggestions(queryStr);
}