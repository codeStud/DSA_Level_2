#include<iostream>
#include<string>
#include<vector>
using namespace std;

int min_operations(int n)
{
    if(n == 1){
        return 0;   // 1 X is already present
    }
    
    if(n == 2){
        return 2;   // 1 copy, 1 paste
    }
    
    // each index 'i' will store minimum operations to build the 'i' size string of X
    vector<int> dp (n+1);
    dp[1] = 0;      // 1 X is already present
    dp[2] = 2;      // 1 copy, 1 paste
    
    for(int i = 3; i < dp.size(); i++){
        // If 'i' is even => minOps will be = dp[i/2] + 2, i.e best way (minOps) to reach half sized string + 1 copy & then 1 paste.
        if(i % 2 == 0){
            dp[i] = dp[i / 2] + 2;
        }

        // If 'i' is odd => Find the largest FACTOR of 'i' and then 1 copy + [(i / largestFactor) - 1] times paste. 
        // (- 1 bcz factor sized string is already present) Eg: 9 => largest factor = 3, then minOps("XXX") + 1 copy + 2 times paste
        else{
            int j = i / 2;
            while(j >= 1){
                // check if j is the factor or not. Copy pasting ONLY FACTORS can build 'i' length string
                // Eg: 9 can't be made by copy pasting 4 or 2 sized string of X
                if(i % j == 0){
                    // when you enter this loop 1st time, you've the largest factor => break
                    dp[i] = dp[j] + 1 + (i / j - 1);        // Eg: dp[9] = dp[3] + 1 copy + 2 paste

                    break;
                }
                
                // keep reducing j
                j--;
            }
        }
    }
    
    return dp[n];
}


int main()
{
    int n;
    cin>>n;
    
    cout<<min_operations(n);
    
    return 0;
}