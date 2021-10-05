#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;


int largest_square_with_ones(vector<vector<int>>& arr)
{
    // dp[i][j] stores the SIZE of the largest SQUARE sub-matrix with all 1
    // STARTING from dp[i][j] (i.e dp[i][j] wud be the top left corner of the square)
    vector<vector<int>> dp (arr.size(), vector<int>(arr[0].size()));
    
    // we WANT dp[0][0], i.e largest SQUARE sub-matrix with all 1 starting from top left
    // So, small problem is in bottom right corner => traverse bottom->up + right->left
    
    // BUT largest SQAURE can start from ANY CELL in the dp. So, dp[0][0]
    // WON'T ALWAYS contain the answer. Thus, keep updating the maxSize variable.
    int maxSize = 0;
    
    for(int i = dp.size() - 1; i >= 0; i--){
        for(int j = dp[0].size() - 1; j >= 0; j--){
            
            if(i == dp.size() - 1 && j == dp[0].size() - 1){
                // if arr[i][j] = 1 then only 1 sized square possible, the cell itself
                // if arr[i][j] = 0 then No square possible => 0
                dp[i][j] = arr[i][j];
            }
            
            else if(i == dp.size() - 1){
                // if arr[i][j] = 1 then only 1 sized square possible, the cell itself
                // if arr[i][j] = 0 then No square possible => 0
                dp[i][j] = arr[i][j];
            }
            
            else if(j == dp[0].size() - 1){
                // if arr[i][j] = 1 then only 1 sized square possible, the cell itself
                // if arr[i][j] = 0 then No square possible => 0
                dp[i][j] = arr[i][j];
            }
            
            else{
                if(arr[i][j] == 1){
                    // this cell will try to expand on left, down & diagonally down to create a square. But, the 
                    // minimum sized square on these three sides will restrict it. Draw yourself OR watch the lecture for better understanding.
                    dp[i][j] = 1 + min({
                                        dp[i][j + 1],
                                        dp[i + 1][j],
                                        dp[i + 1][j + 1]
                                    });
                }
                
                else{
                    // 0 sized square (of all 1s) can be formed treating this cell as the top left corner of the square.
                    dp[i][j] = arr[i][j];
                }
            }
            
            // store the max sized subarray of all 1's
            maxSize = max(maxSize, dp[i][j]);
        }
    }
    
    return maxSize;
}


int main()
{
    int n, m;
    cin>>n>>m;
    
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }
    
    cout<<largest_square_with_ones(arr);
    
    return 0;
}