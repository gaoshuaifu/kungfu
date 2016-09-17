/*
 * time: O(n), space: O(n)
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

void inorderTraverse(TreeNode* root, vector<int>& inorderRes){
  if(root == NULL)
    return;
  inorderTraverse(root->left, inorderRes);
  inorderRes.push_back(root->val);
  inorderTraverse(root->right, inorderRes);
}

void print(vector<int>& res){
  for(int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;
}


class Solution{
public:
  TreeNode* sortedArrayToBSTHelper(vector<int>& num, int low, int high){
    if(low > high)
      return NULL;

    int mid = (low + high) / 2;
    TreeNode* root = new TreeNode(num[mid]);
    root->left = sortedArrayToBSTHelper(num, low, mid - 1);
    root->right = sortedArrayToBSTHelper(num, mid + 1, high);
    return root;
  }

  TreeNode* sortedArrayToBST(vector<int>& num){
    int n = num.size();
    return sortedArrayToBSTHelper(num, 0, n - 1);
  }
};

int main(){
  int numArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> num(numArr, numArr + sizeof(numArr) / sizeof(numArr[0]));

  Solution solution;
  TreeNode* root = solution.sortedArrayToBST(num);

  vector<int> inorderRes;
  inorderTraverse(root, inorderRes);
  print(inorderRes);

  return 0;
}

