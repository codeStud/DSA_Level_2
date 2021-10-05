#include<iostream>
#include<vector>
using namespace std;

void combinations(vector<bool>& boxes, int nboxes, int ritems, int itemCount, int lastFilledBox)
{
    if(itemCount == ritems){
        for(int i = 0; i < nboxes; i++){
            // if current box is filled
            if(boxes[i] == true){
                cout<<"i";
            }
            else{
                cout<<"-";
            }
        }
        cout<<endl;
        
        return;
    }
    
    
    // put the item only in the boxes which are right of the lastFilledBox
    // No need to check if(boxes[i] == false) as we are looping on the right-side of the filled boxes
    for(int i = lastFilledBox + 1; i < nboxes; i++){
        // put the item in the current box
        // (i.e mark the current box visited) => trick to fill item if the actual item value doesn't matter
        boxes[i] = true;
        
        // increase itemCount and set lastFilledBox = current box i
        combinations(boxes, nboxes, ritems, itemCount + 1, i);
        
        // BACKTRACK
        boxes[i] = false;
    }
    
}

int main()
{
    int nboxes, ritems;
    cin>>nboxes>>ritems;
    
    vector <bool> boxes (nboxes, false);
    
    // pass -1 as lastFilledBox for the 1st item
    combinations(boxes, nboxes, ritems, 0, -1);
    
    return 0;
}