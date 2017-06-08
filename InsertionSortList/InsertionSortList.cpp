class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) {
          return head;
        }

        ListNode* tmp = new ListNode(0);
        ListNode* prev = tmp;  // The node to be inserted
        ListNode* curr = head; // Insert node between prev and prev->next
        ListNode* post;        // The next node to be inserted

        while(curr) {
            post = curr->next;

            // Search the place to insert
            while(prev->next and prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Insert node
            curr->next = prev->next;
            prev->next = curr;

            // Reset
            prev = tmp;
            curr = post;
        }

        head = tmp->next;
        delete tmp;
        return head;
    }
};
