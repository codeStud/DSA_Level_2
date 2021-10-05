#include<iostream>
#include<string>
using namespace std;


bool isPalindrome(string s)
{
    int i = 0;
    int j = s.size() - 1;
    
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        
        i++;
        j--;
    }
    
    return true;
}


void allPalindromicPartitions(string str, string asf)
{
    if(str.size() == 0){
        cout<<asf<<endl;
        return;
    }
    
    // take all the palindromic SUBSTRINGS possible
    for(int i = 0; i < str.size(); i++){
        // create substring of length 0, 1 .... n
        string substring = str.substr(0, i+1);
        
        if(isPalindrome(substring)){
            string restOfString = str.substr(i+1);
            // make the recursive call with restOfString and append substring to asf
            allPalindromicPartitions(restOfString, asf + "(" + substring + ") ");
        }
    }
}


int main()
{
    string str;
    cin>>str;
    
    allPalindromicPartitions(str, "");
    
    return 0;
}