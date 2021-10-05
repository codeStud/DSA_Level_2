// NOTE: Move the pascal triangle one step to the right, to make it a lower triangular matrix - 
//     -                        -
//   -   -          =>          -  -
// -   -   -                    -  -  -

// Now, the left glass of the "i-th" glass in on index (i+1, j) & right glass in on the (i+1, j+1) index

// NOTE: CORRECT SOLUTION

#include<iostream>
#include<vector>
using namespace std;


int find_water(int waterQuantity, int r, int c)
{
    // each index "i" in dp[][] will store the quantity of water in the "i-th" glass
    vector<vector<double>> dp (waterQuantity + 1, vector<double> (waterQuantity + 1, 0));

    // first glass will have the waterQuantity amount of water poured in it
    dp[0][0] = waterQuantity;

    // traverse in the lower triangular matrix due to the above explanation
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j <= i; j++){
            // if the current glass is overflowing
            if(dp[i][j] > 1.0){
                // reduce the quantity by 1 ltr
                double spare = dp[i][j] - 1.0;
                // set the amount of water in current glass to 1 ltr
                dp[i][j] = 1.0;
                
                // divide the spare in left and right glass in equal quantities
                dp[i + 1][j] = spare / 2.0;
                dp[i + 1][j + 1] = spare / 2.0;
            }
        }
    }

    // at last, return the amount of water in r, c, glass
    return dp[r][c];
}


int main()
{
    int k, r, c;
    cin>>k>>r>>c;

    find_water(k, r, c);

    return 0;
}