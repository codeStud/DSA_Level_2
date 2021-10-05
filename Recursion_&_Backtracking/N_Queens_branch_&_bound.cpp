#include<iostream>
#include<string>
#include<vector>
using namespace std;


void nQueens(vector<vector<int>>& chess, int row, int* colmn, int* diagonal, int* reverseDiagonal, string boardState)
{
    if(row == chess[0].size()){
        cout<<boardState<<"."<<endl;
        return;
    }
    
    // try placing queen in each column
    for(int col = 0; col < chess[0].size(); col++){
        // Just like isSafeMove(), but we are doing it in O(1) TIME using extra space for cols[], rd[], diag[]
        if(colmn[col] == 0 && diagonal[row+col] == 0 
        && reverseDiagonal[row-col + chess[0].size()-1] == 0){
            
            chess[row][col] = 1;
            colmn[col] = 1;
            diagonal[row+col] = 1;
            reverseDiagonal[row-col + chess[0].size()-1] = 1;
            
            nQueens(chess, row+1, colmn, diagonal, reverseDiagonal, boardState + to_string(row) + "-" + to_string(col) + ", ");
            
            // backtracking
            chess[row][col] = 0;
            colmn[col] = 0;
            diagonal[row+col] = 0;
            reverseDiagonal[row-col + chess[0].size()-1] = 0;
            
        }
    }
}


int main()
{
    int n;
    cin>>n;
    
    vector<vector<int>> chess (n, vector<int>(n));
    
    // for blocking column of current queen
    int colmn[n] = {0};
    
    // for blocking diagonal of current queen
    int diagonal[2*n - 1] = {0};
    
    // for blocking reverse diagonal of current queen
    int reverseDiagonal[2*n - 1] = {0};
    
    nQueens(chess, 0, colmn, diagonal, reverseDiagonal, "");
    
    return 0;
}