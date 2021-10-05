#include <iostream>
#include <vector>
#include <stack>
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

class BSTIterator
{
public:
    
    // stack to simulate inorder traversal recursion
    stack<TreeNode*> st;
    
    BSTIterator(TreeNode* root)
    {
        // add root and it's all leftChidren in stack
        addLeftSubtree(root);
    }
    
    void addLeftSubtree(TreeNode* node)
    {
        while(node != nullptr){
            // node, along with its left children, are added to stack
            st.push(node);
            
            node = node->left;
        }
    }
    
    int next()
    {
        // get the element at stack top
        TreeNode *top = st.top();
        st.pop();
        
        // st.top() node is the leftMost node of unprocessed tree which will be returned currently.
        // To simulate INORDER traversal(i.e to print nodes in increasing order) -
        // push the st.top() node's right-child & all the leftNode of this rightChild.
        addLeftSubtree(top->right);
        
        return top->val;
    }
    
    bool hasNext()
    {
        // if stack has elements => return true
        return !st.empty();
    }
};



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

TreeNode* buildTree(vector<int>& inOrder, int si, int ei)
{
  if (si > ei)
    return nullptr;

  int mid = (si + ei) / 2;
  TreeNode* node = new TreeNode(inOrder[mid]);

  node->left = buildTree(inOrder, si, mid - 1);
  node->right = buildTree(inOrder, mid + 1, ei);

  return node;
}

TreeNode* constructFromInOrder(vector<int>& in)
{
  int n = in.size();
  return buildTree(in, 0, n - 1);
}

void solve()
{
  int n;
  cin >> n;
  vector<int> in(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> in[i];
  }

  TreeNode* root = constructFromInOrder(in);
  BSTIterator itr(root);
  while (itr.hasNext())
  {
    cout << (itr.next()) << endl;
  }
}

int main()
{
  solve();
  return 0;
}