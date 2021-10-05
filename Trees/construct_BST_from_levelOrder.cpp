#include <iostream>
#include <vector>
#include <queue>
#include<climits>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};

class Pair {
    public:
        TreeNode *parent;
        int leftRange;
        int rightRange;
    
        Pair(TreeNode *par, int lb, int rb)
        {
            this->parent = par;
            this->leftRange = lb;
            this->rightRange = rb;
        }
};


// NOTE: Notice that the nodes in the BST would be constructed in the levelwise order only using queue.
TreeNode *constructBSTFromLevelOrder(vector<int> &arr)
{
    // create the root pair with parent null
    Pair rootPair = Pair(NULL, INT_MIN, INT_MAX);
    
    // create a queue and push the rootPair
    queue <Pair> q;
    q.push(rootPair);
    
    // declare an empty root node, to be updated later in the while loop & to be returned at the end.
    TreeNode *root = nullptr;
    
    int idx = 0;
    while(!q.empty() && idx < arr.size()){
        // pop the top pair
        Pair top = q.front();
        q.pop();
        
        // if the current value of arr[idx] doesn't belong to the range of top Pair
        // simply continue and this current arr[idx] will be checked with next top pair in queue.
        if(arr[idx] < top.leftRange || arr[idx] > top.rightRange){
            continue;
        }
        
        // create a node with the current idx value
        TreeNode *newNode = new TreeNode(arr[idx]);
        
        // increment the idx to go to the next element in level-order traversal
        idx += 1;
        
        // if top Pair's parent == NULL => this is the root
        if(top.parent == NULL){
            // set newNode as root
            root = newNode;
        }
        else{
            // get the parent of the current node
            TreeNode *parent = top.parent;
            
            // check if the newNode will be left child or right child of its parent
            if(newNode->val < parent->val){
                parent->left = newNode;
            }
            else{
                parent->right = newNode;
            }
        }
        
        // Push the Pair of the newNode made above with it's
        // proper left-child range and right-child range.
        
        // push for left-child; making newNode as parent & changing rightRange
        q.push(Pair(newNode, top.leftRange, newNode->val));
        
        // push for right-child; making newNode as parent & changing leftRange
        q.push(Pair(newNode, newNode->val, top.rightRange));
    }
    
    return root;
    
}

// input_Section_====================================================================

void display(TreeNode *node)
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

void solve()
{
    int n;
    cin >> n;
    vector<int> levelorder(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> levelorder[i];
    }

    TreeNode *root = constructBSTFromLevelOrder(levelorder);
    display(root);
}

int main()
{
    solve();
    return 0;
}