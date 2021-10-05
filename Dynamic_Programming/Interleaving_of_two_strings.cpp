#include<iostream>
#include<string>
#include<vector>
using namespace std;

int interleaving_of_two_strings(string& s1, string& s2, string& s3, int i, int j, int k, vector<vector<int>>& dp)
{
    // base case
    // if all chars in s1 and s2 have combined to make up all chars in s3
    if(i == s1.size() && j == s2.size() && k == s3.size()){
        dp[i][j] = 1;
        return dp[i][j];
    }
    
    // Memoization
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    if(s1[i] == s3[k]){
        // move to the next character in string-1 and also in string-3
        int res = interleaving_of_two_strings(s1, s2, s3, i+1, j, k+1, dp);
        
        // store result in dp before returning
        dp[i][j] = res;
        // if you get true, return without making the recursive call below
        if(res == 1){
            return 1;
        }
    }
    
    // If the above call doesn't return true then check if the current kth char also matched in s2 string. 
    // If yes, also make this recursive call as this matching might make the interleaving string.
    if(s2[j] == s3[k]){
        // move to the next character in string-2 and also in string-3
        int res = interleaving_of_two_strings(s1, s2, s3, i, j+1, k+1, dp);
        
        // store result in dp before returning
        dp[i][j] = res;
        if(res == 1){
            return 1;
        }
    }
    
    // if the current 'i-th' char or the current 'j-th' char doesn NOT matche the current 'k-th' char, return "false"
    dp[i][j] = 0;
    return dp[i][j];
}

int main()
{
    string s1, s2, s3;
    cin>>s1>>s2>>s3;

    if(s1.size() + s2.size() != s3.size()){
        cout<<"false";
        return 0;
    }
    
    // dp[i][j] = 1 => true    0 => false 
    vector<vector<int>> dp (s1.size() + 1, vector<int>(s2.size() + 1, -1));
    
    if(interleaving_of_two_strings(s1, s2, s3, 0, 0, 0, dp)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    
    return 0;
}