#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;
    ListNode *random = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

// Time: O(N)   Space: O(N)
ListNode *copyRandomList(ListNode *head)
{
    unordered_map<ListNode*, ListNode*> map;
    
    ListNode *current = head;
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    
    // first create an entire copy of th linked-list
    while(current != nullptr){
        ListNode *newNode = new ListNode(current->val);
        prev->next = newNode;
        
        // map newNode with the corresponding node in the given list
        map[current] = newNode;
        
        prev = prev->next;
        current = current->next;
    }
    
    ListNode *newHead = dummy->next;
    
    // start setting the random pointers
    ListNode *l1 = head;
    ListNode *l2 = newHead;
    while(l1){
        // find the node pointed to by l1->random
        ListNode *randNode_1 = l1->random;
        
        if(randNode_1 != nullptr){
            // find the node corresponding to the randNode in the map
            ListNode *randNode_2 = map[randNode_1];
            
            // make l2->random point to this randNode_2
            l2->random = randNode_2;
        }
        
        // move forward
        l1 = l1->next;
        l2 = l2->next;
    }
    
    return newHead;
}


// Time: O(N)    Space: O(1) (Not including space for newList)
ListNode* copyRandomList_2(ListNode *head)
{
    if(head == nullptr) return head;
    
    ListNode *cur = head;
    ListNode *forw;
    
    // add copy nodes just after the original nodes, in the same linked-list.
    while(cur){
        forw = cur->next;
        
        ListNode *newNode = new ListNode(cur->val);
        cur->next = newNode;
        newNode->next = forw;
        
        cur = forw;
    }
    
    // Now, every cur->random->next Node will be the newNode added, and this
    // newNode will be the random node of the cur->next(i.e newly added node)
    cur = head;
    while(cur){
        ListNode *randomNode = cur->random;
        
        // NOTE: Dont' forget this check
        if(randomNode != nullptr){
            // set the random pointer for the newly added node
            cur->next->random = randomNode->next;
        }
        
        // move cur forward as cur->next->next, bcz cur->next is the newly added node
        cur = cur->next->next;
    }
    
    // separate the newList from the given list
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    cur = head;
    while(cur){
        prev->next = cur->next;
        cur->next = cur->next->next;
        
        prev = prev->next;
        cur = cur->next;
    }
    
    // return newHead
    return dummy->next;
}


int main()
{
    int n;
    cin >> n;

    vector<ListNode *> arr(n);
    ListNode *prev = nullptr;
    for (int i = 0; i < n; i++)
    {
        arr[i] = new ListNode(0);
        if (prev != nullptr)
            prev->next = arr[i];
        prev = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int val, idx;
        cin >> val >> idx;

        arr[i]->val = val;
        if (idx != -1)
            arr[i]->random = arr[idx];
    }

    ListNode *head = copyRandomList_2(arr[0]);
    while (head != nullptr)
    {
        cout << "(" + to_string(head->val) + ", " + (head->random != nullptr ? to_string(head->random->val) : to_string(-1)) + ") ";
        head = head->next;
    }
    return 0;
}