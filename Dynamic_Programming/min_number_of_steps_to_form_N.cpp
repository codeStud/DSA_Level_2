// NOTE: Get the below Intuition without help -
// (a) Every number has 2 choices/operations, so it clearly has (1) Overlapping-Subproblem (2) Optimal Substructure => Use DP

// (b) MinSteps to convert 0 to N = MinSteps to convert N to 0
// New rules will become - "Half the number" & "Subtract 1 from the number"

// So, we can use bottom-up approach to solve this problem easily.

#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    // each index 'i' in dp[] will store the minimum number of steps to get 0 from 'i' following NEW rules.
    vector<int> dp (n + 1);
    dp[0] = 0;      // already 0
    
    for(int i = 1; i <= n; i++){
        // to get MinSteps,
        // (1) When number is even => divide by 2   + 1(for current operation)
        // (2) When number is odd => reduce it by 1 + 1(for current operation)
        
        if(i % 2 == 0){
            dp[i] = 1 + dp[i / 2];
        }
        else{
            dp[i] = 1 + dp[i - 1];
        }
    }
    
    
    cout<<dp[n]<<endl;
    
    return 0;
}