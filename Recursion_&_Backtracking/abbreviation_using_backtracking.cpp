#include<iostream>
#include<string>
using namespace std;


void abbreviations(string str, string asf, int pos, int count)
{
    // base case
    if(pos == str.size()){
        if(count > 0){
            // print prev answer + current count
            cout<<asf + to_string(count)<<endl;
        }
        else{
            // simply print the answer
            cout<<asf<<endl;
        }
        
        return;
    }
    
    // 1. Inlclude the current char
    if(count > 0){
        // keep previous answer + include the count + include current char & set count=0
        abbreviations(str, asf + to_string(count) + str[pos], pos+1, 0);
    }
    else{
        // keep previous answer + include current char & set count=0
        abbreviations(str, asf + str[pos], pos+1, 0);
    }
    
    // 2. Don't include the current char
    // pass count+1 (Don't pass like count++ otherwise on returning back from calls, count value will change in the current execution context)
    abbreviations(str, asf, pos+1, count+1);
}


int main()
{
    string str;
    cin>>str;
    
    abbreviations(str, "", 0, 0);
    
    return 0;
}