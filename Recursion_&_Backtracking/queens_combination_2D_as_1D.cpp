#include<iostream>
#include<string>
#include<vector>
using namespace std;

void queens_combinations_2(int qsf, int n, vector<vector<bool>>& chess, int prevQueenCell)
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
    
    // treating the 2-D chess array as 1-D
    for(int cell = prevQueenCell + 1; cell < (chess.size() * chess.size()); cell++){
        
        // get the current cell's row number
        int row = cell / n;
        
        // get current cell's col number
        int col = cell % n;
        
        // place the queen in the current row, col
        chess[row][col] = true;
        
        // pass current queen's cell in 1-D as next queens "prevQueenCell"
        queens_combinations_2(qsf + 1, n, chess, cell);
        
        // BACKTRACKING
        chess[row][col] = false;
        
    }
}

int main()
{
    int n;
    cin>>n;
    
    vector <vector<bool>> chess (n, vector<bool>(n, false));
    
    queens_combinations_2(0, n, chess, -1);
    
    return 0;
}