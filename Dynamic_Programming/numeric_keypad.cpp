#include<iostream>
#include<vector>
#include<string>
using namespace std;


int numeric_keypad(int n)
{
    vector<vector<int>> dp (n+1, vector<int>(10));
    
    // store each keypad key can be pressed AFTER which key
    vector<vector<int>> data (10);
    data[0].insert(data[0].begin(), {0, 8});
    data[1].insert(data[1].begin(), {1, 2, 4});
    data[2].insert(data[2].begin(), {2, 1, 3, 5});
    data[3].insert(data[3].begin(), {3, 2, 6});
    data[4].insert(data[4].begin(), {4, 1, 5, 7});
    data[5].insert(data[5].begin(), {5, 2, 4, 6, 8});
    data[6].insert(data[6].begin(), {6, 5, 9, 3});
    data[7].insert(data[7].begin(), {7, 4, 8});
    data[8].insert(data[8].begin(), {8, 5, 7, 9, 0});
    data[9].insert(data[9].begin(), {9, 8, 6});
    
    // for no. of times the keypad is pressed
    for(int i = 0; i <= n; i++){
        // for each keypad number
        for(int j = 0; j <= 9; j++){
            
            // if 0 times pressed => 0 string possible
            if(i == 0){
                dp[i][j] = 0;
            }
            
            // if 1 time pressed, 1 string (that number itself) is possible
            else if(i == 1){
                dp[i][j] = 1;
            }
            
            else{
                // if "j"th key is being pressed AT THE "i-th" STROKE
                // then, it can be pressed after data[j] keypads, i.e "i-1 th" press should be data[j] keys. So, take their sum.
                for(int prevKeys : data[j]){
                    // take sum from "i - 1"th keypress of the data[j] keys
                    dp[i][j] += dp[i - 1][prevKeys];
                } 
            }
        }
    }
    
    // After "n" keypress, the number of strings possible is the sum of n-th row of dp
    int totalCount = 0;
    for(int j = 0; j < 10; j++){
        totalCount += dp[n][j];
    }
    
    return totalCount;
}


int main()
{
    int n;
    cin>>n;
    
    cout<<numeric_keypad(n);
    
    return 0;
}