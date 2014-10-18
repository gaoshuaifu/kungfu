#include <iostream>
#include <stack>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;    
    }
};

ListNode* initializeList(int array[], int n){
    ListNode* head = NULL;
    ListNode* p = NULL;
    
    for(int i = 0; i < n; i++){
        if(head == NULL){
            head = new ListNode(array[i]);
            p = head;
        }   
        else{
            p->next = new ListNode(array[i]);
            p = p->next;
        }
    }
    return head;
}

void print(ListNode* head){
    for(ListNode* p = head; p != NULL; p = p->next)
        cout << p->val << " ";
    cout << endl;
}

class Solution{
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


int main(){
    int array[] = {1, 2, 2, 3}; 
    ListNode* list = initializeList(array, sizeof(array) / sizeof(array[0]));
    
    Solution solution;
    bool res = solution.isPalindrome(list);
    cout << res << endl;
    
    return 0;   
}