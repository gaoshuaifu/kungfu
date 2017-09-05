/*
 * time: O(nlogk), space: O(k)
 */
#include <iostream>
#include <vector>
#include <queue>
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
    struct Greater{
        bool operator() (const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists){
        int n = lists.size();

        priority_queue<ListNode*, vector<ListNode*>, Greater> minHeap;
        for(int i = 0; i < n; i++){
            if(lists[i]) {
                minHeap.push(lists[i]);
            }
        }

        ListNode* tmp = new ListNode(INT_MIN);
        ListNode* tail = tmp;
        while(!minHeap.empty()){
            ListNode* node = minHeap.top();
            minHeap.pop();

            tail->next = node;
            tail = tail->next;

            if(node->next)
                minHeap.push(node->next);
        }

        ListNode* head = tmp->next;
        delete tmp;
        return head;
    }
};

int main(){
    vector<ListNode*> lists;
    int array1[] = {1, 2};
    int array2[] = {3, 4, 5};
    int array3[] = {6, 7, 8, 9};
    ListNode* list1 = initializeList(array1, sizeof(array1) / sizeof(array1[0]));
    ListNode* list2 = initializeList(array2, sizeof(array2) / sizeof(array2[0]));
    ListNode* list3 = initializeList(array3, sizeof(array3) / sizeof(array3[0]));
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    Solution solution;
    ListNode* res = solution.mergeKLists(lists);
    print(res);

    return 0;
}
