// Don't see this question as permutation or combination. We may be using those concepts here, 
// But read the question and then come up with a general solution like below steps -

// Here you don't have to choose boxes, you've to choose characters. So, treat them like boxes & use combination-2 concept.
// At level 0: You can select either "a" or "b" or "c"
// At level 1: You can select only the characters after the character selected at previous level, i.e -
// "a --> b, a --> c"   "b --> c"   "c --> NONE"

// And then see whether you can apply permutation concepts or combination concepts.


#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;


void select_k_unique_chars(string str, int selectedCharCount, int k, string asf, int lastCharIndex)
{
    // Have made recursive call smartly, thus no need to check if index out of bounds
    if(selectedCharCount == k){
        cout<<asf<<endl;
        return;
    }

    // start looping in "str", AFTER the index of last selected character  
    for(int i = lastCharIndex + 1; i < str.size(); i++){
        char ch = str[i];
        // for the next char, pass the current index as lastCharIndex
        select_k_unique_chars(str, selectedCharCount + 1, k, asf + ch, i);
    }  
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
    
    select_k_unique_chars(uniqueStr, 0, k, "", -1);
    
    return 0;
}