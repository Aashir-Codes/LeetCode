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
    ListNode* split(ListNode*& list)
    {   ListNode* fast=list;
        ListNode* slow = list;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast=fast->next->next;
            if(fast != nullptr)
                slow=slow->next;
        }

        ListNode* temp =  slow->next;
        slow->next=nullptr;
        return temp;
    }

    ListNode* merge_two_sorted_list(ListNode* left, ListNode* right)
    {
        if(left==nullptr)
        {
            return right;
        }
        if(right == nullptr)
        {
            return left;
        }

        if(left->val<right->val)
        {
            left->next= merge_two_sorted_list(left->next,right);
            return left;
        }
        else
        {
            right->next =merge_two_sorted_list(left,right->next);
            return right;
        }

    }
    ListNode* merge_sort(ListNode* head) {
        
        if(head == nullptr || head->next ==nullptr) // handling base case either empty or one element
        {
            return head;
        }

        ListNode* second = split(head);
        head = merge_sort(head);
        second = merge_sort(second);

        return  merge_two_sorted_list(head,second);

    }

    ListNode* sortList(ListNode* head) {
        return merge_sort(head);
    }
};