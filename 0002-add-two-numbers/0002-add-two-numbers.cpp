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
        ListNode* c1=l1;
        ListNode* c2=l2;
        int carry=0;
        ListNode* list=new ListNode();
        ListNode* Head=list;


        while (c1 != nullptr && c2 !=nullptr)
        {
            int _val = c1->val+c2->val;
            if(carry!=0)
            {
                _val+=carry;
                carry=0;
            }
            if(_val>9)
            {
                carry=_val/10;
                _val%=10;
            }
            list->val=_val;
            if(c1->next != nullptr || c2->next != nullptr)
            {
                list->next=new ListNode();
                list=list->next;
            }
            c1=c1->next;
            c2=c2->next;
        }

        while (c1 != nullptr)
        {
            int _val = c1->val;
            if (carry != 0) { _val += carry; carry = 0; }
            if (_val > 9) { carry = _val / 10; _val %= 10; }
            
            list->val = _val;              
            c1 = c1->next;
            
            if (c1 != nullptr)  
            {
                list->next = new ListNode();
                list = list->next;
            }
        }

      
        while (c2 != nullptr)
        {
            int _val = c2->val;
            if (carry != 0) { _val += carry; carry = 0; }
            if (_val > 9) { carry = _val / 10; _val %= 10; }
            
            list->val = _val;              
            c2 = c2->next;
            
            if (c2 != nullptr)  
            {
                list->next = new ListNode();
                list = list->next;
            }
        }

        if(carry != 0)
        {
            list->next=new ListNode();
            list=list->next;
            list->val=carry;
        }



        return Head;
        
    }
};