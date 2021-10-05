#include<iostream>
#include<vector>
#include<climits>
using namespace std;


void burst_balloons(vector<int>& arr)
{
    vector<vector<int>> dp (arr.size(), vector<int> (arr.size()));
    
    for(int gap = 0; gap < dp.size(); gap++){
        for(int i = 0, j = gap; j < dp[0].size(); i++, j++){

            // NOTE: you can also give gap == 0, gap == 1 cases separately. But no need to do that here.
            
            int maxVal = INT_MIN;
            // give each of the balloons from i till j, a chance to be burst LAST
            for(int k = i; k <= j; k++){
                
                int left = k == i ? 0 : dp[i][k - 1];
                int right = k == j ? 0: dp[k + 1][j];
                int curVal = arr[k];
                
                if(i > 0){
                    curVal *= arr[i - 1];
                }
                
                if(j < dp[0].size() - 1){
                    curVal *= arr[j + 1];
                }
                
                int total = left + right + curVal;
                
                maxVal = max(maxVal, total);
            }
            
            dp[i][j] = maxVal;
        }
    }
    
    cout<<dp[0][dp.size() - 1];
}


int main()
{
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    burst_balloons(arr);
    
    return 0;
}