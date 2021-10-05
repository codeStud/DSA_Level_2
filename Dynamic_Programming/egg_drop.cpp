// NOTE: For real life senario of this problem + better understanding of how the solution is working
// - Watch Sumit sir's video.

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Since we just want the minimum attempt COUNT => 'f' is simply the count of the floor to throw eggs from.
int egg_drop(int e, int f, vector<vector<int>>& dp)
{
    // base cases
    if(f == 0 || f == 1){
        return f;
    }
    
    // if 1 egg => in WORST case, we might need f attempts to get a GUARANTEED answer
    else if(e == 1){
        return f;
    }
    
    if(dp[e][f] != -1){
        return dp[e][f];
    }
    
    // NOTE: You need to find the MIN attempts in WORST case => Now, take the minimum (MIN attempt) of all the max (WORST CASE) of 1 to f attempts
    int minAttempts = INT_MAX;
    
    // drop egg from 1st floor till last floor
    for(int i = 1; i <= f; i++){
        
        // You are taking 1 attempt here. Now, 2 things can happen -
        // (1) Egg breaks => egg decreases + throw from remaining i-1 bottom floors => solve for (e - 1, i - 1);
        // (2) Egg doesn't break => #eggs remain same + throw from (f - i) remaining top floors => solve for (e, f - i)
        // NOTE: You want WORST CASE COUNT => take max(1, 2)
        
        int curAttempt = 1 + max( egg_drop(e - 1, i - 1, dp), egg_drop(e, f - i, dp) );
        
        minAttempts = min(minAttempts, curAttempt);
        
    }
    
    // BEFORE RETURNING, store value in dp
    dp[e][f] = minAttempts;
    return dp[e][f];
}


int main()
{
    int n, k;
    cin>>n>>k;
    
    vector<vector<int>> dp (n + 1, vector<int>(k + 1, -1));
    cout<<egg_drop(n, k, dp);
    
    return 0;
}