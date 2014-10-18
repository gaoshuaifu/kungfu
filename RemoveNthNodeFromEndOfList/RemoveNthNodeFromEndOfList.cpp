/*
 * time: O(n), space: O(1)
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
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* tmp = new ListNode(INT_MIN);
        tmp->next = head;   
        ListNode* prev = tmp;
        ListNode* curr = head;
        ListNode* post = head;
        
        int i;
        for(i = 0; i < n; i++){
            if(!post)
                return head;
            post = post->next;
        }
        
        if(i < n) return head;
        
        while(post){
            prev = prev->next;
            curr = curr->next;
            post = post->next;
        }
        
        prev->next = curr->next;
        delete curr;
        
        head = tmp->next;
        delete tmp;
        return head;
    }
};

int main(){
    for(int i = 1; i <= 7; i++){
        int array[] = {1, 2, 3, 4, 5};
        ListNode* head = initializeList(array, sizeof(array) / sizeof(array[0]));
        Solution solution;
        print(solution.removeNthFromEnd(head, i));
    }
    return 0;
}


    