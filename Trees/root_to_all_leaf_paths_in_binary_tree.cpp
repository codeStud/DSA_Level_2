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


// NOTE: Due to certain malloc error while pushing vector<int> path into vector<vector<int>> ans, I am just printing the answer and returning an empty vector<vector<int>>
void root_to_all_leaf_path_util(TreeNode *root, vector<int> path)
{
    if(root->left == nullptr && root->right == nullptr){
        path.push_back(root->val);
        
        for(int el : path){
            cout<<el<<" ";
        }
        
        cout<<"\n";
        
        return;
    }
    
    path.push_back(root->val);
    
    if(root->left)  root_to_all_leaf_path_util(root->left, path);
    if(root->right) root_to_all_leaf_path_util(root->right, path);
}

vector<vector<int>> rootToAllLeafPath(TreeNode* root)
{
    vector<vector<int>> ans;

    vector<int> path;
    root_to_all_leaf_path_util(root, path);
    
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

  vector<vector<int>> ans = rootToAllLeafPath(root);
  if (ans.size() == 0)
    cout << endl;
  for (auto& al : ans)
  {
    for (int ele : al)
      cout << (ele + " ");
    cout << endl;
  }
}

int main()
{
  solve();
  return 0;
}