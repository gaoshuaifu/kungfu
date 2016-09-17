/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <stack>
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
  TreeNode* node1 = new TreeNode(4);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(6);
  TreeNode* node4 = new TreeNode(1);
  TreeNode* node5 = new TreeNode(3);
  TreeNode* node6 = new TreeNode(5);
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

void print(TreeNode* root){
  if(!root)
    return;

  print(root->left);
  cout << root->val << " ";
  print(root->right);
}

class Solution{
public:
  bool isValidBST(TreeNode* root){
    TreeNode* prev = NULL;

    stack<TreeNode*> stk;
    TreeNode* curr = root;
    while(curr || !stk.empty()){
      if(curr){
        stk.push(curr);
        curr = curr->left;
      }
      else{
        curr = stk.top();
        stk.pop();

        if(prev && prev->val >= curr->val)
          return false;
        prev = curr;

        curr = curr->right;
      }
    }
    return true;
  }
};

class Solution1{
public:
  bool isValidBSTHelper(TreeNode* curr, TreeNode*& prev){
    if(!curr)
      return true;

    if(!isValidBSTHelper(curr->left, prev))
      return false;

    if(prev && prev->val >= curr->val)
      return false;
    prev = curr;

    if(!isValidBSTHelper(curr->right, prev))
      return false;

    return true;
  }

  bool isValidBST(TreeNode* root){
    TreeNode* prev = NULL;
    return isValidBSTHelper(root, prev);
  }
};

class Solution2{
public:
  bool isValidBSTHelper(TreeNode* root, int low, int high){
    if(!root)
      return true;

    if(root->val <= low || root->val >= high)
      return false;

    return isValidBSTHelper(root->left, low, root->val) && isValidBSTHelper(root->right, root->val, high);
  }

  bool isValidBST(TreeNode* root){
    return isValidBSTHelper(root, INT_MIN, INT_MAX);
  }
};

int main(){
  TreeNode* root = initialize();
  Solution solution;
  cout << solution.isValidBST(root) << endl;
  return 0;
}

