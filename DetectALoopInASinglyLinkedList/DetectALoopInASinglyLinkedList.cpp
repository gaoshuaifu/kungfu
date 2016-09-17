#include <iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int val){
    this->val = val;
  }
};

ListNode* initialize(){
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(2);
  ListNode* node3 = new ListNode(3);
  ListNode* node4 = new ListNode(4);
  ListNode* node5 = new ListNode(5);
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = node1;

  return node1;
}

class Solution{
public:
  bool isLoop(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(slow && fast && fast->next){
      slow = slow->next;
      fast = fast->next->next;
      if(slow == fast)
        return true;
    }

    return false;
  }
};

int main(){
  ListNode* head = initialize();
  Solution solution;
  cout << solution.isLoop(head) << endl;
  return 0;
}
