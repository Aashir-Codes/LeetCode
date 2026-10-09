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
            if(!head) return head;
            ListNode* List =new ListNode(head->val);
            ListNode* lastnode = List;
            ListNode* current=head;

            while(current != nullptr)
            {
                if(current->val != lastnode->val)
                {
                  lastnode->next = new ListNode(current->val);
                  lastnode=lastnode->next;
                }
                current=current->next;
            }

        return List;

       
    }
};