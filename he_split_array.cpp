#include "stdc++.h"
#include<unordered_map>
using namespace std;

unordered_map<int,bool>mymap;
int firstOcc(vector<int> & A , int element){
    int index =-1;
    for(int i=0;i<A.size();i++){
        if(A[i]==element){
            index = i;
            return index;
        }
    }
    return index;
}

int setIncArray(vector<int>&A , int size , vector<int>&incArr ){
        int smallest = A[0];
        mymap[0]=false;
        incArr.push_back(smallest);
        for(int i=1;i<size;i++){
            if(incArr.size()==size/2) break;
            if(A[i]>smallest){
                incArr.push_back(A[i]);
                mymap[i]=false;
                smallest = A[i];
            }
        }
        int changes = 0;
        while(incArr.size()!=size/2){
            int greatest = incArr[incArr.size()-1];
            incArr.push_back(greatest+1);
            int emptyIndex=0;
            bool found = false;
            while(!found){
                if(emptyIndex>A.size()-1) break;
                if(mymap[emptyIndex]){
                    A[emptyIndex]= greatest+1;
                    mymap[emptyIndex]= false;
                    found = true;
                }
                else emptyIndex++;
            }
            changes++;
        }
        return changes;
}

int setDecArray(vector<int>&A , int size , vector<int>&decArr){
    int last = 0;
    int element=-1;
    bool found =false;
    while(!found){
        if(mymap[last]){
            element = A[last];
            found = true;
            break;
        }
        else last++;
    }
    mymap[last] = false;
    decArr.push_back(A[last]);
    for(int i=last+1;i<size;i++){
        if(decArr.size()==size/2) break;
        if(mymap[i]==true){
            if(A[i]>=element){
                decArr.push_back(A[i]);
                element = A[i];
            }
        }
    }
    int changes =0;
    while(decArr.size()!=size/2){
        int greatest = decArr[decArr.size()-1];
        decArr.push_back(greatest);
    }
    return changes;
}

vector<int> DividingArray (vector<int> &A,int N) {
    vector<int>incArr;
    vector<int>decArr;
    sort(A.begin() , A.end());
    for(int i = 0;i<N;i++){
        mymap[i]=true;
    }
    int a = setIncArray(A , N, incArr);
    int b = setDecArray(A , N , decArr);
    A.clear();
    A.push_back(a+b);
    for(int i=0;i<incArr.size();i++){
        A.push_back(incArr[i]);
    }
    for(int j=0;j<decArr.size();j++){
        A.push_back(decArr[j]);
    }
    
    return A;
    
}
int main() 
{   ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i_A=0; i_A<N; i_A++)
    {
    	cin >> A[i_A];
    }
    vector <int> out_;
    out_ = DividingArray(A,N);
    cout << out_[0]<<endl;
    for(int i_A=1; i_A<out_.size(); i_A++)
    	cout<<out_[i_A]<<" ";
}