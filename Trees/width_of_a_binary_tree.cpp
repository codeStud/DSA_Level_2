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


int widthUtil(TreeNode* root, int curLevel, int& minLevel, int& maxLevel)
{
    if(curLevel < minLevel){
        minLevel = curLevel;
    }
    
    else if(curLevel > maxLevel){
        maxLevel = curLevel;
    }
    
    // if left child exists, go left with curLevel - 1
    if(root->left){
        widthUtil(root->left, curLevel - 1, minLevel, maxLevel);
    }
    
    // if right child exists, go right with curLevel + 1
    if(root->right){
        widthUtil(root->right, curLevel + 1, minLevel, maxLevel);
    }
    
    // widht of the TREE will be maxLevel - minLevel + 1
    return (maxLevel - minLevel + 1);
}


int width(TreeNode *root)
{
    if(root == nullptr){
        return 0;
    }
    
    int minLev = 0;
    int maxLev = 0;
    // call utility function with current horizontal level, minLevel, maxLevel;
    return widthUtil(root, 0, minLev, maxLev);
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

    cout << width(root) << endl;
}

int main()
{
    solve();
    return 0;
}