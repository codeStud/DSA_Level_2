#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minDiff = INT_MAX;
string res;

void minDiffSubset(vector<int>& arr, int idx, vector<int>& subset1, vector<int>& subset2, int sum1, int sum2)
{
    // base case
    if(idx == arr.size()){
        int curDiff = abs(sum1-sum2);
        if(minDiff > curDiff){
            minDiff = curDiff;
            
            // store subsets in string res
            string ans = "[";
            for(int i = 0; i < subset1.size() - 1; i++){
                ans = ans + to_string(subset1[i]) + ", ";
            }
            ans = ans + to_string(subset1[subset1.size() - 1]) + "] ";
            
            ans += "[";
            for(int i = 0; i < subset2.size() - 1; i++){
                ans = ans + to_string(subset2[i]) + ", ";
            }
            ans = ans + to_string(subset2[subset2.size() - 1]) + "] ";
            
            res = ans;
        }
        
        return;
    }
    
    // when the subset has n/2 elements (if n is even) or n/2+1 elements (if n is odd)
    // no need to add to subset cuz we want equal sized (+-1 in case of odd n) subsets
    
    if(subset1.size() < (arr.size() + 1) / 2){
        subset1.push_back(arr[idx]);
        sum1 += arr[idx];
        
        minDiffSubset(arr, idx + 1, subset1, subset2, sum1, sum2);
        
        // Backtracking
        subset1.pop_back();
        sum1 -= arr[idx];
    }
    
    if(subset2.size() < (arr.size() + 1) / 2){
        subset2.push_back(arr[idx]);
        sum2 += arr[idx];
        
        minDiffSubset(arr, idx + 1, subset1, subset2, sum1, sum2);
        
        // Backtracking
        subset2.pop_back();
        sum2 -= arr[idx];
    }
}


int main()
{
    int n;
    cin>>n;
    
    vector <int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    vector <int> subset1;
    vector <int> subset2;
    
    minDiffSubset(arr, 0, subset1, subset2, 0, 0);
    cout<<res<<endl;
    
    return 0;    
}