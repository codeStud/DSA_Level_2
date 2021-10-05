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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if(l1 == nullptr || l2 == nullptr){
        return l1 == nullptr ? l2 : l1;
    }
    
    // CREATE A DUMMY NODE TO STORE THE HEAD OF THE LINKED LIST
    ListNode *dummy = new ListNode(-1);
    
    // CREATE A prev NODE TO TRAVERSE THE SORTED LIST
    ListNode *prev = dummy;
    
    // DON'T MODIFY HEAD OF L1, L2
    ListNode *temp1, *temp2;
    temp1 = l1;
    temp2 = l2;
    
    while(temp1 && temp2){
        if(temp1->val < temp2->val){
            prev->next = temp1;
            
            prev = prev->next;
            temp1 = temp1->next;
        }
        else{
            prev->next = temp2;
            
            prev = prev->next;
            temp2 = temp2->next;
        }
    }
    
    // join prev->next to the remaining list
    if(temp1){
        prev->next = temp1;
    }
    else if(temp2){
        prev->next = temp2;
    }
    
    // return the head of the sorted list
    return dummy->next;
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
    int n, m;
    cin >> n;
    ListNode *h1 = createList(n);
    cin >> m;
    ListNode *h2 = createList(m);

    ListNode *head = mergeTwoLists(h1, h2);
    printList(head);

    return 0;
}