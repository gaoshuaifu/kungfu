/*
 * time: O(n), space O(hight)
 */
#include <iostream>
#include <vector>
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
  vector<int> inorderTraversal(TreeNode* root){
    vector<int> res;
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
        res.push_back(curr->val);
        curr = curr->right;
      }
    }
    return res;
  }
};

class Solution1{
public:
  void inorderTraversalHelper(TreeNode* root, vector<int>& res){
    if(!root)
      return;

    inorderTraversalHelper(root->left, res);
    res.push_back(root->val);
    inorderTraversalHelper(root->right, res);
  }

  vector<int> inorderTraversal(TreeNode* root){
    vector<int> res;
    inorderTraversalHelper(root, res);
    return res;
  }
};

int main(){
  TreeNode* root = initialize();

  Solution solution;
  vector<int> res = solution.inorderTraversal(root);
  for(int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;

  return 0;
}





