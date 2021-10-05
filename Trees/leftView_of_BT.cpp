#include <iostream>
#include <vector>
#include <queue>
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

class levelPair
{
public:
    TreeNode *par = nullptr;
    int lb = -(int)1e8;
    int rb = (int)1e8;

    levelPair()
    {
    }

    levelPair(TreeNode *par, int lb, int rb)
    {
        this->par = par;
        this->lb = lb;
        this->rb = rb;
    }
};


// NOTE: Left-View => Do level order traversal from LEFT-to-RIGHT && push the first node at each level to ans
vector<int> leftView(TreeNode *root)
{
    vector <int> res;
    
    if(root == NULL){
        return res;
    }
    queue <TreeNode*> q;
    
    // push the root
    q.push(root);
    
    while(!q.empty()){
        
        // Push the leftmost node of each level to answer
        // (i.e first node of each level bcz we are adding children from left-to-right)
        
        res.push_back(q.front()->val);
        
        // n will ensure that below for loop runs for all the nodes at the each level
        int n = q.size();
        
        for(int i = 0; i < n; i++){
            TreeNode *top = q.front();
            q.pop();
        
            // add the children to the queue
            if(top->left){
                q.push(top->left);
            }
            
            if(top->right){
                q.push(top->right);
            }
        }
    
    }
    
    return res;
}



// input_section=================================================

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

       vector<int> ans = leftView(root);
    for (int i : ans)
        cout << i << endl;
}

int main()
{
    solve();
    return 0;
}