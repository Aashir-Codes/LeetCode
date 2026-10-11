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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode* left=head;
        stack<ListNode*> st;
        int count=0;
        while(left != nullptr && count < k)
        {
            st.push(left);
            left=left->next;
            count++;
            if(count==k)break;
        }
        if(count<k)return head;
        ListNode* tail = st.top();   
        ListNode* right = head;

        for (int j = 0; j < k / 2; j++) {   
            swap(right->val, st.top()->val);
            right = right->next;
            st.pop();
        }
        tail->next = reverseKGroup(left, k);  
        return head;

        
    }
};