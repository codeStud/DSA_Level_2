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

bool hasPathSum(TreeNode* root, int sum)
{
    if(root == nullptr){
        if(sum == 0){
            return true;
        }
        else{
            return false;
        }
    }
    
    // // if answer found in left-subtree, then no need to go to right-subtree...
    // if(hasPathSum(root->left, sum - root->val)){
    //     return true;
    // }
    
    // if(hasPathSum(root->right, sum - root->val)){
    //     return true;   
    // }
    
    // // if neither in left-subtree nor in right-subtree  => return false
    // return false;
    
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
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
  cout << (boolalpha) << hasPathSum(root, tar) << endl;
}

int main()
{
  solve();
  return 0;
}