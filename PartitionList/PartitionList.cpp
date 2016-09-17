/*
 * time: O(n), space O(n)
 */
#include <iostream>
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
  ListNode* partition(ListNode* head, int x){
    ListNode* tmp1 = new ListNode(INT_MIN);
    ListNode* head1 = tmp1;
    ListNode* tail1 = tmp1;

    ListNode* tmp2 = new ListNode(INT_MIN);
    ListNode* head2 = tmp2;
    ListNode* tail2 = tmp2;

    for(ListNode* curr = head; curr; curr = curr->next){
      if(curr->val < x)
        tail1 = tail1->next = curr;
      else
        tail2 = tail2->next = curr;
    }

    tail1->next = tmp2->next;
    tail2->next = NULL;
    head1 = tmp1->next;
    delete tmp1;
    delete tmp2;
    return head1;
  }
};


int main(){
  int array1[] = {2, 1};
  ListNode* list1 = initializeList(array1, sizeof(array1) / sizeof(array1[0]));
  Solution solution;
  ListNode* res = solution.partition(list1, 2);
  print(res);
  return 0;
}

