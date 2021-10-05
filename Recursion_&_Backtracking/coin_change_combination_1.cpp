#include<iostream>
#include<string>
#include<vector>
using namespace std;


void coinChangeCombination1(int *coins, int n, int idx, int amt, int curAmt, string asf)
{
    if(idx == n){
        // print asf if the curAmt == amt
        if(curAmt == amt){
            cout<<asf<<"."<<endl;
        }
        
        return;
    }
    
    // coins[idx] has 2 choice: 
    
    // 1. come in the answer.
    coinChangeCombination1(coins, n, idx + 1, amt, curAmt + coins[idx], asf + to_string(coins[idx]) + "-");
    
    // 2. Don't come in the answer
    coinChangeCombination1(coins, n, idx + 1, amt, curAmt, asf);
    
}


int main()
{
    int n;
    cin>>n;
    
    int *coins = new int[n];
    for(int i = 0; i < n; i++){
        cin>>coins[i];
    }
    
    int amount;
    cin>>amount;
    
    coinChangeCombination1(coins, n, 0, amount, 0, "");
    
    return 0;
}