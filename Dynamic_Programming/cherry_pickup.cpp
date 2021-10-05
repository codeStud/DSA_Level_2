// NOTE: See the video to understand why collecting maxPossible cherries while going down
// & then collecting maxPossible cherries coming up WON'T GIVE RIGHT ANSWER ALWAYS.

// Since backtracking solution, you'll get TLE. But it's just solved here for backtracking concept.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxCherries = INT_MIN;

void helper(vector<vector<int>>& arr, int row, int col, int curCherryCount)
{
    if(row < 0 || col < 0 || arr[row][col] == -1){
        return;
    }
    
    if(row == 0 && col == 0){
        // update the maxCherries from all valid paths reaching back this cell
        maxCherries = max(maxCherries, curCherryCount);
        return;
    }
    
    // store the initial value of the current cell (0 or 1)
    int cherry = arr[row][col];
    // collect cherry if there and make it 0 (if already 0 => no effect)
    arr[row][col] = 0;
    
    // go left, collecting "cherry" in curCherryCount
    helper(arr, row, col - 1, curCherryCount + cherry);
    // go up, collecting "cherry" in curCherryCount
    helper(arr, row - 1, col, curCherryCount + cherry);
    
    // BACKTRACKING, so that other paths can also include this cherry in their answer & not just the first path.
    arr[row][col] = cherry; // restoring the old value
}


void cherry_pickup_backtracking(vector<vector<int>>& arr, int row, int col, int curCherryCount)
{
    if(row >= arr.size() || col >= arr[0].size() || arr[row][col] == -1){
        return;
    }
    
    if(row == arr.size() -1 && col == arr[0].size() - 1){
        // NO need to collect cherry of last cell bcz it'll be collected by helper function
        
        // call the helper function to return back to 0 0 && calculate maxCherries in the base case
        helper(arr, row, col, curCherryCount);
    }
    
    // store the initial value of the current cell (0 or 1)
    int cherry = arr[row][col];
    // collect cherry if there and make it 0 (if already 0 => no effect)
    arr[row][col] = 0;
    
    // go right, collecting "cherry" in curCherryCount
    cherry_pickup_backtracking(arr, row, col + 1, curCherryCount + cherry);
    // go down, collecting "cherry" in curCherryCount
    cherry_pickup_backtracking(arr, row + 1, col, curCherryCount + cherry);
    
    // BACKTRACKING, so that other paths can also include this cherry in their answer & not just the first path.
    arr[row][col] = cherry; // restoring the old value
}


int main()
{
    int n;
    cin>>n;
    
    vector<vector<int>> arr (n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }
    
    cherry_pickup_backtracking(arr, 0, 0, 0);
    cout<<maxCherries<<endl;
    
    return 0;
}