class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

        stack<ListNode*> st;
        ListNode* current = head;
        while (current != nullptr) {
            st.push(current);
            current = current->next;
        }

        int n = st.size();
        k %= n;                 
        if (k == 0) return head;

        for (int i = 1; i <= k; i++) {
            ListNode* last = st.top();
            st.pop();
            st.top()->next = nullptr;
            last->next = head;
            head = last;
        }
        return head;
    }
};