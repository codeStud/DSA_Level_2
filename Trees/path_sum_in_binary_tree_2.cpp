#include <iostream>
#include <vector>
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


void pathSumUtil(TreeNode* root, int target, vector<vector<int>>& res, vector<int>& path)
{
    if(root == nullptr){
        return;
    }
    
    else if(root->left == nullptr && root->right == nullptr){
        // haven't yet included the leaf's value
        if(target - root->val == 0){
            path.push_back(root->val);
            
            // add path to res
            res.push_back(path);
            
            // backtrack path<>
            path.pop_back();
        }
        
        return;
    }
    
    // add the current root to path
    path.push_back(root->val);
    
    pathSumUtil(root->left, target - root->val, res, path);
    pathSumUtil(root->right, target - root->val, res, path);
    
    // BACKTRACK
    path.pop_back();
}


vector<vector<int>> pathSum(TreeNode* root, int targetSum)
{
  vector<vector<int>> res;
  vector<int> path;
  
  pathSumUtil(root, targetSum, res, path);
  
  return res;
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
  vector<vector<int>> ans = pathSum(root, tar);
if(ans.size() == 0)cout << " "<<endl;
  for (auto ar : ans)
  {
    for (int ele : ar)
    {
      cout << ele << " ";
    }
    cout << endl;
  }
}

int main()
{
  solve();
  return 0;
}