// Don't see this question as permutation or combination. We may be using those concepts here, 
// But read the question and then come up with a general solution like below steps -

// 1. For aabb, we have 4 spots - _ _ _ _
// 2. Each character can have choices to be in any of the empty cell BUT - 
// ( a _ _ _ --> a a _ _ ) AND (_ a _ _ --> a a _ _) will generate DUPLICACY. Similarly,
// ( a a b _ --> a a b b ) AND (a a _ b --> a a b b) will also generate duplicates.

// And then see whether you can apply permutation concepts or combination concepts.

// In the premutation_words_1, we avoided such duplicacy by giving each box choice of ONLY UNIQUE characters.

// In this problem, to avoid duplicacy - "Each character can sit in any empty cell + Will come only AFTER the occurance of previous SAME character"
// (Like "combinations-2" but little different because - here can place after the occurance of previous SAME character 
// & in combination-2, we can place only after the occurance of any previous character)

#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;


void permutations_words_2(string str, int idx, vector<char>& spots, map<char, int>& lastOccurance)
{
    if(idx == str.size()){
        for(int i = 0; i < spots.size(); i++){
            cout<<spots[i];
        }
        cout<<endl;
        return;
    }
    
    char curChar = str[idx];
    int last = lastOccurance[curChar];
    
  // give curChar and opportunity to be in each empty box AFTER lastOccurance of curChar
    for(int i = last + 1; i < spots.size(); i++){
        if(spots[i] == '\0'){
            // put char in current empty spot
            spots[i] = curChar;
            // update the lastOccurance
            lastOccurance[curChar] = i;
            
            permutations_words_2(str, idx + 1, spots, lastOccurance);
            
            // BACKTRACKING
            spots[i] = '\0';        // make it null again
            // NOTE: Restore the lastOccurance[curChar] to it's state previous to the recursive call, i.e "last" variable
            lastOccurance[curChar] = last;
        }
    }
}


int main()
{
    string str;
    cin>>str;
    
    int n = str.size();
    vector <char> spots(n, '\0');
    
    // declare a map to store the last occurance of each UNIQUE character
    map <char, int> lastOccurance;
    for(char c : str){
        lastOccurance[c] = -1;
    }

    permutations_words_2(str, 0, spots, lastOccurance);    
    
    return 0;
}