/*
 * time: O(n), space: O(h)
 */
#include <iostream>
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
  bool hasPathSum(TreeNode* root, int sum){
    if(!root)
      return false;

    if(!root->left && !root->right)
      return root->val == sum;

    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
  }
};

int main(){
  TreeNode* root = initialize();
  int sum = 7;

  Solution solution;
  bool res = solution.hasPathSum(root, sum);
  cout << res << endl;

  return 0;
}

