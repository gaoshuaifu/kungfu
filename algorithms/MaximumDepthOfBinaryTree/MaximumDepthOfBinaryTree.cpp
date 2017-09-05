/*
 * time: O(n), space O(depth)
 */
#include <iostream>
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
    int maxDepth(TreeNode* root){
        if(root == NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

class Solution1{
public:
    int maxDepth(TreeNode* root){
        if(!root)
            return 0;

        int depth = 0;
        stack<TreeNode*> stk;
        stk.push(root);

        TreeNode* prev = NULL;
        TreeNode* curr = NULL;

        while(!stk.empty()){
            curr = stk.top();
            if(!prev || prev->left == curr || prev->right == curr){
                if(curr->left)
                    stk.push(curr->left);
                else if(curr->right)
                    stk.push(curr->right);
            }
            else if(curr->left == prev){
                if(curr->right)
                    stk.push(curr->right);
            }
            else if(curr->right == prev || prev == curr){
                stk.pop();
            }
            prev = curr;

            if(stk.size() > depth)
                depth = stk.size();
        }

        return depth;
    }
};

int main(){
    TreeNode* root = initialize();

    Solution1 solution;
    int res = solution.maxDepth(root);
    cout << res << endl;

    return 0;
}


