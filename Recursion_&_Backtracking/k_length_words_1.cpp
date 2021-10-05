// NOTE: Notice how it's similar to permutation-2 question but also a bit different.
// In permutation-2: Since, #boxes > #items => box has a choice to remain empty. So, box can be either empty or can included unvisited items.
// In this question: #item (abc) > #boxes(k=2, thus _ _) => items will have choice to not go in the box.

// It is same as permutation-1 question (each item has k spots to go. So it can go in any of the unvisited spot) 
// + item also has a choice to NOT go in any box as in the final result, all items can't be included as #items > #spots

#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;


void words_k_length(string str, int curCharIdx, int selectedCharCount, int k, vector<char>& spots)
{
    if(curCharIdx == str.size()){
        if(selectedCharCount == k){
            for(int i = 0; i < spots.size(); i++){
                cout<<spots[i];
            }
            cout<<endl;
        }
        return;
    }
    
    // get the current char
    char ch = str[curCharIdx];
    
    // loop through each spot & give chance to each char to sit in each empty spot
    for(int i = 0; i < spots.size(); i++){
        if(spots[i] == '\0'){
            // current character can come in the current spot.
            spots[i] = ch;
            
            // Try next character in the empty spots
            words_k_length(str, curCharIdx + 1, selectedCharCount + 1, k, spots);
            
            // BACKTRACK to place current char in other boxes
            spots[i] = '\0';
        }
    }
    
    // since #characters > #spots, character has a choice to NOT come in the spot
    words_k_length(str, curCharIdx + 1, selectedCharCount, k, spots);
}


int main()
{
    string str;
    cin>>str;
    
    int k;
    cin>>k;
    
    // get unique characters
    unordered_set <char> hash;
    // form unique string
    string uniqueStr = "";
    
    for(char c : str){
        if(hash.find(c) == hash.end()){
            hash.insert(c);
            uniqueStr += c;
        }
    }
    
    vector <char> spots(k, '\0');
    
    words_k_length(uniqueStr, 0, 0, k, spots);
    
    return 0;
}