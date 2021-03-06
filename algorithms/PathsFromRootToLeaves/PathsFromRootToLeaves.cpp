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
    void sumNumbersHelper(TreeNode* root, vector<int>& path, vector<vector<int> >& res){
        if(!root)
            return;

        path.push_back(root->val);

        if(!root->left && !root->right)
            res.push_back(path);
        else{
            sumNumbersHelper(root->left, path, res);
            sumNumbersHelper(root->right, path, res);
        }

        path.pop_back();
    }

    vector<vector<int> > allPaths(TreeNode* root){
        vector<vector<int> > res;
        vector<int> path;
        sumNumbersHelper(root, path, res);
        return res;
    }
};

int main(){
    TreeNode* root = initialize();

    Solution solution;
    vector<vector<int> > res = solution.allPaths(root);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
