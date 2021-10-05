#include<iostream>
#include<vector>
using namespace std;

void permutations(vector<int>& box, int i, int ritems)
{
    if(i > ritems){
        for(int i : box){
            cout<<i;
        }
        cout<<endl;
        
        return;
    }
    
    // give the i-th item, chance in each box index
    for(int j = 0; j < box.size(); j++){
        // if the place is empty
        if(box[j] == 0){
            box[j] = i;
            permutations(box, i + 1, ritems);
            // BACKTRACKING
            box[j] = 0;
        }
    }
    
}

int main()
{
    int nboxes, ritems;
    cin>>nboxes>>ritems;
    
    // create vector of size nboxes initialised with 0
    vector <int> box (nboxes, 0);
    
    // pass box and item 1
    permutations(box, 1, ritems);
    
    return 0;
}