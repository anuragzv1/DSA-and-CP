#include<iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
    public :
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this -> data = data;
        children = new TrieNode*[26];
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

    public :
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if(word.size() == 0) {
            if (!root->isTerminal) {
                root -> isTerminal = true;
                return true;	
            } else {
                return false;
            }
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    // For user
    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

    void printToLeaves(TrieNode * root , string pattern){
        string temporary = pattern;
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL){
                if(root->children[i]->isTerminal == true){
                    temporary +=root->children[i]->data;
                    cout<<temporary<<endl;
                    printToLeaves(root->children[i], temporary);
                }
                else{
                    temporary +=root->children[i]->data;
                    printToLeaves(root->children[i], temporary);
                    
                }
            }
        } 
        return;
    }

    void autoCompleteHelper(TrieNode * root , string pattern, string unchanged){
        if(pattern.length()==0){
            TrieNode * newRoot = root;
            cout<<unchanged;

            printToLeaves(newRoot , unchanged);
        }

        if(root->children[pattern[0]-'a']!=NULL){
            autoCompleteHelper(root->children[pattern[0]-'a'],pattern.substr(1), unchanged);
        }
        else return;

    }

    void autoComplete(vector<string> input, string pattern) {

        for (int i=0;i<input.size();i++){
            this->insertWord(input[i]);
        }
        autoCompleteHelper(root,pattern, pattern);
    }

};

int main() {
	Trie t;
    int N;
    cin >> N;
    string pattern;
    vector<string> vect;
    for (int i=0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;
    t.autoComplete(vect, pattern);
}
