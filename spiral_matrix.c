#include<stdio.h>
int main(){
    int m ,n,i,j,dir=0,i1;
    printf("Enter the size of the matrix in M  N form seprated by space \n");
    scanf("%d %d",&m ,&n);
    int a[m][n];
    int top=0,bottom=m-1,right=n-1,left=0;
    for(i1=0;i1<m;i1++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i1][j]);
        }
        printf("\n");
    }
    printf("The entered Matrix is: \n");
    for(i1=0;i1<m;i1++){
        for(j=0;j<n;j++){
            printf("%d \t",a[i1][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("The spiral result is: \n");

    while(top<=bottom && left<=right){
        if(dir==0){
            for(i=left;i<=right;i++){
                printf("%d,",a[top][i]);            
            }
            top++;
        }
        else if(dir==1)
        {
            for(i=top;i<=bottom;i++){
                printf("%d,",a[i][right]); 
            }
            right--;
        }
        else if(dir==2){
            for(i=right;i>=left;i--){
                printf("%d,",a[bottom][i]);
            }
            bottom--;
        }
        else if(dir==3){
            for(i=bottom;i>=top;i--){
                printf("%d,",a[i][left]);
            }
            left++;
        }
        dir=(dir+1)%4;
    }
}