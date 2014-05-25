/*
 * time: O(n), space: O(width)
 */
#include <iostream>
#include <vector>
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


class Solution{
public:
	vector<vector<int> > levelOrderBottom(TreeNode* root){ 
		vector<vector<int> > res;
		if(root == NULL)
			return res;
			
		queue<TreeNode*> currQ;
		currQ.push(root);
		
		while(!currQ.empty()){
			vector<int> levelNodes;
			queue<TreeNode*> nextQ;
			while(!currQ.empty()){
				TreeNode* node = currQ.front();
				currQ.pop();
				levelNodes.push_back(node->val);
				if(node->left)
					nextQ.push(node->left);
				if(node->right)
					nextQ.push(node->right);
			}
			res.push_back(levelNodes);
			currQ = nextQ;
		}	
		reverse(res.begin(), res.end());
		return res;
	}
};

int main(){
	TreeNode* root = initialize();
	
	Solution solution;
	vector<vector<int> > res = solution.levelOrder(root);
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << "\n";
	}
	cout << endl;
	
	return 0;
}

