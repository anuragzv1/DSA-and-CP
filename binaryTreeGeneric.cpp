#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class BTnode{
    public:
    T data;
    BTnode *left;
    BTnode * right;

    BTnode(T rootData){
        data = rootData;
        left = NULL;
        right = NULL;
    }
};

BTnode<int>* takeInput(){
    cout<<"Enter the root's data and then data in level order\n";
    int rootData;
    cin>>rootData;
    if(rootData==-1) return NULL;
    queue<BTnode<int>* >pendingNodes;
    BTnode<int> *root = new BTnode<int>(rootData);
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BTnode <int> * front = pendingNodes.front();
        pendingNodes.pop();
        int leftData;
        int rightData;
        cin>>leftData;
        if(leftData!=-1){
            BTnode<int> * newNode = new BTnode<int>(leftData);
            front->left = newNode;
            pendingNodes.push(newNode);
        }
        cin>>rightData;
        if(rightData!=-1){
             BTnode<int> * newNode = new BTnode<int>(rightData);
            front->right = newNode;
            pendingNodes.push(newNode);
        }

    }

return root;

}
int level (BTnode<int> * root ,int t){
    if(root==NULL){
        return -1;
    }
    
    if(root->data == t) return 0;
    int foundInRight = -1;
    int foundInLeft = -1;
    foundInRight = level(root->right,t);
    foundInLeft = level(root->left,t);
    
    if(foundInRight!=-1){
        return 1+ foundInRight;
    }
    else if(foundInLeft!=-1){
        return 1+foundInLeft;
    }
    else return -1;
    
}

void print(BTnode<int>* root){
    if(root==NULL) return;
    queue<BTnode<int> * >pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BTnode<int> * front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data;
        if(front->left!=NULL)pendingNodes.push(front->left);
        if(front->right!=NULL)pendingNodes.push(front->right);
    }
}
int main(){
    BTnode <int> * root = takeInput();
    int number;
    cout<<"Enter number to find level \n";
    cin>>number;
    cout<<"Leevl of number = "<<level(root,number);
    //print(root);
    return 0;
}