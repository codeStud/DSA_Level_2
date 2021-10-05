// NOTE NOTE: Another good approach to this problem - 
// https://www.youtube.com/watch?v=nPtARJ2cYrg

#include <iostream>
#include <vector>
#include <queue>
#include<unordered_set>
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


bool node_to_root_path(TreeNode *root, int target, vector<TreeNode*>& path)
{
    if(root == nullptr){
        return false;
    }
    
    if(root->val == target){
        path.push_back(root);
        return true;
    }
    
    if(node_to_root_path(root->left, target, path) == true){
        path.push_back(root);
        return true;
    }
    
    else if(node_to_root_path(root->right, target, path) == true){
        path.push_back(root);
        return true;
    }
    
    return false;
}


vector<TreeNode*> distanceK(TreeNode* root, int target, int k)
{
    vector<TreeNode*> pathToRoot;
    node_to_root_path(root, target, pathToRoot);
    
    vector<TreeNode*> ans;
    int K = k;
    
    for(int i = 0; i < pathToRoot.size(); i++){
        TreeNode *node = pathToRoot[i];
        k_level_down(node, K, ans, node->val == target ? nullptr : pathToRoot[i - 1]);
        K -= 1;
    }
    
    return ans;
}


int size_of_tree(TreeNode* root)
{
    if(root == nullptr){
        return 0;
    }
    
    int leftSize = size_of_tree(root->left);
    int rightSize = size_of_tree(root->right);
    
    return leftSize + rightSize + 1;
}


// NOTE NOTE: CONCEPT - Burn all nodes of the tree which are 1 level away from fireNode- 1 sec; 2 level away from
// fireNode- 2 sec; 3 level away from fireNode- 3 sec.... Do this until all nodes of the tree are covered.
int burningTree(TreeNode* root, int fireNode)
{
    int size = size_of_tree(root);
    
    
    // NOTE NOTE: KEEP ADDING NODES AT LEVEL-0, LEVEL-1 ... (BFS) UNTIL ALL NODES IN TREE ARE ADDED. 
    unordered_set<TreeNode*> hashSet;
    
    int k = 0;
    // Initialize time var with -1 & NOT 0 bcz if only 1 node in tree, then in while 
    // loop, totalTime += 1 will make ans=1 but the correct ans for 1 node tree = 0 seconds
    int totalTime = -1; 
    
    while(hashSet.size() != size){
        vector<TreeNode*> ans = distanceK(root, fireNode, k);
        for(TreeNode* node : ans){
            if(hashSet.find(node) == hashSet.end()){
                hashSet.insert(node);
            }
        }
        
        k += 1;
        totalTime += 1;
    }
    
    return totalTime;
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

  int fireNode;
  cin >> fireNode;
  int ans = burningTree(root, fireNode);
  cout << ans << endl;
}

int main()
{
  solve();
  return 0;
}