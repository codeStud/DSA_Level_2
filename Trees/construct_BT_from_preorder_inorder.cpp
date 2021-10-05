// NOTE: Use nullptr in place of NULL bcz value of NULL is 0 (cout<<NULL gives 0)
// But nullptr is always a null POINTER. 
// Using NULL can cause ambiguity in function overloading - 
// f(int);
// f(foo *);


#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int val, TreeNode* left, TreeNode* right)
        {
            this->val = val;
            this->left = left;
            this->right = right;
        }
};

// METHOD-1
TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder, int preStartIdx, int preEndIdx, int inStartIdx, int inEndIdx)
{
    // NOTE: In base case, the start and end pointers will cross each other
    if(preStartIdx > preEndIdx || inStartIdx > inEndIdx){
        return nullptr;
    }

    // make the element at preStartIdx as the new Node
    TreeNode *root = new TreeNode(preorder[preStartIdx], nullptr, nullptr);

    // Find this "root's" element data in inorder
    int idx = inStartIdx;
    while(inorder[idx] != root->val){
        idx++;
    }

    // find the count of the elements from inStartIdx till idx => you'll know what preStartIdx & preEndIdx
    // to pass to the left and right recursive calls
    int count = idx - inStartIdx;

    // make the recursive call to make left-subtree passing it all the elements which will occur in the 
    // left subtree of the current root made above along with appropriate preStartIdx and preEndIdx
    root->left = buildTree(preorder, inorder, preStartIdx + 1, preStartIdx + count, inStartIdx, idx - 1);

    
    // make the recursive call to make right-subtree passing it all the elements which will occur in the 
    // right subtree of the current root made above along with appropriate preStartIdx and preEndIdx
    root->right = buildTree(preorder, inorder, preStartIdx + count + 1, preEndIdx, idx + 1, inEndIdx);

    return root;
}


// METHOD-2
// Pass preOrder index by reference and just keep incrementing it by 1 for function call.
TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder, int& preIdx, int inStart, int inEnd)
{
    // BASE CASE
    if(inStart > inEnd){
        return nullptr;
    }

    // make pre[preIdx] as the new node
    TreeNode* root = new TreeNode(preorder[preIdx], nullptr, nullptr);
    
    // NOTE: This is the only step in the function, where preIdx is incremented
    // move to the next element in preIdx
    preIdx += 1;

    // Find this "root's" element data in inorder
    int idx = inStart;
    while(inorder[idx] != root->val){
        idx++;
    }

    // All the elements to the left of idx in INORDER will lie in the left-subtree. 
    // preIdx has already been incremented. Just pass it by REFERENCE. (OR make it a global variable)
    root->left = buildTree2(preorder, inorder, preIdx, inStart, idx - 1);

    // All the elements to the right of idx in INORDER will lie in the right-subtree. 
    // preIdx has already been incremented. Just pass it by REFERENCE. (OR make it a global variable)
    root->right = buildTree2(preorder, inorder, preIdx, idx + 1, inEnd);

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

int main()
{
    int n;
    cin >> n;
    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    // TreeNode *root = buildTree(pre, in, 0, pre.size() - 1, 0, in.size() - 1);

    int preStartIdx = 0;
    TreeNode *root = buildTree2(pre, in, preStartIdx, 0, in.size() - 1);

    display(root);

    return 0;
}