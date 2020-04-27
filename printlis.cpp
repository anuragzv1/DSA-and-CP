#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > printLis(int *arr, int n)
{
    if (n == 1)
    {
        vector<int> one;
        one.push_back(arr[0]);
        vector<vector<int> > two;
        two.push_back(one);
        return two;
    }
    vector<vector<int> > smallInput = printLis(arr + 1, n - 1);
    int length = smallInput.size();
    for (int i = 0; i < length; i++)
    {
        vector<int> temp = smallInput[i];
        temp.push_back(arr[0]);
        smallInput.push_back(temp);
    }
    vector<int> first_element;
    first_element.push_back(arr[0]);
    smallInput.push_back(first_element);

    return smallInput;
}

int main()
{
    int n, *arr;
    cin >> n;
    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int> > v = printLis(arr, n);
    // cout<<v.size();
    reverse(v.begin(), v.end());
    int max= -99999;
    int index = -1;
    for(int i =0;i<v.size();i++){
        reverse(v[i].begin(),v[i].end());
       
       int local_length = v[i].size();
       bool isInc = true;
        for(int j=0;j<v[i].size()-1;j++){
            if(v[i][j]>=v[i][j+1]){
                isInc = false;
                break;
            }
            
        }
        if(isInc){
            if(local_length>max){
                max = local_length;
                index = i;
            }
        }
        

    }
    cout<<"max_length ="<<max<<endl;
    for(int x=0;x<v[index].size();x++){
        cout<<v[index][x]<<" ";
    }
    
        
    return 0;
}