#include<iostream>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int word=0;
    int vowel=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
           vowel++;
        }
        else word++;
        
    }
    cout<<"No of words = "<<word<<" Number of Vowels = "<<vowel<<endl;
    return 0;
}