#include <stdio.h>

int main() {
	int t,n;
	scanf("%d",&t);
	while(t--){
	    scanf("%d",&n);
	    int arr[n];
	    for(int i=0;i<n;i++){
	        scanf("%d",&arr[i]);
	    }
	    int chk=0;
	    for(int z=0;z<n;z++){
	    int sleft=0,sright=0;
	    int j=n-1,i=0;
	    while(i<z || j>z){
	    if(i<z){
	        sleft=sleft+arr[i++];
	    }
	        if(j>z){
	            sright=sright+arr[j--];
	        }
	        
	    }
	    if(sright==sleft){
	        printf("%d ",z+1);
	        chk=1;
	        break;
	    }
	    }
	    if(chk==0){printf("-1");}
	    printf("\n");
	}
	return 0;
}