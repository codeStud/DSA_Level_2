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


// returns yes if data found, no if data not found
bool node_to_root_path_util(TreeNode* root, int data, vector<TreeNode*>& res)
{
    if(root == nullptr){
        return false;
    }
    
    // if root->val==data => store the root in res and return true
    if(root->val == data){
        res.push_back(root);
        return true;
    }
    
    // else, check in left-subtree
    else if(node_to_root_path_util(root->left, data, res) == true){
        // add the current node to path and return true
        res.push_back(root);
        return true;
    }
    
    // else, check in right-subtree
    else if(node_to_root_path_util(root->right, data, res) == true){
        res.push_back(root);
        return true;
    }
    
    // else return false
    return false;
}


// Find the data, and while returning, add the node in vector
vector<TreeNode*> nodeToRootPath(TreeNode* root, int data)
{
    // METHOD-1 
    // vector<TreeNode*> res;
    // node_to_root_path_util(root, data, res);
    // return res;


    // METHOD-2
    // if root is null, return empty vector
    if(root == nullptr){
        vector<TreeNode*> res;
        return res;
    }
    
    // if root->val == data, add root to the vector and return vector itself
    if(root->val == data){
        vector<TreeNode*> res;
        res.push_back(root);
        return res;
    }
    
    // otherwise check in left-subtree
    vector<TreeNode*> left = nodeToRootPath(root->left, data);
    // if found in left-subtree, simply add the current node to vector and return it.
    if(left.size() > 0){
        left.push_back(root);
        return left;
    }
    
    // otherwise search in right-subtree
    vector<TreeNode*> right = nodeToRootPath(root->right, data);
    // if found in right-subtree, simply add the current node to vector and return it.
    if(right.size() > 0){
        right.push_back(root);
        return right;
    }
    
    // if not found anywhere => you'll hit this line of code => return empty vector
    vector<TreeNode*> res;
    
    return res;
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

  int data;
  cin >> data;
  vector<TreeNode*> ans = nodeToRootPath(root, data);
  if (ans.size() == 0)
    cout << endl;
  for (TreeNode* node : ans)
  {
    cout << node->val << " ";
  }
}

int main()
{
  solve();
  return 0;
}