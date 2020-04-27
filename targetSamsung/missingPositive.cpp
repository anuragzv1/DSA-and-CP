#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin >> n;
    int arr[101]={0};

    for(int i =0;i<n;i++){
        int a ;
        cin>>a;
        arr[a]=1;
    }

    for(int i =1;i<102;i++){
        if(arr[i]==0){
            cout<<i<<endl;
            break;
        }
    }
}
return 0;

}