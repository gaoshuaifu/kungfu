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

void initialize(ListNode*& head1, ListNode*& head2){
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);	
	ListNode* node6 = new ListNode(6);
	ListNode* node7 = new ListNode(7);	
	ListNode* node8 = new ListNode(8);
	
	node1->next = node2;
	node2->next = node6;
	
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	
	node6->next = node7;
	node7->next = node8;

	head1 = node1;
	head2 = node3;
}

void print(ListNode* head){
	for(ListNode* p = head; p != NULL; p = p->next)
		cout << p->val << " ";
	cout << endl;
}

class Solution{
public:
	int getLength(ListNode* head){
		int len = 0;
		for(ListNode* curr = head; curr; curr = curr->next)
			len++;
		return len;
	}
	
	int findIntersection(ListNode* head1, ListNode* head2){
		int len1 = getLength(head1);
		int len2 = getLength(head2);

		ListNode* shortP = NULL;
		ListNode* longP = NULL;
		int diff;
		
		if(len1 < len2){
			shortP = head1;
			longP = head2;
			diff = len2 - len1;
		}
		else{
			shortP = head2;
			longP = head1;
			diff = len1 - len2;
		}
		
		while(diff > 0){
			longP = longP->next;
			diff--;
		}
		
		while(shortP != longP){
			shortP = shortP->next;
			longP = longP->next;
		}
			
		return shortP->val;
	}
};

int main(){
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	initialize(head1, head2);
	print(head1);
	print(head2);
	
	Solution solution;
	int res = solution.findIntersection(head1, head2);
	cout << res << endl;

	return 0;	
}