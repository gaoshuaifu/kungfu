#include <iostream>
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

/*
    _______6______
     /        \
  ___2__      ___8__
   /    \    /    \
   1    _4     7     9
     /  \
     3   5

*/
TreeNode* initialize1(){
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

  node2->left = node1;
  node2->right = node4;

  node8->left = node7;
  node8->right = node9;

  node4->left = node3;
  node4->right = node5;

  TreeNode* root = node6;
  return root;
}

TreeNode* initialize2(){
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node4 = new TreeNode(4);

  node2->left = node1;
  node2->right = node4;

  TreeNode* root = node2;
  return root;
}

class Solution{
public:
  bool isIdentical(TreeNode* root1, TreeNode* root2){
    if(!root2)
      return true;

    if(!root1)
      return false;

    if(root1->val != root2->val)
      return false;

    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
  }

  bool hasIdenticalSubtree(TreeNode* root1, TreeNode* root2){
    if(!root1)
      return !root2;

    return isIdentical(root1, root2) || hasIdenticalSubtree(root1->left, root2) || hasIdenticalSubtree(root1->right, root2);
  }
};

int main(){
  Solution solution;

  TreeNode* root1 = initialize1();
  TreeNode* root2 = initialize2();
  bool res = solution.hasIdenticalSubtree(root1, root2);
  cout << res << endl;

  return 0;
}
