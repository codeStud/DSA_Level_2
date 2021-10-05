#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;

class Pair {
    public:
        int lis_len;
        int idx;
        int val;
        string psf;
        
        Pair(int l, int i, int v, string s)
        {
            this->lis_len = l;
            this->idx = i;
            this->val = v;
            this->psf = s;
        }
};

int main()
{
    int n;
    cin>>n;
    
    vector <int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    // get LIS
    vector <int> dp(n);
    int lis_len = 0;
    
    for(int i = 0; i < dp.size(); i++){
        int maxVal = 0;
        
        for(int j = 0; j < i; j++){
            if(arr[j] <= arr[i]){
                maxVal = max(maxVal, dp[j]);
            }
        }
        
        dp[i] = maxVal + 1;
        if(dp[i] > lis_len){
            lis_len = dp[i];
        }
    }
    
    // print the LIS_len
    cout<<lis_len<<endl;
    
    queue <Pair> q;
    
    for(int i = 0; i < dp.size(); i++){
        // push all the elements initially with dp[i] == lis_len 
        if(dp[i] == lis_len){
             // add the Pair of LAST element of LIS in queue
            q.push(Pair(lis_len, i, arr[i], to_string(arr[i])));
        }
    }
    
    
    while(!q.empty()){
        Pair top = q.front();
        q.pop();
        
        // when the top element has lis_len == 1 => print the path
        if(top.lis_len == 1){
            cout<<top.psf<<endl;
        }
        
        // loop from the index left of currently removed element till 0
        for(int j = top.idx - 1; j >= 0; j--){
            // find the element with -
            // 1. lis_len just less than curElement's lis_len &&
            // 2. element smaller in value than curElement.
            if(arr[j] < top.val && dp[j] == top.lis_len - 1){
                q.push(Pair(dp[j], j, arr[j], to_string(arr[j]) + " -> " + top.psf));
            }
        }
        
    }
    
    return 0;
}