/*
 * time: O(n), space: O(1)
 */
#include <iostream>
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


/*

         ____10____
        /          \
      __5_         15_
     /    \           \
     1     8           7
 
 */
 
TreeNode* initialize(){
	TreeNode* node1 = new TreeNode(10);
	TreeNode* node2 = new TreeNode(5);
	TreeNode* node3 = new TreeNode(15);
	TreeNode* node4 = new TreeNode(1);
	TreeNode* node5 = new TreeNode(8);
	TreeNode* node7 = new TreeNode(7);
	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
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
	/* if root is BST, return the number of nodes; else return -1 */
	int largestBSTSubtreeHelper(TreeNode* root, int& min, int& max, int& maxNodeNum, TreeNode*& largestBST){
		if(!root)
			return 0;
		
		bool isBST = true;
		
		int leftNodeNum = largestBSTSubtreeHelper(root->left, min, max, maxNodeNum, largestBST);
		int currMin = (leftNodeNum == 0)? root->val : min;
		if(leftNodeNum == -1 || (leftNodeNum > 0 && root->val <= max))
			isBST = false;
		
		int rightNodeNum = largestBSTSubtreeHelper(root->right, min, max, maxNodeNum, largestBST);
		int currMax = (rightNodeNum == 0)? root->val : max;
		if(rightNodeNum == -1 || (rightNodeNum > 0 && root->val >= min))
			isBST = false;
		
		if(isBST){
			min = currMin;
			max = currMax;
			int totalNodeNum = leftNodeNum + 1 + rightNodeNum;
			if(totalNodeNum > maxNodeNum){
				maxNodeNum = totalNodeNum;
				largestBST = root;
			}
			return totalNodeNum;
		}
		else	
			return -1;
	}
	
	TreeNode* largestBSTSubtree(TreeNode* root){
		int min;
		int max;
		int maxNodeNum = INT_MIN;
		TreeNode* largestBST = NULL;
		largestBSTSubtreeHelper(root, min, max, maxNodeNum, largestBST);
		return largestBST;
	}
};

int main(){
	TreeNode* root = initialize();
	Solution solution;
	TreeNode* largestBST = solution.largestBSTSubtree(root);
	print(largestBST);
	return 0;
}
