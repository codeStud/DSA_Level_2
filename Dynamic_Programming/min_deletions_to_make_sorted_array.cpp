// NOTE: To get the minimum number of deletions + strictly increasing array,
// Find the length of the LONGEST INCREASING SUBSEQUENCE and subtract it from arr.size()

#include<iostream>
#include<vector>
using namespace std;

int min_deletions(vector<int>& arr, vector<int>& dp)
{
    // to keep track of maxLenLIS
    int maxLIS = 0;
    
    // loop through the dp array
    for(int i = 0; i < dp.size(); i++){
        int maxLen = 0;
        
        // look back in the arr and find the maxLen LIS amongst SMALLER (NOT equal) elements
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                maxLen = max(maxLen, dp[j]);
            }
        }
        
        // maxLen + 1 = max length LIS ENDING AT arr[i]
        dp[i] = maxLen + 1;
        
        maxLIS = max(maxLIS, dp[i]);
    }
    
    // we'll have to DELETE the extra elements which don't occur in LIS
    return (arr.size() - maxLIS);
}

int main()
{
    int n;
    cin>>n;
    
    vector <int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    // dp[i] stores the LENGTH of INCREASING subsequence ENDING AT dp[i]
    vector <int> dp(n, 0);
    
    cout<<min_deletions(arr, dp);
    
    return 0;
}