/*
 * time: O(nlogn), space: O(1)
 */
#include <iostream>
#include <climits>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

ListNode* initializeList(int array[], int n){
    ListNode* head = NULL;
    ListNode* tail = NULL;
    
    for(int i = 0; i < n; i++){
        if(head == NULL){
            head = new ListNode(array[i]);
            tail = head;
        }
        else{
            tail->next = new ListNode(array[i]);
            tail = tail->next;
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
    ListNode* getMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* leftHead, ListNode* rightHead){
        ListNode* tmp = new ListNode(INT_MIN);
        ListNode* head = tmp;
        ListNode* tail = tmp;
        
        while(leftHead && rightHead){
            if(leftHead->val < rightHead->val){
                tail = tail->next = leftHead;
                leftHead = leftHead->next;
            }
            else{
                tail = tail->next = rightHead;
                rightHead = rightHead->next;
            }
        }
        
        tail->next = leftHead? leftHead : rightHead;
        
        head = tmp->next;
        delete tmp;
        return head;
    }
    
    ListNode* mergeSort(ListNode* head){
        if(!head || !head->next)
            return head;
        
        ListNode* mid = getMiddle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = mid->next;
        mid->next = NULL;
        
        leftHead = mergeSort(leftHead);
        rightHead = mergeSort(rightHead);
        
        head = merge(leftHead, rightHead);
        return head;
    }
};

int main(){
    int array[] = {5, 8, 7, 1, 3, 2, 6, 4};
    ListNode* head = initializeList(array, sizeof(array) / sizeof(array[0]));
    Solution solution;
    ListNode* res = solution.mergeSort(head);
    print(res);
    return 0;
}
