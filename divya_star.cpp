#include <iostream>
#include"stdc++.h"

using namespace std;

void star(char input[], int start)
{
    if(input[start]=='\0')
    {
        return;
    }
    
    star(input,start+1);
    
    
    if(input[start]==input[start+1])
    {
        
        for(int i=strlen(input)-1;i>=start+1;i--)
        {
            input[i+1]=input[i];
            
        }
        input[start+1]='*';
        input[strlen(input)+1]='\0';
    }
    
    
}

void pairStar(char input[]) {
    // Write your code here
int start=0;
    star(input,start);
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
