// NOTE: Solution - 
// (1) We want to print levelwise => levelOrder traversal
// (2) At each level, we want leftMost node to be printed first => 
//          - consider root node at 0-th level.
//          - nodes on left will keep getting -1, -2, -3... value
//          - nodes on right will keep getting 1, 2, 3... value
    //  In map<int, vector> for each level, maintain all the nodes. Since levelOrder traversal,
    // nodes at below level will come later in the map<int,vector> (as required)
// To know how many horizontal levels are there (from which key to start printing from and where to end) - keep updating minLevel & maxLevel

#include <iostream>
#include <vector>
#include <queue>
#include<unordered_map>
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


// NOTE: Declare a pair to store node along with it's horizontal level
class vPair{
    public:
        TreeNode* node;
        int level;
        
        vPair(TreeNode* node, int level)
        {
            this->node = node;
            this->level = level;
        }
};

vector<vector<int>> verticalOrderTraversal(TreeNode *root)
{
    queue <vPair> q;
    // Push root pair with 0 horizontal level
    q.push(vPair(root, 0));
    
    unordered_map<int, vector<int>> hashMap;
    
    // keep track of minLevel and maxLevel
    int minLevel, maxLevel;
    minLevel = maxLevel = 0;
    
    while(!q.empty()){
        // find queue size for level order traversal
        int n = q.size();
        
        for(int i = 0; i < n; i++){
            vPair top = q.front();
            q.pop();
            
            // push_back the top.node->val inside the vector present at the top.level in hashMap
            hashMap[top.level].push_back(top.node->val);
            
            // update the minLevel/maxLevel
            if(top.level < minLevel){
                minLevel = top.level;
            }
            if(top.level > maxLevel){
                maxLevel = top.level;
            }
            
            // push the left child in queue with top.level-1 value
            if(top.node->left){
                q.push(vPair(top.node->left, top.level - 1));
            }
            
            // push right child with top.level + 1
            if(top.node->right){
                q.push(vPair(top.node->right, top.level + 1));
            }
        }
        
    }
    
    // declare a result vector with number of rows = (maxLevel - minLevel + 1)
    vector<vector<int>> res (maxLevel - minLevel + 1);
    
    // declare 'i' as the row number of res vector
    int i = 0;
    
    // loop from minLevel to maxLevel
    for(int key = minLevel; key <= maxLevel; key++){
        
        // push all the 'int' values in the vector<int> placed at hashMap[key]
        for(int val : hashMap[key]){
            res[i].push_back(val);
        }
        
        // go to the next row
        i++;
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

    vector<vector<int>> ans = verticalOrderTraversal(root);
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