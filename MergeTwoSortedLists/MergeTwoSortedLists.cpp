/*
 * time: O(m + n), space: O(1)
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* tmp = new ListNode(INT_MIN);
        ListNode* head = tmp;
        ListNode* tail = tmp;
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        while(p1 && p2){
            if(p1->val < p2->val){
                tail = tail->next = p1;
                p1 = p1->next;
            }
            else{
                tail = tail->next = p2;
                p2 = p2->next;
            }
        }

        if(p1) tail->next = p1;
        if(p2) tail->next = p2;

        head = tmp->next;
        delete tmp;
        return head;
    }
};

class Solution1{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode* head = NULL;
        ListNode* tail;
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        while(p1 && p2){
            if(p1->val < p2->val){
                if(!head)
                    head = tail = p1;
                else
                    tail = tail->next = p1;
                p1 = p1->next;
            }
            else{
                if(!head)
                    head = tail = p2;
                else
                    tail = tail->next = p2;
                p2 = p2->next;
            }
        }

        if(p1)
            tail->next = p1;
        if(p2)
            tail->next = p2;

        return head;
    }
};

int main(){
    int array1[] = {1, 2};
    int array2[] = {3, 4, 5};
    ListNode* list1 = initializeList(array1, sizeof(array1) / sizeof(array1[0]));
    ListNode* list2 = initializeList(array2, sizeof(array2) / sizeof(array2[0]));
    Solution solution;
    ListNode* res = solution.mergeTwoLists(list1, list2);
    print(res);

    return 0;
}

