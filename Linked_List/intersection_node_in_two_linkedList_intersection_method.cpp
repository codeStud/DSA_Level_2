#include <iostream>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

int length(ListNode *node)
{
    if (node == nullptr)
        return 0;

    int len = 0;
    while (node != nullptr)
    {
        node = node->next;
        len++;
    }

    return len;
}

ListNode *IntersectionNodeInTwoLL(ListNode *headA, ListNode *headB)
{
    if (headA == nullptr || headB == nullptr)
        return nullptr;

    int lenA = length(headA);
    int lenB = length(headB);
    
    int diff = abs(lenA - lenB);
    
    //get the bigger list head
    ListNode *bigHead = lenA > lenB ? headA : headB;
    
    // get smaller list head
    ListNode *smallHead = lenA > lenB ? headB : headA;
    
    // move diff nodes forward in bigger list, so that remaining list and smaller
    // list have equal number of nodes. (Also works if diff = 0)
    while(diff != 0){
        bigHead = bigHead->next;
        diff -= 1;
    }
    
    // move one step at a time until you reach the intersection node
    ListNode *intersectionNode = nullptr;
    while(bigHead && smallHead){
        if(bigHead == smallHead){
            intersectionNode = bigHead;
            break;
        }
        
        bigHead = bigHead->next;
        smallHead = smallHead->next;
    }
    
    return intersectionNode;
}



// Input_code===================================================

ListNode *makeList(int n)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }
    return dummy->next;
}

int main()
{
    int n,idx;
    cin >> n;
    ListNode *head1 = makeList(n);
    cin >> idx;
    
    int m;
    cin >> m;
    ListNode *head2 = makeList(m);

    if (idx >= 0)
    {
        ListNode *curr = head1;

        while (idx-- > 0)
            curr = curr->next;

        ListNode *prev = head2;
        while (prev->next != nullptr)
            prev = prev->next;

        prev->next = curr;
    }

    ListNode *ans = IntersectionNodeInTwoLL(head1, head2);
    cout << (ans != nullptr ? ans->val : -1) << endl;
    return 0;
}