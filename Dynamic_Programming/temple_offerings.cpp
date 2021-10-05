#include<iostream>
#include<vector>
using namespace std;
//                                                          /                   \   
// A peak in a single mountain can be seen as "a left-peak / "  &  "a right-peak \"
// We don't know what value to give to a peak bcz if we give increasing value considering it a "left-peak", it might be deeper on the right side. Eg:
//    /\            
//   /  \       Peak will get 2 from left, 3 from right. Since each temple at higher 
//       \      point should receive larger value + we need to minimise that value => 
//              consider each point as left-peak & right-peak. Give min-value as per rule 
//              in both cases. Then take the maximum of both, i.e max(2, 3) for above eg. 


int temple_offerings(vector<int>& arr)
{
    vector<int> leftPeakOfferings(arr.size());
    leftPeakOfferings[0] = 1;
    
    for(int i = 1; i < leftPeakOfferings.size(); i++){
        // if current element is greater than prev, i.e a peak => increment the value
        if(arr[i] > arr[i - 1]){
            leftPeakOfferings[i] = leftPeakOfferings[i-1] + 1;
        }
        else{
            // reset the value to 1. => next LEFT peak can get minValue of 2, 3 ...
            leftPeakOfferings[i] = 1;
        }
    }
    
    vector<int> rightPeakOfferings(arr.size());
    rightPeakOfferings[arr.size() - 1] = 1;
    
    for(int i = arr.size() - 2; i >= 0; i--){
        // if current element is greater than prev, i.e a peak => increment the value
        if(arr[i] > arr[i + 1]){
            rightPeakOfferings[i] = rightPeakOfferings[i+1] + 1;
        }
        else{
            // reset the value to 1. => next RIGHT peak can get minValue of 2, 3 ...
            rightPeakOfferings[i] = 1;
        }
    }
    
    // At each point, take max of left & right. Then take total sum to get total minimum offerings.
    int minOfferings = 0;
    for(int i = 0; i < arr.size(); i++){
        minOfferings += max( leftPeakOfferings[i], rightPeakOfferings[i] );
    }
    
    return minOfferings;
}


int main()
{
    int n;
    cin>>n;
    
    vector<int> arr (n);
    for(int i = 0; i< n; i++){
        cin>>arr[i];
    }
    
    cout<<temple_offerings(arr);
    
    return 0;
}
