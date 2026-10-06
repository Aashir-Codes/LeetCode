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
    ListNode* swapNodes(ListNode* head, int k) {
     ListNode*  first =nullptr; 
     ListNode*  current=head;
     int count=0;
     while(current != nullptr)
     {
        if(k-1==count)
        {
            first=current;
        }
        current=current->next;
        count++;
     }
    current=head;

     for(int i=1;i<=count-k;i++)
     {
       current=current->next;
     }

     swap(current->val,first->val);

    return head;

    }
};