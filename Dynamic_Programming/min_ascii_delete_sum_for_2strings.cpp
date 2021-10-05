#include<iostream>
#include<string>
#include<vector>
using namespace std;


void min_ascii(string s1, string s2)
{
    vector<vector<int>> dp (s1.size() + 1, vector<int> (s2.size() + 1));
    
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[0].size(); j++){
            
            if(i == 0 && j == 0){
                dp[i][j] = 0;
            }
            
            else if(i == 0){
                // we'll have to remove all the chars to make string equal to "" stirng
                dp[i][j] = s2[j - 1] + dp[i][j - 1];
            }
            
            else if(j == 0){
                // we'll have to remove all the chars to make string equal to "" stirng
                dp[i][j] = s1[i - 1] + dp[i - 1][j];    
            }
            
            else{
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    // 1. remove 1 char from s1 -> add it's askii value & match the remaining s1 str with s2 str.
                    // 2. remove 1 char from s2 -> add it's askii value & match the remaining s2 str with s1 str.
                    // min (1, 2)
                    
                    dp[i][j] = min( (s1[i - 1] + dp[i - 1][j]), (s2[j - 1] + dp[i][j - 1]) );
                }
            }
        }
    }
    
    cout<<dp[dp.size() - 1][dp[0].size() - 1];
}


int main()
{
    string s1, s2;
    cin>>s1>>s2;
    
    min_ascii(s1, s2);
    
    return 0;
}