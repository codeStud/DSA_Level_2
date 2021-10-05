#include<iostream>
#include<string>
#include<vector>
using namespace std;

void queens_combinations_2(int qsf, int n, int i, int j, vector<vector<bool>>& chess)
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
    
    // place the queen in the same row as that of previous queen but to the right of it.
    // No need to check if the box is already visited due to above reason.
    for(int col = j + 1; col < n; col++){
        // just mark the box true as we don't need the actual value in the box
        chess[i][col] = true;
        
        // pass the j as col for the next queen
        queens_combinations_2(qsf + 1, n, i, col, chess);
        
        chess[i][col] = false;
    }
    
    // Place the queen in the next row of the previously placed queen
    for(int row = i + 1; row < n; row++){
        for(int col = 0; col < n; col++){
            chess[row][col] = true;
            
            // pass the i as row and j as col for the next queen
            queens_combinations_2(qsf + 1, n, row, col, chess);
            
            chess[row][col] = false;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    
    vector <vector<bool>> chess (n, vector<bool>(n, false));
    
    // pass row = 0 and col = -1 for first queen
    queens_combinations_2(0, n, 0, -1, chess);
    
    return 0;
}