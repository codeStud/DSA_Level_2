// NOTE: This is just like LIS
// In LIS -
// (a) Maximize:    length of subsequence
// (b) Restriction: numbers will be increasing (i.e NO NUMBER can come after a number in the subsequence which is smaller than the current number)

// In highway billboard:
// (a) Maximize:    Profit
// (b) Restriction: Boards should be at T distance atleast (i.e NO BOARD can come after a board which is less than T distance away from the current board)

// So, at each point, store the max-profit that can be earned if "current-billboard" is the end (last) billboard (just like LIS)

#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;


int max_revenue(int len, int n, vector<int>& dist, vector<int>& revenue, int t)
{
    int maxRev = 0;
    
    // declare a dp of size = number of billboard
    vector<int> dp (dist.size());
    dp[0] = revenue[0];
    
    for(int i = 1; i < dp.size(); i++){
        int maxVal = 0;
        for(int j = 0; j < i; j++){
            
            if(abs(dist[i] - dist[j]) > t){
                // can put current billboard behind the j-th billboard
                maxVal = max(maxVal, dp[j]);
            }
            
        }
        
        // put max-revenue that can be generated if "i"th billboard must be place at end
        dp[i] = maxVal + revenue[i];
        
        // update the maxRev
        maxRev = max(maxRev, dp[i]);
    }
    
    return maxRev;
}


// METHOD-2
// Time: O(m)
// Space: O(m + n)
int max_revenue_2(int m, int n, vector<int>& dist, vector<int>& revenue, int t)
{
    unordered_map<int, int> hashMap;
    for(int i = 0; i < n; i++){
        hashMap.insert({dist[i], revenue[i]});
    }

    // at each index, we'll store the max-revenue that can be generated TILL THAT Distance
    vector<int> dp (m+1, 0);
    dp[0] = 0;      // i.e 0 revenue for 0 km

    for(int i = 1; i < dp.size(); i++){
        // if no billboard at current distance, take the previous value
        if(hashMap.find(i) == hashMap.end()){
            dp[i] = dp[i - 1];
        }

        else{
            // We have 2 choices for current billboard - 
            int dontInclude = dp[i - 1];
            // include the current billboard revenue + max-reveneue till 't' distance back
            int include = hashMap[i] + (i >= t + 1 ? dp[i - t - 1] : 0);

            dp[i] = max(include, dontInclude);
        }
    }

    // dp[m] will contain the max-revenue till 'm' km
    return dp[m];
}


int main()
{
    int m, n;
    cin>>m>>n;
    
    vector<int> dist (n);
    for(int i = 0; i < n; i++){
        cin>>dist[i];
    }
    
    vector<int> revenue (n);
    for(int i = 0; i < n; i++){
        cin>>revenue[i];
    }
    
    int t;
    cin>>t;
    
    cout<<max_revenue(m, n, dist, revenue, t);
    // cout<<max_revenue_2(m, n, dist, revenue, t);
    
    return 0;
}