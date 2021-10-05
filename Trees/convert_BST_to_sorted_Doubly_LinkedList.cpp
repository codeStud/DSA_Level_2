#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
  int val = 0;
  Node* left = nullptr;
  Node* right = nullptr;

  Node(int val)
  {
    this->val = val;
  }
};


// NOTE: create a global node 'previous' which we can change manually. DON'T name it "prev" otherwise ambigous with some bult-in func()
Node *previous = nullptr;

void bToDLLUtil(Node* current)
{
    if(current == nullptr){
        return;
    }
    
    bToDLLUtil(current->left);
  
    previous->right = current;
    current->left = previous;
    previous = current;
  
    bToDLLUtil(current->right);
    
    return; 
}


Node* bToDLL(Node *root)
{
    // create a new node & make "previous" point to it initially
    Node *dummy = new Node(-1);
    previous = dummy;
    
    bToDLLUtil(root);
    
    // dummy->right will be acting as the head of the LL
    Node *head = dummy->right;
    
    // delete dummy
    delete dummy;
    
    // Make circular doubly LL by connecting head->left to tail(= current prev, after bToDLLUtil() returns.)
    head->left = previous;
    previous->right = head;
    
    return head;
}


// input_Section_====================================================================

void display(Node* node)
{
  Node* head = node;
  while (node != nullptr) {
    cout << node->val << " ";
    node = node->right;
    if (node == head)
      break;
  }
}

Node* constructFromInOrder(vector<int>& inOrder, int si, int ei)
{
  if (si > ei)
    return nullptr;
  int mid = (si + ei) / 2;
  Node* root = new Node(inOrder[mid]);

  root->left = constructFromInOrder(inOrder, si, mid - 1);
  root->right = constructFromInOrder(inOrder, mid + 1, ei);

  return root;
}

Node* constructFromInOrder(vector<int>& inOrder)
{
  return constructFromInOrder(inOrder, 0, inOrder.size() - 1);
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

  Node* root = constructFromInOrder(in);
  Node* head = bToDLL(root);
  display(head);
}

int main()
{
  solve();
  return 0;
}