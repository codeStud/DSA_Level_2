#include<iostream>
#include<vector>
#include<climits>
using namespace std;


void optimalBST(vector<int>& arr, vector<int>& freq)
{
    vector<vector<int>> dp (arr.size(), vector<int> (arr.size()));
    
    vector<int> prefixSum(freq.size());
    prefixSum[0] = freq[0];
    
    for(int i = 1; i < freq.size(); i++){
        prefixSum[i] = prefixSum[i - 1] + freq[i];
    }
    
    for(int gap = 0; gap < dp.size(); gap++){
        for(int i = 0, j = gap; j < dp[0].size(); i++, j++){
            
            if(gap == 0){
                dp[i][j] = freq[i];
            }
            
            else if(gap == 1){
                int f1 = freq[i];
                int f2 = freq[j];
                
                dp[i][j] = min(f1 + 2 * f2, f2 + 2 * f1);
            }
            
            else{
                int minVal = INT_MAX;
                
                // Below code is Optimised using prefixSum[]
                
                // int freqSum = 0;
                // for(int x = i; x <= j; x++){
                //     freqSum += freq[x];
                // }
                
                // get Sum of frequencies from 'i' till 'j' 
                // prefixSum[j] stores sum of all elements from 0 till j
                // Subtracting prefixSum[i-1] will remove sum just before till start, i.e sum of elements till just before 'i'
                // Thus you'll get sum from i to j
                int freqSum = prefixSum[j] - (i == 0 ? 0 : prefixSum[i - 1]);
                
                // make each of the nodes from i till j, a root node => It'll have left and right subtree
                for(int k = i; k <= j; k++){
                    // leftSubtree: i to k-1 BUT if i == k => NO leftSubtree
                    int optimalLeftSubtree = k == i ? 0 : dp[i][k - 1];
                    
                    // rightSubtree: k+1 to j BUT if j == k => NO rightSubtree
                    int optimalRightSubtree = k == j ? 0 : dp[k + 1][j];
                    
                    if(optimalLeftSubtree + optimalRightSubtree + freqSum < minVal){
                        minVal = optimalLeftSubtree + optimalRightSubtree + freqSum;
                    } 
                }
                
                dp[i][j] = minVal;
            }
            
        }
    }
    
    cout<<dp[0][dp.size() - 1];
}


int main()
{
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    vector<int> freq(n);
    for(int i = 0; i < n; i++){
        cin>>freq[i];
    }
    
    optimalBST(arr, freq);
    
    return 0;
}