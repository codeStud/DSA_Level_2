#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*

// i1 and i2 are start index of current src, dest strings respectively
int distinct_transformations(string src, string dest, int indexSrc, int indexDest, vector<vector<int>>& dp)
{
    // base case
    if(indexSrc == src.size()){
        if(indexDest == dest.size()){
            // 1 distinct way to make them equal
            return 1;
        }
        else{
            // they can't be made equal
            return 0;
        }
    }
    
    if(indexDest == dest.size()){
        // Remove ALL the src characters to make it equal to dest => 1 Distinct way
        return 1;
    }
    
    // MEMOIZATION
    if(dp[indexSrc][indexDest] != -1){
        return dp[indexSrc][indexDest];
    }
    
    int distinctWays = 0;
    
    // if current chars are equal, then -
    if(src[indexSrc] == dest[indexDest]){
        // exclude the current src character and match remaining src string with dest
        int exclude = distinct_transformations(src, dest, indexSrc + 1, indexDest, dp);
        
        // include the current src character => match remaining src string with remaining dest string
        int include = distinct_transformations(src, dest, indexSrc + 1, indexDest + 1, dp);
        
        distinctWays = exclude + include;
    }
    
    else{
        // if characters not matching then src character must be excluded
        distinctWays = distinct_transformations(src, dest, indexSrc + 1, indexDest, dp);
    }
    
    dp[indexSrc][indexDest] = distinctWays;
    return distinctWays;
}

*/


void distinct_transformations(string src, string dest)
{
    vector<vector<int>> dp (src.size() + 1, vector<int> (dest.size() + 1));
    
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[0].size(); j++){
            
            // blank src to blank target - 1 way
            if(i == 0 && j == 0){
                dp[i][j] = 1;
            }
            
            // blank src to non-empty target => 0 ways
            else if(i == 0){
                dp[i][j] = 0;
            }
            
            // non-empty src to empty target => 1 Way (remove all characters of src)
            else if(j == 0){
                dp[i][j] = 1;
            }
            
            else{
                // current chars equal => // (exclude the current src character and match remaining src 
                // string with dest) + (include the current src character => match remaining src string with remaining dest string)
                if(src[i - 1] == dest[j - 1]){
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                }
                
                else{
                    // if characters not matching then src character must be excluded
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    
    cout<<dp[dp.size() - 1][dp[0].size() - 1];
}


int main()
{
    string src, dest;
    cin>>src>>dest;
    
    // vector<vector<int>> dp (src.size(), vector<int> (dest.size(), -1));
    // cout<<distinct_transformations(src, dest, 0, 0, dp)<<endl;
    
    distinct_transformations(src, dest);
    
    return 0;
}