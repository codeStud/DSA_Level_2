#include<iostream>
#include<string>
#include<vector>
using namespace std;


void queens_permutation_2(int n, int row, int col, int queenCount, vector<bool>& queens, string asf)
{
    if(row == n){
        // if all the queens have been placed, print only those options
        if(queenCount == n){
            cout<<asf<<endl;
            cout<<endl;
        }
        
        return;
    }
    
    int nextRow = 0, nextCol = 0;
    string separator = "";
    
    if(col == n-1){
        nextRow = row + 1;
        col = 0;
        separator = "\n";
    }
    else{
        nextRow = row;
        nextCol = col + 1;
        separator = "\t";
    }
    
    // the current box has 2 choices - 1) Place "unvisited" queen   2) Don't place queen
    
    // let's place the unvisited queens 
    for(int i = 0; i < queens.size(); i++){
        if(queens[i] == false){
            queens[i] = true;
            
            queens_permutation_2(n, nextRow, nextCol, queenCount + 1, queens, asf + "q" + to_string(i + 1) + separator);
            
            //BACKTRACKING
            queens[i] = false;
        }
    }
    
    // Don't place any queen
    queens_permutation_2(n, nextRow, nextCol, queenCount, queens, asf + "-" + separator);
}


int main()
{
    int n;
    cin>>n;
    
    vector <bool> queens(n, false);
    
    queens_permutation_2(n, 0, 0, 0, queens, "");
    
    return 0;
}