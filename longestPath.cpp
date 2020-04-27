#include <iostream>
#include <vector>
#include <queue>

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

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int height(BinaryTreeNode<int> * root){
    if(root==NULL){
        return 0;
    }
    
    int rightHeight = height(root->right);
    int leftHeight = height(root->left);

    if(rightHeight >= leftHeight) return 1+rightHeight;
    else return 1+leftHeight;
}

void fillVector(BinaryTreeNode<int> * root, vector<int> * path ){
    
    path->push_back(root->data);
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    if(rightHeight>=leftHeight) fillVector(root,path);
    else fillVector(root, path);
}

vector<int>* longestPath(BinaryTreeNode<int>* root) {
    vector<int> * path = new vector<int>;
    if(root==NULL) return path;
    fillVector(root, path);
    return path;

}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<int> *output = longestPath(root);
    vector<int> :: iterator i = output -> begin();
    while(i != output -> end()) {
    	cout << *i << endl;
    	i++;
    }
}