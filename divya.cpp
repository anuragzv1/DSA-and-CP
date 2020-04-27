#include<iostream>
using namespace std;
#include<climits>
int findLargest(int arr[][1000], int row, int col){
    int sumRow, sumCol,i,j,k,l,row_num,col_num;
    int maxRow=INT_MIN;
    int maxCol=INT_MIN;
    for(i=0;i<=row-1;i++)
    {
        sumRow=0; row_num=0;
        for(j=0;j<=col-1;j++)
        {
            sumRow=sumRow+arr[i][j];
            
        }
        if(sumRow>maxRow)
            maxRow=sumRow;
        row_num=row_num+i;
    }
    
//Col sum
    for(l=0;l<=col-1;l++)
    {
        sumCol=0, col_num=0; 
        for(k=0;k<=row-1;k++)
        {
            sumCol=sumCol+arr[k][l];
            
            
        }
        if(sumCol>maxCol)
            maxCol=sumCol;
        col_num=col_num+l;
        
        
    }
    if(maxRow>=maxCol)
    {
        cout<<"row "<<row_num<<" "<<maxRow;
    }
    else
    {
        cout<<"column "<<col_num<<" "<<maxCol;
    }
    
return 0;
}


int main() {
    int row, col;
    cin >> row >> col;

    int input[1000][1000]; 
    for(int i = 0; i < row; i++) {
	    for(int j = 0; j < col; j++) {
	        cin >> input[i][j];
	    }
    }
    findLargest(input, row, col);
}