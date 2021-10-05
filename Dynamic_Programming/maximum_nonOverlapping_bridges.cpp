// Two bridges are said to be non-overlapping when -
// if bridge-1[startPoint] <= bridge-2[startPoint]  =>  bridge-1[endPoint] < bridge-2[endPoint]

// So, idea is to -
// 1. Sort the bridges based on their startPoints.
// 2. Find the LIS of the bridges based on their endPoints. 
// LIS will give you length of max-size non-overlapping bridges subset (~ subsequence) 

// NOTE: Think why doing LIS on endPoints will give you the count of maximum number of non-overlapping bridges. 
// (Hint: You need SUBSET of non-overlapping bridges which is of max-Length)

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


int LIS(vector<int>& arr, vector<int>& dp)
{
    int LIS_len = 0;
    
    for(int i = 0; i < dp.size(); i++){
        int maxSize = 0;
        
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                maxSize = max(maxSize, dp[j]);
            }
        }
        
        dp[i] = maxSize + 1;
        
        LIS_len = max(LIS_len, dp[i]);
    }
    
    return LIS_len;
}


// Driver function to sort the 2D vector
// on basis on 0th col (if equal then by 1st col)
bool comparator(const vector<int>& v1, const vector<int>& v2 )
{
    return v1[0] != v2[0] ? v1[0] < v2[0] : v1[1] < v2[1];
}


int main()
{
    int n;
    cin>>n;
    
    vector <vector<int>> bridges (n, vector<int>(2));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            cin>>bridges[i][j];
        }
    }
    
    // sort the bridges in INCREASING order based on their start point 
    // => endPoints of "non-overlapping" bridges will be in INCREASING order as well. (Thus, LIS works)
    sort(bridges.begin(), bridges.end(), comparator);
    
    
    // Find LIS based on endPoints, to get the LENGTH of the max-sized increasing endoPoint subset / subsequence.
    
    // let's create a vector of endPoints from the sorted bridges
    vector <int> endPoints;
    for(int i = 0; i < n; i++){
        endPoints.push_back(bridges[i][1]);
    }
    
    vector <int> dp(n, 0);
    
    int ans = LIS(endPoints, dp);
    
    cout<<ans<<endl;
    
    return 0;
}