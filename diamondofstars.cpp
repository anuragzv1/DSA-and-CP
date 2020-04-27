void printPatt(int n)
{
    int mid = (n+1)/2;
    int i=1;
    int k=1;
    while(i<=mid){
        int space=1;
        while(space<=mid-i){
            cout<<" ";
            space++;
        }
        
        int j=1;
        while(j<=k){
            cout<<"*";
            j++;
        }
        k=k+2;
        i++;
        cout<<endl;
    }
    int k2=k-4;
    int z=1;
    int end = n-mid;
    while(z<=end){
        int space2=1;
        while(space2<=z){
            cout<<" ";
            space2++;
        }
        
        int pattern2 =1;
        while(pattern2<=k2){
            cout<<"*";
            pattern2++;
        }
        k2-=2;
        z++;
        cout<<endl;
    }
}
