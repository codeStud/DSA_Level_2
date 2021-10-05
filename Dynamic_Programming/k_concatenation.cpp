#include<iostream>
#include<vector>
using namespace std;


int kadanesAlgo(vector<int>& arr)
{
    int curSum = arr[0];
    int maxSum = arr[0];
    
    for(int i = 1; i < arr.size(); i++){
        if(curSum >= 0){
            curSum += arr[i];
        }
        else{
            curSum = arr[i];
        }
        
        if(curSum > maxSum){
            maxSum = curSum;
        }
    }
    
    return maxSum;
}


int kadanesOfTwo(vector<int>& arr)
{
    vector<int> copy (arr.size() * 2);
    
    // make two copies of the array
    for(int i = 0; i < arr.size(); i++){
        copy[i] = arr[i];
    }
    
    for(int i = 0; i < arr.size(); i++){
        // i + arr.size() will be the correct copying index for copy[]
        copy[i + arr.size()] = arr[i];
    }
    
    // call kadanes algo on copy[]
    return kadanesAlgo(copy);
}


int k_concatenation(vector<int>& arr, int k, int sum)
{
    // if array is not repeated, i.e k = 1 => simple kadanes on array
    if(k == 1){
        return kadanesAlgo(arr);
    }
    
    // if sumOfArr is -ve => maxSum can occur in two ways:
    // (1) inside the 1st copy of array itself. Eg: (10 -5 -8) (10 -5 -8) (10 -5 -8) ...
    // (2) across the first 2 copies of array. Eg: (2 -28 10) (2 -28 10) (2 -28 10) ...
    // NOTE: maxSum can't expand more than 2 copies bcz the array BETWEEN the 1st & the last copy (till the copy where maxSum is supposed to be) 
    // of array have -VE SUM. => First two copies will anyways give larger sum without including arrays with -VE sum in between.
    else if(sum < 0){
        return kadanesOfTwo(arr);
    }
    
    // if SumOfArr >= 0 => maxSum will occur across all the k copies (since sum is +ve)
    // Also, maxSum subarray can't occur wholely inside a single copy like case (1) of -ve sum bcz - (a, b, c, d) (a, b, c, d) ... & you say (b, c) 
    // is maxSum subarray then (b, c, d) & (a, b, c) will give even larger Sum as d+a+b+c is +ve
    else{
        // take kadanes of 1st & last copy(i.e kadanesOfTwo) and multiply the sumOfArray(+ve) with (k-2) copies in between the 1st & last copy of array
        return (kadanesOfTwo(arr) + (k-2) * sum);    
    }
}


int main()
{
    int n;
    cin>>n;
    
    vector <int> arr (n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    
    int k;
    cin>>k;
    
    cout<<k_concatenation(arr, k, sum);
    
    return 0;
}