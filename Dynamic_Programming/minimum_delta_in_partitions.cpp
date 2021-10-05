#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// arr has to be divided into two subsets s1, s2.
// let their respective sum of elements be sum1, sum2.
// for min-ABSOLUTE difference( sum of subsets ) - best case is "sum1 = sum2" => diff is 0. But sum1 = sum2 isn't always possible.
// So, let sum1 > sum2. Now, since "sum1 + sum2 = sum" => sum1 - sum2 can be written as "(sum - sum2) - sum2" (Reducing to 1 varaible)
// So, minimising difference of sum of subsets == minimising "sum - 2 * sum2" 

// Also, value of sum2 will lie in range (0, sum) but note that we can take the maxValue of sum2 in the leftHalf i.e sum / 2, bcz if sum2 exceeds sum / 2
// then sum-2*sum2 becomes -ve, but the ABSOLUTE VALUE of difference REPEATS.


int subsetSum(vector<int>& arr, int target)
{
    int n = arr.size();
    bool dp[n + 1][target+1];
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= target; j++){
            
            if(i == 0 && j == 0){
                dp[i][j] = true;
            }
            else if(i == 0){
                dp[i][j] = false;
            }
            else if(j == 0){
                dp[i][j] = true;
            }
            else{
                if(j < arr[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
                }
            }
            
        }
    }
    
    
    // to minimize the value of ABSOLUTE DIFFERENCE of sum of subsets, take the max possible sum of sum2 in the left-half(i.e till totalSum / 2)
    // bcz when sum2 crosses left-half, aboslute value of (sum - 2 * sum2) starts increasing.
    // Thus, Minimizing (sum - 2 * sum2) means Maximizing(sum) but only till sum / 2
    int maxVal_of_sum2 = 0;
    
    for(int i = target / 2; i >= 0 ; i--){
        // Last row will contain what target-values can be generated from the subsets of arr.
        if(dp[n][i] == true){
            maxVal_of_sum2 = i;
            // break after finiding maximum value of sum of subset2 in the (0, target/2)
            break;
        }
    }
    
    return maxVal_of_sum2;
}


int min_delta_partition(vector<int>& arr)
{
    // calculate the sum of all the elements in arr 
    int sum = 0;
    for(int i : arr){
        sum += i;
    }
    
    int maxVal_of_sum2 = subsetSum(arr, sum);
    
    int minVal_of_abs_diff = sum - 2 * maxVal_of_sum2;
    
    return minVal_of_abs_diff;
}


int main()
{
    int n;
    cin>>n;
    
    vector<int> arr (n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    cout<<min_delta_partition(arr);
    
    return 0;
}