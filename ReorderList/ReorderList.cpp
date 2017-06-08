class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* mid = NULL;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) {
            mid = slow;
            slow = slow->next;
        }

        fast = head;
        slow = reverseList(slow);

        // At this point, the original list is split into two.
        // fast: the 1st half in original order.
        // slow: the 2nd half in reverse order.
        ListNode* tmp = new ListNode(0);
        ListNode* tail = tmp;

        while(slow) {
            tail->next = fast;
            tail = fast;
            fast = fast->next;

            tail->next = slow;
            tail = slow;
            slow = slow->next;
        }

        if(mid) {
            tail->next = mid;
            mid->next = NULL;
        }

        delete tmp;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* post = NULL;
        while(head) {
            post = head->next;
            head->next = prev;
            prev = head;
            head = post;
        }
        return prev;
    }
};
