#include<iostream>
#include<limits>
#include<vector>
using namespace std;


int max_sum_subarray_atleast_k_elements(vector<int>& arr, int k)
{
    // find maxSum subarray till each index in arr[] using kadane's
    vector<int> maxSum(arr.size());
    
    int curSum = arr[0];
    maxSum[0] = arr[0];
    
    for(int i = 1; i < arr.size(); i++){
        if(curSum >= 0){
            curSum += arr[i];
        }
        else{
            curSum = arr[i];
        }
        
        // store maxSum till the i-th index
        maxSum[i] = curSum;
    }
    
    // find SUM of 1st k-size subarray
    int kSubarraySum = 0;
    for(int i = 0; i < k; i++){
        kSubarraySum += arr[i];
    }
    
    // store the max-sum of at least k size subarray in a variable & initalise it with sum of 1st k-size-subarray
    int max_k_sum = kSubarraySum;
    
    // loop through each possible k size subarray
    for(int i = k; i < arr.size(); i++){
        // take SUM of current k size subarray by including "i"th & excluding "i-k"th element from kSubarraySum.
        // We have kept a separate variable "kSubarraySum" bcz we want to first calculate the sum of EXACT 'k' size window.
        kSubarraySum = kSubarraySum + arr[i] - arr[i - k];
        
        // update max_k_sum if sum of EXACTLY k size subarray is greater
        if(kSubarraySum > max_k_sum){
            max_k_sum = kSubarraySum;
        }
        
        // Now, subarray size is "atleast-k" => size can be greater than k.
        // Thus, INCLUDING THE maxSum[i-k], i.e maxSum subarray (found using kadane's) TILL the point just before the 
        // current k-size window starts will give the maxSum of subarray with size ATLEAST "k"
        int moreThanK = maxSum[i - k] + kSubarraySum;
        
        // Again update the max_k_sum if sum of ATLEAST k size subarray is greater
        if(moreThanK > max_k_sum){
            max_k_sum = moreThanK;
        }
    }
    
    // at end, max_k_sum will contain the maximum sum of atleast k size subarray
    return max_k_sum;
}


int main()
{
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    int k;
    cin>>k;
    
    cout<<max_sum_subarray_atleast_k_elements(arr, k);
    
    return 0;
}