#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;


void words_combination(string uniqueStr, unordered_map<char, int>& charCount, int curSpot, int k, string asf, int lastUsedCharIndex)
{
    if(curSpot == k){
        cout<<asf<<endl;
        return;
    }
    
    // loop starting from lastUsedCharIndex to avoid permutations
    // We are also including lastUsedCharIndex (& NOT doing lastUsedCharIndex + 1) bcz, repeated characters are also allowed!
    for(int i = lastUsedCharIndex; i < uniqueStr.size(); i++){
        char ch = uniqueStr[i];
        if(charCount[ch] > 0){
            charCount[ch]--;
            
            // move to next spot and for next character, lastUsedCharIdx = i
            words_combination(uniqueStr, charCount, curSpot + 1, k, asf + ch, i);
            
            charCount[ch]++;
        }
    }
    
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
    
    words_combination(uniqueStr, charCount, 0, k, "", 0);
    
    return 0;
}