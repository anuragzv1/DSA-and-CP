#include<bits/stdc++.h>
using namespace std;
struct car{
int x;
int y;
int v;
double t;
};

double caldistance(struct car c){
    return pow((c.x*c.x+c.y*c.y),0.5);
}
int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c;
    cin>>c;
     struct car arr[c];

     for(int i=0;i<c;i++){
         cin>>arr[i].x>>arr[i].y>>arr[i].v;
         arr[i].t = caldistance(arr[i])/arr[i].v;
     }
    int count=0;
     for(int z=0;z<c;z++){
         for(int p=z+1;p<c;p++){
             if(z!=p && arr[z].t==arr[p].t) count++;
         }
     }
    cout<<count<<"\n";


    return 0;
}