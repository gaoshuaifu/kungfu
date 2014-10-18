/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <climits>
#include <cassert>
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
    void printBackwards(ListNode* head){
        if(!head)
            return;

        printBackwards(head->next);
        cout << head->val << " ";
    }
};

int main(){
    int array[] = {1, 2, 3, 4, 5};
    ListNode* head = initializeList(array, sizeof(array) / sizeof(array[0]));
    Solution solution;
    solution.printBackwards(head);
    return 0;
}
