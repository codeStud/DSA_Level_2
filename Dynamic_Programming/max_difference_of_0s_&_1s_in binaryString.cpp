// NOTE: We need to find max (#0's - #1's). So the trick is to replace 0 -> 1 (to get count of 0's)
// and 1 -> -1 (to subtract from count of 0's). And then to get the max difference, apply kadane's algorithm 
// to get the maxSum subarray which will represent the max difference of #0's AND #1'S

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int maxDiff(string str)
{
    // initialise maxVal with -1 bcz if 1111 then you've to return -1 bcz #0's = 0
    int maxVal = -1;
    int curVal = 0;
    
    for(char ch : str){
        int val = 0;
        
        // replace '0' with 1
        if(ch == '0'){
            val = 1;
        }
        
        // replace '1' with -1
        else if(ch == '1'){
            val = -1;
        }
        
        // kadane's
        if(curVal >= 0){
            curVal += val;
        }
        else{
           curVal = val; 
        }
        
        // update maxVal
        if(curVal > maxVal){
            maxVal = curVal;
        }
    }
    
    return maxVal;
}


int main()
{
    string str;
    cin>>str;
    
    cout<<maxDiff(str);
    
    return 0;
}