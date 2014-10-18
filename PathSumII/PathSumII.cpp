/*
 * time: O(n), space: O(h)
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

TreeNode* initialize(){
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(3);
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
    void pathSumHelper(TreeNode* root, int sum, vector<int>& path, vector<vector<int> >& res){
        if(!root)
            return;

        path.push_back(root->val);
        if(!root->left && !root->right && sum == root->val){
            res.push_back(path);
            path.pop_back();
            return;
        }

        pathSumHelper(root->left, sum - root->val, path, res);
        pathSumHelper(root->right, sum - root->val, path, res);

        path.pop_back();
    }

    vector<vector<int> > pathSum(TreeNode* root, int sum){
        vector<vector<int> > res;
        vector<int> path;
        pathSumHelper(root, sum, path, res);
        return res;
    }
};

int main(){
    TreeNode* root = initialize();
    int sum = 7;

    Solution solution;
    vector<vector<int> > res = solution.pathSum(root, sum);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
    cout << endl;

    return 0;
}

