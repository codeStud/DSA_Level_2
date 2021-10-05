#include<iostream>
#include<string>
#include<vector>
using namespace std;


void pattern_matching(string str, string pat)
{
    vector<vector<bool>> dp(pat.size() + 1, vector<bool> (str.size() + 1));
    
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[0].size(); j++){
            
            // empty pat matches empty str
            if(i == 0 && j == 0){
                dp[i][j] = true;
            }
            
            // empty pattern doesn't match non-empty string
            else if(i == 0){
                dp[i][j] = false;
            }
            
            // empty string is matched only by "" or '*'
            else if(j == 0){
                if(pat[i - 1] == '*'){
                    dp[i][j] = dp[i - 1][j];
                }
                else{
                    dp[i][j] = false;
                }
            }
            
            else{
                if(pat[i - 1] == '?'){
                    // ? matches any single char => go diagonally and check rest
                    dp[i][j] = dp[i-1][j-1];
                }
                
                else if(pat[i - 1] == '*'){
                    // * can match empty => look just above && * can match any other substring => look just left (i.e * becomes current char and is still alive to match remaining chars)    
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                
                else if(pat[i-1] == str[j-1]){
                    // check for remaining string and remaining pattern => diagonally
                    dp[i][j] = dp[i-1][j-1];
                }
                
                else{
                    dp[i][j] = false;
                }
            }
        }
    }
    
    if(dp[pat.size()][str.size()]){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    
}


int main()
{
    string str, pat;
    cin>>str>>pat;
    
    pattern_matching(str, pat);
    
    return 0;
}