#include<iostream>
#include<vector>
using namespace std;


void display(vector<vector<int>>& arr)
{
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


bool isValidOp(vector<vector<int>>& arr, int i, int j, int op)
{
    // check in row
    for(int col = 0; col < 9; col++){
        if(arr[i][col] == op){
            return false;
        }
    }
    
    // check in col
    for(int row = 0; row < 9; row++){
        if(arr[row][j] == op){
            return false;
        }
    }
    
    // check 3*3 sub-matrix
    // go to the top left corner of the current sub-matrix
    int subi = (i / 3) * 3;         // x/3 * 3 != x (since we we take the floor of x/3)
    int subj = (j / 3) * 3;
    
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            if(arr[subi + x][subj + y] == op){
                return false;
            }
        }
    }
    
    // if reached here => op is valid
    return true;
}


void sudokuSolver(vector<vector<int>>& arr, int i, int j)
{
    // base case: if "i" reaches outside of the board
    if(i == arr.size()){
        display(arr);
        return;
    }
    
    
    // store the next index you wanna go to
    int ni, nj;
    if(j == arr[0].size() - 1){
        // go to next row and 0th col
        ni = i+1;
        nj = 0;
    }
    else{
        ni = i;
        nj = j+1;
    }
    
    // if current cell > 0 => go to ni and nj
    if(arr[i][j] != 0){
        sudokuSolver(arr, ni, nj);
    }
    
    else{
        // at the current cell, try all the options from 1 to 9
        for(int op = 1; op <= 9; op++){
            if(isValidOp(arr, i, j, op) == true){
                // fill the option in the current cell
                arr[i][j] = op;
                
                // make call for next cell
                sudokuSolver(arr, ni, nj);
                
                // if you reach this post area ==> 
                // 1. current op didn't take you to the last cell of the sudoku. Thus, reset it to 0  & try another op.
                // 2. You've displayed one of the possible solutions & trying to figure out another solution, if any.
                
                arr[i][j] = 0;
            }
        }
    
    }
}


int main()
{
    vector <vector<int>> arr (9, vector<int> (9));
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin>>arr[i][j];
        }
    }
    
    sudokuSolver(arr, 0, 0);
    
    return 0;
}