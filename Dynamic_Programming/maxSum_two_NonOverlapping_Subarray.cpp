#include<iostream>
#include<vector>
using namespace std;


int func(vector<int>& arr, int n1, int n2)
{
    int finalMaxSum = 0;
    
    // dp1[i] will store the max sum of n1 size sub-array ENDING AT index "i"
    vector<int> dp1 (arr.size());
    
    // dp2[i] will store the max sum of n2 size sub-array STARTING FROM index "i"
    vector<int> dp2 (arr.size());
    
    // to store the sum of current n1 window subarray
    int curWindSum = 0;
    
    // fill dp1[] from left to right
    for(int i = 0; i < dp1.size(); i++){
        
        if(i < n1){
            curWindSum += arr[i];
            dp1[i] = curWindSum;
        }
        else{
            // max sum amongst all the previous n1 size window is stored at dp1[i - 1] (by the definition of dp1[])
            int prevMaxSum = dp1[i - 1];
            
            // move the window and take the sum of current n1 size window, i.e
            // include current element && subtract element before the 1st element of window (i-n1)
            curWindSum = curWindSum + arr[i] - arr[i - n1];
            
            // store the max sum amongst current n1 window sum or max sum amongst previous n1 window sum
            dp1[i] = max(curWindSum, prevMaxSum);
        }
    }
    
    curWindSum = 0;
    
    // fill dp2[] from right to left
    for(int i = dp2.size() - 1; i >= 0; i--){
        
        // NOTE: Remember that n2-Sized Window is coming from right to left.
        
        // if window size < n2, simply keep taking sum and putting sum in dp2
        if(i + n2 >= dp2.size()){
            // simply keep taking the sum of array elements
            curWindSum += arr[i];
            dp2[i] = curWindSum;
        }
        else{
            int rightWindSum = dp2[i + 1];
            
            curWindSum = curWindSum + arr[i] - arr[i + n2];
            
            dp2[i] = max(rightWindSum, curWindSum);
        }
    }

    
    // NOTE: Since, NON-OVERLAPPING => maxSum( ALL (n1-size subarray on left + n2-size subarray on right) )
    for(int i = n1 - 1; i <= dp1.size() - n2 - 1; i++){
        int curSubarraySum = dp1[i] + dp2[i + 1];
        
        finalMaxSum = max(finalMaxSum, curSubarraySum);
    }
    
    return finalMaxSum;
}


int max_sum_nonOverlapping_subarray(vector<int>& arr, int x, int y)
{
    // MAX NON-OVERLAPPING subarray sum if x-Sized subarray on LEFT && y-sized on right
    int ans1 = func(arr, x, y);
    
    // MAX NON-OVERLAPPING subarray sum if y-Sized subarray on LEFT && x-sized on right
    int ans2 = func(arr, y, x);
    
    return max(ans1, ans2);
}


int main()
{
    int n;
    cin>>n;
    
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    int x, y;
    cin>>x>>y;
    
    cout<<max_sum_nonOverlapping_subarray(arr, x, y);
    
    return 0;
}