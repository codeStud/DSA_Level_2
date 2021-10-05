// C-0 = 1
// C-1 = 1
// C-2 = (C-0 * C-2) + (C-1 * C-1) + (C-2 * C-0)
// C-3 = (C-0 * C-3) + (C-1 * C-2) + (C-2 * C-1) + (C-3 * C-0)

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector<int> dp (n + 1);
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++){
        
        // create formula for n = 3 to understand the loop below
        for(int j = 0; j < i; j++){
            dp[i] += dp[j] * dp[i - j - 1];
        }

        // METHOD-2: Easier to understand
        // int left = 0;
        // int right = i - 1;
        
        // // or, while(left <= i - 1)
        // while(right >= 0){
        //     dp[i] += dp[left] * dp[right];
            
        //     left++;
        //     right--;
        // }
        
    }
    
    cout<<dp[n]<<endl;
    
    return 0;
}