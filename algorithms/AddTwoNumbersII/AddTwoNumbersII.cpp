class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> stk1;
        stack<ListNode*> stk2;

        for(ListNode* p = l1; p; p = p->next) {
            stk1.push(p);
        }

        for(ListNode* p = l2; p; p = p->next) {
            stk2.push(p);
        }

        int carry = 0;
        int sum, digit;
        ListNode* tmp = new ListNode(0);
        while(!stk1.empty() || !stk2.empty()) {
            sum = 0;
            if(!stk1.empty()) {
                sum += stk1.top()->val;
                stk1.pop();
            }
            if(!stk2.empty()) {
                sum += stk2.top()->val;
                stk2.pop();
            }
            sum += carry;
            digit = sum % 10;
            carry = sum / 10;

            ListNode* node = new ListNode(digit);
            node->next = tmp->next;
            tmp->next = node;
        }

        if(carry) {
            ListNode* node = new ListNode(carry);
            node->next = tmp->next;
            tmp->next = node;
        }

        ListNode* head = tmp->next;
        delete tmp;
        return head;
    }
};
