// #include <iostream>
// #include <vector>
// #include <queue>
// #include <stringstream>
#include <bits/stdc++.h>
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


// NOTE: NOTE: CORRECT IMPLEMENTATION AS PER LEETOCODE SUBMISSION. 
// PepCoding is not constructing BT properly in C++ that's why wrong answer.


// NOTE: WIDTH AS PER QUESTION INCLUDES "NULL" nodes in between too.
// Eg-      5
//         / \
//        3   4
//       /     \
//      8       9       maxWidth = 4 (8, null, null, 9)

// Eg-      5
//         / \
//        3   4
//       /   /
//      8   6        maxWidth = 3 (8, null, 6)


// NOTE: APPROACH - 
// Do a BFS traversal, but in queue, push (node, index) where leftChildIndex = 2*i + 1
// & rightChildIndex = 2*i + 2.
// Keep updating maxLevel AT EACH LEVEL- with largest value of (indexOf lastNode in q - indexOf firstNode in q + 1)

int widthOfBinaryTree(TreeNode* root)
{
    if(root == nullptr)
        return 0;
        
    queue <pair<TreeNode*, int>> q;
    // push root pair with start index as 0
    q.push({root, 0});
    
    int result = 0;
    
    while(!q.empty()){
        // for bfs(levelOrder traversal) - find size of queue in order to run for loop
        int n = q.size();
        
        // get the index of first and last child of the current level
        int start = q.front().second;
        int end = q.back().second;
        
        // update the result for current level
        result = max(result, end - start + 1);
        
        
        // level-order traversal
        for(int i = 0; i < n; i++){
            pair <TreeNode*, int> topPair = q.front();
            q.pop();
            
            TreeNode *node = topPair.first;
            
            // NOTE: OPTIMISATION - 
            // idx will grow exponentially (2*idx + 1) so it won't fit in "int"
            // => either use long, or subtract "start" from idx bcz we care about
            // idx only to calculate width & if we subtract some constant from idx
            // width won't change. => Now, idx AT EACH LEVEL will always be ranging from 0 till 2^level-1 (bcz idx == start)
            int idx = topPair.second - start;
            
            // check if left child exists, then push it along with it's index
            if(node->left){
                q.push({node->left, 2*idx + 1});
            }
            
            // check if right child exists, then push it along with it's index
            if(node->right){
                q.push({node->right, 2*idx + 2});
            }
        }
    }
    
    return result;
}

// input_Section_====================================================================

void display(TreeNode* node)
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
  
  string s;
  for (int i = 0; i < n; i++)
  {
    cin>>s;
    if(s == "null")
        arr[i] = -1;
    else
        arr[i] = stoi(s);
  }

  vector<int> IDX(1, 0);
  TreeNode* root = createTree(arr, IDX);

  cout << widthOfBinaryTree(root) << endl;
}

int main()
{
  solve();
  return 0;
}