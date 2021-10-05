// NOTE: Notice how regex is different from wildcard.

#include<iostream>
#include<string>
#include<vector>
using namespace std;


void regex_matching(string str, string pat)
{
    vector<vector<bool>> dp (pat.size() + 1, vector<bool> (str.size() + 1));
    
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[0].size(); j++){
            
            // empty pat matches empty str
            if(i == 0 && j == 0){
                dp[i][j] = true;
            }
            
            // empty pat doesn't match and str
            else if(i == 0){
                dp[i][j] = false;
            }
            
            // empty str only matched by (any_char)* & empty pat
            else if(j == 0){
                if(pat[i - 1] == '*'){
                    // look 2 row above bcz if s* => when * = 0, "" pat can match "" str
                    dp[i][j] = dp[i-2][j];
                }
                else{
                    dp[i][j] = false;
                }
            }
            
            else{
                
                if(pat[i - 1] == '.'){
                    // . matches any single char => look diagonally up
                    dp[i][j] = dp[i - 1][j - 1];
                }
                
                
                else if(pat[i - 1] == '*'){
                    // Eg: abcs* => when * = 0, abc => look 2 rows above
                    // Also, to match abcs, abcss, abcsss.... (equivalent to abcss*) => if curStrChar == 's' && curPatChar == '*' then -
                    // match that s, reduce the string by 1 len, and still be in abcs*
                    // Eg: str:"abss" pat:"abs*"  => ("abss"->"ab", when * = 0) && ("abs"->"abs*", when * matches last 's' & still survives)
                    // But when "abd" matching with "abs*", Only see ("abd"->"ab", when * = 0) bcz when (* = 1 (or more), it can't match 'd') 
                    
                    // pat[i-1] is * => pat[i-2] is 's' (for s*). Also, '.' can match any stringChar
                    if(str[j - 1] == pat[i - 2] || pat[i - 2] == '.'){       
                        // look 2 rows above, i.e when * == 0 && look just left, 
                        // i.e reduce the string after matching but pattern remains same
                        dp[i][j] = dp[i - 2][j] || dp[i][j - 1];
                    }
                    
                    else{
                        // if str = abc (or abd) & pat = abcs* => curStrChar 'c' != charBefore* 's' => * has only one choice of being = 0
                        dp[i][j] = dp[i - 2][j];
                    }
                    
                }
                
                
                else if(pat[i - 1] == str[j - 1]){
                    // current strChar matched with current patChar => look diagonally 
                    dp[i][j] = dp[i - 1][j - 1];
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
    
    regex_matching(str, pat);
    
    return 0;
}