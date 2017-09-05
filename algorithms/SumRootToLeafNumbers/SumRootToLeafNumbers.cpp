/*
 * time: O(n), space: O(1)
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
    void sumNumbersHelper(TreeNode* root, int pathSum, int& sum){
        if(!root)
            return;

        pathSum = pathSum * 10 + root->val;

        if(!root->left && !root->right)
            sum += pathSum;
        else{
            sumNumbersHelper(root->left, pathSum, sum);
            sumNumbersHelper(root->right, pathSum, sum);
        }
    }

    int sumNumbers(TreeNode* root){
        int sum = 0;
        sumNumbersHelper(root, 0, sum);
        return sum;
    }
};

int main(){
    TreeNode* root = initialize();

    Solution solution;
    int res = solution.sumNumbers(root);
    cout << res << endl;

    return 0;
}

