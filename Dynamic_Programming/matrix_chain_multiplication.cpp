#include<iostream>
#include<vector>
#include<climits>
using namespace std;


void mcm(vector<int>& dim)
{
    // size of dp will be 1 less than the size of dim
    vector<vector<int>> dp (dim.size() - 1, vector<int> (dim.size() - 1));
    
    // travel in upper triangular matrix
    for(int gap = 0; gap < dp.size(); gap++){
        for(int i = 0, j = gap; j < dp[0].size(); i++, j++){
            
            if(gap == 0){
                dp[i][j] = 0;
            }
            
            else if(gap == 1){
            // dimension of AB will be stored at (i, i+1) & (j, j+1) in dim[] (i+1 = j)
                dp[i][j] = dim[i] * dim[j] * dim[j + 1];
            }
            
            else{
                int minCost = INT_MAX;
                
                // try breaking the matrix into two parts for multiplication
                // (ABCD) i=0, j=3 => (A)(BCD) k=0  vs  (AB)(CD) k=1  vs  (ABC)(D) k=2
                for(int k = i; k < j; k++){
                    // leftMatrices = i till k   rightMatrices = k+1 till j
                    // dimLeftMat = i * k+1      dimRightMat = k+1 * j+1
                    
                    int leftMatMinCost = dp[i][k];
                    int rightMatMinCost = dp[k + 1][j];
                    
                    int leftRightMultCost = dim[i] * dim[k + 1] * dim[j + 1];
                    
                    int totalCost =leftMatMinCost + rightMatMinCost + leftRightMultCost;
                    
                    if(totalCost < minCost){
                        minCost = totalCost;
                    }
                }
                
                dp[i][j] = minCost;
            }
            
        }   
    }
    
    // print final minCost
    cout<<dp[0][dp.size() - 1]<<endl;
}


int main()
{
    int n;
    cin>>n;
    
    vector <int> dim (n);
    for(int i = 0; i < n; i++){
        cin>>dim[i];
    }
    
    mcm(dim);
    
    return 0;
}