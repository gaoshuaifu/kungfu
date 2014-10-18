/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <stack>
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
    int getLength(ListNode* head){
        int n = 0;
        for(ListNode* curr = head; curr; curr = curr->next)
            n++;
        return n;
    }
    
    ListNode* rotateRight(ListNode* head, int k){
        int n = getLength(head);
        if(n == 0)
            return head;
        
        k = k % n;
        if(k == 0)
            return head;
        
        ListNode* post = head;
        for(int i = 0; i < k; i++)
            post = post->next;
        
        ListNode* curr = head;
        while(post->next){
            curr = curr->next;
            post = post->next;
        }
        
        post->next = head;
        head = curr->next;
        curr->next = NULL;
        
        return head;
    }
};

int main(){
    for(int i = 1; i <= 5; i++){
        int array[] = {1, 2, 3, 4, 5};
        ListNode* head = initializeList(array, sizeof(array) / sizeof(array[0]));
        Solution solution;
        print(solution.rotateRight(head, i));
        cout << endl;
    }
    return 0;
}

