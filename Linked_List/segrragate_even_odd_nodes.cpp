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

// Keep two dummy nodes and tailPointers for evenList and oddList.
// Keep adding the nodes to tail as per curNode value.
// At last, adjust pointers accordingly NOTE: DON'T FORGET TO SET odd-tail->next = null
// otherwise loop can be formed in LL.
ListNode *segregateEvenOdd(ListNode *head)
{
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    
    ListNode *dummyEven = new ListNode(-1);
    ListNode *dummyOdd = new ListNode(-1);
    
    ListNode *etail = dummyEven;
    ListNode *otail = dummyOdd;
    ListNode *cur = head;
    
    while(cur != nullptr){
        if(cur->val % 2 == 0){
            etail->next = cur;
            etail = etail->next;
        }
        else{
            otail->next = cur;
            otail = otail->next;
        }
        
        cur = cur->next;
    }
    
    // attach odd-list after the even-list.
    // Will work even if list contains only even or only odd elements.
    etail->next = dummyOdd->next;
    
    // NOTE: DON'T FORGET TO DO THIS STEP OTHERWISE MAY CREATE A LOOP IN LIST.
    otail->next = nullptr;
    
    // return the new head, i.e dummyEven->next. It'll work even if NO even elements 
    // are there in list, bcz of etail->next = dummyOdd->next step.
    return dummyEven->next;
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

    ListNode *head = segregateEvenOdd(dummy->next);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}