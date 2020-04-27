#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        int k=i;
        int spaces=1;
        while(spaces<=n-i){
            cout<<" ";
            spaces++;
        }

        while(j<=i){
            cout<<k;
            j++;
            k++;
        }

        int pattern2= 2*(i-1);
        int z=i;
        while(z<=pattern2){
            cout<<pattern2;
            pattern2--;
        }

        i++;
        cout<<endl;
    }
}
