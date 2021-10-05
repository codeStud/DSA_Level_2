#include<iostream>
#include<string>
using namespace std;

string maxVal;

string swap(string s, int i, int j)
{
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    
    return s;
}

void largestNumWithKswaps(string str, int k)
{
    // update the maxVal before returning even in case if k == 0
    // as the k == 0 case str might be larger
    if(stoi(maxVal) < stoi(str)){
        maxVal = str;
    }
    
    if(k == 0){
        return;
    }
    
    for(int i = 0; i < str.size() - 1; i++){
        for(int j = i+1; j < str.size(); j++){
            if(str[j] > str[i]){
                // METHOD-1: Normal Recursion
                // string swappedStr = swap(str, i, j);
                // largestNumWithKswaps(swappedStr, k - 1);
                
                // Method-2 : BACKTRACKING
                str = swap(str, i, j);
                largestNumWithKswaps(str, k - 1);
                str = swap(str, i, j);  // get the previous str back
            }
        }
    }
}

int main()
{
    string str;
    cin>>str;
    
    int k;
    cin>>k;
    
    maxVal = str;
    
    largestNumWithKswaps(str, k);
    cout<<maxVal<<endl;
    
    return 0;
}