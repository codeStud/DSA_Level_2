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


void one_child_parent(TreeNode *root, vector<int>& ans)
{
    if(root->left == nullptr && root->right == nullptr){
        return;
    }
    
    else if(root->right == nullptr){
        ans.push_back(root->val);
        one_child_parent(root->left, ans);    
    }
    
    else if(root->left == nullptr){
        ans.push_back(root->val);
        one_child_parent(root->right, ans);    
    }
    
    else{
        one_child_parent(root->left, ans);
        one_child_parent(root->right, ans);
    }
}


vector<int> exactlyOneChild(TreeNode* root)
{
  vector<int> ans;
  
  if(root != nullptr)
    one_child_parent(root, ans);
    
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

  vector<int> ans = exactlyOneChild(root);
  if (ans.size() == 0)
    cout << endl;
  for (int i : ans)
  {
    cout << i << " ";
  }
}

int main()
{
  solve();
  return 0;
}