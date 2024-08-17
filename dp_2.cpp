//Dp bottom-up approach
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1);
    //step 1
    dp[0] = 0;
    dp[1] = 1;
    //step 2
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[n];
    return 0;
}