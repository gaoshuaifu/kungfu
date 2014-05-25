*

* time: O(n), space: O(1)
 */
#include <iostream>
#include <climits>
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
	ListNode* tail = NULL;
	
	for(int i = 0; i < n; i++){
		if(head == NULL){
			head = new ListNode(array[i]);
			tail = head;
		}
		else{
			tail->next = new ListNode(array[i]);
			tail = tail->next;
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
	ListNode* swapPairs(ListNode* head){
		ListNode* tmp = new ListNode(INT_MIN);
		tmp->next = head;
		ListNode* prev = tmp;
		ListNode* curr = head;
		
		while(curr && curr->next){
			ListNode* post = curr->next;
			curr->next = post->next;
			post->next = prev->next;
			prev->next = post;
			prev = curr;
			curr = curr->next;
		}
		
		head = tmp->next;
		delete tmp;
		return head;
	}
};

int main(){
	int array[] = {1, 2, 3, 4, 5};
	ListNode* head = initializeList(array, sizeof(array) / sizeof(array[0]));
	Solution solution;
	ListNode* res = solution.swapPairs(head);
	print(res);
	return 0;
}
