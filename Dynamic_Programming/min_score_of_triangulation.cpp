#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int minScoreOfTriangulation(vector<int>& arr)
{
    // dp[] will store minScore of all triangles that can be formed treating vertical vertex'i' and horizontal vertex 'j' as base
    vector<vector<int>> dp (arr.size(), vector<int> (arr.size()));
    
    for(int gap = 0; gap < dp.size(); gap++){
        
        for(int i = 0, j = gap; j < dp[0].size(); i++, j++){
            
            // gap = 0 => 1 vertex => 0 score
            if(gap == 0){
                dp[i][j] = 0;    
            }
            
            // gap = 1 => 2 vertices => empty triangle => 0 score
            else if(gap == 1){
                dp[i][j] = 0;
            }
            
            //gap = 2 => 3 vertices => 1 triangle => score = product of those 3 vertices
            else if(gap == 2){
                dp[i][j] = arr[i] * arr[i + 1] * arr[i + 2];    
            }
            
            else{
                
                int minScore = INT_MAX;
                
                // 'i'th and 'j'th vertex are base of triangle. 
                // 3rd point of the triangle varies from i+1 till j-1
                for(int k = i + 1; k < j; k++){
                    int curTriangleScore = arr[i] * arr[j] * arr[k];
                    
                    // triangles left to curTriangle will have base 'i'th vertex & 'k'th
                    // vertex => minScore of all the left triangles will be stored at dp[i][k]
                    int leftScore = dp[i][k];
                    
                    // triangles right to curTriangle will have base 'k'th vertex &
                    // 'j'th vertex => minScore of all right triangles will be stored at dp[k][j]
                    int rightScore = dp[k][j];
                    
                    int totalScore = curTriangleScore + leftScore + rightScore;
                    
                    minScore = min(minScore, totalScore);   
                }
                
                // store the minScore of all triangles that can be formed on the base
                // of vertical vertex 'i' & horizontal vertex 'j' at dp[i][j]
                dp[i][j] = minScore;
                
            }
            
        }
    }
    
    // result will be in top right corner
    return dp[0][dp[0].size() - 1];
}


int main()
{
    int n;
    cin>>n;
    
    vector <int> arr (n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    cout<< minScoreOfTriangulation(arr) <<endl;
    
    return 0;
}