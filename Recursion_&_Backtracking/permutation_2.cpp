#include<iostream>
#include<string>
#include<vector>
using namespace std;

void permutations(vector<int>& boxes, int idx, int nboxes, int ritems, int itemCount, bool* visited)
{
    if(idx == nboxes){
        
        // print only if all the ritems has been placed in the box
        if(itemCount == ritems){        // (OR can modify function to check if ritems == 0)
            for(int i : boxes){
                cout<<i;
            }
            cout<<endl;
        }
        return;
    }
    
    // explore each item as a choice for boxes[idx]
    for(int item = 1; item <= ritems; item++){
        // if the item isn't already visited
        if(visited[item] == false){
            // put the item in the current box
            boxes[idx] = item;

            // mark the current item visited
            visited[item] = true;
            
            // move to next box and increase the itemCount (OR decrease the ritems by 1)
            permutations(boxes, idx + 1, nboxes, ritems, itemCount + 1, visited);
            
            // BACKTRACKING
            visited[item] = false;
            boxes[idx] = 0;
        }
    }
    
    // boxes[idx] can also choose NOT to put any items. Simply go to next box then.
    permutations(boxes, idx + 1, nboxes, ritems, itemCount, visited);
}

int main()
{
    int nboxes, ritems;
    cin>>nboxes>>ritems;
    
    bool visited[ritems + 1] = {false};
    vector <int> boxes (nboxes, 0);
    
    permutations(boxes, 0, nboxes, ritems, 0, visited);
    
    return 0;
}