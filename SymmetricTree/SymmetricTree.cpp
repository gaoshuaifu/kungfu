/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <queue>
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
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(2);
	TreeNode* node4 = new TreeNode(3);
	TreeNode* node5 = new TreeNode(4);
	TreeNode* node6 = new TreeNode(4);
	TreeNode* node7 = new TreeNode(3);
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
	cout << root->val << endl;
	print(root->right);
}

class Solution{
public:
	bool isSymmetricHelper(TreeNode* left, TreeNode* right){
		if(!left && !right)
			return true;
		
		if((!left && right) || (left && !right) || (left->val != right->val))
			return false;

		return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
	}

	bool isSymmetric(TreeNode* root){
		if(!root)
			return true;
		return isSymmetricHelper(root->left, root->right);
	}
};

class Solution1{
public:
	bool isSymmetric(TreeNode* root){
		if(!root)
			return true;
		
		queue<TreeNode*> leftQ;
		queue<TreeNode*> rightQ;
		leftQ.push(root->left);
		rightQ.push(root->right);
		
		while(!leftQ.empty() && !rightQ.empty()){
			TreeNode* left = leftQ.front();
			TreeNode* right = rightQ.front();
			leftQ.pop();
			rightQ.pop();
			if(!left && !right)
				continue;
			if((left && !right) || (!left && right) || (left->val != right->val))
				return false;
			leftQ.push(left->left);
			leftQ.push(left->right);
			rightQ.push(right->right);
			rightQ.push(right->left);
		}
		
		return leftQ.empty() && rightQ.empty();
	}
};

int main(){
	TreeNode* root = initialize();
	Solution solution;
	bool res = solution.isSymmetric(root);
	cout << res << endl;

	return 0;
}