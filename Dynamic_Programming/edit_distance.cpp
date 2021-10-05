#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


void min_edit_distance(string s1, string s2)
{
    vector<vector<int>> dp (s1.size() + 1, vector<int> (s2.size() + 1));
    
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[0].size(); j++){
            
            // if s1="" & s2.size() = j => make 'j' insertions to make s1=s2
            if(i == 0){
                dp[i][j] = j;
            }
            
            // if s2="" & s1.size() = i => make 'i' deletions to make s1=s2
            else if(j == 0){
                dp[i][j] = i;
            }
            
            else{
                // char of s1 & s2 are mapped to i-1 and j-1 respectively
                if(s1[i - 1] == s2[j - 1]){
                    // No edit required. Check for remaining string
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    // insert in s1 => s1 length remains same after matching the inserted char, but since 1 char from s2 is matched => reduce s2 length by 1.
                    int insertChar = dp[i][j - 1];
                    
                    // delete in s1 => s1 length reduced by 1 and s2 length remains same
                    int deleteChar = dp[i - 1][j];
                    
                    // replace => both chars matched => length of s1 & s2 reduced by 1
                    int replaceChar = dp[i - 1][j - 1];
                    
                    // Take minimum of all three + 1(for current operation)
                    dp[i][j] = min({insertChar, deleteChar, replaceChar}) + 1;    
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
    
    min_edit_distance(s1, s2);
    
    return 0;
}