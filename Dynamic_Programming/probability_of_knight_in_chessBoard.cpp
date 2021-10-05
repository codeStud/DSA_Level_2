#include<iostream>
#include<vector>
#include<limits>
#include <iomanip>      // is used to import setprecision()
using namespace std;


bool isValidMove(int i, int j, int n)
{
    if(i >= 0 && j >= 0 && i < n && j < n){
        return true;
    }
    else{
        return false;
    }
}


void probability_of_knight(int n, int k, int row, int col)
{
    vector <vector<double>> curStateDP (n, vector<double>(n));
    vector <vector<double>> nextStateDP (n, vector<double>(n));
    
    // probability of knight in row, col initially = 1
    curStateDP[row][col] = 1;
    
    // make the "k" moves
    for(int m = 0; m < k; m++){
        
        // look in the cells of curStateDP
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                // if value in cell isn't 0
                if(curStateDP[i][j] != 0){
                    // look at all the 8 possible moves
            // Each possible next -cell has probabilty = probabilty of cur-state * 1/8
                    int ni, nj;
                    
                    ni = i-2;
                    nj = j+1;
                    if(isValidMove(ni, nj, n)){
                        nextStateDP[ni][nj] += curStateDP[i][j] / 8.0; 
                    }
                    
                    ni = i-1;
                    nj = j+2;
                    if(isValidMove(ni, nj, n)){
                        nextStateDP[ni][nj] += curStateDP[i][j] / 8.0; 
                    }
                    
                    ni = i+1;
                    nj = j+2;
                    if(isValidMove(ni, nj, n)){
                        nextStateDP[ni][nj] += curStateDP[i][j] / 8.0; 
                    }
                    
                    ni = i+2;
                    nj = j+1;
                    if(isValidMove(ni, nj, n)){
                        nextStateDP[ni][nj] += curStateDP[i][j] / 8.0; 
                    }
                    
                    ni = i+2;
                    nj = j-1;
                    if(isValidMove(ni, nj, n)){
                        nextStateDP[ni][nj] += curStateDP[i][j] / 8.0; 
                    }
                    
                    ni = i+1;
                    nj = j-2;
                    if(isValidMove(ni, nj, n)){
                        nextStateDP[ni][nj] += curStateDP[i][j] / 8.0; 
                    }
                    
                    ni = i-1;
                    nj = j-2;
                    if(isValidMove(ni, nj, n)){
                        nextStateDP[ni][nj] += curStateDP[i][j] / 8.0; 
                    }
                    
                    ni = i-2;
                    nj = j-1;
                    if(isValidMove(ni, nj, n)){
                        nextStateDP[ni][nj] += curStateDP[i][j] / 8.0; 
                    }
                }
            }
        }
        
        // move curStateDP to nextStateDP & make nextStateDP empty
        curStateDP = nextStateDP;
        vector <vector<double>> newDP (n, vector<double>(n)); 
        nextStateDP = newDP;
    }
    
    // calculate the sum of all the probability in the last curStateDP board
    double sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum += curStateDP[i][j];
        }
    }
    
    // set decimal precision to 17 for answer submission.
    cout<<setprecision(17)<<sum<<endl;
}


int main()
{
    int n, k, r, c;
    cin>>n>>k>>r>>c;
    
    probability_of_knight(n, k, r, c);
    
    return 0;
}