#include <iostream>
#include <vector>

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


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
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

// TIME = O(N*K*log(K))   "Can test it using Raudra's method"
// N: avg size of each list       K: Number of lists
ListNode* mergeKLists_Util(vector<ListNode*>& lists, int start, int end)
{
    // BASE CASE SHOULD RETURN THE SINGLE LIST
    if(start == end){
        return lists[start] ;   
    }
    
    if(start < end){
        int mid = start + (end - start) / 2;
        
        // O(log(K))
        ListNode *list1 = mergeKLists_Util(lists, start, mid);
        ListNode *list2 = mergeKLists_Util(lists, mid+1, end);
        
        // O(N*K) for merging entire K lists each of size N
        return mergeTwoLists(list1, list2);
    }
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    return mergeKLists_Util(lists, 0, lists.size() - 1);
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
    vector<ListNode *> list(n, 0);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        list[i] = createList(m);
    }

    ListNode *head = mergeKLists(list);
    printList(head);

    return 0;
}