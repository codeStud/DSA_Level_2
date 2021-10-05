// Below code is "exactly" same as NQueens problem in level-1 backtracking.
// Note the minor difference in the way we are treating the 2-D array as 1-D and how we generated combination in 
// "level-1 NQueens" by placing queen in the next row only (=> we placed queens only AFTER the prevQueenCell)

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isSafeMove(vector<vector<bool>>& chess, int row, int col)
{
    // check the column
    for(int i = row, j = col; i >= 0; i--){
        if(chess[i][j] == true){
            return false;
        }
    }
    
    // check the row 
    for(int i = row, j = col; j >= 0; j--){
        if(chess[i][j] == true){
            return false;
        }
    }
    
    // check diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(chess[i][j] == true){
            return false;
        }
    }
    
    // check reverse diagonal
    for(int i = row, j = col; i >= 0 && j < chess[0].size(); i--, j++){
        if(chess[i][j] == true){
            return false;
        }
    }
    
    return true;
}

void N_Queens_Combinations(int qsf, int n, vector<vector<bool>>& chess, int prevQueenCell)
{
    // NOTE: checking if(i == n) in the base case WON'T work here as we are making the 
    // recursive calls smartly. All the recursive calls will be made within n * n
    if(qsf == n){
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(chess[row][col] == true){
                    cout<<"q\t";
                }
                else{
                    cout<<"-\t";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        
        return;
    }
    
    // treating the 2-D chess array as 1-D and placing the queen AFTER the previous queen to generate combination
    for(int cell = prevQueenCell + 1; cell < (chess.size() * chess.size()); cell++){
        
        // get the current cell's row number
        int row = cell / n;
        
        // get current cell's col number
        int col = cell % n;
        
        // check if it is safe place to put the queen
        if(isSafeMove(chess, row, col) == true){
            // place the queen in the current row, col
            chess[row][col] = true;
            
            // pass current queen's cell in 1-D as next queens "prevQueenCell"
            N_Queens_Combinations(qsf + 1, n, chess, cell);
            
            // BACKTRACKING
            chess[row][col] = false;
        }
        
    }
}

int main()
{
    int n;
    cin>>n;
    
    vector <vector<bool>> chess (n, vector<bool>(n, false));
    
    N_Queens_Combinations(0, n, chess, -1);
    
    return 0;
}