/*
 * time: O(), space: O()
 */
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

void print(TreeNode* root){
  if(root == NULL)
    return;

  print(root->left);
  cout << root->val << ' ';
  print(root->right);
}

class Solution{
public:
  TreeNode* copyTree(TreeNode* root){
    if(root == NULL)
      return NULL;
    TreeNode* node = new TreeNode(root->val);
    node->left = copyTree(root->left);
    node->right = copyTree(root->right);
    return node;
  }

  vector<TreeNode*> generateTreesHelper(int begin, int end){
    vector<TreeNode*> res;
    if(begin > end){
      res.push_back(NULL);
      return res;
    }
    for(int i = begin; i <= end; i++){
      vector<TreeNode*> leftTrees = generateTreesHelper(begin, i - 1);
      vector<TreeNode*> rightTrees = generateTreesHelper(i + 1, end);
      for(int j = 0; j < leftTrees.size(); j++){
        for(int k = 0; k < rightTrees.size(); k++){
          TreeNode* root = new TreeNode(i);
          root->left = copyTree(leftTrees[j]);
          root->right = copyTree(rightTrees[k]);
          res.push_back(root);
        }
      }
    }
    return res;
  }

  vector<TreeNode*> generateTrees(int n){
    vector<TreeNode*> res;
    if(n <= 0) {
      return res;
    }
    return generateTreesHelper(1, n);
  }
};

int main(){
  Solution solution;
  int n = 3;

  vector<TreeNode*> res = solution.generateTrees(n);

  for(int i = 0; i < res.size(); i++){
    print(res[i]);
    cout << "\n";
  }

  return 0;
}
