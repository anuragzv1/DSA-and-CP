#include<iostream>
using namespace std;
struct square{
int ilandno;
int x1;
int y1;
int x2;
int y2;
int x3;
int y3;
int x4;
int y4;
int minimumdist;
};

int manhattan(int x1,int y1,int x2,int y2){
    int distance = abs(x1-x2)+abs(y1-y2);
    return distance;
}

int setMindistance(struct square s ,int o1,int o2 ){
    int distance1 = manhattan(o1 ,o2 ,s.x1,s.y1);
    int distance2 = manhattan(o1 ,o2 ,s.x2,s.y2);
    int distance3 = manhattan(o1 ,o2 ,s.x3,s.y3);
    int distance4 = manhattan(o1 ,o2 ,s.x4,s.y4);
    int mindis = min(min(distance1,distance2),min(distance3,distance4));
    return mindis;
}

bool compareLength(struct square s1 ,struct square s2){
    if(s1.minimumdist <= s2.minimumdist){
        return true;
    }
    else return false;
}
int main(){
    int ni;
    cin>>ni;
    int num=ni;
    int brr[num];
        struct square arr[num];
        for(int i=0;i<num;i++){
            cin>>arr[i].x1>>arr[i].y1>>arr[i].x3>>arr[i].y3;
            arr[i].ilandno=i+1;
        } 
        int o1,o2;
        cin>>o1>>o2;
        for(int z=0;z<num;z++){
            arr[z].x2=arr[z].x3;
            arr[z].y2=arr[z].y1;
            arr[z].x4=arr[z].x1;
            arr[z].y4=arr[z].y3;
        }

        for(int xx=0;xx<num;xx++){
            arr[xx].minimumdist = setMindistance(arr[xx],o1,o2);
        }

        sort(arr,arr+num ,compareLength);
        for(int iz=0;iz<num;iz++){
            cout<<arr[iz].ilandno<<" ";
        }


    return 0;
}