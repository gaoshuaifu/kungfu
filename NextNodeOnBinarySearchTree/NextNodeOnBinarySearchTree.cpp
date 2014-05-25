#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
	int val;
	TreeNode * parent;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val){
		this->val = val;
		this->parent = NULL;
		this->left = NULL;
		this->right = NULL;
	}
};

/*
        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   1      _4       7       9
         /  \
         3   5
         
*/
TreeNode* initialize(){
	
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);
	TreeNode* node7 = new TreeNode(7);
	TreeNode* node8 = new TreeNode(8);
	TreeNode* node9 = new TreeNode(9);
	node6->left = node2;
	node6->right = node8;
	
	node2->parent = node6;
	node2->left = node1;
	node2->right = node4;
	
	node8->parent = node6;
	node8->left = node7;
	node8->right = node9;
	
	node1->parent = node2;
	
	node4->parent = node2;
	node4->left = node3;
	node4->right = node5;
	
	node7->parent = node8;
	node9->parent = node8;
	
	node3->parent = node4;
	node5->parent = node4;
	
	TreeNode* root = node6;
	return root;
}

class Solution{
public:
	TreeNode* nextNode(TreeNode* root, TreeNode* query){
		TreeNode* curr;
		
		if(query->right){
			curr = query->right;
			while(curr->left)
				curr = curr->left;
			return curr;
		}
		else{
			curr = query;
			while(curr->parent && curr == curr->parent->right)
				curr = curr->parent;
			return curr->parent;
		}
	}
};

int main(){
	Solution solution;
	
	TreeNode* root = initialize();
	stack<TreeNode*> stk;
	TreeNode* curr = root;
	TreeNode* next;
	while(!stk.empty() || curr){
		if(curr){
			stk.push(curr);
			curr = curr->left;
		}
		else{
			curr = stk.top();
			stk.pop();
			
			next = solution.nextNode(root, curr);
			if(next)
				cout << curr->val << " next node is " << next->val << "\n";
			else 
				cout << curr->val << " next node is " << "NULL" << "\n";	
			
			curr = curr->right;
		}
	}
	
	return 0;
}
