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
  void remove(ListNode* head, ListNode* nodeToRemove){
    if(!head) return;

    if(head == nodeToRemove){
      head = head->next;
      delete nodeToRemove;
    }

    ListNode* nextNode = nodeToRemove->next;
    nodeToRemove->val = nextNode->val;
    nodeToRemove->next = nextNode->next;
    delete nextNode;
  }
};

int main(){
  int array[] = {5, 4, 3, 2, 1};
  ListNode* list = initializeList(array, sizeof(array) / sizeof(array[0]));
  ListNode* nodeToRemove = list->next->next;

  Solution solution;
  solution.remove(list, nodeToRemove);
  print(list);

  return 0;
}
