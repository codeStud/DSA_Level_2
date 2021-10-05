// Watch the youtube video bottom-up table filling to understand how below recursion is working in practice.

// NOTE: Assumptions:
// 1) First turn - mine
// 2) Opponent will always choose the coin number such that I'll get lesser value to choose in my next turn.
// Note that opponent may choose lesser value himself in order to give me a worst choice in my turn.
// Eg: 4 5 10 6 2 1
// 1st turn (mine) - choose max => 4  (remaining: 5 10 6 2 1)
// 2nd turn (opp) - choose such that I'll get least in next turn => choose 1 (NOT 5)  (remaining: 5 10 6 2)
// 3rd turn (mine) - choose max => 5  (remaining: 10 6 2)
// 4th turn (opp) - choose such that I'll get least in next turn => choose 10 (remaining: 6 2)
// so on....

// NOTE: Thus, choose BEST IN YOUR TURN  &&  YOU'LL GET WORST (i.e min) AFTER OPPONENTS TURN

// NOTE: I can either choose from left-extreme OR right-extreme && opponent will choose such that I'll get min
// in the next turn. Thus, I'll choose both left-extreme & right-extreme, and let opponent give me the worst choice.
// The max amongst the leftchoice & rightchoice will be the final answer.

#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;


int optimal_strategy(vector<int> arr, int n, int i, int j, vector<vector<int>>& dp)
{
    // Return INT_MAX bcz you're calculating min() in the recursive call
    if(i > j){
        return INT_MAX;
    }
    
    // Only 1 coin remains
    if(i == j){
        return arr[i];
    }
    
    // two coins remaining. I'll choose the max as first chance is mine.
    if(i+1 == j){
        return max(arr[i], arr[j]);
    }
    
    // Memoization
    if(dp[i][j] != INT_MAX){
        return dp[i][j];
    }
    
    // Select arr[i], i.e left-extreme
    // I'll get arr[i] + Opponent will get (i+1 to j)
    // Opponent will select a number (arr[i+1] or arr[j]) such that I'll get minimum to choose amongst ((i+2, j), (i+1, j-1)) in the next turn.
    
    int leftSelect = arr[i] + min( optimal_strategy(arr, n, i + 2, j, dp), optimal_strategy(arr, n, i + 1, j - 1, dp) );
    
    // Select arr[j], i.e right-extreme
    // I'll get arr[j] + Opponent will get (i to j-1)
    // Opponent will select a number (arr[i] or arr[j-1]) such that I'll get minimum to choose amogst ((i+2, j), (i+1, j-1)) in the next turn.
    
    int rightSelect = arr[j] + min( optimal_strategy(arr, n, i + 1, j - 1, dp), optimal_strategy(arr, n, i, j - 2, dp) );
    
    // to make the maxScore, take whatever gives you maximum value
    dp[i][j] = max(leftSelect, rightSelect);
    
    return dp[i][j];
}


int main()
{
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    
    cout<<optimal_strategy(arr, n, 0, n-1, dp);
    
    return 0;
}