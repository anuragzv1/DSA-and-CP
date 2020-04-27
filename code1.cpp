#include"stdc++.h"
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string order;
        string str;
        cin>>order;
        cin>>str;
        string final;
      int orderlength =order.length();
      int strlength = str.length();
      for(int z=0;z<strlength;z++){
          if(!isalpha(str[z])){
              str.erase(str.begin()+z);
          }
      }
      transform(str.begin(), str.end(), str.begin(), ::tolower); 
      transform(order.begin(), order.end(), order.begin(), ::tolower); 
  	  
      strlength = str.length();
        for(int i=0;i<orderlength;i++){
            for(int j=0;j<strlength;j++){
                if(order[i]==str[j]){
                    final = final+str[j];
                    break;
                }
            }
        }
        cout<<final<<endl;
        
    }
  return 0;
}