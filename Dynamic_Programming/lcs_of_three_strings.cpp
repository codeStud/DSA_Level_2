#include<iostream>
#include<algorithm>
#include<cstring>       // memset is deined in cstring header-file
using namespace std;

// 3-D dp
int dp[101][101][101];

int lcs_of_three(string& s1, string& s2, string& s3, int i, int j, int k)
{
    if(i < 0 || j < 0 || k < 0){
        return 0;    
    }
    
    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }
    
    int res = 0;
    if(s1[i] == s2[j] && s2[j] == s3[k]){
        res = 1 + lcs_of_three(s1, s2, s3, i-1, j-1, k-1);
    }
    
    else{
        res = max({lcs_of_three(s1, s2, s3, i-1, j, k),
                  lcs_of_three(s1, s2, s3, i, j-1, k),
                  lcs_of_three(s1, s2, s3, i, j, k-1)
                  });
    }
    
    // store in dp before returning
    dp[i][j][k] = res;
    return res;
}


int main()
{
    string s1, s2, s3;
    cin>>s1>>s2>>s3;
    
    // initialise dp with -1
    memset(dp, -1, sizeof(dp));
    
    cout<<lcs_of_three(s1, s2, s3, s1.size()-1, s2.size()-1, s3.size()-1);
    
    return 0;
}