

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        int counter = 0;

        while (current != nullptr)
        {
            counter++;
            current = current->next;
        }
        current = head;

        int Tnode = counter - n + 1;

        if (Tnode == 1) {
            return head->next;
        }


        current = head;
        for (int i = 1; i < Tnode - 1; i++) {
            current = current->next;
        }
        current->next = current->next->next;


        return head;

    }
};