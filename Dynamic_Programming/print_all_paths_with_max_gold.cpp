#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
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


void printPaths(vector<vector<int>>& arr, vector<vector<int>>& dp, int n, int m, int maxVal)
{
    queue <Pair> q;
    // push the max profit Pairs from 0th col
    for(int i = 0; i < n; i++){
        if(dp[i][0] == maxVal){
            q.push(Pair(i, 0, to_string(i) + " "));
        }
    }
    
    while(!q.empty()){
        Pair top = q.front();
        q.pop();
        
        if(top.j == m-1){
            cout<<top.psf<<endl;
        }
        
        else if(top.i == 0){
            // since d2 and d3 might give same value, this approach will make your code cleaner
            int greater = max(dp[top.i][top.j + 1], dp[top.i + 1][top.j + 1]);
            
            if(dp[top.i][top.j + 1] == greater){
                q.push(Pair(top.i, top.j + 1, top.psf + "d2 "));
            }
            
            if(dp[top.i + 1][top.j + 1] == greater){
                q.push(Pair(top.i + 1, top.j + 1, top.psf + "d3 "));
            }
        }
        
        else if(top.i == n - 1){
            // since d1 and d2 might give same value
            int greater = max(dp[top.i - 1][top.j + 1], dp[top.i][top.j + 1]);
            
            if(dp[top.i - 1][top.j + 1] == greater){
                q.push(Pair(top.i - 1, top.j + 1, top.psf + "d1 "));
            }
            
            if(dp[top.i][top.j + 1] == greater){
                q.push(Pair(top.i, top.j + 1, top.psf + "d2 "));
            }
        }
        
        else{
            // since d1, d2 and d3 might give same value
            int greater = max({dp[top.i][top.j + 1], dp[top.i - 1][top.j + 1], dp[top.i + 1][top.j + 1]});
            
            if(dp[top.i - 1][top.j + 1] == greater){
                q.push(Pair(top.i - 1, top.j + 1, top.psf + "d1 "));
            }
            
            if(dp[top.i][top.j + 1] == greater){
                q.push(Pair(top.i, top.j + 1, top.psf + "d2 "));
            }
            
            if(dp[top.i + 1][top.j + 1] == greater){
                q.push(Pair(top.i + 1, top.j + 1, top.psf + "d3 "));
            }
        }
    }
}


void goldmine(vector<vector<int>>& arr, int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m));
    
    for(int j = m-1; j >= 0; j--){
        for(int i = 0; i < n; i++){
            
            if(j == m-1){
                dp[i][j] = arr[i][j];
            }
            
            else if(i == 0){
                dp[i][j] = arr[i][j] + max(dp[i][j+1], dp[i+1][j+1]);
            }
            
            else if(i == n-1){
                dp[i][j] = arr[i][j] + max(dp[i][j+1], dp[i-1][j+1]);
            }
            
            else{
                dp[i][j] = arr[i][j] + max({dp[i][j+1], dp[i-1][j+1], dp[i+1][j+1]});
            }
            
        }
    }
    
    // print max profit
    int maxVal = INT_MIN;
    for(int i = 0; i < n; i++){
        maxVal = max(maxVal, dp[i][0]);
    }
    cout<<maxVal<<endl;
    
    
    printPaths(arr, dp, n, m, maxVal);
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
    
    goldmine(arr, n, m);
    
    return 0;
}