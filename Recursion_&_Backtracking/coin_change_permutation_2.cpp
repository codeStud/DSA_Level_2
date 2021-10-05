#include<iostream>
#include<string>
#include<vector>
using namespace std;


void coin_change_permutations_1(vector<int>& coins, int tamt, int amtsf, string asf)
{
    if(amtsf > tamt){
        return;
    }
    
    // only this is sufficient as base case, bcz we are calling recursion smartly
    if(amtsf == tamt){
        cout<<asf<<"."<<endl;
        return;
    }
    
    // To generate Permutation: At current level, give each coin a chance.
    // Coins can be repeated, thus no need to check for used / unused coins.
    for(int i = 0; i < coins.size(); i++){

        coin_change_permutations_1(coins, tamt, amtsf + coins[i], asf + to_string(coins[i]) + "-");

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
    
    coin_change_permutations_1(coins, amt, 0, "");
    
    return 0;
}