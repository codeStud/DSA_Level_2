#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>
using namespace std;

class TreeNode
{
public:
  int val = 0;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;

  TreeNode(int val)
  {
    this->val = val;
  }
};


// NOTE NOTE: Just like Dia_03 (diameter of bt all methods) - 
// maxSum(leaf->leaf) can either be in left-Subtree or in right-subtree or can pass through root.
// So, we need leftSubtree-maxSum(leaf->leaf) rightSubtree-maxSum(leaf->leaf) curNode-maxSum(leaf->leaf)
// Also, to calculate curNode-maxSum(leaf->leaf), we need [ maxSum(leftChild->leaf) & maxSum(rightChild->leaf) + curNode->val ]

// Thus take a pair which returns two things...
// pair.first = maxSum from current node till any of its leaf
// pair.second = maxSum between any 2 leaves in BT rooted at the current node
pair<int, int> maxPathSumUtil(TreeNode* root)
{
    // base pair when either left or right child DOESN'T exist
    if(root == nullptr){
        pair<int, int> basePair = {-(int)1e9 - 1, -(int)1e9 - 1};
        return basePair;
    }
    
    // base pair when current node is a leaf
    if(root->left == nullptr && root->right == nullptr){
        // maxSum from current node till any of its leaf = root->val
        // maxSum between any 2 leaves in BT rooted at the current node (N/A)
        pair<int, int> basePair = {root->val, -(int)1e9 - 1};
        return basePair;
    }
    
    pair<int, int> leftPair = maxPathSumUtil(root->left);
    pair<int, int> rightPair = maxPathSumUtil(root->right);
    
    pair<int, int> curPair;
    
    // maxSum of path from current node to any of its leaf
    curPair.first = root->val + max(leftPair.first, rightPair.first);
    
    // Now, lets find maxSum of path (leaf->leaf) PASSING THROUGH CURRENT node
    // = root->val + maxSum of path(leftChildNode->leaf) + maxSum of path(rightChildNode->leaf)
    int curLeafToLeafSum = -(int)1e9 - 1;
    
    // BUT NOTE that path (leaf->leaf) PASSING THROUGH CURRENT node is possible
    // only if current node has both left and right child, otherwise NOT (i.e -(int)1e9 - 1).
    if(root->left && root->right){
        curLeafToLeafSum = root->val + leftPair.first + rightPair.first;
    }
    
    // Overall maxSum of path (leaf->leaf) of binary tree ROOTED AT CURRENT node
    // NOT NECCESSARILY PASSING THROUGH IT.
    curPair.second = max({leftPair.second, rightPair.second, curLeafToLeafSum});
    
    return curPair;
}

// NOTE: Just like Dia_02 (dia of bt all methods) - 
// We are calculating maxSum from each node to one of it's leaf. So, on our path - we'll get Opportunity
// to find maxSum (leaf-to-leaf) passing through ANY NODE.
// So, keep a global variable for maxSum_LeafToLeaf and keep updating it at each node (if that node has
// both left and right child) as = maxSum_LeafToLeaf = node->val + maxSum(rightChild node->leaf) 
int maxSum_LeafToLeaf = -(int)1e9 - 1;
int maxPathSumUtil_02(TreeNode *root)
{
    if(root == nullptr){
        return -(int)1e9 - 1;
    }
    
    if(root->left == nullptr && root->right == nullptr){
        return root->val;
    }
    
    int leftSum = maxPathSumUtil_02(root->left);
    int rightSum = maxPathSumUtil_02(root->right);
    
    int curSum = root->val + max(leftSum, rightSum);
    
    if(root->left && root->right){
        int curLeafToLeafSum = root->val + leftSum + rightSum;
        if(curLeafToLeafSum > maxSum_LeafToLeaf){
            maxSum_LeafToLeaf = curLeafToLeafSum;
        }
    }
    
    return curSum;
}


int maxPathSum(TreeNode* root)
{
    // pair<int, int> finalPair = maxPathSumUtil_01(root);
    // return finalPair.second;
    
    maxPathSumUtil_02(root);
    return maxSum_LeafToLeaf;
}



// input_Section=================================================

TreeNode* createTree(vector<int>& arr, vector<int>& IDX)
{
  if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
  {
    IDX[0]++;
    return nullptr;
  }
  TreeNode* node = new TreeNode(arr[IDX[0]++]);
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
  int tar;
  cin >> tar;
  vector<int> IDX(1, 0);
  TreeNode* root = createTree(arr, IDX);
  cout << maxPathSum(root) << endl;
}

int main()
{
  solve();
  return 0;
}