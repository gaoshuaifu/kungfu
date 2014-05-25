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
	void partition(ListNode* head, ListNode*& left, ListNode*& right){	
		if(!head){
			left = NULL;
			right = NULL;
			return;
		}
		
		ListNode* slow = head;
		ListNode* fast = head;
		while(fast && fast->next && fast->next->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		
		left = head;
		right = slow->next;
		slow->next = NULL;
	}
};


int main(){
	int array[] = {1, 2, 3, 4, 5}; 
	ListNode* head = initializeList(array, sizeof(array) / sizeof(array[0]));
	Solution solution;
	ListNode* left;
	ListNode* right;
	solution.partition(head, left, right);
	print(left);
	print(right);
	return 0;
}
