// NOTE: It is almost exactly same as coin change problem.
// Eg: 3x + 4y + 5z = 15
// (a) Treat 3, 4, 5 (coefficient) as coin denominations.
// (b) Target sum = 15 => create an array from 0 to 15.
// Index "i" of arr[] will denote the RHS value.
// First iterate with value 3 over the arr[] to get "no." of solutions to eqn "3x = i"
// Secondly iterate with value 4 over the arr[] to get "no." of solutions to eqn "3x + 4y = i"
// lastly, iterate with value 3 over the arr[] to get "no." of solutions to eqn "3x + 4y +5z = i"

#include<iostream>
#include<vector>
using namespace std;

long no_of_solutions(vector<int>& lhsCofficient, int rhs)
{
    vector<long> dp(rhs + 1, 0);
    
    // if RHS = 0, then 1 trivial solution, x = y = z = 0
    dp[0] = 1;
    
    // take each cofficient in outer-for & RHS "i" in inner-for loop to avoid generating
    // permutation. See coin change for this concept
    for(int coff : lhsCofficient){
        for(int i = 0; i <= rhs; i++){
            // if cofficient is smaller than the RHS value, it can't satisfy the equation
            if(i >= coff){
                dp[i] = dp[i] + dp[i - coff];
            }
        }
    }
    
    return dp[rhs];
}

int main()
{
    int n;
    cin>>n;
    
    vector<int> lhsCofficient(n);
    for(int i = 0; i < n; i++){
        cin>>lhsCofficient[i];
    }
    
    int rhs;
    cin>>rhs;
    
    cout<<no_of_solutions(lhsCofficient, rhs);
    
    return 0;
}