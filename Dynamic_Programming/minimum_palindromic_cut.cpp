// NOTE: Two Strategies to solve this problem, just like rod-cutting.

// Method-1: All-Possible-Cuts
// Cut string at all possible places and then take the minimum amongst all the values of 
// [min (left-half-min-cut, right-half-min-cut) + 1]
// Eg: "abccbc" -> min[ ("a", "bccbc") vs ("ab", "ccbc") vs ("abc", "cbc") vs ("abcc", "bc") vs ("abccb", "c") ] + 1

// Method-2: Optimized-Cuts-Only
// Traverse the string from behind taking the suffix-substring and MAKE CUT ONLY IF THE SUFFIX-SUBSTRING 
// is already a PALINDROME. Then take minimum amongst all such cuts + 1.
// Eg: "abccbc" -> min[ ("abccb", "c") vs ("abc", "cbc") ] + 1. (Note that suffix-substring is palindrome & we'll find 
// minCut for the remaining left-part of the string recursively). (Could have solved using prefix-substring also)

#include<iostream>
#include<vector>
#include<climits>
#include<string>
using namespace std;


void min_palindromic_cut(string str)
{
    // Mark all the palindromic substrings
    vector<vector<bool>> dp (str.size(), vector<bool> (str.size()));
    
    for(int gap = 0; gap < str.size(); gap++){
        for(int i = 0, j = gap; j < dp[0].size(); i++, j++){
            if(gap == 0){
                dp[i][j] = true;
            }
            
            else if(gap == 1){
                if(str[i] == str[j]){
                    dp[i][j] = true;
                }
                else{
                    dp[i][j] = false;
                }
            }
            
            else{
                dp[i][j] = (str[i] == str[j]) && (dp[i + 1][j - 1]);
            }
        }
    }
    

    // NOTE: METHOD-1: All-Possible-Cuts [O(n^3)]

    // vector<vector<int>> cache (str.size(), vector<int> (str.size()));
    
    // for(int gap = 0; gap < str.size(); gap++){
    //     for(int i = 0, j = gap; j < cache[0].size(); i++, j++){
            
    //         if(gap == 0){
    //             cache[i][j] = 0;
    //         }
            
    //         else if(gap == 1){
    //             if(str[i] == str[j]){
    //                 cache[i][j] = 0;
    //             }
    //             else{
    //                 cache[i][j] = 1;
    //             }
    //         }
            
    //         else{
                
    //             if(dp[i][j] == true){
    //                 cache[i][j] = 0;
    //             }
                
    //             else{
    //                 int minCut = INT_MAX;
                
    //                 for(int k = i; k < j; k++){
    //                     int left = cache[i][k];
    //                     int right = cache[k + 1][j];
                        
    //                     if(left + right + 1 < minCut){
    //                         minCut = left + right + 1;
    //                     }
    //                 }
                    
    //                 cache[i][j] = minCut;
    //             }
                
    //         }
            
    //     }
    // }
    
    // cout<<cache[0][str.size() - 1];
    
    // NOTE: METHOD-2: Optimized-Cuts-Only [O(n^2)]

    vector <int> cache (str.size());
    cache[0] = 0;
    
    // fill cache[] starting from 1 till end
    for(int j = 1; j < cache.size(); j++){
        
        // if the entire string starting from 0, ending at j is already palindome => minCut = 0
        if(dp[0][j] == true){
            cache[j] = 0;
        }
        
        else{
            int minCut = INT_MAX;
            // endPoint = j
            // Vary startPoint "i" from j, j-1, j-2 ... 1 (Not till 0 bcz dp[0][j] has already been checked above)
            for(int i = j; i >= 1; i--){
                // cut only if current suffix-substring is a palindrome => if "i" se "j" is already palindome => 0 cuts req.
                // => "0" se "i-1" substring is reamining now.
                if(dp[i][j] == true){
                    // minCut for remaining left-part of string ("0" se "i-1") will be stored at cache[i-1]
                    // Also +1 bcz we are cutting the string into two parts - [0 to (i-1)] & [i to j]
                    if(cache[i - 1] + 1 < minCut){
                        minCut = cache[i - 1] + 1;
                    }
                }
            }
            
            cache[j] = minCut;
        }
    }
    
    cout<<cache[str.size() - 1];
}


int main()
{
    string str;
    cin>>str;
    
    min_palindromic_cut(str);
    
    return 0;
}