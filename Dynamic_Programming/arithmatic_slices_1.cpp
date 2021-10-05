#include<iostream>
#include<vector>
using namespace std;


int arithmatic_slices(vector<int>& arr)
{
    int totalAP = 0;
    
    // each index will store the NUMBER OF A.P ending at that index element
    vector<int> dp (arr.size());
    dp[0] = dp[1] = 0;
    
    // since min AP length = 3 elements
    for(int i = 2; i < dp.size(); i++){
        // if i, i-1, i-2 NOT in AP => No AP can end at i
        if(arr[i] - arr[i - 1] != arr[i - 1] - arr[i - 2]){
            dp[i] = 0;
        }
        
        // else 'i' th element can form 3 size AP + AP by coming after APs of "i-1" (4 length, 5 length ...)
        // Eg-1:     [1, 4, 6, 8]
        // AP Count: [0, 0, 0, 1]   // (4 6 8) total 1 AP
        // Eg-2:     [1, 4, 6, 8, 10]
        // AP Count: [0, 0, 0, 1, 2]   // (4 6 8) ((6, 8, 10), (4, 6, 8, 10)) total 3 AP
        // Eg-3:     [1, 4, 6, 8, 10, 12]
        // AP Count: [0, 0, 0, 1, 2, 3]   // (4 6 8) ((6, 8, 10), (4, 6, 8, 10)) ((8, 10, 12), (6, 8, 10, 12), (4, 6, 8, 10, 12)) total 6 AP
        else{
            dp[i] = 1 + dp[i - 1];
            // keep taking the sum of all possible AP to get the total AP count
            totalAP += dp[i];
        }
    }
    
    return totalAP;
}


int main()
{
    int n;
    cin>>n;
    
    vector<int> arr (n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    cout<<arithmatic_slices(arr);
    
    return 0;
}