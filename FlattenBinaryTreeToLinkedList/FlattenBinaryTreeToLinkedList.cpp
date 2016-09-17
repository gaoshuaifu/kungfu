/*
 * time: O(n), space: O(hight)
 */
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
  void flattenHelper(TreeNode* root, TreeNode*& tail){
    if(!root)
      return;

    TreeNode* leftNode = root->left;
    TreeNode* rightNode = root->right;

    if(tail)
      tail->right = root;
    tail = root;
    tail->left = NULL;
    tail->right = NULL;

    flattenHelper(leftNode, tail);
    flattenHelper(rightNode, tail);
  }

  void flatten(TreeNode* root){
    TreeNode* tail = NULL;
    flattenHelper(root, tail);
  }
};


int main(){
  TreeNode* root = initialize();
  Solution solution;
  solution.flatten(root);
  for(TreeNode* p = root; p != NULL; p = p->right){
    cout << p->val << " ";
    cout << "[" << ((p->left == NULL)? "#":"") << "]" << " ";
  }
  cout << endl;
  return 0;
}

