class Solution{
public:
    ListNode* detectCycle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* meet = NULL;
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                meet = slow;
                break;
            }
        }

        if(!meet) return NULL;

        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
