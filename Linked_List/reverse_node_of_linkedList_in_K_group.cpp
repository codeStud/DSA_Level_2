#include <iostream>
using namespace std;

class ListNode
{
public:
  int val = 0;
  ListNode* next = nullptr;

  ListNode(int val)
  {
    this->val = val;
  }
};

// O(N) recursive call stack space in worst case
ListNode* recursiveSol(ListNode* head, int k)
{
    if(head == nullptr || head->next == nullptr || k == 0)
        return head;
        
    ListNode* cursor = head;
    
    // if current group of LL has less than K elements, simply return head of curGroup.
    for(int i = 0; i < k; i++){
        if(cursor == nullptr) 
            return head;
        cursor = cursor->next;
    }
    
    // else reverse first K nodes
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* nxt = nullptr;
    for(int i = 0; i < k; i++){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    
    // recursively reverse rest of the list in groups of K and attach 
    // the "prev" in head->next.
    head->next = recursiveSol(curr, k);
    return prev;
}



int length(ListNode* head)
{
    int len = 0;
    ListNode *cur = head;
    while(cur){
        cur = cur->next;
        len++;
    }
    
    return len;
}

ListNode* iterativeSol(ListNode* head, int k)
{
    if(head == nullptr || head->next == nullptr || k == 0){
        return head;
    }
    
    // find the length of the linked-list
    int totalLen = length(head);
    
    ListNode *prevHead = nullptr, *prevTail = nullptr;
    ListNode *curHead = nullptr, *curTail = nullptr;
    ListNode *cur = head;
    
    // we will keep decrementing totalLen by K, after each K reverse
    // But only if at-least k nodes remaining.
    while(totalLen >= k){
        int tempLen = k;
        
        // reverse K nodes by using addFirst method.
        while(tempLen--){
            ListNode *forw = cur->next;
            cur->next = nullptr;
            
            if(curHead == nullptr){
                curHead = curTail = cur;
            }
            else{
                cur->next = curHead;
                curHead = cur;
            }
            
            // move cur forward
            cur = forw;
        }
        
        if(prevHead == nullptr){
            prevHead = curHead;
            prevTail = curTail;
        }
        else{
            prevTail->next = curHead;
            prevTail = curTail;
        }
        
        // reset the curHead and curTail, to reverse next group of K nodes
        curHead = curTail = nullptr;
        
        // decrease the totalLength by k
        totalLen -= k;
    }
    
    // Here, either cur=nullptr or cur="head of remaining list of length < k"
    prevTail->next = cur;
    
    return prevHead;
}

ListNode* reverseInKGroup(ListNode* head, int k)
{
//   return recursiveSol(head, k);
  
  return iterativeSol(head, k);
}



void printList(ListNode* node)
{
  ListNode* curr = node;
  while (curr != nullptr)
  {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}

ListNode* createList(int n)
{
  ListNode* dummy = new ListNode(-1);
  ListNode* prev = dummy;
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
  ListNode* h1 = createList(n);
  int k;
  cin >> k;
  h1 = reverseInKGroup(h1, k);
  printList(h1);

  return 0;
}