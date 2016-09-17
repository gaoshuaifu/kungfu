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
    ListNode* curr = head;
    while(curr){
      ListNode* post = curr->next;
      while(post && curr->val == post->val){
        curr->next = post->next;
        delete post;
        post = curr->next;
      }
      curr = curr->next;
    }
    return head;
  }
};

class Solution1{
public:
  ListNode* deleteDuplicates(ListNode* head){
    if(!head) return NULL;
    ListNode* curr = head;
    ListNode* post = head->next;
    while(post){
      if(curr->val == post->val){
        curr->next = post->next;
        delete post;
        post = post->next;
      }
      else{
        curr = curr->next;
        post = post->next;
      }
    }
    return head;
  }
};


int main(){
  int array[] = {1, 1, 2, 3, 3, 4};
  ListNode* list = initializeList(array, sizeof(array) / sizeof(array[0]));
  print(list);
  Solution solution;
  ListNode* res = solution.deleteDuplicates(list);
  print(res);
  return 0;
}

