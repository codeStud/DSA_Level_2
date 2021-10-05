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


// NOTE: Constructing Balanced BST. (Multiple BST possible with only inorder given)
TreeNode *constructFromInOrder(vector<int> &in, int start, int end)
{
    if(start > end){
        return nullptr;
    }
    
    int mid = start + (end-start)/2;
    
    TreeNode *root = new TreeNode(in[mid]);
    
    root->left = constructFromInOrder(in, start, mid - 1);
    root->right = constructFromInOrder(in, mid + 1, end);
    
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
    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = constructFromInOrder(in, 0, in.size() - 1);
    display(root);
}

int main()
{
    solve();
    return 0;
}