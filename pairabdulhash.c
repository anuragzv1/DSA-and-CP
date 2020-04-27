#include <stdio.h>

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
    scanf("%d",&n);
    int arr[n];
    for(int ii=0;ii<n;ii++){
        scanf("%d ",&arr[ii]);
    }
    int k;
    scanf("%d ",&k);
    int max =0;
    for(int i =0;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    int hash[max+1];
    for(int z=0;z<max+1;z++){
        hash[z]=0;
    }
    
    for(int kz=0;kz<n;kz++){
        int rem = k-arr[kz];
        if(hash[rem]!=0){
            printf("%d + %d \n",arr[kz],k-arr[kz]);
        }
        hash[arr[kz]]=1;
    }
    }
	return 0;
}