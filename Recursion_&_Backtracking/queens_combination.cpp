#include<iostream>
#include<string>
using namespace std;

void queensCombinations(int queenCountSoFar, int n, int row, int col, string asf)
{
    // if have discovered all the n*n cells
    if(row == n){
        // if have placed n-queens
        if(queenCountSoFar == n){
            cout<<asf<<endl;
        }
        return;
    }
    
    int nextRow;
    int nextCol;
    // there can be 2 yesAnswers and 2 noAnswers. Thus, we need a separate variable
    string yesAnswer = "";
    string noAnswer = "";
    
    // if not at extreme right corner
    if(col < n-1){
        nextRow = row;
        nextCol = col + 1;
        yesAnswer = asf + "q";
        noAnswer = asf + "-";
    }
    // if at extreme right corner
    else{
        nextRow = row + 1;
        nextCol = 0;
        yesAnswer = asf + "q\n";
        noAnswer = asf + "-\n";
    }
    
    // place the queen in the current row-col
    queensCombinations(queenCountSoFar + 1, n, nextRow, nextCol, yesAnswer);
    
    // don't place the queen in the current row-col
    queensCombinations(queenCountSoFar, n, nextRow, nextCol, noAnswer);
}

int main()
{
    int n;
    cin>>n;
    
    // pass queenCountSoFar, n, row, col, asf
    queensCombinations(0, n, 0, 0, "");
    
    return 0;
}