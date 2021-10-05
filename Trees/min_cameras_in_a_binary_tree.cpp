// NOTE: (1) Return a value of -1 if node NEEDs camera
// (2) Return value = 0 if node already has a camera
// (3) Return value = 1 if node is covered by some other node having camera.


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


int minCamerasUtil(TreeNode* root, int& count)
{
    // BASE CASE
    if(root == nullptr){
        // empty node doesn't need a camera => return 1
        return 1;
    }
    
    // For minCamera, start viewing nodes for camera from bottom => in postorder
    int left = minCamerasUtil(root->left, count);
    int right = minCamerasUtil(root->right, count);
    
    // Case-1: Left OR Right CHILD needs a camera => 
    //  - allot the camera to the current node & increase count by 1.
    //  - now, this current node will return 0 bcz it has a camera
    if(left == -1 || right == -1){
        count += 1;
        return 0;
    }
    
    // Case-2: Left AND Right CHILD are covered by some other node(i.e val = 1)
    // => Current node doesn't need a camera to cover its children & to minimise count
    // this current node will return -1(I need camera) and ask its parent to cover it.
    if(left == 1 && right == 1){
        // keep count as it is and return -1 so that current node's parent will cover it
        return -1;
    }
    
    // Case-3: If either of the left or right CHILD of current node has a camera(i.e val=0) &&
    // NONE of the children need camera (Already covered in case-1)
    // => Current node doesn't need a camera to cover its children & to minimise count
    // this current node will return 1(I am already COVERED)
    if(left == 0 || right == 0){
        return 1;
    }
}


int MinCamerasInBT(TreeNode *root)
{
    int cameraCount = 0;
    
    int rootReq = minCamerasUtil(root, cameraCount);
    
    // if the last returned value from minCamerasUtil == -1 => root is depending on it's parent to cover it.
    // Thus, we need to place an extra camera at root, since root doesn't have parent
    if(rootReq == -1){
        cameraCount +=1 ;
    }
    
    return cameraCount;
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
    cout << MinCamerasInBT(root) << endl;
}

int main()
{
    solve();
    return 0;
}