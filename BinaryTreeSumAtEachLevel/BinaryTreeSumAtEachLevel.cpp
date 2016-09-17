/*
 * time: O(n), space: O(width)
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
  int getHeight(TreeNode* root){
    if(!root)
      return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
  }

  void sumAtLevel(TreeNode* root, int level, int&sum){
    if(!root) return;

    if(level == 1){
      sum += root->val;
      return;
    }

    sumAtLevel(root->left, level - 1, sum);
    sumAtLevel(root->right, level - 1, sum);
  }

  vector<int> sumAtEachLevel(TreeNode* root){
    vector<int> res;
    int height = getHeight(root);
    for(int level = 1; level <= height; level++){
      int sum = 0;
      sumAtLevel(root, level, sum);
      res.push_back(sum);
    }
    return res;
  }
};

int main(){
  TreeNode* root = initialize();

  Solution solution;
  vector<int> res = solution.sumAtEachLevel(root);
  for(int i = 0; i < res.size(); i++)
    cout << res[i] << "\n";

  return 0;
}
