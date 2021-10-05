#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Pair {
    public:
        int i;
        int j;
        string psf;
        
        Pair(int i, int j, string s)
        {
            this->i = i;
            this->j = j;
            this->psf = s;
        }
};


void print_paths(vector<vector<int>>& arr, vector<vector<int>>& dp, int n, int m)
{
    queue <Pair> q;
    
    // push the 0th index Pair
    q.push(Pair(0, 0, ""));
    
    while(!q.empty()){
        Pair top = q.front();
        q.pop();
        
        // check if you've reached dest => print psf
        if(top.i == n-1 && top.j == m-1){
            cout<<top.psf<<endl;
        }
        
        // if in last row => must have to move horizontally
        else if(top.i == n-1){
            q.push(Pair(top.i, top.j + 1, top.psf + "H"));
        }
        
        // if in last col => must have to move vertically
        else if(top.j == m-1){
            q.push(Pair(top.i + 1, top.j, top.psf + "V"));
        }
        
        // otherwise, you've choice to move either horizontal or vertical
        else{
            // if horizontal move results in mincost
            if(dp[top.i][top.j + 1] < dp[top.i + 1][top.j]){
                q.push(Pair(top.i, top.j + 1, top.psf + "H"));
            }
            
            // if vertical move results in mincost
            else if(dp[top.i + 1][top.j] < dp[top.i][top.j + 1]){
                q.push(Pair(top.i + 1, top.j, top.psf + "V"));
            }
            
            // both move have same cost => push both
            else{
                q.push(Pair(top.i + 1, top.j, top.psf + "V"));
                q.push(Pair(top.i, top.j + 1, top.psf + "H"));
            }
        }
    }
}


void mincost(vector<vector<int>>& arr, int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m));
    
    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            if(i == n - 1 && j == m - 1){
                dp[i][j] = arr[i][j];
            }
            
            else if(i == n - 1){
                dp[i][j] = arr[i][j] + dp[i][j+1];
            }
            
            else if(j == m - 1){
                dp[i][j] = arr[i][j] + dp[i+1][j];
            }
            
            else{
                dp[i][j] = arr[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout<<dp[i][j] <<" ";
    //     }
    //     cout<<endl;
    // }
    
    // print the mincost
    cout<<dp[0][0]<<endl;
    
    // print the path
    print_paths(arr, dp, n, m);
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
    
    mincost(arr, n, m);
    
    return 0;
}