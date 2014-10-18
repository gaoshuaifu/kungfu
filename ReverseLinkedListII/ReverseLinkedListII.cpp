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
    ListNode* reverseBetween(ListNode* head, int m, int n){
        if(!head || m >= n)
            return head;

        ListNode* tmp = new ListNode(INT_MIN);
        tmp->next = head;
        ListNode* prev = tmp;
        ListNode* curr = head;

        for(int i = 0; i < m - 1; i++){
            prev = prev->next;
            curr = curr->next;
        }

        for(int i = 0; i < n - m; i++){
            ListNode* post = curr->next;
            curr->next = post->next;
            post->next = prev->next;
            prev->next = post;
        }

        head = tmp->next;
        delete tmp;
        return head;
    }
};

class Solution1{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n){
        if(!head || m >= n)
            return head;

        ListNode* tmp = new ListNode(INT_MIN);
        tmp->next = head;
        ListNode* prev = tmp;
        ListNode* curr = head;

        ListNode* post = head;
        for(int i = 0; i < n - m; i++)
            post = post->next;

        for(int i = 0; i < m - 1; i++){
            prev = prev->next;
            curr = curr->next;
            post = post->next;
        }

        while(curr != post){
            prev->next = curr->next;
            curr->next = post->next;
            post->next = curr;
            curr = prev->next;
        }

        head = tmp->next;
        delete tmp;

        return head;
    }
};

int main(){

    for(int i = 1; i <= 5; i++){
        for(int j = i; j <= 5; j++){
            int array[] = {1, 2, 3, 4, 5};
            ListNode* head = initializeList(array, sizeof(array) / sizeof(array[0]));
            Solution solution;
            cout << "m = " << i << ", n = " << j << "\n";
            print(solution.reverseBetween(head, i, j));
            cout << endl;
        }
    }
    return 0;
}
