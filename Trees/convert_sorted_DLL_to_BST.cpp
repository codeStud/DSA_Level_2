#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val = 0;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int val)
    {
        this->val = val;
    }
};


Node* getMidNode(Node *head)
{
    if(head == nullptr || head->right == nullptr){
        return head;
    }
    
    Node *slow, *fast;
    slow = fast = head;
    
    while(fast->right != nullptr && fast->right->right != nullptr){
        slow = slow->right;
        fast = fast->right->right;
    }
    
    return slow;
}


Node* SortedDLLToBST(Node* head)
{
    // null node or single node => return
    if(head == nullptr || head->right == nullptr){
        return head;
    }
    
    // get midNode
    Node *mid = getMidNode(head);
    
    // NOTE NOTE: get prev and next nodes to make the mid-node ISOLATED;
    // Otherwise leafNodes of the BST WON'T have left = right = nullptr & they'd
    // still be pointing to some other nodes in the BST
    Node *prev = mid->left;
    Node *next = mid->right;
    
    // First, get the head of left half (= current head, or nullptr if #nodes == 2)
    Node* leftHead;
    if(prev != nullptr)
        leftHead = head;
    else
        leftHead = nullptr;
    
    // get the head of right half (= midNode->right)
    Node* rightHead = mid->right;
    
    // Isolate the mid-node BUT sometimes mid->left might not be there (Eg: in case of only 2 nodes, 1st node is mid => no mid->left)
    if(prev){
        prev->right = nullptr;
    }
    mid->left = mid->right = next->left = nullptr;
    
    // recursively call for left-half and attach it to midNode->left
    mid->left = SortedDLLToBST(leftHead);
    
    // recursively call for right-half and attach it to midNode->right
    mid->right = SortedDLLToBST(rightHead);
    
    // return midNode (since it'll be the root of the overall BST)
    return mid;
}



// input_Section_====================================================================

void display(Node *node)
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

Node* makeList(int n) {
        Node* dummy = new Node(-1);
        Node* prev = dummy;
        while (n-- > 0) {
            int val; cin >> val;
            Node* node = new Node(val);
            prev->right = node;
            node->left = prev;
            prev = prev->right;
        }

        Node *head = dummy->right;
        head->left = dummy->right = nullptr;

        return head;
    }

void solve()
{
    int n;
    cin >> n;
    Node* head = makeList(n);
    
    head = SortedDLLToBST(head);
    display(head);
}

int main()
{
    solve();
    return 0;
}