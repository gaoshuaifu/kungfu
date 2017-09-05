/*
 * time: O(n), space: O(1)
 */
#include <iostream>
using namespace std;

struct ListNode{
    char val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

ListNode* initializeList(char array[], int n){
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
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    ListNode* deleteDuplicates(ListNode* head){
        ListNode* tmp = new ListNode('z');
        tmp->next = head;
        ListNode* prev = tmp;
        ListNode* curr = head;

        while(curr){
            if(isVowel(curr->val)){
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else{
                prev = prev->next;
                curr = curr->next;
            }
        }

        head = tmp->next;
        delete tmp;
        return head;
    }
};

int main(){
    char array[] = {'a', 'b', 'c', 'd', 'e'};
    ListNode* list = initializeList(array, sizeof(array) / sizeof(array[0]));
    print(list);
    Solution solution;
    ListNode* res = solution.deleteDuplicates(list);
    print(res);
    return 0;
}
