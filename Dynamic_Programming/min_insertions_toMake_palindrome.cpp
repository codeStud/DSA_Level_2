#include<iostream>
#include<string>
#include<vector>
using namespace std;


int lps(string str, vector<vector<int>>& dp, int leftIndex, int rightIndex)
{
    // Negative Base-Case
    if(leftIndex > rightIndex){
        return 0;
    }
    
    // Positive Base case
    if(leftIndex == rightIndex){
        return 1;
    }
    
    if(dp[leftIndex][rightIndex] != -1){
        return dp[leftIndex][rightIndex];
    }
    
    int res = 0;
    
    if(str[leftIndex] == str[rightIndex]){
        res = 2 + lps(str, dp, leftIndex + 1, rightIndex - 1);
    }
    else{
        res = max( lps(str, dp, leftIndex + 1, rightIndex), lps(str, dp, leftIndex, rightIndex - 1) );
    }
    
    // store the result before returning
    dp[leftIndex][rightIndex] = res;
    
    return dp[leftIndex][rightIndex];
}


int min_insertions(string str, vector<vector<int>>& dp)
{
    // find longest palindromic subsequence already present in the str
    int lps_len = lps(str, dp, 0, str.size()-1);
    
    // At MINIMUM, we need to remain the counter-part of remaining characters
    int minCharsInsertion = str.size() - lps_len;
    
    return minCharsInsertion;
    
}


int main()
{
    string str;
    cin>>str;
    
    vector<vector<int>> dp (str.size(), vector<int>(str.size(), -1));
    
    cout<<min_insertions(str, dp);
    
    return 0;
}