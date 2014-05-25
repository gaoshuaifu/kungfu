/*
 * time: O(n), space: O(n)
 */
#include <iostream>
#include <algorithm>
#include <climits>
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
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);
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

class Solution {
public:
	int maxPathSumHelper(TreeNode* root, int& res){
		if(!root) return 0;
		int left = maxPathSumHelper(root->left, res);
		int right = maxPathSumHelper(root->right, res);
		int sum = left + right + root->val;
		res = max(res, sum);
		return max(max(left, right) + root->val, 0);
	}
	
	int maxPathSum(TreeNode* root) {
		int res = INT_MIN;
		maxPathSumHelper(root, res);
		return res;
	}
};

int main(){
	TreeNode* root = initialize();
	
	Solution solution;
	int res = solution.maxPathSum(root);
	cout << res << endl;
	
	return 0;
}

