// NOTE: Each level represents a knight and each knight has chess[][] boxes as options (Like combinations-2).
// But since we don't care about the actual value in the chess cell, we don't have a "int curKnight" variable. 
// We are just making chess[row][col] = true -> increasing the knightCount (for base case) -> moving to the "next" safe cell

#include<iostream>
#include<string>
#include<vector>
using namespace std;


bool isSafeMove(vector<vector<bool>>& chess, int i, int j)
{
    if(i - 1 >= 0 && j - 2 >= 0 && chess[i-1][j-2] == true){
        return false;
    }   
    
    if(i - 2 >= 0 && j - 1 >= 0 && chess[i-2][j-1] == true){
        return false;
    } 
    
    if(i - 2 >= 0 && j + 1 < chess.size() && chess[i-2][j+1] == true){
        return false;
    }
    
    if(i - 1 >= 0 && j + 2 < chess.size() && chess[i-1][j+2] == true){
        return false;
    }
    
    // else safe move
    return true;
}


void N_Knights_Combination(int knightCount, int n, vector<vector<bool>>& chess, int prevKnightCell)
{
    if(knightCount == n){
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(chess[row][col] == true){
                    cout<<"k\t";
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
    
    // Current knight has option to sit in all the cells AFTER the prevKnightCell. Thus,
    // treating 2-D as 1-D and exploring all the cell options AFTER the prevKnightCell
    for(int cell = prevKnightCell + 1; cell < n * n; cell++){
        int row = cell / n;
        int col = cell % n;
        
        if(isSafeMove(chess, row, col) == true){
            chess[row][col] = true;
        
            // current knight's cell = "prevKnightCell" for the next knight
            N_Knights_Combination(knightCount + 1, n, chess, cell);
            
            // backtrack to explore other safe combinations of "n-knights"
            chess[row][col] = false;
        }
    }
}


int main()
{
    int n;
    cin>>n;
    
    vector<vector<bool>> chess (n, vector<bool>(n, false));
    
    N_Knights_Combination(0, n, chess, -1);
    
    return 0;
}