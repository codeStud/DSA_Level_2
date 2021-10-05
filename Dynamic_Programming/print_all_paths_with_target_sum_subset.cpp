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


void print_target_subsets(vector<int>& arr, vector<vector<bool>>& dp)
{
    queue <Pair> q;
    // push the Pair of the last cell of dp
    q.push(Pair(dp.size() - 1, dp[0].size() - 1, ""));
    
    while(!q.empty()){
        
        Pair top = q.front();
        q.pop();
        
        if(top.j == 0){
            cout<<top.psf<<endl;
        }
        
        // NOTE: without giving else, it will give segmentation fault
        else{
            
            // Including top Pair gives "yes" => add top to ans and push the corresponding above pair in queue.
            if(top.j >= arr[top.i - 1] && dp[top.i - 1][top.j - arr[top.i - 1]] == true){
                q.push(Pair(top.i - 1, top.j - arr[top.i - 1], to_string(top.i - 1) + " " + top.psf));
                
            }
            
            //NOTE: Don't write else-if cuz we want to check both include and exclude calls
            // Not including top pair results in YES => push the pair above this cell
            if(dp[top.i - 1][top.j] == true){
                q.push(Pair(top.i - 1, top.j, top.psf));
            }
            
        }
        
    }
}


void targetSumSubset(vector<int>& arr, int target)
{
    vector<vector<bool>> dp (arr.size()+1, vector<bool>(target+1));
    
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[0].size(); j++){
            // sum 0 can be formed by all
            if(j == 0){
                dp[i][j] = true;
            }
            
            // empty set can't form non-zero sum
            else if(i == 0){
                dp[i][j] = false;
            }
            
            else{
                if(j < arr[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
            }
        }
    }
    
    if(dp[arr.size()][target]){
        cout<<"true"<<endl;
        
        // print the subsets
        print_target_subsets(arr, dp);
    }    
    else{
        cout<<"false"<<endl;
    }
    
}


int main()
{
    int n, target;
    cin>>n;
    
    vector <int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    cin>>target;
    
    targetSumSubset(arr, target);
    
    return 0;
}