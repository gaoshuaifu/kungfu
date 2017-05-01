#include <iostream>
#include <vector>
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
  void getAllPathsHelper(TreeNode* root, vector<TreeNode*>& path, vector<vector<TreeNode*> >& res) {
    if(!root->left && !root->right) {
      res.push_back(path);
      return;
    }

    if(root->left) {
      path.push_back(root->left);
      getAllPathsHelper(root->left, path, res);
      path.pop_back();
    }
    if(root->right) {
      path.push_back(root->right);
      getAllPathsHelper(root->right, path, res);
      path.pop_back();
    }
  }

  vector<vector<TreeNode*> > getAllPaths(TreeNode* root) {
    vector<vector<TreeNode*> > res;
    if(!root)
      return res;

    vector<TreeNode*> path;
    path.push_back(root);
    getAllPathsHelper(root, path, res);
    return res;
  }
};

class Solution1 {
public:
  void getAllPathsHelper(TreeNode* root, vector<TreeNode*>& path, vector<vector<TreeNode*> >& res) {
    path.push_back(root);
    if(!root->left && !root->right) {
      res.push_back(path);
    }

    if(root->left) {
      getAllPathsHelper(root->left, path, res);
    }

    if(root->right) {
      getAllPathsHelper(root->right, path, res);
    }

    path.pop_back();
  }

  vector<vector<TreeNode*> > getAllPaths(TreeNode* root) {
    vector<vector<TreeNode*> > res;
    if(!root)
      return res;

    vector<TreeNode*> path;
    getAllPathsHelper(root, path, res);
    return res;
  }
};

int main(){
  TreeNode* root = initialize();

  Solution solution;
  vector<vector<TreeNode*> > res = solution.getAllPaths(root);
  for(int i = 0; i < res.size(); i++){
    for(int j = 0; j < res[i].size(); j++)
      cout << res[i][j]->val << " ";
    cout << "\n";
  }
  cout << endl;

  return 0;
}
