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


ListNode* reverse(ListNode *head)
{
    if(head == nullptr || head->next == nullptr)
        return head;
    
    ListNode *prev, *cur, *next;
    prev = nullptr;
    cur = head;
    
    while(cur){
        next = cur->next;
        
        cur->next = prev;
        
        prev = cur;
        
        cur = next;
    }
    
    // prev will be the new head
    return prev;
}


void unfold(ListNode *head)
{
    if(head == nullptr || head->next == nullptr){
        return;
    }
    
    ListNode *head1 = head;    // first head
    ListNode *l1 = head1;      // will construct first list
    
    ListNode *head2 = head->next;    // second head
    ListNode *l2 = head2;      // will construct second list
    
    // Odd length list => l2 will become null first
    // Even length list => l2->next will become null first
    while(l2 != nullptr && l2->next != nullptr){
        ListNode *forw = l2->next;
        
        // keep connecting l1 to nodes at odd places
        // and l2 with nodes at even places
        l1->next = forw;
        l2->next = forw->next;
        
        // move l1 and l2 ahead
        l1 = l1->next;
        l2 = l2->next;
    }
    
    // Reverse the list-2
    head2 = reverse(head2);
    
    // l1 pointer will be pointing to the last node in the list-1
    l1->next = head2;
}

void printList(ListNode *node)
{
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }

    ListNode *head = dummy->next;
    unfold(head);
    printList(head);

    return 0;
}