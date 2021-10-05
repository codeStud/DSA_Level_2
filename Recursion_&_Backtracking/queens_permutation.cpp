#include<iostream>
#include<string>
#include<vector>
using namespace std;

void queensPermutations(vector<vector<int>>& chess, int n, int curQueen)
{
    
    if(curQueen > n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(chess[i][j] == 0){
                    cout<<"-\t";                
                }
                else{
                    cout<<"q"<<chess[i][j]<<"\t";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    
    // give the current queen, a chance to be placed in everyBox which is empty
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(chess[i][j] == 0){
                // place the current queen in the chess
                chess[i][j] = curQueen;
                
                // go to the next queen
                queensPermutations(chess, n, curQueen + 1);
                
                // BACKTRACKING
                chess[i][j] = 0;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    
    vector<vector<int>> chess(n, vector<int>(n, 0));
    
    queensPermutations(chess, n, 1);
}