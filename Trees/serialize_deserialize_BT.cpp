// NOTE NOTE: See how stringstream works. It's just like cin and cout stream.

// Resources -

// https://www.youtube.com/watch?v=LM6EDIKS5Pk

// https://www.geeksforgeeks.org/stringstream-c-applications/

// See how we can use stringstream to read comma-separated strings using getline, just like getline with cin.
// We'll need it when we have to read individual words from a string which is separated by comma as delimiter.

// https://www.tutorialspoint.com/parsing-a-comma-delimited-std-string-in-cplusplus

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
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

// NOTE: METHOD-1 (Serialize without using stringstream)
// void serializeUtil(TreeNode* root, string & str)
// {
//     if(root == NULL){
//         str += "null ";
//         return;
//     }
    
//     str = str + to_string(root->val) + " ";
//     serializeUtil(root->left, str);
//     serializeUtil(root->right, str);
// }

// string serialize(TreeNode *root)
// {
//     string str;
    
//     serializeUtil(root, str);
    
//     return str;
// }



// NOTE: METHOD-2 (Using stringstream)
void serializeUtil(TreeNode *root, stringstream& ss)
{
    if(root == nullptr){
        ss << "null ";
        return;
    }

    // We will use space " " as the delimiter as it would be easier to deserialize

    ss << root->val << " ";
    serializeUtil(root->left, ss);
    serializeUtil(root->right, ss);
}


// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    stringstream ss;
    
    serializeUtil(root, ss);
    
    // return a string object with a copy of the current contents of the stream
    return ss.str();
}



// NOTE: Without using stringstream, it'd be really difficult to deserialize
// as you'll need to reading individuals words from the string, treating space as delimiter.
TreeNode* deserializeUtil(stringstream& ss)
{
    // stringstream makes it much easier to read words from string bcz we have taken
    // space " " as delimeter, which is also a default delimiter for string.
    string str;
    ss >> str;
    if(str == "null"){
        return nullptr;
    }
    
    TreeNode *root = new TreeNode(stoi(str));
    root->left = deserializeUtil(ss);
    root->right = deserializeUtil(ss);
    
    return root;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string s)
{
    stringstream ss;
    ss << s;
    return deserializeUtil(ss);
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

TreeNode *createTree(vector<int> &arr, vector<int> &IDX)
{

    if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
    {
        IDX[0]++;
        return nullptr;
    };

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

    string s = serialize(root);
    // cout<<s;
    display(deserialize(s));
}

int main()
{
    solve();
    return 0;
}