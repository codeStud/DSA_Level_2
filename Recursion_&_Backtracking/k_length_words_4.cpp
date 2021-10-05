#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


void kLengthWords(string uniqueStr, unordered_map<char, int>& hashMap, int curSpot, int totalSpot, string asf)
{
    if(curSpot == totalSpot){
        cout<<asf<<endl;
        return;
    }
    
    // spot is at level, characters at options
    // curSpot can have any of the uniqueStr characters IF it has some frequency remaining
    // No need of separate uniqueStr. Can use hashMap to loop through the unique chars
    for(int i = 0; i < uniqueStr.size(); i++){
        
        char ch = uniqueStr[i];
        if(hashMap[ch] > 0){
            // reduce the frequency of the current character
            hashMap[ch]--;
            
            // Append the char to asf. No need to use spots[], just have a curSpot variable for the base case
            kLengthWords(uniqueStr, hashMap, curSpot + 1, totalSpot, asf + ch);
            
            // BACKTRACKING
            hashMap[ch]++;
        }
        
    }
}


int main()
{
    string str;
    cin>>str;
    
    int k;
    cin>>k;
    
    unordered_map <char, int> hashMap;
    string uniqueStr = "";
    
    for(int i = 0; i < str.size(); i++){
        if(hashMap.find(str[i]) == hashMap.end()){
            hashMap[str[i]] = 1;
            uniqueStr += str[i];
        }
        else{
            hashMap[str[i]]++;
        }
    }
    
    kLengthWords(uniqueStr, hashMap, 0, k, "");
    
    return 0;
}