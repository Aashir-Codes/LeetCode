/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int L1=0;
        int L2=0;

        ListNode* h1 = headA;
        ListNode* h2 = headB;


        while(h1 != nullptr)
        {
            L1++;
            h1=h1->next;
        }
        while(h2 != nullptr)
        {
            L2++;
            h2=h2->next;
        }
        h1 = headA;
        h2 = headB;
        int gap= abs(L1-L2);
        if(L1>L2)
        {
          for(int i=1;i<=gap;i++)
            h1=h1->next;
        }
        else
        {
         for(int i=1;i<=gap;i++)
            h2=h2->next;
        }

        while(h1 != nullptr && h2 != nullptr)
        {
            if(h1 == h2) return h1;
             h1=h1->next;
             h2=h2->next;
        }

        return h1;


    }
};