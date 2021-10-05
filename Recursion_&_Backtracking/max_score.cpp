#include<iostream>
#include<string>
using namespace std;

int nofWords;

int maxScore(string* words, int* farr, int* score, int idx)
{
    // base case
    if(idx == nofWords){
        return 0;
    }
    
    // 1. Don't include the idx-th WORD
    int scoreNo = maxScore(words, farr, score, idx+1);
    
    // 2. Include the idx-th WORD
    
    // calculate the score for the idx-th WORD
    int currentWordScore = 0;
    bool flag = true;   // will help figuring if current word can be made or not
    
    for(int i = 0; i < words[idx].size(); i++){
        char ch = words[idx][i];
        
        // if no frequency remains for the current char, make flag = false
        if(farr[ch-'a'] == 0){
            flag = false;
        }
        
        // keep decrementing the frequency of current char
        farr[ch - 'a']--;
        
        // keep incrementing the score of current word
        currentWordScore += score[ch -'a'];
    }
    
    // if you were able to make the current word
    int scoreYes = 0;
    if(flag == true){
        scoreYes = currentWordScore + maxScore(words, farr, score, idx + 1);
    }
    
    // No need to make the below call as it is repetative of Don't include idx word
    /*
    else{
        scoreYes = maxScore(words, farr, score, idx + 1);
    }
    */
    
    // after the call, undo the changes made in farr (BACKTRACKING)
    for(int i = 0; i < words[idx].size(); i++){
        char ch = words[idx][i];
        farr[ch - 'a']++;
    }
    
    // like faith and expectation - 
    // scoreYes = include current word       + restOfScore
    // scoreNo = don't include current word  + restOfScore
    // return max of both    
    return max(scoreYes, scoreNo);
}
		

int main()
{
    cin>>nofWords;
    
    string words[nofWords];
    for(int i = 0; i < nofWords; i++){
        cin>>words[i];
    }
    
    int nofLetters;
    cin>>nofLetters;
    
    char letters[nofLetters];
    for(int i = 0; i < nofLetters; i++){
        cin>>letters[i];
    }
    
    int score[26];
    for(int i = 0; i < 26; i++){
        cin>>score[i];
    }
    
    
    // create a frequency array storing integer frequency count of each char
    int farr[26] = {0};
    for(char c : letters){
        farr[c - 'a']++;
    }
    
    cout<<maxScore(words, farr, score, 0);
    
    return 0;
}