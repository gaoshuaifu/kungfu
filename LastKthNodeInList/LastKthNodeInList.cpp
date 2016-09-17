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
  ListNode* lastKth(ListNode* head, int k){
    ListNode* post = head;
    int i;
    for(i = 0; i < k; i++){
      if(post)
        post = post->next;
      else
        break;
    }

    if(i < k) return NULL;

    ListNode* curr = head;
    while(post){
      post = post->next;
      curr = curr->next;
    }

    return curr;
  }
};

int main(){
  int array[] = {5, 4, 3, 2, 1};
  ListNode* list = initializeList(array, sizeof(array) / sizeof(array[0]));
  Solution solution;
  for(int i = 1; i <= 7; i++){
    ListNode* res = solution.lastKth(list, i);
    cout << i << ": ";
    if(res)
      cout << res->val << "\n";
    else
      cout << "NULL" << "\n";
  }
  return 0;
}
