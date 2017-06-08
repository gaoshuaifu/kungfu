class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = slow->next;
        slow = reverseList(slow);
        while(slow) {
            if(head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
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
