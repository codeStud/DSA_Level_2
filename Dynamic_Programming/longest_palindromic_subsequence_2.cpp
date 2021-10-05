#include<iostream>
#include<string>
#include<vector>
using namespace std;


int lps(string str, vector<vector<int>>& dp, int leftIndex, int rightIndex)
{   
    // Negative Base case
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


int main()
{
    string str;
    cin>>str;
    
    vector<vector<int>> dp (str.size(), vector<int>(str.size(), -1));
    
    cout<<lps(str, dp, 0, str.size()-1);
    
    return 0;
}