#include<iostream>
#include<string>
using namespace std;

void combinations(int currentBox, int noOfBoxes, int itemsRemaining, string asf)
{
    if(currentBox > noOfBoxes){
        // check if only two boxes filled
        if(itemsRemaining == 0){
            cout<<asf<<endl;
        }
        // if(noOfBoxSelected == itemsRemaining){
        //     cout<<asf<<endl;
        // }
        
        return;
    }
    
    // at each level, consider either selecting the box for putting item, or not selecting it
    
    // combinations(currentBox + 1, noOfBoxes, ritems, noOfBoxSelected + 1, asf + "i");

    // put the item in the current box and move to next box & decrement itemsRemaining
    combinations(currentBox + 1, noOfBoxes, itemsRemaining - 1, asf + "i");
    
    // don't put the item in the current box and move to next box & keep itemsRemaining intact.
    combinations(currentBox + 1, noOfBoxes, itemsRemaining, asf + "-");

    // combinations(currentBox + 1, noOfBoxes, itemsRemaining, noOfBoxSelected, asf + "-");
    
}

int main()
{
    int nboxes, ritems;
    cin>>nboxes>>ritems;
    
    int noOfBoxSelected = 0;
    int currentBox = 1;
    string answer = "";
    
    // combinations(currentBox, nboxes, ritems, noOfBoxSelected, answer);
    
    // no need of noOfBoxSelected, just keep decrementing ritems until it reaches 0
    combinations(currentBox, nboxes, ritems, answer);
    
    return 0;
}