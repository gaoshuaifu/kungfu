#include <iostream>
#include <map>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode* extra;
	ListNode(int val){
		this->val = val;
		this->next = NULL;
		this->extra = NULL;
	}
};

ListNode* initializeList(int array[], int n){
	ListNode* head = NULL;
	ListNode* tail = NULL;
	
	for(int i = 0; i < n; i++){
		if(head == NULL)
			head = tail = new ListNode(array[i]);
		else
			tail = tail->next = new ListNode(array[i]);
		
		tail->extra = tail;
	}
	return head;
}

void print(ListNode* head){
	for(ListNode* p = head; p != NULL; p = p->next)
		cout << p->val << "(" << p->extra->val << ")"<< " ";
	cout << endl;
}

class Solution{
public:	
	ListNode* cloneList(ListNode* head){
		ListNode* newHead = NULL;
		ListNode* newTail = NULL;
		map<ListNode*, ListNode*> mapping;
		
		for(ListNode* curr = head; curr; curr = curr->next){
			if(!newHead)
				newHead = newTail = new ListNode(curr->val);	
			else
				newTail = newTail->next = new ListNode(curr->val);
			mapping[curr] = newTail;
		}
		
		for(ListNode* curr = head; curr; curr = curr->next)
			mapping[curr]->extra = mapping[curr->extra]	;
		
		return newHead;	
	}
};

int main(){
	int array[] = {1, 2, 3, 4, 5};
	ListNode* head = initializeList(array, sizeof(array) / sizeof(array[0]));	
	print(head);
	
	Solution solution;
	ListNode* newHead = solution.cloneList(head);
	print(newHead);
	
	return 0;	
}

