#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Pair {
    public:
       int idx;
       int step_size_allowed;
       int min_step_req;
       string psf;
       
       Pair(int i, int j, int m, string s)
       {
           this->idx = i;
           this->step_size_allowed = j;
           this->min_step_req = m;
           this->psf = s;
       }
};


void print_min_jumps_paths(vector<int>& arr, vector<int>& dp)
{
    queue <Pair> q;
    
    // push the starting pair
    q.push(Pair(0, arr[0], dp[0], to_string(0)));
    
    while(!q.empty()){
        Pair top = q.front();
        q.pop();
        
        // once the removed element top has min_step_req == 0 => print psf
        if(top.min_step_req == 0){
            cout<<top.psf<<" ."<<endl;
        }
        
        for(int j = 1; j <= top.step_size_allowed && j + top.idx < arr.size(); j++){
            int curIdx = top.idx + j;
            
            // add the reachable steps from the top Pair if min_step_count is 1 less than top-Pair's min_steps_req bcz we want to print "min_jumps_path"
            if(dp[curIdx] == top.min_step_req - 1){
                q.push(Pair(curIdx, arr[curIdx], dp[curIdx], top.psf + " -> " + to_string(curIdx)));
            }
        }
    }
    
}


void min_jumps(vector<int>& arr)
{
    vector <int> dp(arr.size(), INT_MAX);
    
    // base case
    dp[arr.size() - 1] = 0;
    
    for(int i = dp.size() - 2; i >= 0; i--){
        int steps = arr[i];
        
        int min_steps = INT_MAX;
        // find the min_steps to reach destination from all the reachable steps from curStep
        for(int j = 1; j <= steps && i + j < dp.size(); j++){
            if(dp[i + j] < min_steps){
                min_steps = dp[i + j];
            }
        }
        
        if(min_steps != INT_MAX){
            dp[i] = min_steps + 1;
        }
    }
    
    // print the min_steps
    if(dp[0] == INT_MAX){
        cout<<"null"<<endl;
    }
    else{
        cout<<dp[0]<<endl;
    }
    
    
    print_min_jumps_paths(arr, dp);
}


int main()
{
    int n;
    cin>>n;
    
    vector <int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    min_jumps(arr);
    
    return 0;
}