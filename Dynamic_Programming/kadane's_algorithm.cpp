// NOTE: Kadane's algorithm gives "max-sum-subarray"

#include<iostream>
using namespace std;

int kadanesAlgo(int *arr, int n)
{
    int curSum = arr[0];
    int maxSum = arr[0];
    
    for(int i = 1; i < n; i++){
        // If curSum is +ve && -
        // 1) arr[i] +ve => including curSum + arr[i] will give even greater sum
        // 2) arr[i] -ve => curSum + arr[i] will reduce sum but there is a chance that the next element may be so high that it'll make it even larger.
        // Eg: 2 3 -3 11
        if(curSum >= 0){
            curSum += arr[i];
        }
        
        // if curSum IS -VE && -
        // (1) arr[i] +ve => Just start a new subarray from arr[i] as it'll always give a higher sum subarray than being included in curSum
        // (2) arr[i] -ve => curSum is already -ve => start a new subarray otherwise curSum + arr[i] will be even more -ve
        else{
            curSum = arr[i];
        }
        
        // update the maxSum
        if(curSum > maxSum){
            maxSum = curSum;
        }
    }
    
    return maxSum;
}

int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    cout<<kadanesAlgo(arr, n);
}