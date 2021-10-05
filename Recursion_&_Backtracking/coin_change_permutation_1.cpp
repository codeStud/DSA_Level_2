#include<iostream>
#include<string>
#include<vector>
using namespace std;


void coin_change_permutations_1(vector<int>& coins, int tamt, int amtsf, string asf, vector<bool>& visited)
{
    if(amtsf > tamt){
        return;
    }
    
    // only this is sufficient as base case, bcz we are calling recursion smartly
    if(amtsf == tamt){
        cout<<asf<<"."<<endl;
        return;
    }
    
    // To generate Permutation: At current level, give each UNUSED coins chance.
    // UNUSED bcz coins aren't supposed to be repeated
    for(int i = 0; i < coins.size(); i++){
        if(visited[coins[i]] == false){
            // use it
            visited[coins[i]] = true;
            
            coin_change_permutations_1(coins, tamt, amtsf + coins[i], asf + to_string(coins[i]) + "-", visited);
            
            // BACKTRACK
            visited[coins[i]] = false;
        }
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
    
    vector <bool> visited (n, false);
    
    coin_change_permutations_1(coins, amt, 0, "", visited);
    
    return 0;
}