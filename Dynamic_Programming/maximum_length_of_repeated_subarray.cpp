// NOTE: Exactly same as LONGEST COMMON SUBSTRING question.

#include<iostream>
#include<vector>
#include<string>
using namespace std;


void longest_common_substring(vector<int>& arr1, vector<int>& arr2)
{
    vector<vector<int>> dp (arr1.size() + 1, vector<int> (arr2.size() + 1, 0));
    
    int maxLen = 0;
    
    for(int i = 1; i < dp.size(); i++){
        for(int j = 1; j < dp[0].size(); j++){
            
            if(arr1[i - 1] == arr2[j - 1]){
                // check diagonally above and add 1
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            
            else{
                // not a common substring if current characters don't match
                dp[i][j] = 0;
            }
            
            // update the maxLen
            if(dp[i][j] > maxLen){
                maxLen = dp[i][j];
            }
            
        }
    }
    
    cout<<maxLen<<endl;
}


int main()
{
    int n;
    cin>>n;
    
    vector<int> arr1 (n);
    for(int i = 0; i < n; i++){
        cin>>arr1[i];
    }
    
    int m;
    cin>>m;
    
    vector<int> arr2 (m);
    for(int i = 0; i < m; i++){
        cin>>arr2[i];
    }
    
    longest_common_substring(arr1, arr2);
    
    return 0;
}