#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Pair {
    public:
        int i, j;
        string psf;
        
        Pair(int i, int j, string s)
        {
            this->i = i;
            this->j = j;
            this->psf = s;
        }
};


void print_knapsack(int n, vector<vector<int>>& dp, vector<int>& val, vector<int>& wt)
{
    queue <Pair> q;
    // push the Pair of the last cell of dp
    q.push(Pair(dp.size() - 1, dp[0].size() - 1, ""));
    
    while(!q.empty()){
        
        Pair top = q.front();
        q.pop();
        
        // when capcity becomes 0 or no items left => print answer
        if(top.j == 0 || top.i == 0){
            cout<<top.psf<<endl;
        }
        
        // NOTE: without giving else, it will give segmentation fault
        else{
            
            if(top.j >= wt[top.i - 1]){
                int include = val[top.i - 1] + dp[top.i - 1][top.j - wt[top.i-1]];
                
                // if the current cell value == include => add curElement ("i-1" of wt[] & val[]) to ans and push corresponding Pair
                if(dp[top.i][top.j] == include){
                    q.push(Pair(top.i - 1, top.j - wt[top.i - 1], to_string(top.i - 1) + " " + top.psf));
                }
            }
            
            //NOTE: Don't write else-if cuz we can get same value from include & exclude => push both Pairs
            
            int exclude = dp[top.i - 1][top.j];
            // if the current cell value == excludes => max-val has come from top
            if(dp[top.i][top.j] == exclude){
                q.push(Pair(top.i - 1, top.j, top.psf));
            }
            
        }
    }
}


void knapsack_0_1(int n, vector<int>& val, vector<int>& wt, int cap)
{
    vector<vector<int>> dp (n+1, vector<int> (cap + 1));
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= cap; j++){
            
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            
            else if(wt[i-1] <= j){
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j - wt[i-1]]);
            }
            
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout<<dp[n][cap]<<endl;
    
    print_knapsack(n, dp, val, wt);
}


int main()
{
    int n, capacity;
    cin>>n;
    
    vector <int> val(n);
    for(int i = 0; i < n; i++){
        cin>>val[i];
    }
    
    vector <int> wt(n);
    for(int i = 0; i < n; i++){
        cin>>wt[i];
    }
    
    cin>>capacity;
    
    knapsack_0_1(n, val, wt, capacity);
    
    return 0;
}