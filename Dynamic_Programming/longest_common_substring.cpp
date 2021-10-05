// NOTE: For each of the prefixes in s1 and s2, find the longest common suffix. The length of the longest common
// suffix would be the length of the longest common substring

#include<iostream>
#include<vector>
#include<string>
using namespace std;


void longest_common_substring(string s1, string s2)
{
    vector<vector<int>> dp (s1.size() + 1, vector<int> (s2.size() + 1, 0));
    
    int maxLen = 0;
    
    for(int i = 1; i < dp.size(); i++){
        for(int j = 1; j < dp[0].size(); j++){
            
            if(s1[i - 1] == s2[j - 1]){
                // check diagonally above and add 1
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            
            else{
                // not a common substring if current characters don't match
                dp[i][j] = 0;
            }
            
            // update the maxLen
            if(dp[i][j] > maxLen){
                maxLen = dp[i][j];
            }
            
        }
    }
    
    // note that longest common substring length can be stored anywhere in dp[]. Thus we have a maxLen variable
    cout<<maxLen<<endl;
}


int main()
{
    string s1, s2;
    cin>>s1>>s2;
    
    longest_common_substring(s1, s2);
    
    return 0;
}