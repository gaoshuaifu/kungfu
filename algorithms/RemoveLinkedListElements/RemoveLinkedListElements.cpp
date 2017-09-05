class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) {
            return head;
        }

        ListNode* tmp = new ListNode(0);
        tmp->next = head;

        ListNode* prev = tmp;
        ListNode* curr = head;

        while(curr) {
            if(curr->val == val) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        head = tmp->next;
        return head;
    }
};
