#include<iostream>
#include<vector>
using namespace std;

int josephusProblem(int n, int k)
{
    // if 1 guy remaining, return it's index (i.e 0-th index, which will be then converted back to the corresponding answer by below formula)
    if(n == 1){
        return 0;
    }
    
    // I don't know the final survivor of "n" persons. Give me the solution for n-1, I'll convert it back 
    // to answer of "n" persons using the formula. (Bottom-up approach of recursion)
    int currentSurvivorIndex = josephusProblem(n - 1, k);
    
    // When returning from recursive call, convert this survivor to it's corresponding original index 
    int actualSurvivorIndex = (currentSurvivorIndex + k) % n;
    
    return actualSurvivorIndex;
    
}

int main()
{
    int n, k;
    cin>>n>>k;
    
    cout<<josephusProblem(n, k)<<endl;
    
    return 0;
}