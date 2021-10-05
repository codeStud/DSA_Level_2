// Application of Catalan Number

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int noOfNodes;
    cin>>noOfNodes;
    
    vector<int> BST_Count (noOfNodes + 1);
    
    // 0 nodes => empty bst (count = 1)
    BST_Count[0] = 1;
    // 1 node => 1 bst
    BST_Count[1] = 1;
    
    for(int i = 2; i <= noOfNodes; i++){
        
        int noOfLeftNodes = 0;
        int noOfRightNodes = i - 1;
        
        while(noOfLeftNodes <= i - 1){
            
            BST_Count[i] += BST_Count[noOfLeftNodes] * BST_Count[noOfRightNodes];
            
            noOfLeftNodes++;
            noOfRightNodes--;
            
        }
        
    }
    
    cout<<BST_Count[noOfNodes]<<endl;
    
    return 0;
}