/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return head;

    deque<int> st;
    ListNode* current = head;
    int ct = INT_MIN;  
    while (current != nullptr) {
        if (st.empty()) {
            if (ct != current->val)  
                st.push_back(current->val);
            current = current->next;
            continue;
        }
        if (st.back() == current->val || ct == current->val) {
         if (st.back() == current->val) {
             
                ct = st.back();
                st.pop_back();
                current = current->next;
                continue;
            }
            if (ct == current->val) {
              
    current = current->next;
    continue;
}
            current = current->next;
            continue;
        }
        st.push_back(current->val);
        current = current->next;
    }

 
    ListNode dummy = ListNode();
    ListNode* tail = &dummy;      

    while (!st.empty()) {
        tail->next = new ListNode(st.front()); 
        tail = tail->next;                  
        st.pop_front();
    }
    tail->next = nullptr;

    return dummy.next;
}
};