// Question says "n" is #rows & "m" is #cols but for passing test cases, treat it opposite.

#include<iostream>
#include<vector>
using namespace std;


void maxSumGoldmine(vector<vector<int>>& mine, vector<vector<bool>>& visited, int i, int j, vector<int>& bag)
{
    if(i >= mine.size() || j >= mine[0].size() || i < 0 || j < 0 || 
       visited[i][j] == true || mine[i][j] == 0){
    
        return;       
    }
    
    // mark it visited
    visited[i][j] = true;
    // push it into bag
    bag.push_back(mine[i][j]);
    
    maxSumGoldmine(mine, visited, i-1, j, bag);
    maxSumGoldmine(mine, visited, i, j+1, bag);
    maxSumGoldmine(mine, visited, i, j-1, bag);
    maxSumGoldmine(mine, visited, i+1, j, bag);
    
}


int main()
{
    int n, m;
    cin>>n>>m;
    
    vector<vector<int>> mine (m, vector<int> (n));
    vector<vector<bool>> visited (m, vector<bool> (n));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>mine[i][j];
            visited[i][j] = false;
        }
    }
    
    int maxSum = 0;
    
    // make each of the un-visited and non-0 index as the potential starting point
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            
            if(mine[i][j] != 0 && visited[i][j] == false){
                // pass an empty vector to store the values reachable from this vertex
                vector <int> bag;
                
                maxSumGoldmine(mine, visited, i, j, bag);
                
                // take the sum of elements currently in the bag
                int sum = 0;
                for(int val : bag){
                    sum += val;
                }
                
                // update the maxSum
                if(sum > maxSum){
                    maxSum = sum;
                }
            }
            
        }
    }
    
    cout<<maxSum<<endl;
    
    return 0;
}