
void findLargest(int arr[][1000], int row, int col){

    int maxRow=0;
    int maxRowSum=0;
    int maxCol = 0;
    int maxColSum = 0;
    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<col;j++){
            sum+=arr[i][j];
        }
        if(sum>maxRowSum){
            maxRowSum=sum;
            maxRow =i;
        }
    }
    for(int j=0;j<col;j++){
        int sum=0;
        for(int i=0;i<row;i++){
            sum+=arr[i][j];
        }
        if(sum>maxColSum){
            maxColSum=sum;
            maxCol=j;
        }
    }
    
    if(maxRowSum>maxColSum){
        cout<<"row "<<maxRow<<" "<<maxRowSum;
    }
    else if(maxRowSum<maxColSum){
        cout<<"column "<<maxCol<<" "<<maxColSum;
    }
    else if(maxRowSum==maxColSum){
        cout<<"row "<<maxRow<<" "<<maxRowSum;
    }
}
