/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <cassert>
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
        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
         
*/
TreeNode* initialize(TreeNode*& root, TreeNode*& p, TreeNode*& q){
	TreeNode* node0 = new TreeNode(0);
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);
	TreeNode* node7 = new TreeNode(7);
	TreeNode* node8 = new TreeNode(8);
	node3->left = node5;
	node3->right = node1;
	node5->left = node6;
	node5->right = node2;
	node1->left = node0;
	node1->right = node8;
	node2->left = node7;
	node2->right = node4;
	
	root = node3;
	p = node6;
	q = node4;
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
	TreeNode* LCA(TreeNode* root, TreeNode* node1, TreeNode* node2){
		if(!root)
			return NULL;
		
		if(root == node1 || root == node2)
			return root;
		
		TreeNode* l = LCA(root->left, node1, node2);
		TreeNode* r = LCA(root->right, node1, node2);
		
		if(l && r) return root;
		
		return l ? l : r;
	}
};

int main(){
	TreeNode* root;
	TreeNode* p;
	TreeNode* q;
	initialize(root, p, q);
	Solution solution;
	TreeNode* lca = solution.LCA(root, p, q);
	if(lca)
		cout << lca->val << endl;
	return 0;
}

