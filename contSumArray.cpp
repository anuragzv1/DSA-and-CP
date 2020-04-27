#include <iostream>
using namespace std;

int lSum(int *arr, int n)
{
    int *dp = new int[n];
    dp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        dp[i]=arr[i];
        int j = i - 1;
        int max_sum = -1;
        int index = 0;
        while (j >= 0)
        {
            if(dp[j]>max_sum){
                max_sum = dp[j];
                index = j;
            }
            j--;
        }
        dp[i]+=dp[index];
        if(index != i-1){
            for(int x = i-1;x>index;x--){
                dp[i]+=arr[x];
            }
        }
        }
        int ans=0;
        for(int i=0;i<n;i++)ans=max(ans,dp[i]);
        delete[]dp;
        return ans;
    }

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int ans = lSum(arr, n);
        delete[] arr;
        cout << ans << endl;
    }
    return 0;
}