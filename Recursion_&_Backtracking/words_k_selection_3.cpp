#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;


void words_combination(string uniqueStr, unordered_map<char, int>& charCount, int idx, int k, string asf)
{
    if(k == 0){
        cout<<asf<<endl;
        return;
    }
    
    if(idx == uniqueStr.size()){
        return;
    }
    
    
    // try the "idx"-th character of uniqueStr charCount[uniqueStr[idx]] no. of times
    char ch = uniqueStr[idx];

    // for(int i = charCount[ch]; i >= 0; i--){
    //     string s = "";
    //     // try current char - 0 times, 1 times, 2 times... 
    //     for(int j = 0; j < i; j++){
    //         s += ch;
    //     }

    //     // decrease the length k by "i" since string "s" is of length i
    //     words_combination(uniqueStr, charCount, idx + 1, k - i, asf + s);
    // }


    // NOTE: Using recursion to replace the above for loop.
    if(charCount[ch] != 0){
        // reduce the count
        charCount[ch]--;
        
        // NOTE: use it and give the SAME CHARACTER another chance (NOT DOING idx + 1)
        words_combination(uniqueStr, charCount, idx, k-1, asf + ch);
        
        // increment the count BACKTRACKING
        charCount[ch]++;
    }
    
    // since #k(slots) < #chars => character has a choice not to come in slot
    // NO ki call
    // go to next char
    words_combination(uniqueStr, charCount, idx + 1, k, asf);
    
}


int main()
{
    string str;
    cin>>str;
    
    int k;
    cin>>k;
    
    string uniqueStr = "";
    
    unordered_map <char, int> charCount;
    
    for(char ch : str){
        if(charCount.find(ch) == charCount.end()){
            charCount[ch] = 1;
            uniqueStr += ch;
        }
        else{
            charCount[ch]++;
        }
    }
    
    words_combination(uniqueStr, charCount, 0, k, "");
    
    return 0;
}