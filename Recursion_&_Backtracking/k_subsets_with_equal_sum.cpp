#include<iostream>
#include<string>
#include<vector>
using namespace std;


void kSubsetsWithEqualSum(vector<int> arr, int idx, int n, int k, vector<int> subsetSum, int noOfNonEmptySubsets, vector<vector<int>>& subsets)
{
    if(idx == arr.size()){
        // if all the partitons are non-empty
        if(noOfNonEmptySubsets == k){
            
            // check if all subset-sums are equal
            bool flag = true;
            
            for(int i = 1; i < subsetSum.size(); i++){
                if(subsetSum[i-1] != subsetSum[i]){
                    flag = false;
                    break;
                    
                }
            }
            
            if(flag){
                for(int j = 0; j < k; j++){
                    cout<<"[";
                    for(int i = 0; i < subsets[j].size() - 1; i++){
                        cout<<subsets[j][i]<<", ";
                    }
                    cout<<subsets[j][subsets[j].size() - 1]<<"] ";
                }
                cout<<endl;
            }
        }
        
        return;
    }
    
    // give "arr[idx]" a chance to be a part of each subset
    for(int i = 0; i < subsets.size(); i++){
        
        // if current subset is already non-empty => simply push_back
        if(subsets[i].size() > 0){
            subsets[i].push_back(arr[idx]);
            // increase the subsetSum at the i-th index as it's the i-th subset
            subsetSum[i] += arr[idx];
            
        kSubsetsWithEqualSum(arr, idx + 1, n, k, subsetSum, noOfNonEmptySubsets, subsets);
            
            // undo the effects on BACKTRACKING
            subsets[i].pop_back();
            subsetSum[i] -= arr[idx];
        }
        
        // if current subset is empty => push and break (to avoid permutations)
        else{
            subsets[i].push_back(arr[idx]);
            // increase the subsetSum at the i-th index as it's the i-th subset
            subsetSum[i] += arr[idx];
            
            // increase the no of non-empty subsets
        kSubsetsWithEqualSum(arr, idx + 1, n, k, subsetSum, noOfNonEmptySubsets + 1, subsets);
            
            // undo the effects on BACKTRACKING
            subsets[i].pop_back();
            subsetSum[i] -= arr[idx];
            
            break;
        }
    }
}


int main()
{
    int n, k;
    cin>>n;
    
    vector<int> arr(n);
    int sum = 0;
    
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    
    cin>>k;
    
    if(k == 1){
        cout<<"[";
        for(int i = 0; i < n; i++){
            cout<<arr[i]<<", ";
        }
        cout<<"]";
        
        return 0;
    }
    
    if(k > n || sum % k != 0){
        cout<<"-1"<<endl;
        return 0;
    }
    
    // declare a vector to store sum of each the "k" subsets
    vector <int> subsetSum (k);
    
    // declare a vector to store k subsets
    vector <vector<int>> subsets (k);
    
    // pass array, array-start-index, n, k, subset-sum, no-of-nonEmpty-subsets, subsets
    kSubsetsWithEqualSum(arr, 0, n, k, subsetSum, 0, subsets);
    
    return 0;
}