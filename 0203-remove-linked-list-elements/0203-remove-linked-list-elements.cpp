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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* current=head;
        ListNode* prev=nullptr;
        if(!head) return head;
        while(head &&head->val==val)
        {
            head=head->next;
            delete current;
            current=head;
        }

        while(current!=nullptr)
        {
            if(val==current->val)
            {
             prev->next=current->next;
             delete current;
             current=prev->next;
             continue;   
            }
            prev=current;
            current=current->next;
        }


        return head;
    }
};