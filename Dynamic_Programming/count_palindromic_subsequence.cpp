 #include<iostream>
 #include<string>
 #include<vector>
 using namespace std;
 
 int main()
 {
    string str;
    cin>>str;
    
    // row (vertically down) stores the startIndex of substring
    // col (horizontal) stores the endIndex of substring
    //Eg- dp[1][6] => substring starting from INDEX-1 and ending at INDEX-6
    vector<vector<int>> dp(str.size(), vector<int> (str.size()));
    
    // gap between the startIndex and endIndex of substring
    for(int gap = 0; gap < str.size(); gap++){
        
        // traverse diagonally in the upper half diagonals by doing this -
        // for each gap - starting row: 0  starting col: gap  and go till last col in dp
        for(int i = 0, j = gap; j < dp[0].size(); i++, j++){
            
            // gap == 0  =>  startIndex and endIndex are same => 1 character
            if(gap == 0){
                dp[i][j] = 1;
            }
            
            //gap == 1  =>  startIndex and endIndex differ by 1 in length => 2 chars
            else if(gap == 1){
                if(str[i] == str[j]){
                    dp[i][j] = 3;  // Eg- "aa" => 'a',  'a',  'aa' (3)
                }
                else{
                    dp[i][j] = 2;   // Eg- "ab" => 'a',  'b'  (2)
                }
            }
            
            else{
                
                if(str[i] == str[j]){
                    // Eg- "a bcd a"
                    // +1 bcz of "aa" subsequence
                    // dp[i+1][j] bcz count palindrome in "bcda"
                    // dp[i][j-1] bcz count palindrome in "abcd"
                    // Also, count palindrome "bcd" is covered twice but we won't subtract it bcz: 
                    // ALL THE PALINDROMES IN "bcd" WILL ALSO MAKE PALINDROME SUBSEQUENCE WITH 'a' --- 'a'.
                    // So, counting palindrome "bcd" twice covers for - palindrome "bcd" and palindrome 'a' (bcd) 'a'
                    
                    // Eg- "aba" => "a a"(+1),  ["a",  "b"](ab),  ["b",  "a"](ba),  "aba"(Counted by not subtracting count("b"))
                    dp[i][j] = 1 + dp[i+1][j] + dp[i][j-1];
                    
                }
                
                else{
                    // Eg- "a bcd e"
                    // dp[i+1][j] bcz count palindrome in "bcde"
                    // dp[i][j-1] bcz count palindrome in "abcd"
                    // - dp[i+1][j-1] bcz count of palindrome subseq. in "bcd" is counted twice.
                    // Eg- "abc" => ['a', 'b'](ab),  ['b', 'c'](bc),   (-'b')
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
                }
                
            }
            
        }
        
    }
    
    cout<< dp[0][str.size()-1];
    
    return 0;
 }