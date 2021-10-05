#include <iostream>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode *next = nullptr;
    
    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode* getMidNode(ListNode *head)
{
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    
    ListNode *slow, *fast;
    slow = fast = head;
    
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

ListNode* mergeTwoSortedList(ListNode* list1, ListNode* list2)
{
    if(list1 == nullptr || list2 == nullptr){
        return list1 == nullptr ? list2 : list1;
    }
    
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    
    ListNode *l1, *l2;
    l1 = list1;
    l2 = list2;
    
    while(l1 && l2){
        if(l1->val < l2->val){
            prev->next = l1;
            
            prev = prev->next;
            l1 = l1->next;
        }
        else{
            prev->next = l2;
            
            prev = prev->next;
            l2 = l2->next;
        }
    }
    
    if(l1){
        prev->next = l1;
    }
    else if(l2){
        prev->next = l2;
    }
    
    return dummy->next;
}


// Linked-List MergeSort: Time=O(NlogN)   Space=O(logN) i.e recursive call stack only
// Array MergeSort:  Time=O(NlogN)  Space=O(N + logN) i.e recursive call + extra array
ListNode *mergeSort(ListNode *head)
{
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    
    ListNode *mid = getMidNode(head);
    
    // separate list into halves, otherwise nodes would remain connected 
    // and mergeTwoSortedList() won't work!
    ListNode *secondHead = mid->next;
    mid->next = nullptr;
    
    ListNode *list1 = mergeSort(head);
    ListNode *list2 = mergeSort(secondHead);
    
    return mergeTwoSortedList(list1, list2);
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

ListNode *createList(int n)
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
    int n;
    cin >> n;
    ListNode *h1 = createList(n);

    ListNode *head = mergeSort(h1);
    printList(head);

    return 0;
}