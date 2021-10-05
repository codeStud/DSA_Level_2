#include <iostream>
#include <vector>
#include <queue>
#include<unordered_map>
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
        TreeNode *node;
        int level;
        
        Pair(TreeNode *node, int level)
        {
            this->node = node;
            this->level = level;
        }
};

// NOTE: TopView => First node at each horizontal level in vertical order traversal
vector<int> TopView(TreeNode *root)
{
    queue <Pair> q;
    q.push(Pair(root, 0));
    
    unordered_map <int, vector<int>> hashMap;
    
    int minRange = 0;
    int maxRange = 0;
    
    while(!q.empty()){
        int n = q.size();
        
        for(int i = 0; i < n; i++){
            Pair top = q.front();
            q.pop();
            
            if(top.level < minRange){
                minRange = top.level;
            }
            else if(top.level > maxRange){
                maxRange = top.level;
            }
            
            hashMap[top.level].push_back(top.node->val);
            
            if(top.node->left){
                q.push(Pair(top.node->left, top.level - 1));
            }
            
            if(top.node->right){
                q.push(Pair(top.node->right, top.level + 1));
            }
        }
    }
    
    vector<int> res;
    
    for(int key = minRange; key <= maxRange; key++){
        // keep pushing the FIRST ELEMENT (0th index of vector stored at hashMap[key]) of every HORIZONTAL LEVEL
        res.push_back(hashMap[key][0]);
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

    vector<int> ans = TopView(root);

    for (int i : ans)
    {
        cout << i << " ";
    }
}

int main()
{
    solve();
    return 0;
}