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

class Solution1{
public:
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next)
            return head;

        ListNode* rest = head->next;
        rest = reverseList(rest);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
};

int main(){
    int array[] = {1, 2, 3, 4, 5};
    ListNode* head = initializeList(array, sizeof(array) / sizeof(array[0]));
    Solution1 solution;
    print(solution.reverse(head));
    return 0;
}
