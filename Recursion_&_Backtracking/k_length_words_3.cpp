#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;


void k_length_words(string str, unordered_map<char, int>& hashMap, int idx, vector<char>& spots, int selectedCharCount, int totalSpot)
{
    if(idx == str.size()){
        if(selectedCharCount == totalSpot){
            for(int i = 0; i < spots.size(); i++){
                cout<<spots[i];
            }
            cout<<endl;
        }
        
        return;
    }
    
    char ch = str[idx];
    int lastSpotIndex = hashMap[ch];
    
    // to avoid permutation, make calls after the last occuring index of current char
    for(int i = lastSpotIndex + 1; i < spots.size(); i++){
        if(spots[i] == '\0'){
            // fill the spot
            spots[i] = ch;
            // update the lastSpotIndex to 'i'
            hashMap[ch] = i;
            
            k_length_words(str, hashMap, idx + 1, spots, selectedCharCount + 1, totalSpot);
            
            // BACKTRACKING
            spots[i] = '\0';
            hashMap[ch] = lastSpotIndex;
        }
    }
    
    //can make "NO" call only if ch didn't occured in any spot yet (to avoid duplicates)
    if(lastSpotIndex == -1){
        k_length_words(str, hashMap, idx + 1, spots, selectedCharCount, totalSpot);
    }
}


int main()
{
    string str;
    cin>>str;
    
    int k;
    cin>>k;
    
    // map will store the lastOccuring Index for each character    
    unordered_map <char, int> hashMap;
    
    for(char ch : str){
        if(hashMap.find(ch) == hashMap.end()){
            hashMap[ch] = -1;
        }
    }
    
    vector <char> spots(k, '\0');
    k_length_words(str, hashMap, 0, spots, 0, k);
    
    return 0;
}