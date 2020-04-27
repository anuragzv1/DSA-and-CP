#include<iostream>
#include<vector>
using namespace std;



bool checkRowNCol(vector<vector<int> >vec , int row , int col,int num){
    
    //checking row
    for(int i=0;i<9;i++){
        if(vec[row][i]==num) return false;
    }

    //check col
    for(int i=0;i<9;i++){
        if(vec[i][col]==num) return false;
    }

    return true;
}

bool checkBox(vector<vector<int> > vec , int row , int col,int num){
    row = row - (row%3);
    col = col - (col%3);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(vec[i+row][j+col]==num) return false;
        }
    }
    return true;
}

        

bool isFull(vector<vector<int> >vec , int &row , int &col){
    for(int i =0;i<9;i++){
        for(int j=0;j<9;j++){
            if(vec[i][j]==0){
                row = i;
                col = j;
                return false;
            }
        }
    }
    return true;
}

bool solveSodoku(vector<vector<int> > vec ){
    int row , col;
    if(isFull(vec ,row , col )==true){
        //cout<<"Base case hit \n";
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<vec[i][j];
            }
            cout<<endl;
        }
        return true;
    }
    isFull(vec , row , col);

    for(int i=1;i<=9;i++){
        if(checkRowNCol(vec,row,col,i) && checkBox(vec,row,col,i)){
            vec[row][col]=i;
            if(solveSodoku(vec)){
                return true;
            }
            else vec[row][col]=0;
        }
    }
return false;
    
}


int main(){
    
    vector<vector<int> >vec;
    for(int i=0;i<9;i++){
        vector <int> v;
        string str;
        cin>>str;
        for(int i=0;i<9;i++){
            int t = str[i]-48;
            v.push_back(t);
        }
        vec.push_back(v);
    }

    solveSodoku(vec);
    // if(solveSodoku(vec)){
    //     cout<<"true";
    // }
    // else cout<<"false";
    return 0;
}



// 305420810 
// 487901506 
// 029056374
// 850793041
// 613208957
// 613208957
// 074065280 
// 241309065 
// 508670192 


// 900020750 
// 600050040 
// 020400010 
// 208000000 
// 070509060 
// 000000401 
// 010005080 
// 090070004 
// 082040006