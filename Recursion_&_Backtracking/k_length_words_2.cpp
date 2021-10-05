// Don't see this question as permutation or combination. We may be using those concepts here, 
// But read the question and then come up with a general solution with the help of all the learnt concepts.

// This is similar to Permutation-2 (the minor difference is here slot doesn't have a choice to remain empty. It must contain one of the chars as #slots < #chars)
// Also, in Permutation-2, items were at levels & had choice of going into any of the unused slots. (#items < #slots)
// Here, slots are at levels & each slot has choice of putting unused character. (#slots < #items)

// For "abc" & ( _ _ ) - each slot has 3 choices -> then 2 choices (unused chars)

#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;


// NOTE: We are not creating slots[] to store the result. We are simply using asf variable in place of that.
void k_length_words(string uniqueStr, int curSlot, int k, unordered_set<char>& visited, string asf)
{
    if(curSlot == k){
        cout<<asf<<endl;
        return;
    }
    
    // current slot index has choices amongst unvisited chars of uniqueStr
    for(int i = 0; i < uniqueStr.size(); i++){
        char ch = uniqueStr[i];
        // NOTE: We can use hash set for visited array purpose. It makes task more easy.
        if(visited.find(ch) == visited.end()){
            // mark it visited
            visited.insert(ch);
            
            // We don't need to backtrack "asf". It'll be restored to it's original state after every recursion returns.
            k_length_words(uniqueStr, curSlot + 1, k, visited, asf + ch);
            
            //BACKTRACKING
            visited.erase(ch);
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
    
    unordered_set <char> hash;
    
    for(char ch : str){
        if(hash.find(ch) == hash.end()){
            hash.insert(ch);
            uniqueStr += ch;
        }
    }
    
    unordered_set <char> visited;
    
    k_length_words(uniqueStr, 0, k, visited, "");
    
    return 0;
}