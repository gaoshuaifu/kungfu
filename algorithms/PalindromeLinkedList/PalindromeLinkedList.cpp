
// Reverse the 2nd half of the list.
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) {
            slow = slow->next;
        }

        fast = head;
        slow = reverseList(slow);

        // At this point, the original list is split into two.
        // fast: the 1st half in original order.
        // slow: the 2nd half in reverse order.
        while(slow) {
            if(fast->val != slow->val)
                return false;
            fast = fast->next;
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

// Put the 1st half of the list into a stk.
class Solution1 {
public:
    bool isPalindrome(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        stack<ListNode*> stk;
        while(fast && fast->next){
            stk.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast)
            slow = slow->next;

        while(slow){
            if(slow->val != stk.top()->val)
                return false;
            slow = slow->next;
            stk.pop();
        }
        return true;
    }
};
