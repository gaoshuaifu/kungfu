/*
 * time: O(n), space: O(n)
 */
#include <iostream>
#include <algorithm>
#include <vector>
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
    void pathSumHelper(TreeNode* root, int target, vector<int>& path, vector<vector<int> >& res){
        if(!root) return;

        path.push_back(root->val);

        int n = path.size();
        int total = 0;
        vector<int> sol;
        for(int i = n - 1; i >= 0; i--){
            total += path[i];
            sol.insert(sol.begin(), path[i]);
            if(total == target)
                res.push_back(sol);
        }

        pathSumHelper(root->left, target, path, res);
        pathSumHelper(root->right, target, path, res);

        path.pop_back();
    }

    vector<vector<int> > pathSum(TreeNode* root, int target){
        vector<vector<int> > res;
        vector<int> path;
        pathSumHelper(root, target, path, res);
        return res;
    }
};

int main(){
    Solution solution;
    TreeNode* root = initialize();
    int target = 6;

    vector<vector<int> > res = solution.pathSum(root, target);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
