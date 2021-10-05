// Two envelops can be nested when -
// if envelope-1[width] < envelope-2[width]  =>  envelope-1[height] < envelope-2[height]

// So, idea is to -
// 1. Sort the envelopes based on their width.
// 2. Find the LIS of the envelopes based on their heights. 
// LIS will give you length of max-size subset (~ subsequence) of envelopes that can be nested

// NOTE: Think why doing LIS on height will give you the count of maximum number of envelops that can be nested. 

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


int LIS(vector<int>& arr, vector<int>& dp, vector<vector<int>>& envelopes)
{
    int LIS_len = 0;
    
    for(int i = 0; i < dp.size(); i++){
        int maxSize = 0;
        
        for(int j = 0; j < i; j++){
            
            // height must be less + width must also be less for nesting
            if(arr[j] < arr[i] && envelopes[j][0] < envelopes[i][0]){
                maxSize = max(maxSize, dp[j]);
            }
            
        }
        
        dp[i] = maxSize + 1;
        
        LIS_len = max(LIS_len, dp[i]);
    }
    
    return LIS_len;
}


// Driver function to sort the 2D vector
// on basis on 0th col
bool comparator(const vector<int>& v1, const vector<int>& v2 )
{
    return v1[0] < v2[0];
}


int main()
{
    int n;
    cin>>n;
    
    vector <vector<int>> envelopes (n, vector<int>(2));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            cin>>envelopes[i][j];
        }
    }
    
    // sort the envelopes in INCREASING order based on their width.
    // => height of envelopes that can be nested will be in INCREASING order as well. (Thus, LIS works)
    sort(envelopes.begin(), envelopes.end(), comparator);
    
    
    // Find LIS on the height to get the LENGTH of the max-sized increasing height subset / subsequence.
    
    // let's create a vector of height from the sorted envelopes
    vector <int> heights;
    for(int i = 0; i < n; i++){
        heights.push_back(envelopes[i][1]);
    }
    
    vector <int> dp(n, 0);
    
    int ans = LIS(heights, dp, envelopes);
    
    cout<<ans<<endl;
    
    return 0;
}