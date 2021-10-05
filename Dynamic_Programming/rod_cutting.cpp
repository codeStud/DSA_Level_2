// NOTE: This can be solved using 2 strategies: (1) All Possible Cut Strategy     (2) Optimal-LeftHalf + Optimal-RightHalf Strategy.
// 4 -> Actual price of length 4    (from prices[])
// 4* -> Optimized price for length 4 (from dp[])

// (1) All Possible Cut Strategy:
// For length "n"- take all possible length cuts & their ACTUAL PRICE (1st-cut-len = 0, 1, 2 ... n) and then,
// take OPTIMIZED PRICE for the remaining length after 1st cut - (remaining-len = n, n-1, n-2, .... 0) respectively.
// At end, take the maximum amongst all the (actual-1st-cut-price + optimized-rem-len-price)

// Eg: n=4 => (1st-cut-price, rem-len-price): max[ (1, 3*) vs (2, 2*) vs (3, 1*) vs (4) ]


// (2) Optimal-LeftHalf + Optimal-RightHalf Strategy:
// For length "n"- You can initally make 2 cuts & divide the rod into left-half and right-half.
// Then find the OPTIMIZED prices of both left-half and right-half & take the maximum amongst all the (left-half-opt-price + right-half-opt-price).

// Eg: n=6 => (left-half-price, right-half-price): max [ (1*, 5*) vs (2*, 4*) vs (3*, 3*) vs (6) ]
// NOTE: [(4*, 2*), (5*, 1*) are repeatations]. Thus, GO TILL MID-HALF OF "n" & also include price(n) as it is.


#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;


// METHOD-1: All Possible Cut Strategy:

int cutRod(vector<int>& price)
{
   int n = price.size();
   int val[n+1];
   val[0] = 0;
   int i, j;
 
   for (i = 1; i<=n; i++)
   {
       int max_val = INT_MIN;
       for (j = 0; j < i; j++)
         max_val = max(max_val, price[j] + val[i-j-1]);
       val[i] = max_val;
   }
 
   return val[n];
}


// METHOD-2: Optimal-LeftHalf + Optimal-RightHalf Strategy

int rod_cutting(vector<int>& arr)
{
    vector <int> dp (arr.size() + 1);
    
    dp[0] = 0;
    // cost of rod of len=1
    dp[1] = arr[0];
    
    for(int i = 2; i < dp.size(); i++){
        dp[i] = arr[i-1];
        
        // start from making a leftCut of len=1  => right-cut will be of len=i-1
        int leftCut = 1;
        int rightCut = i - 1;
        
        // go till leftCut size <= rightCut size. If continued after that, 
        // values will start repeating, just the values of leftCut - rightCut will be interchanged.
        while(leftCut <= rightCut){
            
            // get the optimum prices of left-cut size and right-cut size
            if(dp[leftCut] + dp[rightCut] > dp[i]){
                // update the maxProfit in dp[i]
                dp[i] = dp[leftCut] + dp[rightCut];
            }
            
            // increase the left-cut size
            leftCut++;
            // decrease the right-cut size
            rightCut--;
            
        }
    }
    
    return dp[arr.size()];
}


int main()
{
    int n;
    cin>>n;
    
    vector <int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    cout<<rod_cutting(arr);
    cout<<cutRod(arr);
    
    return 0;
}