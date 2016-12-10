#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode* sub;
  ListNode(int val){
    this->val = val;
    this->next = NULL;
    this->sub = NULL;
  }
};

ListNode* initialize(){
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(2);
  ListNode* node3 = new ListNode(3);
  ListNode* node4 = new ListNode(4);
  ListNode* node5 = new ListNode(5);
  ListNode* node6 = new ListNode(6);
  ListNode* node7 = new ListNode(7);
  ListNode* node8 = new ListNode(8);
  ListNode* node9 = new ListNode(9);
  ListNode* node10 = new ListNode(10);
  ListNode* node11 = new ListNode(11);

  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;

  node2->sub = node6;
  node6->next = node7;

  node4->sub = node8;
  node8->next = node9;

  node8->sub = node10;
  node10->next = node11;

  return node1;
}

class Solution {
public:
  void flattenHelper(ListNode* node, ListNode*& tail) {
    tail->next = node;
    tail = node;

    if(node->next)
      flattenHelper(node->next, tail);

    if(node->sub)
      flattenHelper(node->sub, tail);
  }

  ListNode* flatten(ListNode* head) {
    if(!head)
      return head;
    ListNode* tmp = new ListNode(0);
    ListNode* tail = tmp;
    flattenHelper(head, tail);
    head = tmp->next;
    delete tmp;
    return head;
  }
};

int main(){
  ListNode* head = initialize();
  Solution solution;
  solution.flatten(head);
  for(ListNode* curr = head; curr; curr = curr->next)
    cout << curr->val << " ";
  cout << endl;
  return 0;
}
