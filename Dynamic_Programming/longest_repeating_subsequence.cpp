#include<iostream>
#include<string>
#include<vector>
using namespace std;

void longest_repeating_subsequence(string str)
{
    vector<vector<int>> dp (str.size() + 1, vector<int> (str.size() + 1, 0));

    // Find the LCS of str with str. But when the chars are same, make sure that
    // their indices are NOT same.
    for(int i = 1; i < dp.size(); i++){
        for(int j = 1; j < dp[0].size(); j++){
            
            if(str[i - 1] == str[j - 1] && i != j){
                dp[i][j] = 1 + dp[i - 1][j - 1]; 
            }
            
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][ j - 1]);
            }
            
        }
    }
    
    cout<<dp[dp.size() - 1][dp[0].size() - 1]<<endl;
}

int main()
{
    string s;
    cin>>s;
    
    longest_repeating_subsequence(s);
    
    return 0;
}