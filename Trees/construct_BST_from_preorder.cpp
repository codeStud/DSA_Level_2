#include <iostream>
#include <vector>
#include<climits>
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

// Multiple BST possible given only preorder. 
// In our BST, we are passing leftRange and rightRange for each of the nodes.
// We keep moving from left to right in preorder[] and keep adding node in left if
// it lies within the leftRange. If it doesn't, return and check for making it right node.

// Pass idx by reference as we continuously want to move only forward in preorder
TreeNode *bstFromPreorder(vector<int> &preorder, int& idx, int leftRange, int rightRange)
{
    // IF IT DOESN'T Lie in any range, return null
    if(idx >= preorder.size() || preorder[idx] < leftRange || preorder[idx] > rightRange){
        return nullptr;
    }
    
    TreeNode* root = new TreeNode(preorder[idx]);
    idx++;
    
    root->left = bstFromPreorder(preorder, idx, leftRange, root->val);
    root->right = bstFromPreorder(preorder, idx, root->val, rightRange);
    
    return root;
}

// input_Section_====================================================================

void display(TreeNode *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->val) : "."));
    str += (" -> " + to_string(node->val) + " <- ");
    str += ((node->right != nullptr ? to_string(node->right->val) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    
    int idx = 0;
    int leftRange = INT_MIN;
    int rightRange = INT_MAX;
    
    TreeNode *root = bstFromPreorder(pre, idx, leftRange, rightRange);
    display(root);
}

int main()
{
    solve();
    return 0;
}