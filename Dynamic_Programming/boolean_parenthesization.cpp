#include<iostream>
#include<vector>
#include<string>
using namespace std;


void solution(string oprnd, string oprtr)
{
    int n = oprnd.size();
    
    // will store the number of ways current expression will evaluate to True
    vector<vector<int>> dpTrue (n, vector<int> (n));
    // will store the number of ways current expression will evaluate to False
    vector<vector<int>> dpFalse (n, vector<int> (n));
    
    for(int gap = 0; gap < n; gap++){
        for(int i = 0, j = gap; j < n; i++, j++){
            
            if(gap == 0){
                char ch = oprnd[i];
                
                if(ch == 'T'){
                    dpTrue[i][j] = 1;
                    dpFalse[i][j] = 0;
                }
                else{
                    dpTrue[i][j] = 0;
                    dpFalse[i][j] = 1;
                }
            }
            
            else{
                for(int k = i; k < j; k++){
                    char booleanSign = oprtr[k]; 
                    
                    int leftTrueCount = dpTrue[i][k];
                    int rightTrueCount = dpTrue[k + 1][j];
                    
                    int leftFalseCount = dpFalse[i][k];
                    int rightFalseCount = dpFalse[k + 1][j];
                    
                    // Don't forget to put "+=" in calculations below
                    if(booleanSign == '&'){
                        dpTrue[i][j] += leftTrueCount * rightTrueCount;
                        
                        dpFalse[i][j] += leftTrueCount*rightFalseCount + leftFalseCount*rightTrueCount + leftFalseCount*rightFalseCount;
                    }
                    
                    else if(booleanSign == '|'){
                        dpTrue[i][j] += leftTrueCount*rightTrueCount + leftFalseCount*rightTrueCount + leftTrueCount*rightFalseCount;
                        
                        dpFalse[i][j] += leftFalseCount*rightFalseCount;
                    }
                    
                    else{   // xor '^'
                        dpTrue[i][j] += leftTrueCount*rightFalseCount + leftFalseCount*rightTrueCount;
                        
                        dpFalse[i][j] += leftFalseCount*rightFalseCount + leftTrueCount*rightTrueCount;
                    }
                }
            }
            
        }
    }
    
    cout<<dpTrue[0][n - 1];
}


int main()
{
    string s1, s2;
    cin>>s1>>s2;
    
    solution(s1, s2);
    
    return 0;
}