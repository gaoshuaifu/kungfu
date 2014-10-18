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
    ListNode* reverseKGroup(ListNode* head, int k){ 
        if(!head || k <= 1)
            return head;
        
        ListNode* tmp = new ListNode(INT_MIN);
        tmp->next = head;
        ListNode* prev = tmp;
        ListNode* curr = head;
        
        while(true){
            ListNode* checker = curr;
            int i;
            for(i = 0; i < k; i++){
                if(checker)
                    checker = checker->next;
                else
                    break;
            }
            if(i < k) break;
            
            for(int i = 0; i < k - 1; i++){
                ListNode* post = curr->next;
                curr->next = post->next;
                post->next = prev->next;
                prev->next = post;
            }
            
            prev = curr;
            curr = curr->next;
        }
        
        head = tmp->next;
        delete tmp;
        return head;
    }
};

class Solution1{
public:
    int getLength(ListNode* head){
        int len = 0;
        for(ListNode* p = head; p; p = p->next)
            len++;
        return len;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k){
        if(!head || k <= 1)
            return head;
        
        int round = getLength(head) / k;

        ListNode* tmp = new ListNode(INT_MIN);
        tmp->next = head;
        ListNode* prev = tmp;
        ListNode* curr = head;
        
        for(int i = 0; i < round; i++){
            for(int j = 0; j < k - 1; j++){
                ListNode* post = curr->next;
                curr->next = post->next;
                post->next = prev->next;
                prev->next = post;
            }
            prev = curr;
            curr = curr->next;
        }
        
        head = tmp->next;
        delete tmp;
        return head;
    }
};

int main(){

    for(int i = 1; i <= 10; i++){
        int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        ListNode* head = initializeList(array, sizeof(array) / sizeof(array[0]));
        Solution solution;
        print(solution.reverseKGroup(head, i));
        cout << endl;
    }
    return 0;
}
