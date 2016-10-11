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

    while(l1 && l2){
      if(l1->val < l2->val){
        tail->next = l1;
        tail = tail->next;
        l1 = l1->next;
      }
      else{
        tail->next = l2;
        tail = tail->next;
        l2 = l2->next;
      }
    }

    if(l1)
      tail->next = l1;
    if(l2)
      tail->next = l2;

    head = tmp->next;
    delete tmp;
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
