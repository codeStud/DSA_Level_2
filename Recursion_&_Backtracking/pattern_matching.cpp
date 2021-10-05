#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;


void patternMatching(string remainingStr, string pat, int idx, unordered_map<char, string>& patMap)
{
    if(idx == pat.size()){
        // string should also be over
        if(remainingStr.size() == 0){
            
            // for printing non-repeated char
            unordered_set <char> hash;
            
            for(int i = 0; i < pat.size(); i++){
                // if char appearing for the first time
                if(hash.find(pat[i]) == hash.end()){
                    // insert the current char in hash
                    hash.insert(pat[i]);
                    // print
                    cout<<pat[i]<<" -> "<<patMap[pat[i]]<<", ";
                }
            }
            cout<<"."<<endl;
        }
        
        return;
    }
    
    // if current pattern char is already mapped
    if(patMap.find(pat[idx]) != patMap.end()){
        // get the mapping
        string oldMappedVal = patMap[pat[idx]];
        
        // check if remainingString is atleast of size oldMappedVal
        if(remainingStr.size() >= oldMappedVal.size()){
            // take the substring of oldMappedVal size from remainingStr
            string newMappedVal = remainingStr.substr(0, oldMappedVal.size());
            
            // get the remaining string
            string restOfStr = remainingStr.substr(oldMappedVal.size());
            
            // check if both the mappings are same or not
            if(oldMappedVal == newMappedVal){
                // continue your calls
                patternMatching(restOfStr, pat, idx + 1, patMap);
            }
            else{
                // no such mapping possible
                return;
            }
        }
        
        else{
            // no such mapping possible
            return;
        }
        
    }
    
    // else if the current char of pattern is seen for the first time
    else{
        // try all the substring for mapping
        for(int i = 0 ; i < remainingStr.size(); i++){
            string substring = remainingStr.substr(0, i+1);
            string restOfStr = remainingStr.substr(i+1);
            
            // map current substring to the current pattern character
            patMap[pat[idx]] = substring;
            
            patternMatching(restOfStr, pat, idx + 1, patMap);
            
            // remove the mapping to try mapping of current pattern character with another substring, BACKTRACKING
            patMap.erase(pat[idx]);
        }
    }
}


int main()
{
    string str, pattern;
    cin>>str>>pattern;
    
    unordered_map <char, string> patternMap;
    
    patternMatching(str, pattern, 0, patternMap);
    
    return 0;
}