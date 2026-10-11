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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy= ListNode();

        int carry=0;
        ListNode* current=&dummy;
        ListNode* cr1=l1;
        ListNode* cr2=l2;
        while(cr1 or cr2 or carry)
        {
            int val1 = (!cr1)?0:cr1->val;
            int val2 = (!cr2)?0:cr2->val;
            int value=val1+val2+carry;
            carry=value/10;
            value=value%10;
            
            current->next=new ListNode(value);
            current=current->next;
            if(cr1)
            cr1=cr1->next;
            if(cr2)
            cr2=cr2->next;
        }


        return dummy.next;

    }
};