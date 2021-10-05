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


// NOTE: MaxPathSum(node->node) has 6 potential candidates - 
// (1) It can entirely be in left-subtree of current node
// (2) It can entirely be in right-subtree of current node
// (3) It can be in leftSubtree + root->val (when elements in right-subtree are -ve)
// (4) It can be in rightSubtree + root->val (when elements in left-subtree are -ve)
// (5) It can only be the root->val (when all elements in left & right subtree are -ve)
// (6) It can be leftSubtree + root->val + rightSubtree

// pair.first = maxSumPath STARTING from current node ending at another node (in left/right subtree depending upon maxSum we can get)

// pair.second = maxSumPath (node->node) for the entire tree ROOTED AT current node

pair<int, int> maxPathSumUtil(TreeNode *root)
{
    if(root == nullptr){
        // maxSumPath starting from curNode = 0
        // maxSumPath node->node for entire tree = -infinity 
        pair<int, int> basePair = {0, -(int)1e9 - 1};
        return basePair;
    }
    
    if(root->left == nullptr && root->right == nullptr){
        // maxSumPath starting from curNode = leaf's value
        // maxSumPath node->node for entire tree = leaf's value 
        pair<int, int> basePair = {root->val, root->val};
        return basePair;
    }
    
    pair<int, int> leftPair = maxPathSumUtil(root->left);
    pair<int, int> rightPair = maxPathSumUtil(root->right);
    
    pair<int, int> curPair;
    
    // rootToNodeSum stores maximum of [ case-(3) and case-(4) ]
    int rootToNodeSum = root->val + max(leftPair.first, rightPair.first);
    
    // case (1) = leftPair.second       case (2) = rightPair.second
    // case (3) + case (4) = rootToNodeSum
    // case (5) = root->val     case (6) = leftPair.first + root->val + rightPair.first
    curPair.second = max({leftPair.second, rightPair.second, rootToNodeSum, root->val, leftPair.first + root->val + rightPair.first});
    
    // if left and right subtrees have negative values => maxSum from root to node 
    // will be root to root itself
    curPair.first = max(rootToNodeSum, root->val);
    
    return curPair;
}


int maxPathSum(TreeNode* root)
{
    // pair<int, int> finalPair = maxPathSumUtil_01(root);
    // return finalPair.second;
    
    pair<int, int> finalPair = maxPathSumUtil(root);
    return finalPair.second;
    // return maxSum_LeafToLeaf;
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