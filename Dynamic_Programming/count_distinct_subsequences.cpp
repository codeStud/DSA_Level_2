#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

int main()
{
    string str;
    cin>>str;
    
    unordered_map <char, long> lastOccurance;
    
    vector<long> dp(str.size() + 1);
    
    // empty string has 1 subsequence " "
    dp[0] = 1;
    
    // traverse in dp
    for(int i = 1; i < dp.size(); i++){
        char ch = str[i-1];
        
        dp[i] = 2 * dp[i-1];  // curchar will come with prevSubseq + curChar won't come with prevSubseq
        
        // if this character has already occured before => "curChar will come with prevSubseq" will generate duplicates, 
        // whose count = count of subsequences just before the previous occurance of the current character. 
        
        if(lastOccurance.find(ch) != lastOccurance.end()){
            // Subtract the count of subsequences JUST BEFORE the previous occurance of the current character
            int prevOccurance = lastOccurance[ch];
            dp[i] = dp[i] - dp[prevOccurance - 1];
        }
        
        // keep inserting / updating the lastOccurance of "ch" in dp (= 'i') (NOT i-1 since ch(=str[i-1]) is mapped to "i"th index of dp)
        // and we want character's index in dp[]
        lastOccurance[ch] = i;
    }
    
    
    // to print non-empty subsequence, subtract 1 from final answer
    cout<<dp[str.size()] - 1<<endl;
    
    return 0;
}