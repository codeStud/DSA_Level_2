// NOTE: Use nullptr in place of NULL bcz value of NULL is 0 (cout<<NULL gives 0)
// But nullptr is always a null POINTER. 
// Using NULL can cause ambiguity in function overloading - 
// f(int);
// f(foo *);


// NOTE: IN POST-ORDER Traversal
// We make the last element of the post[] as the root. Then, we keep decrementing the index to traverse post[] 
// from right to left. But since it is POSTORDER traversal & you are traversing post[] from RIGHT TO LEFT
// => the elements of post[] will "first represent the elements of the RIGHT-Subtree of the root" and then
// they'll represent the elements of the left-subtree.

// THUS - If you are following METHOD-2, make the RIGHT SUBTREE FIRST and then make left-subtree


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
TreeNode* buildTree(vector<int> &postorder, vector<int> &inorder, int postStartIdx, int postEndIdx, int inStartIdx, int inEndIdx)
{
    // NOTE: In base case, the start and end pointers will cross each other
    if(postStartIdx > postEndIdx || inStartIdx > inEndIdx){
        return nullptr;
    }

    // make the element at postEndIndex as the new Node
    TreeNode *root = new TreeNode(postorder[postEndIdx], nullptr, nullptr);

    // Find this "root's" element data in inorder
    int idx = inStartIdx;
    while(inorder[idx] != root->val){
        idx++;
    }

    // find the count of the elements from inStartIdx till idx => you'll know what postStartIdx & postEndIdx
    // to pass to the left and right recursive calls
    int count = idx - inStartIdx;

    // make the recursive call to make left-subtree passing it all the elements which will occur in the 
    // left subtree of the current root made above along with appropriate postStartIdx and postEndIdx
    root->left = buildTree(postorder, inorder, postStartIdx, postStartIdx + count - 1, inStartIdx, idx - 1);

    
    // make the recursive call to make right-subtree passing it all the elements which will occur in the 
    // right subtree of the current root made above along with appropriate postStartIdx and postEndIdx
    root->right = buildTree(postorder, inorder, postStartIdx + count, postEndIdx - 1, idx + 1, inEndIdx);

    return root;
}


// METHOD-2
// Pass postEnd index by reference and just keep decrementing it by 1 for function call. (Or make it Global)
TreeNode* buildTree2(vector<int>& postorder, vector<int>& inorder, int& postEndIdx, int inStart, int inEnd)
{
    // BASE CASE
    if(inStart > inEnd){
        return nullptr;
    }

    // make postorder[postEndIdx] as the new node
    TreeNode* root = new TreeNode(postorder[postEndIdx], nullptr, nullptr);
    
    // NOTE: This is the only step in the function, where postEndIdx is DECREMENTED
    // move to the next element in postEndIdx
    postEndIdx--;

    // Find this "root's" element data in inorder
    int idx = inStart;
    while(inorder[idx] != root->val){
        idx++;
    }

    // NOTE NOTE NOTE: MAKE RIGHT SUBTREE FIRST, bcz elements from the back of postorder[] represent the right subtree
    // first and then the left-subtree.

    // All the elements to the right of idx in INORDER will lie in the right-subtree. 
    // postEndIdx has already been Decremented. Just pass it by REFERENCE. (OR make it a global variable)
    root->right = buildTree2(postorder, inorder, postEndIdx, idx + 1, inEnd);

    // All the elements to the left of idx in INORDER will lie in the left-subtree. 
    // postEndIdx has already been Decremented. Just pass it by REFERENCE. (OR make it a global variable)
    root->left = buildTree2(postorder, inorder, postEndIdx, inStart, idx - 1);

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
    vector<int> post(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }

    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = buildTree(post, in, 0, post.size() - 1, 0, in.size() - 1);

    // int postEndIdx = post.size() - 1;
    // TreeNode *root = buildTree2(post, in, postEndIdx, 0, in.size() - 1);

    display(root);

    return 0;
}