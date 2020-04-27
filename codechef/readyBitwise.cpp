#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#define mod 998244353

using namespace std;


long long  add(long long a , long long b)
{
	return (a + b) % mod;
} 

long long power(long long a , long long n)
{
	long long res = 1;
	
	while(n)
	{
		if(n & 1)
			res = (res * a) % mod;
		
		n >>= 1;
		a = (a * a) % mod;
	}
	
	return res;
}

vector<long long> perform_operation(vector<long long> &a , vector<long long> &b ,char _operator ){
    vector<long long> res (4 , 0);
    if(_operator == '|')
	{
		res[0] = add(res[0] , (a[0] * b[0]) % mod);
		res[1] = add(res[1] , (a[1] * b[0]) % mod);
		res[2] = add(res[2] , (a[2] * b[0]) % mod);
		res[3] = add(res[3] , (a[3] * b[0]) % mod);
		
		res[1] = add(res[1] , (a[0] * b[1]) % mod);
		res[1] = add(res[1] , (a[1] * b[1]) % mod);
		res[1] = add(res[1] , (a[2] * b[1]) % mod);
		res[1] = add(res[1] , (a[3] * b[1]) % mod);
		
		res[2] = add(res[2] , (a[0] * b[2]) % mod);
		res[1] = add(res[1] , (a[1] * b[2]) % mod);
		res[2] = add(res[2] , (a[2] * b[2]) % mod);
		res[1] = add(res[1] , (a[3] * b[2]) % mod);
		
		res[3] = add(res[3] , (a[0] * b[3]) % mod);
		res[1] = add(res[1] , (a[1] * b[3]) % mod);
		res[1] = add(res[1] , (a[2] * b[3]) % mod);
		res[3] = add(res[3] , (a[3] * b[3]) % mod);
	}
	
	
	if(_operator == '^')
	{
		res[0] = add(res[0] , (a[0] * b[0]) % mod);
		res[1] = add(res[1] , (a[1] * b[0]) % mod);
		res[2] = add(res[2] , (a[2] * b[0]) % mod);
		res[3] = add(res[3] , (a[3] * b[0]) % mod);
		
		res[1] = add(res[1] , (a[0] * b[1]) % mod);
		res[0] = add(res[0] , (a[1] * b[1]) % mod);
		res[3] = add(res[3] , (a[2] * b[1]) % mod);
		res[2] = add(res[2] , (a[3] * b[1]) % mod);
		
		res[2] = add(res[2] , (a[0] * b[2]) % mod);
		res[3] = add(res[3] , (a[1] * b[2]) % mod);
		res[0] = add(res[0] , (a[2] * b[2]) % mod);
		res[1] = add(res[1] , (a[3] * b[2]) % mod);
		
		res[3] = add(res[3] , (a[0] * b[3]) % mod);
		res[2] = add(res[2] , (a[1] * b[3]) % mod);
		res[1] = add(res[1] , (a[2] * b[3]) % mod);
		res[0] = add(res[0] , (a[3] * b[3]) % mod);
	}
	
	//apply AND operator
	if(_operator == '&')
	{
		res[0] = add(res[0] , (a[0] * b[0]) % mod);
		res[0] = add(res[0] , (a[1] * b[0]) % mod);
		res[0] = add(res[0] , (a[2] * b[0]) % mod);
		res[0] = add(res[0] , (a[3] * b[0]) % mod);
		
		res[0] = add(res[0] , (a[0] * b[1]) % mod);
		res[1] = add(res[1] , (a[1] * b[1]) % mod);
		res[2] = add(res[2] , (a[2] * b[1]) % mod);
		res[3] = add(res[3] , (a[3] * b[1]) % mod);
		
		res[0] = add(res[0] , (a[0] * b[2]) % mod);
		res[2] = add(res[2] , (a[1] * b[2]) % mod);
		res[2] = add(res[2] , (a[2] * b[2]) % mod);
		res[0] = add(res[0] , (a[3] * b[2]) % mod);
		
		res[0] = add(res[0] , (a[0] * b[3]) % mod);
		res[3] = add(res[3] , (a[1] * b[3]) % mod);
		res[0] = add(res[0] , (a[2] * b[3]) % mod);
		res[3] = add(res[3] , (a[3] * b[3]) % mod);
	}
	
	return res;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<long long> v(4,1);
        stack<vector<long long> > stk;
        stack<char> par_stack;
        stack<char> op_stack;
        for(char ch :s){
            if(ch=='(')par_stack.push(ch);
            else if (ch=='&' || ch=='|' || ch=='^')op_stack.push(ch);
            else if (ch == '#')stk.push(v);
            else{
                char _operator = op_stack.top();
                op_stack.pop();
                par_stack.pop();
                vector<long long> op2 = stk.top();
                stk.pop();
                vector<long long> op1 = stk.top();
                stk.pop();
                stk.push(perform_operation(op2 , op1 , _operator));
            }
        }
        vector<long long > ans = stk.top();
        long long noOfHash =0;
        for(char ch : s){
            if(ch=='#')noOfHash++;
        }
        long long inverse = power(power(4,noOfHash),mod-2);
        cout<<(ans[0]*inverse)%mod<<" ";
        cout<<(ans[1]*inverse)%mod<<" ";
        cout<<(ans[2]*inverse)%mod<<" ";
        cout<<(ans[3]*inverse)%mod<<"\n";

    }
    return 0;
}