// NOTE: Application of Catalan number

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int pointPair;
    cin>>pointPair;
    
    vector <long> dp (pointPair + 1);
    
    // 0 pointPair can make 1 chord (empty)
    dp[0] = 1;
    
    // 1 pointPair can make 1 chord
    dp[1] = 1;
    
    // for 2 ... n pointPairs
    for(int i = 2; i <= pointPair; i++){
        
        // NOTE: to keep chords non-intersecting, draw one chord and then -
        // 1. Put chords on left (or before) this drawn chord.
        // 2. Put chords on the right (or after) this drawn chord.
        // This will ensure that NO chord CROSSES the drawn chord => Non-Intersecting
        
        // initially no chord on left side (or above, whichever way you see) 
        int leftSideChords = 0;
        // initally, all the remaining i - 1 chords on the right side of the drawn chord
        int rightSideChords = i - 1;
        
        while(rightSideChords >= 0){
            
            dp[i] += dp[leftSideChords] * dp[rightSideChords];
            
            leftSideChords++;
            rightSideChords--;
        }
    }
    
    cout<<dp[pointPair]<<endl;
    
    return 0;
}