// NOTE: Notice how it's different from Nqueens_Combination and how it is generating the permutation. 
// It'll generate permutation as we are placing queen in all of the empty + safe cells and NOT restricting that 
// curQueen will be placed only AFTER the prevQueens(Combinations) (Look at permutation-1 and combinations-2 for clearer understanding)

#include<iostream>
#include<string>
#include<vector>
using namespace std;


// NOTE: will have to check NOT only above the current queen but also below it as
// it can be placed anywhere in an empty cell...
bool isSafeMove(vector<vector<int>>& chess, int row, int col)
{
    // check vertically up
    for(int i = row, j = col; i >= 0; i--){
        if(chess[i][j] > 0){
            return false;
        }
    }
    
    // check vertically down
    for(int i = row, j = col; i < chess.size(); i++){
        if(chess[i][j] > 0){
            return false;
        }
    }
    
    // check horizontally left
    for(int i = row, j = col; j >= 0; j--){
        if(chess[i][j] > 0){
            return false;
        }
    }
    
    // check horizontally right
    for(int i = row, j = col; j < chess.size(); j++){
        if(chess[i][j] > 0){
            return false;
        }
    }
    
    // check up diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(chess[i][j] > 0){
            return false;
        }
    }
    
    // check up reverse diagonal
    for(int i = row, j = col; i >= 0 && j < chess.size(); i--, j++){
        if(chess[i][j] > 0){
            return false;
        }
    }
    
    // check down diagonal
    for(int i = row, j = col; i < chess.size() && j < chess[0].size(); i++, j++){
        if(chess[i][j] > 0){
            return false;
        }
    }
    
    // check down reverse diagonal
    for(int i = row, j = col; i < chess.size() && j >= 0; i++, j--){
        if(chess[i][j] > 0){
            return false;
        }
    }
    
    return true;
}

void N_Queens_Permutations(int qsf, int n, vector<vector<int>>& chess)
{
    // NOTE: checking if(i == n) in the base case WON'T work here as we are making the 
    // recursive calls smartly. All the recursive calls will be made within n * n
    if(qsf == n){
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(chess[row][col] == 0){
                    cout<<"-\t";
                }
                else{
                    cout<<"q"<<to_string(chess[row][col]) + "\t";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        
        return;
    }
    
    // Each queen can sit in any of the cell if it's empty + safe & NOT only AFTER the previous queens => Will generate permutation
    // So, treating the 2-D chess array as 1-D
    for(int cell = 0; cell < (chess.size() * chess.size()); cell++){
        
        // get the current cell's row number
        int row = cell / n;
        
        // get current cell's col number
        int col = cell % n;
        
        // check if it is empty + safe place to put the queen
        if(chess[row][col] == 0 && isSafeMove(chess, row, col) == true){
            
            // place the queen number in the current row, col
            chess[row][col] = qsf + 1;
            
            N_Queens_Permutations(qsf + 1, n, chess);
            
            // BACKTRACKING
            chess[row][col] = 0;
        }
        
    }
}

int main()
{
    int n;
    cin>>n;
    
    vector <vector<int>> chess (n, vector<int>(n, 0));
    
    N_Queens_Permutations(0, n, chess);
    
    return 0;
}