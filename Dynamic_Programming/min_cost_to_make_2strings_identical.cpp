// NOTE: Watch youtube video for this lecture to Understand why the below approach WOULDN'T WORK for - "Minimum Ascii delete sum for two strings"

#include<iostream>
#include<string>
#include<vector>
using namespace std;


int LCS(string s1, string s2)
{
    vector <vector<int>> dp (s1.size() + 1, vector<int> (s2.size() + 1));
    
    for(int i = 0; i <= s1.size(); i++){
        for(int j = 0; j <= s2.size(); j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[s1.size()][s2.size()];
}


void min_cost_identical(string s1, string s2, int c1, int c2)
{
    // get the LCS(s1, s2) => you'll have the longest common-subseq. => you'll know the minNumber of chars to delete from s1, s2.
    
    int lcsLen = LCS(s1, s2);
    
    int removalsInS1 = s1.size() - lcsLen;
    int removalsInS2 = s2.size() - lcsLen;
    
    int minCost = (c1 * removalsInS1) + (c2 * removalsInS2);
    
    cout<<minCost<<endl;
}


int main()
{
    string s1, s2;
    cin>>s1>>s2;
    
    int c1, c2;
    cin>>c1>>c2;
    
    min_cost_identical(s1, s2, c1, c2);
    
    return 0;
}