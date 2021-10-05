#include <iostream>
#include <vector>
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


int height(TreeNode* root)
{
    if(root == nullptr){
        return -1;
    }
    
    return max(height(root->left), height(root->right)) + 1;
}

// NOTE: `````````O(n^2)```````````
int Dia_01(TreeNode* root)
{
    if(root == nullptr){
        return 0;
    }
    
    int leftDia = Dia_01(root->left);
    int rightDia = Dia_01(root->right);
    
    int curDia = height(root->left) + height(root->right) + 2;
    
    return max({leftDia, rightDia, curDia});
}


// NOTE: `````````O(n)```````````
// CalcDiaReturnHeight
int diameter = 0;
int Dia_02(TreeNode *root)
{
    if(root == nullptr){
        return -1;
    }
    
    int leftHeight = Dia_02(root->left);
    int rightHeight = Dia_02(root->right);
    
    int curDia = leftHeight + rightHeight + 2;
    
    if(curDia > diameter){
        diameter = curDia;
    }
    
    // return height of current node
    return max(leftHeight, rightHeight) + 1;
}


// NOTE: `````````O(n)```````````
// Using Pair to calculate multiple values together
// NOTE: Each current pair stores HEIGHT OF CURRENT NODE & LARGEST DIAMETER TILL THAT NODE -
// (not necessarily diameter passing through the current node)
pair<int, int> Dia_03(TreeNode* root)
{
    if(root == nullptr){
        // height = -1   diameter = 0
        pair<int, int> basePair = make_pair(-1, 0);
        return basePair;
    }
    
    pair<int, int> leftPair = Dia_03(root->left);
    pair<int, int> rightPair = Dia_03(root->right);
    
    pair<int, int> curPair;
    
    // height
    curPair.first = max(leftPair.first, rightPair.first) + 1;
    
    // diameter passing through current node
    int curDia = leftPair.first + rightPair.first + 2;
    
    // Actual diameter of the tree ROOTED AT THE CURRENT node
    curPair.second = max({leftPair.second, rightPair.second, curDia});
    
    return curPair;
}


int diameterOfBinaryTree(TreeNode* root)
{
    // return Dia_01(root);
    
    // Dia_02(root);
    // return diameter;
    
    // finalPair will store height of the ROOT node & diameter of binary tree ROOTED
    // at ROOT node (not neccessary that diameter will pass through root node)
    pair<int, int> finalPair = Dia_03(root);
    return finalPair.second;
}



// input_Section=================================================

TreeNode* createTree(vector<int>& arr, vector<int>& IDX)
{
  if (IDX[0] > arr.size() || arr[IDX[0]] == -1) {
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
  
  cout<<diameterOfBinaryTree(root);
}

int main()
{
  solve();
  return 0;
}