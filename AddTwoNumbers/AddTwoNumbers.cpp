/*
 * time: O(m + n), space: O(max(m + n))
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

void printNumber(ListNode* l){
	for(ListNode* p = l; p != NULL; p = p->next){
		if(p->next == NULL)
			cout << p->val;
		else 
			cout << p->val << "->";
	}
	cout << endl;
}

class Solution{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
		ListNode* head = NULL;
		ListNode* tail;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		int digit;
		int carry = 0;
		
		while(p1 || p2){
			int sum = 0;
			if(p1){
				sum += p1->val;
				p1 = p1->next;
			}
			if(p2){
				sum += p2->val;
				p2 = p2->next;
			}
			sum += carry;
			digit = sum % 10;
			carry = sum / 10;
			if(!head)
				head = tail = new ListNode(digit);
			else
				tail = tail->next = new ListNode(digit);
		}
		if(carry > 0)
			tail->next = new ListNode(carry);
		
		return head;
	}
};

int main(){
	ListNode* l1 = new ListNode(4);
	ListNode* p1 = l1;
	p1->next = new ListNode(5);
	p1 = p1->next;
	p1->next = new ListNode(6);
	p1 = p1->next;
	printNumber(l1);
	
	ListNode* l2 = new ListNode(6);
	ListNode* p2 = l2;
	p2->next = new ListNode(7);
	p2 = p2->next;
	p2->next = new ListNode(8);
	p2 = p2->next;
	p2->next = new ListNode(9);
	p2 = p2->next;
	printNumber(l2);
	
	Solution solution;
	ListNode* l3 = solution.addTwoNumbers(l1, l2);
	printNumber(l3);
		
	return 0;
}

