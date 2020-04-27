#include<iostream>
using namespace std;



int level(BinaryTreeNode<int> * root , int p){


    if(root==NULL){
        return -1;
    }
    int leftLevel = leve(root->left , p);
    int rightLevel = level(root->right , p);

    if(root->data == p ){
        return 0;
    }
    else if(leftLevel!=-1) return 1+leftLevel;
    else if(rightLevel!=-1) return 1+rightLevel;
    else return -1;


}

BinaryTreeNode<int> * parentOf(BinaryTreeNode<int> * root ,int p){
    if(root==NULL){
        return NULL;
    }
    
    if(root->left!=NULL && root->left->data == p) return root;
    if(root->right!=NULL && root->right->data == p) return root;
    
    if(parentOf(root->left,p)!=NULL)return parentOf(root->left,p);
    if(parentOf(root->right ,p)!=NULL)return parentOf(root->right,p);
}

bool cousin (BinaryTreeNode<int>* root , int p , int q){
    if((level(root, p)==level(root, q))&& parentOf(root, p)!=parent(root, q)) return true;
    else return false;
}