// Answer is correct, just the order is different due to map

// NOTE: Notice the difference between this code and "Print Permutations (Level-1)" (Visualise level and options)
// Looking at both the base cases might help understanding what is going on...

// NOTE: Using the approach in "Print Permutations (Level-1)" here will generate duplicates bcz there all the chars were distinct
// and here, chars may be reapeated. So, at each level, giving choice to each of the chars will generate duplicate.
// Watch the lecture time- 7:20 to understand the above concept.

// NOTE: Use "Print Permutations (Level-1)" approach if all characters of input are distinct, i.e when you can apply
// the maths formula - #Permutation(x) = len(x)! = n!
// Use "Below method for palindrome" if characters are reapeated, in order to avoid the duplicates. Here, you
// will have to apply maths formula - #permutation(x) = n! / a! b!  bcz reapeated chars.

// NOTE: In "Print Permutations (Level-1)" && "All Palindromic Permutations (Level-2)", "No. of items = No. of boxes"
// But in "Permutation 1" && "Permutation 2" (level 2), "No. of boxes > No. of items" + "No repeated items"
// Also, in "Permutation Word 1" && "Permutations Word 2" (level 2), "#boxes < #items" + "Repeated items"

#include<iostream>
#include<string>
#include<map>
using namespace std;


void palindromicPermutation(int strLen, int totalLen, map<char, int>& hashMap, string oddChar, string asf)
{
    if(strLen > totalLen){
        // cout<<"asf: "<<asf<<endl;
        // prepare reverse of asf
        string revAsf;
        for(int i = asf.size() - 1; i >= 0; i--){
            revAsf += asf[i];
        }
        
        string palindrome;
        // append asf
        palindrome += asf;
        
        // append odd char if any
        if(oddChar.size() > 0){
            palindrome += oddChar;
        }
        
        //append reverse string
        palindrome += revAsf;
        
        cout<<palindrome<<endl;
        
        return;
    }
    
    // for each UNIQUE character as options at the current level
    for(auto it : hashMap){
        // If it has some count left
        if(it.second > 0){
            int val = it.second;
            // reduce the frequency by 1
            
            hashMap[it.first] = val - 1;

            // call for the next idx in the string & append ch to asf
            palindromicPermutation(strLen + 1, totalLen, hashMap, oddChar, asf + it.first);
            
            // restore the frequency while returning back
            // DON'T DO (val + 1) otherwise it'd increase the freq by 1 & not restore it back to old value
            hashMap[it.first] = val;
        }
    }
}


int main()
{
    string str;
    cin>>str;
    
    map <char, int> hashMap;
    
    // hashMap stores UNIQUE characters and their count
    for(char ch : str){
        hashMap[ch]++;
    }
    
    int oddFreq = 0;
    string oddFreqChar = "";
    int len = 0;
    
    // reduce the frequency by half
    for(auto it : hashMap){
        
        int freq = it.second;
        
        if(freq % 2 == 1){
            oddFreq++;
            
            if(oddFreq > 1){
                cout<<"-1"<<endl;
                return 0;
            }
            
            oddFreqChar = it.first;
        }
        
        hashMap[it.first] = freq / 2;
        // find the length of the string obtained by reducing the freq by half
        len += freq / 2;
    }
    
    palindromicPermutation(1, len, hashMap, oddFreqChar, "");
    
    // cout<<len<<endl;
    // cout<<oddFreqChar<<endl;
    
    // for(auto it : hashMap){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    
    return 0;
}