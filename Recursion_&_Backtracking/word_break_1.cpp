#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;

void wordBreak(string remainingStr, unordered_set<string>& hash, string asf)
{
    if(remainingStr.size() == 0){
        cout<<asf<<endl;
        return;
    }
    
    // try all possible substrings from the remainingStr
    for(int i = 0; i < remainingStr.size(); i++){
        string substring = remainingStr.substr(0, i+1);
        
        // if current substring is a valid word
        if(hash.find(substring) != hash.end()){
            // get the remaining string
            string restOfStr = remainingStr.substr(i+1);

            // append substring to answer and call with rest of the string
            wordBreak(restOfStr, hash, asf + substring + " ");
        }
    }
}

int main()
{
    int n;
    cin>>n;
    
    string word = "";
    unordered_set <string> hash;
    for(int i = 0; i < n; i++){
        cin>>word;
        // push the word into hashset
        hash.insert(word);
    }

    string sentence;
    cin>>sentence;
    
    wordBreak(sentence, hash, "");
    
    return 0;
}