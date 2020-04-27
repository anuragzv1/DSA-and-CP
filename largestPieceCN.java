public class solution {
    
    int myFunc(String cake[], int n, int row , int col ,int visited[][]){
        if(row>=n || col>=n || row<0 || col <0)return 0;
        
        if(visited[row][col]==1 || cake[row].charAt(col)!='1')return 0;
    
        visited[row][col] = 1;
        int ans = 0;
        int top = myFunc(cake, n, row-1,col,visited);
        ans = Math.max(ans,top);
        int left = myFunc(cake, n, row,col-1,visited);
        ans = Math.max(ans,left);
        int down = myFunc(cake, n, row+1,col,visited);
        ans = Math.max(ans,down);
        int right = myFunc(cake, n, row,col+1,visited);
        ans = Math.max(ans,right);
        int topleft = myFunc(cake, n, row-1,col-1,visited);
        ans = Math.max(ans,topleft);
        int topright = myFunc(cake, n, row-1,col+1,visited);
        ans = Math.max(ans,topright);
        int downleft = myFunc(cake, n, row+1,col-1,visited);
        ans = Math.max(ans,downleft);
        int downright = myFunc(cake, n, row+1,col+1,visited);
        ans = Math.max(ans,downright);
        
        visited[row][col]=0;
        return 1+ans;
        
    }
    
    public int solve(int n,String cake[]) {
        int visited[][] = new int[n][n];
        
        int ans = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(cake[i].charAt(j)=='0')continue;
                ans = Math.max(ans,myFunc(cake, n , i, j,visited));
            }
        }
        return ans;
    }
}
