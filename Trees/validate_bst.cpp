#include <iostream>
#include <vector>
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


bool is_valid_bst_util(TreeNode *root, TreeNode *prev)
{
    if(root == nullptr){
        return true;
    }
    
    // if left-subtree isn't a BST, return false immediately without going any further
    if(!is_valid_bst_util(root->left, prev))  return false;
    
    // Work in Inorder to check if the values are in SORTED order or not
    if(prev != nullptr && prev->val > root->val)
        return false;
    // else, move previous forward
    prev = root;
    
    // if right-subtree isn't a BST, return false immediately without going any further
    if(!is_valid_bst_util(root->right, prev)) return false;
    
    // if left-subtree is a root, current node is in increasing order, right-subtree is a root => return true
    return true;
}


bool isValidBST(TreeNode *root)
{
    TreeNode *prev = nullptr;
    return is_valid_bst_util(root, prev);
}

TreeNode *createTree(vector<int> &arr, vector<int> &IDX)
{
    if (IDX[0] > arr.size() || arr[IDX[0]] == -1){
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
    cout << (boolalpha) << isValidBST(root);
}

int main()
{
    solve();
    return 0;
}