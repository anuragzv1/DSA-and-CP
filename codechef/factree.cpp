#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class treeNode{
    public:
        int value;
        vector<treeNode *>children;

        treeNode(int data){
            value = data;
        }
};



treeNode * createTree(treeNode * root,vector<vector<int> > &vec ,int cur){
    for(int i = 0;i<vec[cur].size();i++){
        treeNode * newNode = new treeNode(vec[cur][i]);
        root->children.push_back(newNode);
        createTree(newNode, vec ,vec[cur][i]);
    }
    return root;
}

void printTree(treeNode * root){
    if(root==NULL)return;
    cout<<root->value<<" : ";
    for(int i =0;i<root->children.size();i++){
        cout<<root->children[i]->value<<" ";
    }
    cout<<endl;
    for(int i = 0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        treeNode *root = new treeNode(1);
        vector <vector<int> > vec(n+1);

        for(int i =0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            vec[a].push_back(b);
        }
        unordered_map<int, int> map;
        for(int i =1;i<=n;i++){
            int val;
            cin>>val;
            map[i]=val;
        }
        root = createTree(root,vec, 1);
        printTree(root);

    }
    return 0;
}