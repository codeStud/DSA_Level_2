#include<iostream>
#include<vector>
using namespace std;

int maxSum_Increasing_Subseq(vector<int>& arr, vector<int>& dp)
{
    // to keep track of maxSum
    int maxSumLIS = 0;
    
    // loop through the dp array
    for(int i = 0; i < dp.size(); i++){
        int maxVal = 0;
        
        // look back in the arr and find the maxSum INCREASING Subsequence amongst SMALLER elements
        for(int j = 0; j < i; j++){
            //curElement arr[i] can be included only if previous element is less/equal
            if(arr[j] <= arr[i]){
                maxVal = max(maxVal, dp[j]);
            }
        }
        
        // maxVal + arr[i] = max SUM INCREASING Subsequence ENDING AT arr[i]
        // It'll also handle base case when no previous element is smaller
        dp[i] = maxVal + arr[i];
        
        maxSumLIS = max(maxSumLIS, dp[i]);
    }
    
    return maxSumLIS;
}

int main()
{
    int n;
    cin>>n;
    
    vector <int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    // dp[i] stores the SUM of INCREASING subsequence ENDING AT dp[i]
    vector <int> dp(n, 0);
    
    cout<<maxSum_Increasing_Subseq(arr, dp);
    
    return 0;
}