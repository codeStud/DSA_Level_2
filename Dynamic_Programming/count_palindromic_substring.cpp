// NOTE: Notice how managing substring is different from managing subsequence.
// In Subsequence: Every character has 2 choice - (1) Come (2) Don't come... (See level-1 Print Subsequence)
// In Substring: We consider all the CONTINUOUS substring starting from each of the characters. 
// Eg "abcd" -
// a, ab, abc, abcd
// b, bc, bcd
// c, cd
// d

// Easiest way to get substrings is the "gap-strategy". First print all substring of len=1, then len=2, ... len=str.size()

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string str;
    cin>>str;
    
    // NOTE: Each of the cell in upper triangular matrix in "gap-strategy" represents a Substring.
    // So, just check if each cell is Palindromic or not and at last, count the "true" marked cells to get ALL Palindromic Substrings.
    int count = 0;
    
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
                // increase the count
                count++;
            }
            
            //gap == 1  =>  startIndex and endIndex differ by 1 in length => 2 chars
            else if(gap == 1){
                // check if characters are equal or not
                if(str[i] == str[j]){
                    dp[i][j] = true;
                    // increase the count
                    count++;
                }
                else{
                    dp[i][j] = false;
                }
            }
            
            else{
                
                // Eg- "a bcb a" Check if start == end && "bcb" is palindrome or not
                if(str[i] == str[j] && dp[i+1][j-1] == true){
                    dp[i][j] = true;
                    // increase the count
                    count++;
                }
                else{
                    dp[i][j] = false;
                }
                
            }
            
        }
    }
    
    cout<<count<<endl;
    
    return 0;
}