#include<iostream>
using namespace std;


class TrieNode{
    public:
    char data;
    TrieNode ** children;
    bool isTerminal;

    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for( int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal = false;
    }
};


class Trie{
    TrieNode * root;
    public:

    Trie(){
        root = new TrieNode('\0');
    }

    void insertHelper(TrieNode * root , string word){
        if(word.length()==0){
            root->isTerminal=true;
        }
        int index = word[0]-'a';
        if(root->children[index]!=NULL){
            insertHelper(root->children[index],word.substr(1));
        }
        else{
            TrieNode * newNode = new TrieNode(word[0]);
            root->children[index] = newNode;
            insertHelper(newNode, word.substr(1));
        }
    }
    void insert(string word){
        insertHelper(this->root,word);
    }

    void deleteWordHelper(TrieNode * root , string word){
        if(word.length()==0){
            if(root->isTerminal==true){
                root->isTerminal=false;
            }
        }
        int index = word[0]-'a';
        if(root->children[word[0]-'a']!=NULL){
            deleteWordHelper(root->children[word[0]-'a'],word.substr(1));
        }
        else return;

        for (int x =0;x<26 ;x++){
            if(root->children[index]->children[x]!=NULL){
                return;
            }
        }
        delete root->children[index];
        root->children[index]=NULL;
    }

    void deleteWord(string word){
        deleteWordHelper(root , word);
    }
      bool searchHelper(TrieNode * root , string word){
        if(word.length()==0){
            if(root->isTerminal==true)return true;
            else return false;
        }
        
        if(root->children[word[0]-'a']!=NULL){
            return searchHelper(root->children[word[0]-'a'],word.substr(1));
        }
        else return false;
        
        
        
    }
    
    bool search(string word) {
       return searchHelper(root, word);
        
    }
};

int main(){
    Trie T;
    T.insert("anurag");
    if(T.search("anurag"))cout<<"found \n";
    return 0;
}