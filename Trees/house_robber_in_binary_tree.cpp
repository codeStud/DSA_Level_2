// NOTE: - IDEA - 
// Store 2 data for each node - 
// (a) withRobbery = maxAmount generated if we DO robbery at this node.
// (b) withoutRobbery = maxAmount generated if we DON'T do robbery at this node.

// Thief has 2 choices at each NODE, (1) Rob it (2) Don't Rob it
// (1) Rob the current node: node->withRobbery = (node->val + left->withoutRobbery + right->withoutRobbery)
// (2) Don't Rob the current node: node->withoutRobbery = max(left->withoutRobbery, left->withRobbery) + max(right->withoutRobbery, right->withRobbery)


#include <iostream>
#include <vector>
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


class Pair{
    public:
        int withRobbery;
        int withoutRobbery;
        
        Pair(int a, int b)
        {
            withRobbery = a;
            withoutRobbery = b;
        }
};


Pair HouseRobberUtil(TreeNode *root)
{
    if(root == nullptr){
        // create base pair with both amounts = 0 and return it 
        Pair basePair = Pair(0, 0);
        return basePair;
    }
    
    Pair leftPair = HouseRobberUtil(root->left);
    Pair rightPair = HouseRobberUtil(root->right);
    
    // Work in post-order, after getting the values from left & right subtree
    
    // make the current pair
    Pair curPair = Pair(0, 0);
    
    // update the withRobbery & withoutRobbery for current pair as per the above rules
    curPair.withRobbery = root->val + leftPair.withoutRobbery + rightPair.withoutRobbery;
    
    curPair.withoutRobbery = max(leftPair.withRobbery, leftPair.withoutRobbery) + max(rightPair.withRobbery, rightPair.withoutRobbery);
    
    // return the root pair
    return curPair;
}


int HouseRobber(TreeNode *root)
{
    Pair rootPair = HouseRobberUtil(root);
    return max(rootPair.withRobbery, rootPair.withoutRobbery);
}

// input_Section_====================================================================

TreeNode *createTree(vector<int> &arr, vector<int> &IDX)
{
    if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
    {
        IDX[0]++;
        return nullptr;
    }

    TreeNode *node = new TreeNode(arr[IDX[0]++]);
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
    TreeNode *root = createTree(arr, IDX);
    cout << HouseRobber(root) << endl;
}

int main()
{
    solve();
    return 0;
}