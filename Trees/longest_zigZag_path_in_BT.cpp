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
        // Initialising with -1 bcz we want to find length in terms of edges
        int forwardSlopeLen = -1;
        int backwardSlopeLen = -1;
        int maxLenATcurrentNode = 0;
};


Pair longest_zigzag_path_util(TreeNode* root, int& maxLen)
{
    // BASE PAIR
    if(root == nullptr){
        Pair basePair = Pair();
        return basePair;
    }
    
    // Faith: Left and Right subtree will return their respective pair
    Pair leftPair = longest_zigzag_path_util(root->left, maxLen);
    Pair rightPair = longest_zigzag_path_util(root->right, maxLen);
    
    // Now create the pair for root/current node
    Pair curPair = Pair();
    
    // forward slope path for current node is made by adding 1 to left-subtree's backward slope
    curPair.forwardSlopeLen = 1 + leftPair.backwardSlopeLen;
    
    // backward slope path for current node is made by adding 1 to right-subtree's forward slope
    curPair.backwardSlopeLen = 1 + rightPair.forwardSlopeLen;
    
    // Max length zig-zag path AT current node will be maximum amongst forwardSlopeLen & backwardSlopeLen
    curPair.maxLenATcurrentNode = max(curPair.backwardSlopeLen, curPair.forwardSlopeLen);
    
    // But the longest zig-zag path for the entire tree might not start from the root.
    // So, on your way up, keep updating global maxLen variable
    if(curPair.maxLenATcurrentNode > maxLen){
        maxLen = curPair.maxLenATcurrentNode;
    }
    
    // return curPair for nodes above
    return curPair;
}


int longestZigZagPath(TreeNode *root)
{
    int longestPath = 0;
    
    longest_zigzag_path_util(root, longestPath);
    
    return longestPath;
}

// input_Section_====================================================================

TreeNode *createTree(vector<int> &arr, vector<int> &IDX)
{
    if (IDX[0] > arr.size() || arr[IDX[0]] == -1){
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

    cout << longestZigZagPath(root) << endl;
}

int main()
{
    solve();
    return 0;
}