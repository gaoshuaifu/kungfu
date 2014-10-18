/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <map>
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
    ListNode* deleteDuplicates(ListNode* head){
        if(!head)
            return head;
        
        map<int, bool> visited;
        visited[head->val] = true;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while(curr){
            if(visited[curr->val]){
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else{
                visited[curr->val] = true;
                prev = prev->next;
                curr = curr->next;
            }
        }
        
        return head;
    }
};

int main(){
    int array[] = {2, 1, 4, 4, 3, 2, 1, 3, 2}; 
    ListNode* list = initializeList(array, sizeof(array) / sizeof(array[0]));
    print(list);
    Solution solution;
    ListNode* res = solution.deleteDuplicates(list);
    print(res);
    return 0;
}
