#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};

// NOTE: APPROACH
// (1) We will keep going right and appending the value to vector<int> until right becomes NULL.
// (2) For each node being processed in step (1), push it's left children in the QUEUE
// so that we'll get the elements for next diagonal.

vector<vector<int>> diagonalOrder(TreeNode *root)
{
    queue <TreeNode*> q;
    // push root
    q.push(root);
    
    vector<vector<int>> res;
    
    while(!q.empty()){
        // find the size of queue, to run "for" loop for each left-component in queue
        int n = q.size();
        
        // declare a vector<int> to store diagonal of node (i.e nodes to right)
        vector<int> curDiagonal;
        
        for(int i = 0; i < n; i++){
            // get the element from queue
            TreeNode *node = q.front();
            q.pop();
            
            // keep going right until you can & keep adding left-children in queue.
            while(node != nullptr){
                // add the node to curDiagonal vector
                curDiagonal.push_back(node->val);
                
                // check if the left-child exists & if yes, push it to queue
                if(node->left){
                    q.push(node->left);
                }
                
                // move right
                node = node->right;
            }
            
            // after coming out from while loop:
            // (a) You've diagonal elements of q.front() node. Remaining (n-1) nodes 
            //     in the current diagonal still need to be processed.
            // (b) Queue has all the left-node of nodes from step(a). Diagonal elements
            //    of these left-nodes in queue has to be printed next.
            
        }
        
        // curDiagonal has now all the nodes in current diagonal
        res.push_back(curDiagonal);
    }
    
    return res;
}




// input_section=================================================

TreeNode *createTree(vector<int> &arr, vector<int> &IDX)
{

    if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
    {
        IDX[0]++;
        return nullptr;
    }

    TreeNode *node = new TreeNode(arr[IDX[0]++]);
    node->left = createTree(arr, IDX);
    node->right = createTree(arr, IDX);

    return node;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> IDX(1, 0);
    TreeNode *root = createTree(arr, IDX);

    vector<vector<int>> ans = diagonalOrder(root);
    int idx = 0;
    for (vector<int> &i : ans)
    {
        cout << idx++ << " -> ";
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}