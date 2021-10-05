#include<iostream>
#include<vector>
#include<queue>
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


// NOTE: For submission on PepCoding, change the delimeter from " " to "\n" while displaying the result.

vector<int> verticalOrderSum(TreeNode *root)
{
    queue <pair<int, TreeNode*>> q;
    // push root pair with 0-th horizontal level
    q.push({0, root});
    
    vector<int> res;
    int minRange, maxRange;
    minRange = maxRange = 0;
    
    unordered_map<int, int> hashMap;
    
    while(!q.empty()){
        pair<int, TreeNode*> top = q.front();
        q.pop();
        
        // keep adding the value of nodes at same level (rather than pushing them into vector<int> & later finding sum)
        hashMap[top.first] += top.second->val;
        
        if(top.first < minRange){
            minRange = top.first;
        }
        
        else if(top.first > maxRange){
            maxRange = top.first;
        }
        
        // push left child with top.first - 1 horizontal level
        if(top.second->left){
            q.push({top.first - 1, top.second->left});
        }
        
        // push right child with top.first + 1 horizontal level
        if(top.second->right){
            q.push({top.first + 1, top.second->right});
        }
    }
    
    for(int i = minRange; i <= maxRange; i++){
        res.push_back(hashMap[i]);
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

    vector<int> ans = verticalOrderSum(root);
    for (int j : ans)
    {
        cout << j << "\n";
    }
}

int main()
{
    solve();
    return 0;
}