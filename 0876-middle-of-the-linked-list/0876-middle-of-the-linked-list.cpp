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
    ListNode* middleNode(ListNode* head) {
        int counter=0;


      ListNode *current=head;

        while (current != nullptr)
        {

            counter++;
            current= current->next;
        }

       int middle=0;


        if(counter%2==0)
        {
            middle = (counter+2)/2;
        }
        else 
        {
            middle =  (counter+1)/2;
        }
         current=head;


        for (int i=1;i<middle;i++)
           current= current->next;

         return current;
    }
};