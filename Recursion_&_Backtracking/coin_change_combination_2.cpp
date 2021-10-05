// We are ensuring combination (& NOT Permutation) by keeping each of the denominations at different levels.
// If you express choices of all the denominations at the same level, you'll generate permutation (like previous backtracking & level-1 Dp coin-change-permutation)

#include<iostream>
#include<string>
#include<vector>
using namespace std;


void coin_change_combinations_2(vector<int>& coins, int idx, int amt, int curAmt, string asf)
{
    if(idx == coins.size()){
        if(amt == curAmt){
            cout<<asf<<"."<<endl;
        }
        
        return;
    }
    
    // get the current coin denomination
    int coinVal = coins[idx];
    
    // the current denomination coin can come from (amt/coinVal) times ..... 0 times
    for(int i = amt/coinVal; i >= 0; i--){
        
        // form string for the current number of coins being used
        // if i == 0, parts will remain an empty string
        string parts = "";
        for(int j = 0; j < i; j++){
            parts += to_string(coinVal) + "-";
        }
        
        // curAmt will increase by - coinVal * i (if i == 0 => curAmt won't change)
        coin_change_combinations_2(coins, idx + 1, amt, curAmt + coinVal * i, asf + parts);
    }
}


int main()
{
    int n;
    cin>>n;
    
    vector <int> coins (n);
    for(int i = 0; i < n; i++){
        cin>>coins[i];
    }
    
    int amt;
    cin>>amt;
    
    coin_change_combinations_2(coins, 0, amt, 0, "");
    
    return 0;
}