#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector <int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++){
        int minSteps = INT_MAX;
        
        for(int j = 1; j*j <= i; j++){
            int num = i - j*j;
            int val = dp[num];
            
            minSteps = min(minSteps, val);
        }
        
        dp[i] = minSteps + 1;
    }
    
    cout<<dp[n]<<endl;
    
    return 0;
}