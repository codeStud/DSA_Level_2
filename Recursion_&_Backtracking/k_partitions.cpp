#include<iostream>
#include<vector>
using namespace std;

int counter = 0;

void display(vector<vector<int>> sets, int k)
{
    counter++;
    cout<<counter<<". ";
    
    for(int i = 0; i < k; i++){
        cout<<"[";
        for(int j = 0; j < sets[i].size() - 1; j++){
            cout<<sets[i][j]<<", ";
        }
        cout<<sets[i][sets[i].size()-1]<<"] ";
    }
    
    cout<<endl;
}


void kSubsets(int i, int n, int k, vector<vector<int>>& sets, int noOfNonEmptySubsets)
{
    if(i > n){
        if(noOfNonEmptySubsets == k){
            display(sets, k);
        }
        
        return;
    }
    
    // loop through all the k-subsets
    for(int j = 0; j < k; j++){
        
        // if the current subset is non-empty
        if(sets[j].size() > 0){
            // push the i-th element in j-th subset
            sets[j].push_back(i);
            
            // count of non empty subsets remains same
            kSubsets(i + 1, n, k, sets, noOfNonEmptySubsets);
            
            // remove the i-th element from j-th subset, so that in next iteration of loop, i-th element can sit back in the (j+1)th subset.
            sets[j].pop_back();
        }
        
        else{
            // push i-th element in the first empty subset
            sets[j].push_back(i);
            
            // count of non empty subsets increases ny 1
            kSubsets(i + 1, n, k, sets, noOfNonEmptySubsets + 1);
            
            // remove the i-th element from jth subset so that other elements can 
            // also come in this jth subset as single element
            sets[j].pop_back();
            
            break;
        }
        
    }
}


int main()
{
    int n, k;
    cin>>n>>k;
    
    vector<vector<int>> sets (k);
    
    kSubsets(1, n, k, sets, 0);
    
    return 0;
}