#include<iostream>
#include<queue>
using namespace std;

void printBFS(int ** edges , int size ,int sv ,int * pushed){
    queue<int>pendingNodes;
    pendingNodes.push(sv);
    pushed[sv]=1;
    while(pendingNodes.size()!=0){
        int front = pendingNodes.front();
        cout<<front<<" ";
        pendingNodes.pop();
        for(int i =0;i<size;i++){
            if(edges[front][i]==1 && pushed[i]!=1){
                pushed[i]=1;
                pendingNodes.push(i);
            }
        }

    }

}

int main(){

    int v,e;
    cin>>v>>e;
    
    int ** edges = new int*[v];
    int *visited = new int[v];
    for(int i =0;i<v;i++){
        edges[i] = new int [v];
        for(int j=0;j<v;j++){
            edges[i][j]=0;
            visited[j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int first,second;
        cin>>first>>second;
        edges[first][second]=1;
        edges[second][first]=1;
    }
    
    printBFS(edges, v, 0, visited);

    return 0;
}