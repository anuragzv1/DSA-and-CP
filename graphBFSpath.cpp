#include <iostream>
#include<unordered_map>
#include<queue>
using namespace std;
unordered_map<int,int>mymap;


bool fillWithPath(int **edges , int size, int start , int end , int * visited){
    queue<int> q;

    q.push(start);
    visited[start]=1;
    if(start == end){
        mymap[start]=start;
        return true;
    }

    while(q.size()!=0){
        int front=q.front();
        q.pop();

        for(int i =0;i<size;i++){
            if(edges[front][i]==1 && visited[i]!=1){
                visited[i] =1;
                mymap[i]=front;
                if(i==end){
                    return true;                    
                }
                q.push(i);
            }
        }
    }

    return false;

}

int main()
{
    int v, e ,start , end;
    cin>>v>>e;

    int ** edges = new int *[v];
    int * visited = new int[v];
    for(int i =0;i<v;i++){
        edges[i] = new int[v];
        for(int j = 0;j<v;j++){
            edges[i][j]=1;
            visited[j]=0;
        }
    }

    for(int i=0;i<v;i++){
        int first , second;
        cin>>first >>second;
        edges[first][second]=1;
        edges[second][first]=1;
    }


    // if(fillWithPath(edges, v , start , end,visited)){
    //     // for(auto i : mymap){
    //     //     //cout<<i.first<<" "<<i.second<<endl;
    //     // }
    // }


    return 0;
}
