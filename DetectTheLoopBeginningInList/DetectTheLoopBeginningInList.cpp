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
	ListNode* node6 = new ListNode(6);
	ListNode* node7 = new ListNode(7);	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;
	node7->next = node4;
	return node1;
}

class Solution{
public:
	ListNode* loopBeginning(ListNode* head){
		ListNode* slow = head;
		ListNode* fast = head;
		ListNode* meet = NULL;
		while(slow && fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast){
				meet = slow;
				break;
			}
		}
		
		if(!meet) return NULL;
		
		slow = head;
		while(slow != fast){
			slow = slow->next;
			fast = fast->next;
		}
		
		return slow;
	}
};


int main(){
	ListNode* head = initialize();
	Solution solution;
	ListNode* res = solution.loopBeginning(head);
	cout << res->val << endl;
	return 0;	
}