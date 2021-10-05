// Don't see this question as permutation or combination. We may be using those concepts here, 
// But read the question and then come up with a general solution like below steps -

// Each UNIQUE character has 2 choices - (1) Come in the ans   (2) Don't come in the ans

// And then see whether you can apply permutation concepts or combination concepts.


#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;


void select_k_unique_chars(int k, int idx, int charCount, string uniqueStr, string asf)
{
    if(idx == uniqueStr.size()){
        // check if you've got a string of length 'k'
        if(asf.size() == k){
            cout<<asf<<endl;
        }
        
        return;
    }
        
    // get the current unique char
    char ch = uniqueStr[idx];
    
    // include + move to next char + increase the charCount
    select_k_unique_chars(k, idx + 1, charCount + 1, uniqueStr, asf + ch);

    // dont include + move to next char
    select_k_unique_chars(k, idx + 1, charCount, uniqueStr, asf);    
    
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
    
    select_k_unique_chars(k, 0, 0, uniqueStr, "");
    
    return 0;
}