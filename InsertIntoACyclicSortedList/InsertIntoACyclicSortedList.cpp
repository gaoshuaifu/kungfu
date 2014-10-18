/*
 * time: O(n), space: O(1)
 */
#include <iostream>
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
    if(n == 0)
        return NULL;
    
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
    p->next = head;
    return head;
}

void print(ListNode* head){
    if(head == NULL)
        return;
    ListNode* p;
    for(p = head; p->next != head; p = p->next)
        cout << p->val << " ";
    cout << p->val;
    cout << endl;
}

class Solution{
public:
    ListNode* insert(ListNode* head, int val){
        if(!head){
            head = new ListNode(val);
            head->next = head;
        }
        else if(val < head->val){
            ListNode* curr = head; 
            while(curr->next != head) 
                curr = curr->next;
            ListNode* node = new ListNode(val);
            node->next = curr->next;
            curr->next = node;
            head = node;
        }
        else{
            ListNode* curr = head;
            while(curr->next != head && curr->next->val <= val)
                curr = curr->next;
            ListNode* node = new ListNode(val);
            node->next = curr->next;
            curr->next = node;
        }
        return head;
    }
};

int main(){
    Solution solution;
    for(int i = 0; i <= 6; i++){
        int array[] = {1, 2, 3, 4, 5}; 
        ListNode* list = initializeList(array, sizeof(array) / sizeof(array[0]));
        print(list);
        ListNode* newList = solution.insert(list, i);
        print(newList);
        cout << endl;
    }
    return 0;
}

