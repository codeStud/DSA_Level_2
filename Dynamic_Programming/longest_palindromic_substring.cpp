// NOTE: Notice how managing substring is different from managing subsequence.
// In Subsequence: Every character has 2 choice - (1) Come (2) Don't come... (See level-1 Print Subsequence)
// In Substring: We consider all the CONTINUOUS substring starting from each of the characters. 
// Eg "abcd" -
// a, ab, abc, abcd
// b, bc, bcd
// c, cd
// d

// Easiest way to get substrings is the "gap-strategy". First print all substring of len=1, then len=2, ... len=str.size()

// NOTE: By intuition, you might want to store the length of Longest Palindromic substring at each cell. But then -
// You'd also have to store if each cell is substring or not (try & see). In below approach, we avoid storing 2 information.

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string str;
    cin>>str;
    
    // keep the maxLen of palindromic substring
    // NOTE: Each of the cell in upper triangular matrix in "gap-strategy" represents a Substring.
    // So, store if each substring (matrix box) is a substring or not. The box with max gap will be Longest Palindromic Substring.
    int maxLen = 0;
    
    // row (vertically down) stores the startIndex of substring
    // col (horizontal) stores the endIndex of substring
    //Eg- dp[1][6] => substring starting from INDEX-1 and ending at INDEX-6
    vector<vector<bool>> dp(str.size(), vector<bool> (str.size()));
    
    // gap between the startIndex and endIndex of substring
    for(int gap = 0; gap < str.size(); gap++){
        
        // traverse diagonally in the upper half diagonals by doing this -
        // for each gap - starting row: 0  starting col: gap  and go till last col in dp
        for(int i = 0, j = gap; j < dp[0].size(); i++, j++){
            
            // gap == 0  =>  startIndex and endIndex are same => 1 character(palindrome)
            if(gap == 0){
                dp[i][j] = true;
                // set maxLen to current gap + 1 (a => gap 0 => maxLen = 1)
                maxLen = gap + 1;
            }
            
            //gap == 1  =>  startIndex and endIndex differ by 1 in length => 2 chars
            else if(gap == 1){
                // check if characters are equal or not
                if(str[i] == str[j]){
                    dp[i][j] = true;
                    // set maxLen to current gap + 1 (aa => gap 1 => maxLen = 2)
                    maxLen = gap + 1;
                }
                else{
                    dp[i][j] = false;
                }
            }
            
            else{
                
                // Eg- "a bcb a" Check if start == end && "bcb" is palindrome or not
                if(str[i] == str[j] && dp[i+1][j-1] == true){
                    dp[i][j] = true;
                    // set maxLen to current gap + 1 (aba => gap 2 => maxLen = 3)
                    maxLen = gap + 1;
                }
                else{
                    dp[i][j] = false;
                }
                
            }
            
        }
    }
    
    // NOTE: since gap is increasing => last time when the maxLen would have been updated will be the maxLen palindromic SUBSTRING
    cout<<maxLen<<endl;
    
    return 0;
}