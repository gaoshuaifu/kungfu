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
    ListNode* quickSort(ListNode* head){
        if(!head || !head->next)
            return head;

        ListNode* mid = head;
        ListNode* leftHead = NULL;
        ListNode* leftTail = NULL;
        ListNode* rightHead = NULL;
        ListNode* rightTail = NULL;

        for(ListNode* curr = head->next; curr; curr = curr->next){
            if(curr->val <= mid->val){
                if(!leftHead)
                    leftHead = leftTail = curr;
                else
                    leftTail = leftTail->next = curr;
            }
            else{
                if(!rightHead)
                    rightHead = rightTail = curr;
                else
                    rightTail = rightTail->next = curr;
            }
        }

        if(leftTail)
            leftTail->next = NULL;
        if(rightTail)
            rightTail->next = NULL;

        leftHead = quickSort(leftHead);
        rightHead = quickSort(rightHead);

        if(leftHead){
            head = leftHead;
            ListNode* curr = leftHead;
            while(curr->next)
                curr = curr->next;
            curr->next = mid;
        }
        else
            head = mid;

        mid->next = rightHead;

        return head;
    }
};

int main(){
    int array[] = {5, 8, 7, 1, 3, 2, 6, 4};
    ListNode* head = initializeList(array, sizeof(array) / sizeof(array[0]));
    Solution solution;
    ListNode* res = solution.quickSort(head);
    print(res);
    return 0;
}
