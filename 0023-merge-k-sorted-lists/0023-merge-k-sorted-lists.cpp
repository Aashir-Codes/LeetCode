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
    ListNode* merge_two_list(ListNode* left,ListNode* right)
    {
        if(!left)
        {
            return right;
        }
        if(!right)
        {
            return left;
        }

        if(left->val<right->val)
        {
            left->next=merge_two_list(left->next,right);
            return left;
        }
        else
        {
            right->next = merge_two_list(left, right->next);
            return right;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* ans=nullptr;
        if(lists.empty())
        {
            return ans;
        }
        for (int i=0;i<lists.size();i++)
        {
            ans=merge_two_list(ans,lists[i]);
        }

        
        return ans;

    }
};