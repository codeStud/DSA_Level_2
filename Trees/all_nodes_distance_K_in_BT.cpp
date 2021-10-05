// NOTE: Resource: https://www.youtube.com/watch?v=s22QClql9LU

// NOTE NOTE: Another good approach to this problem - 
// https://www.youtube.com/watch?v=nPtARJ2cYrg

#include <iostream>
#include <vector>
#include <queue>
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


void k_level_down(TreeNode* root, int k, vector<TreeNode*>& kLevelDown, TreeNode* blocker)
{
    if(root == nullptr || k < 0 || root == blocker){
        return;
    }
    
    if(k == 0){
        kLevelDown.push_back(root);
        return;
    }
    
    k_level_down(root->left, k-1, kLevelDown, blocker);
    k_level_down(root->right, k-1, kLevelDown, blocker);
}


// bool node_to_root_path(TreeNode *root, int target, vector<TreeNode*>& path)
// {
//     if(root == nullptr){
//         return false;
//     }
    
//     if(root->val == target){
//         path.push_back(root);
//         return true;
//     }
    
//     if(node_to_root_path(root->left, target, path) == true){
//         path.push_back(root);
//         return true;
//     }
    
//     else if(node_to_root_path(root->right, target, path) == true){
//         path.push_back(root);
//         return true;
//     }
    
//     return false;
// }


// NOTE: This function will return a non-negative value if the target is found
// at a node or in a subtree. 

// NOTE: The above logic will simulate NODE-TO-ROOT path in RECURSIVE STACK and 
// NO NEED OF EXTRA SPACE TO STORE nodeToRootPath
int K_distance_Util(TreeNode* root, int target, int k, vector<TreeNode*>& ans)
{
    if(root == nullptr){
        // target is not found => return negative value
        return -1;
    }
    
    if(root->val == target){
        // We want all nodes "k" level down from this target node, bocker=NULL
        k_level_down(root, k - 0, ans, nullptr);
        
        // NOTE: return how far this target node is away from just-above parent, 
        // i.e parent of the current root node(which is = targetNode) = 1 distance away
        return 1;
    }
    
    // go to left-subtree
    int leftVal = K_distance_Util(root->left, target, k, ans);
    // target found in left-subtree
    if(leftVal > 0){
        // we want all nodes at "k - leftVal" down the current node, blocker will be the left node of current node
        k_level_down(root, k - leftVal, ans, root->left);
        
        // since target found in left subtree, return +ve value of "How far is current node's PARENT from target"
        return leftVal + 1;
    }
    
    // go to right-subtree
    int rightVal = K_distance_Util(root->right, target, k, ans);
    // target found in right-subtree
    if(rightVal > 0){
        // we want all nodes at "k - rightVal" down the current node, blocker will be the right node of current node
        k_level_down(root, k - rightVal, ans, root->right);
        
        // since target found in right subtree, return +ve value of "How far is current node's PARENT from target"
        return rightVal + 1;
    }
    
    // if you reach this part => target node not found => return negative value
    return -1;
}



vector<TreeNode*> distanceK(TreeNode* root, int target, int k)
{
    vector<TreeNode*> ans;
    
    K_distance_Util(root, target, k, ans);
    
    return ans;
}

// input_section=================================================

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

  vector<int> IDX(1, 0);
  TreeNode* root = createTree(arr, IDX);

  int target, k;
  cin >> target >> k;
  vector<TreeNode*> ans = distanceK(root, target, k);
  if (ans.size() == 0)
    cout << endl;
  for (TreeNode* node : ans)
  {
    cout << node->val << "\n";
  }
}

int main()
{
  solve();
  return 0;
}