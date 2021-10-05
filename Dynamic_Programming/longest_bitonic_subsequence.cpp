// To find the longest bitonic subsequence, at each point store -
// 1. Maximum length Increasing subsequence ENDING at that point
// 2. Maximum length Decreasing subsequence STARTING from that point

#include<iostream>
#include<vector>
using namespace std;


void LIS(vector<int>& arr, vector<int>& dp)
{
    int maxLenLIS = 0;
    
    for(int i = 0; i < dp.size(); i++){
        int maxLen = 0;
        
        for(int j = 0; j < i; j++){
            if(arr[j] <= arr[i]){
                maxLen = max(maxLen, dp[j]);
            }
        }
        
        dp[i] = maxLen + 1;
    }
}


void LDS(vector<int>& arr, vector<int>& dp)
{
    int maxLenLDS = 0;
    
    // start filling from RIGHT to LEFT
    for(int i = dp.size() - 1; i >= 0; i--){
        int maxLen = 0;
        
        // check for the SMALLER elements on the right side of the current element
        for(int j = i + 1; j < arr.size(); j++){
            if(arr[j] < arr[i]){
                maxLen = max(maxLen, dp[j]);
            }
        }
        
        dp[i] = maxLen + 1;
    }
}


int main()
{
    int n;
    cin>>n;
    
    vector <int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    vector <int> lis(n, 0);
    vector <int> lds(n, 0);
    
    LIS(arr, lis);
    LDS(arr, lds);
    
    // find the maxLen bitonic
    int maxBitonicLen = 0;
    for(int i = 0; i < n; i++){
        // do -1 to avoid including the current element's count twice (once in LIS, and then again in LDS)
        maxBitonicLen = max(maxBitonicLen, (lis[i] + lds[i] - 1));
    }
    
    cout<<maxBitonicLen<<endl;
    
    return 0;
}