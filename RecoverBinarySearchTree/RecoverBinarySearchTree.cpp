/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <climits>
#include <stack>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val){
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

TreeNode* initialize(){
	TreeNode* node1 = new TreeNode(5);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(6);
	TreeNode* node4 = new TreeNode(1);
	TreeNode* node5 = new TreeNode(3);
	TreeNode* node6 = new TreeNode(4);
	TreeNode* node7 = new TreeNode(7);
	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->left = node6;
	node3->right = node7;
	TreeNode* root = node1;
	return root;
}

void print(TreeNode* root){
	if(root == NULL)
		return;
	
	print(root->left);
	cout << root->val << " ";
	print(root->right);
}

class Solution{
public:
	void recoverTree(TreeNode* root){
		TreeNode* tmp = new TreeNode(INT_MIN);
		TreeNode* prev = tmp;
		TreeNode* first = NULL;
		TreeNode* second = NULL;
		
		TreeNode* curr = root;
		stack<TreeNode*> stk;
		
		while(curr || !stk.empty()){
			if(curr){
				stk.push(curr);	
				curr = curr->left;
			}
			else{
				curr = stk.top();
				stk.pop();
				
				if(prev->val > curr->val){
					if(!first)
						first = prev;
					second = curr;
				}
				prev = curr;
	
				curr = curr->right;
			}
		}
		
		if(first && second)
			swap(first->val, second->val);
		delete tmp;
	}
};

class Solution1{
public:
	void recoverTreeHelper(TreeNode* curr, TreeNode*& prev, TreeNode*& first, TreeNode*& second){
		if(!curr) return;
		
		recoverTreeHelper(curr->left, prev, first, second);
		
		if(prev->val > curr->val){
			if(!first)
				first = prev;
			second = curr;
		}
		prev = curr;
		
		recoverTreeHelper(curr->right, prev, first, second);
	}
	
	void recoverTree(TreeNode* root){
		TreeNode* tmp = new TreeNode(INT_MIN);
		TreeNode* prev = tmp;
		TreeNode* first = NULL;
		TreeNode* second = NULL;
		
		recoverTreeHelper(root, prev, first, second);
		
		if(first && second)
			swap(first->val, second->val);
		delete tmp;
	}
};

int main(){
	TreeNode* root = initialize();
	print(root);
	cout << "\n";
	Solution solution;
	solution.recoverTree(root);
	print(root);
	cout << "\n";
	return 0;
}

