/*
 * time: O(n)
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
  int minDepth(TreeNode *root) {
     if(!root)
       return 0;

     if(!root->left && !root->right)
       return 1;

     if(root->left && !root->right)
       return minDepth(root->left) + 1;

     if(!root->left && root->right)
       return minDepth(root->right) + 1;

     return min(minDepth(root->left), minDepth(root->right)) + 1;
  }
};

class Solution1{
public:
  int minDepth(TreeNode* root){
    if(!root)
      return 0;

    queue<TreeNode*> currQ;
    currQ.push(root);
    int depth = 1;

    while(!currQ.empty()){
      queue<TreeNode*> nextQ;
      while(!currQ.empty()){
        TreeNode* node = currQ.front();
        currQ.pop();
        if(!node->left && !node->right)
          return depth;
        if(node->left)
          nextQ.push(node->left);
        if(node->right)
          nextQ.push(node->right);
      }
      currQ = nextQ;
      depth++;
    }
  }
};

int main(){
  TreeNode* root = initialize();

  Solution solution;
  int res = solution.minDepth(root);
  cout << res << endl;

  return 0;
}

