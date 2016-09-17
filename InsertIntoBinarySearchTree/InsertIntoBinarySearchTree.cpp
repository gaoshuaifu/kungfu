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
  bool insert(TreeNode*& root, int value){
    if(!root){
      root = new TreeNode(value);
      return true;
    }

    TreeNode* curr = root;
    while(true){
      if(root->val == value)
        return false;

      if(curr->val > value){
        if(!curr->left){
          curr->left = new TreeNode(value);
          return true;
        }
        else
          curr = curr->left;
      }
      else if(curr->val < value){
        if(!curr->right){
          curr->right = new TreeNode(value);
          return true;
        }
        else
          curr = curr->right;
      }
    }
  }
};

class Solution1{
public:
  bool insertHelper(TreeNode*& root, int value){
    if(root->val == value)
      return false;

    else if(root->val > value){
      if(!root->left){
        root->left = new TreeNode(value);
        return true;
      }
      else
        return insertHelper(root->left, value);
    }
    else if(root->val < value){
      if(!root->right){
        root->right = new TreeNode(value);
        return true;
      }
      else
        return insertHelper(root->right, value);
    }
  }

  bool insert(TreeNode*& root, int value){
    if(!root){
      root = new TreeNode(value);
      return true;
    }

    return insertHelper(root, value);
  }
};

int main(){
  TreeNode* root = NULL;
  Solution solution;
  bool success;

  cout << solution.insert(root, 4) << "\n";
  print(root);
  cout << "\n";

  cout << solution.insert(root, 2) << "\n";
  print(root);
  cout << "\n";

  cout << solution.insert(root, 1) << "\n";
  print(root);
  cout << "\n";

  cout << solution.insert(root, 3) << "\n";
  print(root);
  cout << "\n";

  cout << solution.insert(root, 6) << "\n";
  print(root);
  cout << "\n";

  cout << solution.insert(root, 7) << "\n";
  print(root);
  cout << "\n";

  cout << solution.insert(root, 5) << "\n";
  print(root);
  cout << "\n";

  return 0;
}
