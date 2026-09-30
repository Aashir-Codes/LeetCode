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

 /*
        ListNode* past=nullptr;
        ListNode* current=head;
        ListNode* future=nullptr;

        if(head == nullptr)
        {
            return head;
        }


        while(current != nullptr )
        {
            future = current->next;
            current->next=past;
            past=current;
            current=future;
        }
        return past;
 
 */
class Solution {
public:
    ListNode* reverse(ListNode* current,ListNode* past=nullptr)
    {
        if(current == nullptr)
        {
            return past;
        }

        ListNode* future=current->next;
        current->next=past;
        past=current;

        return reverse(future,past);

    }
    ListNode* reverseList(ListNode* head) {
        return  reverse(head);
    }
};