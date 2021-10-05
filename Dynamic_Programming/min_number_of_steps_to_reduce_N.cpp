#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    // each index 'i' in dp[] will store the minimum number of steps to form 'i' following rules.
    vector<int> dp (n + 1);
    dp[0] = INT_MAX; // can't be made 1 following rules
    dp[1] = 0;  // already 1
    
    for(int i = 2; i <= n; i++){
        // each number has 3 choices as per the rule
        int ans1 = INT_MAX;
        int ans2 = INT_MAX;
        int ans3 = INT_MAX;
        
        if(i % 2 == 0){
            ans1 = 1 + dp[i / 2];
        }
        
        if(i % 3 == 0){
            ans2 = 1 + dp[i / 3];
        }
        
        // following "decrement by 1" rule
        ans3 = 1 + dp[i - 1];
        
        // store the minimum of those three at dp[i]
        dp[i] = min({ans1, ans2, ans3});
    }
    
    
    cout<<dp[n]<<endl;
    
    return 0;
}